// VPC - HUPC  2576
// B - Doctor Course Is Recommended / D進どうですか？

use std::collections::HashMap;
use std::collections::BTreeMap;

#[allow(dead_code)]
fn read_line(n: usize) -> String {
    let mut ss = String::new();
    for _i in 0..n {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        ss.push_str(&s);
    }
    ss
}

macro_rules! parse {
    ($s:expr => $($r:tt)*) => {
        let s = $s;
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        use std::io::Read;
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        parse!{s => $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
    ($iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        let mut $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

fn main() {
    parse! {
        mut d: usize,
        x: usize,
        mut aps: [(char, usize); x],
        y: usize,
        mut bcqs: [(String, usize); y],
    }

    aps .retain(|ap |  ap.0 == 'D' );
    bcqs.retain(|bcq| bcq.0 == "DD");

    let mut map = BTreeMap::new();
    for ap in aps {
        *map.entry(ap.1).or_insert(HashMap::new()).entry(1).or_insert(0) += 1;
    }
    for bcq in bcqs {
        *map.entry(bcq.1).or_insert(HashMap::new()).entry(2).or_insert(0) += 1;
    }

    let mut ans = 0;
    while d > 0 {
        let last = map.iter_mut().next_back();
        match last {
            Some(last_v) => {
                let p   = last_v.0;
                let one = last_v.1.get_mut(&1);
                match one {
                    Some(one_v) => {
                        ans += p;
                        *one_v -= 1;
                        if *one_v == 0 {
                            last_v.1.remove(&1);
                        }
                        d -= 1;
                    }
                    None => {
                        let two = last_v.1.get_mut(&2);
                        match two {
                            Some(two_v) => {
                                ans += p;
                                *two_v -= 1;
                                if *two_v == 0 {
                                    last_v.1.remove(&2);
                                }
                                d -= 2;
                            }
                            None => {},
                        }
                    },
                }
                if last_v.1.is_empty() {
                    //map.remove(&p);
                    let del = *p;
                    map.remove(&del);
                }
            },
            None => break,
        }
    }

    //println!("{:?}", map);
    println!("{}", ans);
}

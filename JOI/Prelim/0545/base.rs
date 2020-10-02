// JOI - Prelim  0545

use std::collections::HashMap;
use std::collections::HashSet;

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

fn sub() -> bool
{
    parse!{
        read_line(2) =>
        n: usize,
        m: usize,
    }
    if n == 0 && m == 0 {
        return false;
    }
    let mut map = HashMap::new();
    for _i in 0..m {
        parse!{
            read_line(1) =>
            key: i32,
            val: i32,
        }
        let set = map.entry(key).or_insert(HashSet::new());
        set.insert(val);
    }
    let my = 1;
    if !map.contains_key(&my) {
        // あなたには友達がいない
        println!("0");
        return true;
    }
    // 友人をリストアップ
    let friends = &map[&my];
    let mut set_target = HashSet::new();
    for friend in friends {
        set_target.insert(friend);
    }
    // 友人の友人をリストアップ
    for friend in friends {
        if !map.contains_key(friend) {
            // 友人に友人が居ない
            continue;
        }
        for ff in &map[friend] {
            set_target.insert(ff);
        }
    }
    let ans = set_target.len();
    println!("{}", ans);
    return true;
}

fn main()
{
    while sub() {}
}

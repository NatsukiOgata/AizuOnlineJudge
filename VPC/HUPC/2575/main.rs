// VPC - HUPC  2575
// A - D's Ambition / Dのやぼう

use std::collections::HashMap;

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
        ds: chars,
    }

    let base = "AIZUNYAN";

    let anagram = "AIDUNYAN";
    let al = anagram.len();

    let dl = ds.len();
    if dl < al {
        for d in ds {
            print!("{}", d);
        }
        println!("");
        return;
    }

    let mut map_a = HashMap::new();
    for a in anagram.chars() {
        *map_a.entry(a).or_insert(0) += 1;
    }

    let mut i = 0;
    while i < dl {
        let d = ds[i];
        let mut hit = false;
        match d {
            'A' | 'I' | 'D' | 'U' | 'N' | 'Y' => {
                let mut map_d = HashMap::new();
                for j in 0..al {
                    let d = ds.get(i + j);
                    match d {
                        Some(v) => *map_d.entry(*v).or_insert(0) += 1,
                        None => break,
                    }
                }
                hit = map_a == map_d;
            }
            _ => {}
        }
        if hit {
            print!("{}", base);
            i += al;
        } else {
            print!("{}", d);
            i += 1;
        }
    }

    println!("");
}

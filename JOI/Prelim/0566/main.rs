// JOI - Prelim - 0566

use std::cell::*;
use std::collections::*;

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

thread_local! {
    static MAP_COUNT: RefCell<BTreeMap<usize, usize>> = RefCell::new(BTreeMap::new());
}

fn add_point(team: usize, value: usize) {
    MAP_COUNT.with(|map_count| {
        *map_count.borrow_mut().entry(team).or_insert(0) += value;
    });
}

fn main() {
    parse! {
        read_line(1) =>
        n: usize,
    }
    let cnt = n * (n - 1) / 2;
    for _i in 0..cnt {
        parse! {
            read_line(1) =>
            a: usize,
            b: usize,
            c: usize,
            d: usize,
        }
        if c > d {
            add_point(a, 3);
        } else if c < d {
            add_point(b, 3);
        } else {
            add_point(a, 1);
            add_point(b, 1);
        }
    }
    let mut vec = Vec::new();
    MAP_COUNT.with(|map_count| {
        for (_k, v) in map_count.borrow().iter() {
            vec.push(*v);
        }
    });
    for v in &vec {
        let ans = vec.iter().filter(|&f| v < f).count() + 1;
        println!("{}", ans);
    }
}

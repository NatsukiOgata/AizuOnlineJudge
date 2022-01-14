// JOI - Prelim - 0501

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

fn sub() -> bool {
    parse! {
        read_line(1) =>
        n: usize,
    }
    if n == 0 {
        return false;
    }
    let mut conv_map = HashMap::with_capacity(n);
    for _i in 0..n {
        parse! {
            read_line(1) =>
            from_to: (char, char),
        }
        conv_map.insert(from_to.0, from_to.1);
    }
    parse! {
        read_line(1) =>
        m: usize,
    }
    parse! {
        read_line(m) =>
        s: [char; m],
    }
    for c in s {
        let o = match conv_map.get(&c) {
            Some(&v) => v,
            None => c,
        };
        print!("{}", o);
    }
    println!();
    return true;
}

fn main() {
    loop {
        if !sub() {
            break;
        }
    }
}

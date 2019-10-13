// UOA - Uapc  3064
// Problem A: AOJ50M

// std input
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),*  )) => {
        ( $(read_value!($iter, $t)),*  )
    };
    ($iter:expr, [ $t:tt ; $len:expr  ]) => {
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

fn sub() -> String
{
    input!
    {
        t1: i32,
        t2: i32,
        r1: i32,
        r2: i32,
    }
    if r1 < 0 || r2 < 0 {
        if t1 < t2 {
            "Alice".to_string()
        }
        else if t1 > t2 {
            "Bob".to_string()
        }
        else {
            "Draw".to_string()
        }
    }
    else if r1 > r2 {
        "Alice".to_string()
    }
    else if r1 < r2 {
        "Bob".to_string()
    }
    else {
        "Draw".to_string()
    }
}

fn main()
{
    println!("{}", sub());
}

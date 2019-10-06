// JOI - Prelim  0533
// コンテスト
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

fn main() {
    input!{
        ns: [u64; 20],
    }
    let mut a_s = ns;
    let mut b_s = a_s.split_off(10);
    a_s.sort_by(|a, b| b.cmp(a));
    b_s.sort_by(|a, b| b.cmp(a));
    let a_sum = a_s.iter().take(3).fold(0, |sum, v| sum + v);
    let b_sum = b_s.iter().take(3).fold(0, |sum, v| sum + v);
    println!("{} {}", a_sum, b_sum);
}

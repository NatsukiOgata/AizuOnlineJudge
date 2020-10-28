// UOA - UAPC  1552
// Problem B: Mountain Climbing

use std::collections::VecDeque;

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
        n: usize,
        a_s: [i32; n],
    }

    let mut ans = [0, 0, 0, 0, 0];

    let mut que = VecDeque::new();
    let mut prev = i32::max_value();
    for a in a_s {
        if prev == i32::max_value() {
            prev = a;
            continue;
        }

        let diff = a - prev;
        prev = a;
        if let Some(quep) = que.front() {
            if *quep == diff {
                continue;
            }
        }
        que.push_front(diff);
        //while que.len() > 3 {
        //    que.pop_back();
        //}

        let quel = que.len();
        if quel == 1 {
            continue;
        }

        let mut iter = que.iter();
        let a0 = *iter.next().unwrap();
        let a1 = *iter.next().unwrap();

        let mut j = usize::max_value();
        if a1 > 0 && a0 < 0 {
            j = 3;
        } else if a1 < 0 && a0 > 0 {
            j = 4;
        }

        if quel >= 3 && j == usize::max_value() {
            let a2 = *iter.next().unwrap();

            if a2 > 0 && a1 == 0 && a0 < 0 {
                j = 0;
            } else if a2 < 0 && a1 == 0 && a0 > 0 {
                j = 1;
            } else if a2 < 0 && a1 == 0 && a0 < 0 {
                j = 2;
            } else if a2 > 0 && a1 == 0 && a0 > 0 {
                j = 2;
            }
        }

        if j == usize::max_value() {
            continue;
        }
        ans[j] += 1;
    }

    println!("{} {} {} {} {}", ans[0], ans[1], ans[2], ans[3], ans[4]);
}

// UOA - UAPC  1552
// Problem B: Mountain Climbing

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
    for i in 2..n {
        let a0 = a_s.get(i);
        let a1 = a_s.get(i - 1);
        let a2 = a_s.get(i - 2);
        if a2 < a1 && a1 > a0 {
            ans[3] += 1;
            continue;
        }
        if a2 > a1 && a1 < a0 {
            ans[4] += 1;
            continue;
        }

        if i < 3 {
            continue;
        }
        let a3 = a_s.get(i - 3);
        if a3 < a2 && a2 == a1 && a1 > a0 {
            ans[0] += 1;
            continue;
        }
        if a3 > a2 && a2 == a1 && a1 < a0 {
            ans[1] += 1;
            continue;
        }
        if a3 < a2 && a2 == a1 && a1 < a0 {
            ans[2] += 1;
            continue;
        }
        if a3 > a2 && a2 == a1 && a1 > a0 {
            ans[2] += 1;
            continue;
        }
    }

    println!("{} {} {} {} {}", ans[0], ans[1], ans[2], ans[3], ans[4]);
}

// UOA - UAPC  1575
// Product Sale Lines

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

fn main()
{
    parse!{
        w: i32,
        h: i32,
        n: usize,
        ps: [usize; n],
    }
    let mut ans = 0;
    let mut pos = [0; 2];
    let p0_c1 = w - 1;
    let p0_c2 = p0_c1 + h - 1;
    let p1_c1 = p0_c1 - 1;
    let p1_c2 = p1_c1 + h - 3;
    for p in ps {
        pos[p] += 1;
        let mut p0 = pos[0];
        let     p1 = pos[1];
        if 0 <= p0 && p0 < p0_c1 && 0 <= p1 && p1 <= p1_c1 {
            // 最初の直線
        }
        else if p0_c1 < p0 && p0 < p0_c2 && p1_c1 <= p1 && p1 <= p1_c2 {
            // 2番目の直線
            p0 -= 2;
        }
        else if p0_c2 < p0 && p1_c2 <= p1 {
            // 最後の直線
            p0 -= 4;
        }
        else {
            continue;
        }
        if p0 == p1 {
            ans += 1;
        }
    }
    println!("{}", ans);
}

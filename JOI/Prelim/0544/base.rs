// JOI - Prelim  0544

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
        read_line(1) =>
        n: usize,
        m: usize,
    }
    if n == 0 && m == 0 {
        return false;
    }
    parse!{
        read_line(n) =>
        masus: [i32; n],
    }
    parse!{
        read_line(m) =>
        dices: [i32; m],
    }

    let mut ans = 0;
    {
        let mut pos: i32 = 0;
        for i in 0..dices.len() {
            pos += dices[i];
            if n as i32 - 1 <= pos {
                ans = i + 1;
                break;
            }
            pos += masus[pos as usize];
            if n as i32 - 1 <= pos {
                ans = i + 1;
                break;
            }
        }
    }
    println!("{}", ans);
    return true;
}

fn main()
{
    while sub() {}
}

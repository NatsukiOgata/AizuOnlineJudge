// JOI - Prelim - 0502

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
    parse! {
        read_line(n) =>
        moves: [String; n],
    }
    let mut dice = (1, 2, 3);
    let mut ans = dice.0;
    for m in moves {
        dice = match m.as_str() {
            "North" => (dice.1, 7 - dice.0, dice.2),
            "East" => (7 - dice.2, dice.1, dice.0),
            "South" => (7 - dice.1, dice.0, dice.2),
            "West" => (dice.2, dice.1, 7 - dice.0),
            "Right" => (dice.0, dice.2, 7 - dice.1),
            "Left" => (dice.0, 7 - dice.2, dice.1),
            _ => (0, 0, 0),
        };
        ans += dice.0;
    }
    println!("{}", ans);
    return true;
}

fn main() {
    loop {
        if !sub() {
            break;
        }
    }
}

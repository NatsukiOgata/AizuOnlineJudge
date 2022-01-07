// UOA - UAPC - 3511

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

fn next(vec: usize) -> (i32, i32)
{
    match vec {
        0 => ( 1,  0),
        1 => ( 0,  1),
        2 => (-1,  0),
        3 => ( 0, -1),
        _ => ( 0,  0), // error
    }
}

fn is_inner(senco: &Vec<Vec<char>>, x: i32, y: i32) -> bool
{
    if x < 0 {
        false
    }
    else
    if y < 0 {
        false
    }
    else
    if y >= senco.len() as i32 {
        false
    }
    else
    if x >= senco[y as usize].len() as i32 {
        false
    }
    else {
        true
    }
}

fn main()
{
    parse! {
        h: usize,
        w: usize,
        mut n: usize,
    }
    let mut senco = vec![vec!['#'; w]; h];
    let mut pos = (0, 0);
    let mut vec = 0;
    let mut stopper = 0;
    while n > 0 {
        senco[pos.1][pos.0] = 'X';
        let add = next(vec);
        let new = (pos.0 as i32 + add.0, pos.1 as i32 + add.1);
        if !is_inner(&senco, new.0, new.1) || senco[new.1 as usize][new.0 as usize] == 'X' {
            vec = (vec + 1) % 4;
            stopper = stopper + 1;
            if stopper >= 3 {
                // 無限ループ回避
                break;
            }
        }
        else {
            pos.0 = new.0 as usize;
            pos.1 = new.1 as usize;
            stopper = 0;
            n = n - 1;
        }
    }
    for senco1 in &senco {
        for senco2 in senco1 {
            print!("{0}", &senco2);
        }
        println!("");
    }
}

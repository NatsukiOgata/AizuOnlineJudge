// UOA - UAPC  1051
// Problem A: Citation Format

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
        read_line(1) =>
        pages: [i32; n],
    }

    let mut pairs = Vec::new();
    {
        let mut pagefo = None;
        let mut pagep = 0;
        for page in pages {
            match pagefo.as_mut() {
                Some(pagef) => {
                    if page - pagep != 1 {
                        pairs.push((*pagef, pagep));
                        *pagef = page;
                    }
                }
                None => pagefo = Some(page),
            }
            pagep = page;
        }
        if let Some(pagef) = pagefo {
            pairs.push((pagef, pagep));
        }
    }

    for pair in &pairs {
        if pair != &pairs[0] {
            print!(" ");
        }
        if pair.0 == pair.1 {
            print!("{}", pair.0);
        } else {
            print!("{}-{}", pair.0, pair.1);
        }
    }
    println!("");

    return true;
}

fn main() {
    while sub() {}
}

// UOA - UAPC  1021
// Problem C: Emacs-like Editor

use std::cmp;

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
    let mut lines:Vec<Vec<char>> = Vec::new();
    loop {
        parse!{
            read_line(1) =>
            line: String,
        }
        if line == "END_OF_TEXT" {
            break;
        }
        let mut linec:Vec<char> = Vec::new();
        lines.push(linec);
    }
    let mut cur_x = 0;
    let mut cur_y = 0;
    let mut buff = String::new();
    loop {
        parse!{
            read_line(1) =>
            cmds: chars,
        }
        let cmd = cmds[0];
        match cmd {
            'a' => cur_x = 0,
            'e' => cur_x = lines[cur_y].len() - 1,
            'p' => {
                cur_x = 0;
                cur_y = cmp::max(cur_y - 1, 0);
            },
            'n' => {
                cur_x = 0;
                cur_y = cmp::min(cur_y + 1, lines.len() - 1);
            },
            'f' => {
                if cur_x == lines[cur_y].len() - 1 && cur_y < lines.len() - 1 {
                    cur_x = 0;
                    cur_y += 1;
                }
                else {
                    cur_x = cmp::min(cur_x + 1, lines[cur_y].len() - 1);
                }
            },
            'b' => {
                if cur_x == 0 && cur_y > 0 {
                    cur_y -= 1;
                    cur_x = lines[cur_y].len() - 1;
                }
            },
            'd' => {
                if cur_x == lines[cur_y].len() - 1 && cur_y < lines.len() - 1 {
                    let mut d = &mut lines.remove(cur_y + 1);
                    lines[cur_y].append(d);
                }
                else {
                    lines[cur_y].remove(cur_x);
                }
            }
            'k' => {
                if cur_x == lines[cur_y].len() - 1 && cur_y < lines.len() - 1 {
                    let mut d = &mut lines.remove(cur_y + 1);
                    lines[cur_y].append(d);
                    buff = "\n".to_string();
                }
                else {
                    
                }
            },
            _ => break,
        }
    }
}

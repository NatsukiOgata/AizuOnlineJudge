// UOA - PCKWU  1046
// Problem 06: Ghost Buster!

use std::cmp;
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

const INF: i32 = i32::max_value();

fn find(tiless: &Vec<Vec<char>>, target: &char) -> (usize, usize) {
    for y in 0..tiless.len() {
        let tiles = &tiless[y];
        for x in 0..tiles.len() {
            let tile = &tiles[x];
            if tile == target {
                return (x, y);
            }
        }
    }
    (0, 0)
}

fn cost(tiless: &Vec<Vec<char>>, xy: &(usize, usize)) -> (Vec<Vec<i32>>, usize) {
    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    let h = tiless.len() as i32;
    let w = tiless[0].len() as i32;

    let mut costss = Vec::new(); // Vec<Vec<i32>>
    for tiles in tiless {
        let mut costs = Vec::new(); // Vec<i32>
        for _tile in tiles {
            costs.push(INF);
        }
        costss.push(costs);
    }

    costss[xy.1][xy.0] = 0;

    let mut que = VecDeque::new();
    que.push_back(*xy);
    let mut max_count: usize = 0;
    while !que.is_empty() {
        let (x, y) = que.pop_front().expect("error");
        let mc = costss[y][x] + 1;
        for i in 0..dx.len() {
            let nx = (x as i32 + dx[i]) as i32;
            let ny = (y as i32 + dy[i]) as i32;
            if 0 > nx || nx >= w || 0 > ny || ny >= h {
                continue;
            }
            let nx = nx as usize;
            let ny = ny as usize;
            if tiless[ny][nx] == '#' || costss[ny][nx] != INF {
                continue;
            }
            que.push_back((nx, ny));
            costss[ny][nx] = mc;
            if max_count < mc as usize {
                max_count = mc as usize;
            }
        }
    }

    (costss, max_count)
}

fn move_g(
    costss: &Vec<Vec<i32>>,
    i: usize,
    g_moves: &Vec<char>,
    x: &mut usize,
    y: &mut usize,
) -> bool {
    if costss[*y][*x] <= i as i32 {
        return true;
    }
    let h = costss.len();
    let w = costss[0].len();
    let pos = i % g_moves.len();
    let act = g_moves[pos];
    match act {
        '5' => {}
        '8' => {
            if *y > 0 {
                *y -= 1;
            }
        }
        '6' => {
            if *x < w - 1 {
                *x += 1;
            }
        }
        '4' => {
            if *x > 0 {
                *x -= 1;
            }
        }
        '2' => {
            if *y < h - 1 {
                *y += 1;
            }
        }
        _ => {}
    }
    false
}

fn sub() -> bool {
    parse! {
        read_line(1) =>
        h: usize,
        w: usize,
    }
    if h == 0 && w == 0 {
        return false;
    }
    parse! {
        read_line(h) =>
        tiless: [chars; h],
    }
    parse! {
        read_line(1) =>
        g_moves: chars,
    }

    // 少女と幽霊を探す
    let a = find(&tiless, &'A');
    let b = find(&tiless, &'B');

    // 移動距離を求める
    let (costss, max_count) = cost(&tiless, &a);

    // 調査するターン数を決める
    let g_move_len = g_moves.len();
    let g_count = g_move_len * g_move_len * 2;
    let count = cmp::max(max_count, g_count) + 1;

    // 幽霊を動かす
    let mut x = b.0;
    let mut y = b.1;
    for i in 0..count {
        if move_g(&costss, i, &g_moves, &mut x, &mut y) {
            println!("{} {} {}", i, y, x);
            return true;
        }
    }

    println!("impossible");
    true
}

fn main() {
    while sub() {}
}

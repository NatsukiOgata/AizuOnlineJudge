// JOI - Prelim  0523
// カードゲーム
use std::fmt::Debug;
use std::str::FromStr;

fn read_line<T>() -> Vec<T>
where
    T: FromStr,
    <T as FromStr>::Err: Debug,
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .map(|c| T::from_str(c).unwrap())
        .collect()
}

fn sub() -> bool {
    let datas: Vec<usize> = read_line();
    let n = datas[0];
    if n == 0 {
        return false;
    }
    let mut cards0 = Vec::with_capacity(n);
    let mut cards1 = Vec::with_capacity(n * 2);
    for _i in 0..n {
        let datas: Vec<u32> = read_line();
        cards0.push(datas[0]);
    }
    cards0.sort();
    for i in 1..2 * n + 1 {
        let i_u32 = i as u32;
        if let Err(_val) = cards0.binary_search(&i_u32) {
            cards1.push(i_u32);
        }
    }
    let mut cardss = vec![&mut cards0, &mut cards1];
    let mut ba = 0u32;
    'fin: loop {
        for cards in &mut cardss {
            let index = cards.iter().position(|&card| card > ba);
            if index == None {
                ba = 0u32;
                continue;
            }
            let si = index.unwrap();
            ba = cards.remove(si);
            if cards.is_empty() {
                break 'fin;
            }
        }
    }
    println!("{}", cardss[1].len());
    println!("{}", cardss[0].len());
    return true;
}

fn main() {
    loop {
        if !sub() {
            break;
        }
    }
}

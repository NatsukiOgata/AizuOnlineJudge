// PCK - Prelim  0027
// 何曜日？
use std::str::FromStr;
use std::fmt::Debug;

fn read_line<T>() -> Vec<T>
where T: FromStr, <T as FromStr>::Err : Debug{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|c| T::from_str(c).unwrap()).collect()
}

fn sub() -> bool
{
    let dates : Vec<u32> = read_line();
    let mut m = dates[0];
    let     d = dates[1];
    if m == 0 || d == 0 {
        return false;
    }
    let mut y = 2004;
    if m < 3 {
        y -= 1;
        m += 12;
    }
    let dayofweek = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
    let table = [
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
    ];
    let ans = table[dayofweek as usize];
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

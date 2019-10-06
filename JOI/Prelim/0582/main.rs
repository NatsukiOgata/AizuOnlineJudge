// JOI - Prelim  0582
// 問題1
use std::str::FromStr;
use std::fmt::Debug;

fn read_line<T>() -> Vec<T>
where T: FromStr, <T as FromStr>::Err : Debug
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|c| T::from_str(c).unwrap()).collect()
}

fn pow2(value: u32) -> f64
{
    (value * value) as f64
}

fn sub(anss: &mut [u32]) -> bool
{
    let mut datas : Vec<u32> = read_line();
    datas.sort();
    if datas[0] + datas[1] <= datas[2] {
        return false;
    }
    anss[0] += 1;
    let len = (pow2(datas[0]) + pow2(datas[1])).sqrt();
    let oth = datas[2] as f64;
    if len < oth {
        anss[3] += 1;
    }
    else if len > oth {
        anss[2] += 1;
    }
    else {
        anss[1] += 1;
    }
    return true;
}

fn main()
{
    let mut anss = [0u32; 4];
    loop {
        if !sub(&mut anss) {
            break;
        }
    }
    println!("{} {} {} {}", anss[0], anss[1], anss[2], anss[3]);
}

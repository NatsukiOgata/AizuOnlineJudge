// UOA - UAPC  1019
// Problem A: Vampirish Night
use std::fmt::Debug;
use std::str::FromStr;

// std input(line)
fn read_line<T>() -> Vec<T>
where T: FromStr, <T as FromStr>::Err : Debug{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|c| T::from_str(c).unwrap()).collect()
}

fn sub() -> bool
{
    let lines = read_line();
    let n = lines[0];
    let k = lines[1];

    if n == 0 && k == 0 {
        return false;
    }

    let stocks:Vec<u32> = read_line();
    assert!(stocks.len() == k);

    let mut wants = Vec::new();
    for _i in 0..k {
        wants.push(Vec::new());
    }

    for _i in 0..n {
        let lines = read_line();
        assert!(lines.len() == k);
        for j in 0..k {
            wants[j].push(lines[j]);
        }
    }

    let mut over = false;
    for i in 0..k {
        let sum = wants[i].iter().fold(0u32, |sum, v| sum + v);
        if stocks[i] < sum {
            over = true;
            break;
        }
    }

    if over {
        println!("No");
    }
    else {
        println!("Yes");
    }

    return true;
}

fn main()
{
    while sub() {}
}

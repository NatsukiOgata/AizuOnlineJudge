// PCK - Prelim  0028
// 最頻値

use std::collections::BTreeMap;

fn main()
{
    let ns = {
        let mut vec = Vec::new();
        let mut s = String::new();
        loop {
            s.clear();
            match std::io::stdin().read_line(&mut s) {
                Ok(0) => break, // EOF
                Ok(_) => vec.push(s.trim_right().parse::<i32>().unwrap()),
                Err(e) => println!("{}", e),
            }
        }
        vec
    };

    let mut map_count: BTreeMap<i32, usize> = BTreeMap::new();
    for n in ns {
        *map_count.entry(n).or_insert(0) += 1;
    }

    let max_value = map_count.values().max().unwrap();

    for (key, value) in &map_count {
        if value != max_value {
            continue;
        }
        println!("{}", key);
    }
}

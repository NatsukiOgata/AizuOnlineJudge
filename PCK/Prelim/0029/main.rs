// PCK - Prelim  0029
// 英語の文章

use std::collections::*;

fn main()
{
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let ss = s.trim().split_whitespace().collect::<Vec<&str>>();

    let mut map_count = HashMap::with_capacity(ss.len());
    for s in ss {
        *map_count.entry(s).or_insert(0) += 1;
    }

    let max_count = {
        let mut ret = String::new();
        let max_value = map_count.values().max().unwrap();
        for (key, value) in &map_count {
            if value != max_value {
                continue;
            }
            ret = key.to_string();
            break;
        }
        ret
    };

    let max_len = map_count.keys().max_by(|l, r| l.len().cmp(&r.len())).unwrap();
    println!("{} {}", max_count, max_len);
}

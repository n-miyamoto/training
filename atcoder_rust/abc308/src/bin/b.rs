use::proconio::input;
use std::collections::HashMap;

fn main() {
    input!{
        n: usize, 
        m: usize, 
        c: [String;n],
        d: [String;m],
        p: [usize;m+1],
    }

    let price_map: HashMap<&String, &usize> = d.iter().zip(&p[1..]).collect();
    let ans: usize = c.iter().map(|x| *price_map.get(x).unwrap_or(&&p[0])).sum();
    println!("{}", ans);
}

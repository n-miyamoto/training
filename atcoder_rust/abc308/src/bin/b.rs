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

    let mut price_map = HashMap::new();
    for (i, color) in d.iter().enumerate(){
        price_map.insert(color, p[i+1]);
    }

    let ans: usize = c.iter().map(|x| {
        price_map.entry(x).or_insert(p[0]);
        price_map[x]
    }).sum();

    println!("{}", ans);
}

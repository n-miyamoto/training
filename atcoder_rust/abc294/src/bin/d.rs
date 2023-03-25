use proconio::input;
use std::collections::BTreeSet;

fn main() {
    input!{
        _n: usize, 
        q: usize,
    }

    let mut called_id = 0;
    let mut set = BTreeSet::new();

    for _ in 0..q {
        input!{ event: u8}
        match event{
            1 => {
                called_id+=1;
                set.insert(called_id);
            }
            2 => {
                input!{
                    x: usize
                }
                set.remove(&x);
            }
            3 => {
                let min_id = set.iter().next().unwrap_or(&0);
                println!{"{}", min_id}
            }
            _ => {}
            
        }
    }
}

use proconio::input;
use itertools::Itertools;
use std::collections::HashSet;

fn main() {
    input!{
        h: usize,
        w: usize,
        a: [[u32; w]; h],
    }

    let mut ans = 0 as usize;
    for comb in (0..(h+w-2)).combinations(h-1) {
        let mut right= vec![true; h+w-2];
        
        for c in comb {
            right[c]=false;
        }
        
        let mut x_cur=0;
        let mut y_cur=0;
        let mut good = true;
        let mut hashset= HashSet::new();
        for r in right{
            let tmp = a[y_cur][x_cur];
            if hashset.contains(&tmp) {
                good = false;
            }else {
                hashset.insert(tmp);
            }

            if r{
                x_cur+=1;
            }else{
                y_cur+=1;
            }
        }

        let tmp = a[y_cur][x_cur];
            if hashset.contains(&tmp) {
                good = false;
            }else {
                hashset.insert(tmp);
            }

        if good { ans+=1;}
    }

    println!{"{}", ans};
}

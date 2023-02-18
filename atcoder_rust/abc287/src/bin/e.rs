use::proconio::input;
use::proconio::marker::Chars;

#[derive(Debug, Eq, Ord, PartialEq, PartialOrd)]
struct S{
    s: String,
    id: usize,
    lcp: usize
}

impl S{
    pub fn new(s: String, id: usize) -> Self {
        S {
            s,
            id,
            lcp:0
        }
    }
}

fn min_of_two<T: std::cmp::Ord>(a: T, b: T) -> T {
    if a < b {
        a
    } else {
        b
    }
}

fn max_of_two<T: std::cmp::Ord>(a: T, b: T) -> T {
    if a > b {
        a
    } else {
        b
    }
}

fn count_lcp(c1: &Vec<char>, c2: &Vec<char>) -> usize{
    let n = min_of_two(c1.len(), c2.len());
    let mut ret=0;
    for i in 0..n{
        if c1[i]!=c2[i]{
            break;
        }
        ret+=1;
    }
    ret
}

fn main() {

    input!{
        n: usize,
        c: [Chars; n]
    }

    let mut svec: Vec<S> = vec![];
    for i in 0..n{
        let s: String = c[i].iter().collect();
        svec.push(S::new(s, i));
        //println!("{}", &svec[i].s);
    }

    svec.sort();

    for i in 0..n{
        //println!("{}", &svec[i].s);
        if i > 0 {
            svec[i].lcp = max_of_two(svec[i].lcp, count_lcp(&c[svec[i-1].id], &c[svec[i].id]));
        }

        if i+1 < n {
            svec[i].lcp = max_of_two(svec[i].lcp, count_lcp(&c[svec[i].id], &c[svec[i+1].id]));
        }
    }

    svec.sort_by(|a, b| a.id.cmp(&b.id));
    for i in 0..n{
        //println!("{} id: {}", &svec[i].s, svec[i].lcp);
        println!("{}", svec[i].lcp);
    }
}


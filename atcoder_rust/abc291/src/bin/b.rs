use proconio::input;

fn main() {
    input!{
        n: usize,
        mut x: [u32;5*n],
    }

    x.sort();

    let mut sum = 0;
    for i in n..4*n {
        sum+=x[i];
    }

    println!{"{:.15}", sum as f64 / (3*n) as f64};

}

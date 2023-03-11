use proconio::input;

fn main() {
    input! { n: usize }

    let mut v = vec![0 as u64 ; n];

    for i in 1..n {
        let m = n/i;
        for j in 1..=m {
            if i*j < n{
                v[i*j]+=1;
            }
        }
    }

    let mut ans = 0 as u64;
    for i in 1..n{
        let j = n-i;
        ans += v[i]*v[j];
    }

    println!{"{}", ans };
}

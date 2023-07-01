use::proconio::input;

fn main() {
    input!{
        a: [u64; 64],
    }
    let mut ans = 0 as u64;
    for (i, x) in a.iter().enumerate() {
        ans += x<<i;
    }
    println!("{}" , ans);
}

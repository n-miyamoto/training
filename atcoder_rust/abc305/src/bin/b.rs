use proconio::input;

fn main() {
    input!{
        p: char,
        q: char,
    }

    let v = vec![0, 3, 4, 8, 9, 14, 23];
    let ans: i32= v[p as usize - 'A' as usize] - v[q as usize - 'A' as usize];

    println!("{}", ans.abs());
}

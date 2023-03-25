use proconio::input;

fn main() {
    input!{
        n: usize,
        a: [u32; n],
    }

    let even = a.iter().filter(|&x| x%2==0).collect::<Vec<_>>();
    let ans = even.iter().map(|x| x.to_string()).collect::<Vec<_>>();
    println!{"{}", ans.join(" ")};
}

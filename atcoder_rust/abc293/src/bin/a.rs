use proconio::{input, marker::Chars};

fn main() {
    input!{
        s: Chars,
    }
    let l = s.len();
    for i  in 0..l {
        if i%2==0{
            print!("{}", s[i+1]);
        }else{
            print!("{}", s[i-1]);
        }
    }
    println!();
}

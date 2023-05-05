use proconio::input;

fn main() {
    input!{
        n: usize,
        a: i32,
        b: i32,
        c: [i32; n],
    }

    for i in 0..n {
        if a + b == c[i] {
            println!("{}", i + 1);
            return;
        }
    }
}

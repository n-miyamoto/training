use::proconio::input;
use::proconio::marker::Chars;

fn main() {
    input!{
        n: usize,
        s: Chars,
    }

    for c in s {
        print!("{}{}", c, c);
    }
}

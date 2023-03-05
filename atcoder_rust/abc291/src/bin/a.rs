use proconio::input;
use proconio::marker::Chars;

fn main() {
    input!{
        c: Chars,
    }

    for (i, ch) in c.iter().enumerate() {
        if ch.is_ascii_uppercase() {
            println!("{}", i + 1);
            return;
        }
    }
}

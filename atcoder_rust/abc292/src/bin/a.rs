use proconio::input;
use proconio::marker::Chars;

fn main() {
    input! {s: Chars}

    for c in s {
        print! {"{}", (c as u8 - ('a' as u8 - 'A' as u8)) as char };
    }
    println! {};
}

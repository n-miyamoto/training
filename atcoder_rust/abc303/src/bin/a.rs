use::proconio::input;
use::proconio::marker::Chars;

fn is_same_char(c1: &char, c2: &char) -> bool{
    match (c1, c2){
        ('0', 'o') => true,
        ('o', '0') => true,
        ('1', 'l') => true,
        ('l', '1') => true,
        (c1, c2) => c1 == c2
    }
}

fn main() {
    input!{
        n: usize,
        s: Chars,
        t: Chars
    }

    let mut ans = true;
    for i in 0..n {
        if !is_same_char(&s[i], &t[i]) {
            ans = false;
            break;
        }
    }

    println!("{}", if ans {"Yes"} else {"No"});
}

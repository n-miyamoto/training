use::proconio::input;

fn main() {
    input!{
        s: String
    }

    let char_vec: Vec<char> = s.chars().collect();
    for c in char_vec {
        let t;
        if c=='0' {t='1'}
        else {t='0'}
        print!("{}", t);
    }
}

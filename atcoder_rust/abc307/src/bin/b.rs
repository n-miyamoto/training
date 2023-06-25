use proconio::input;

fn is_kaibun(s : String) -> bool {
    let n = s.len();
    for i in 0..n {
        let c0 = s.chars().nth(i);
        let c1 = s.chars().nth(n-i-1);
        if c0!=c1 {return false;}
    }

    return true;
}
fn main() {

    input!{
        n: usize,
        s: [String;n],
    }

    for i in 0..n {
        for j in 0.. n {
            if i==j {continue;}

            let sc = s[i].clone() + &s[j];
            if is_kaibun(sc) {
                println!("Yes");
                return;
            }
        }
    }

    println!("No");
    return;
}

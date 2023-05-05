use proconio::{input, marker::Chars};

fn main() {
    input!{
        h: usize,
        w: usize,
        c: [Chars; h], 
    }

    let n =  std::cmp::min(h, w);
    let mut s = vec![0; n];

    for k in 1..=n {
        for i in k..h - k {
            for j in k ..w - k {
                if c[i][j] == '#' && c[i + k][j + k] == '#' && c[i - k][j + k] == '#' && c[i - k][j + k] == '#' && c[i - k][j - k] == '#' {
                    let mut valid = true;
                    for d in 1..k {
                        if c[i + d][j + d] != '#' || c[i + d][j - d] != '#' || c[i - d][j + d] != '#' || c[i - d][j - d] != '#' {
                            valid = false;
                            break;
                        }
                    }
                    if valid {
                        s[k-1] += 1;
                    }
                }
            }
        }
    }



    let mut ans = vec![0; n];
    for i in 0..n-1 {
        ans[i] = s[i]-s[i+1];
    }

    for i in 0..n-1{
        print!("{} ", s[i]- s[i+1]);
    }
    println!("0");
}

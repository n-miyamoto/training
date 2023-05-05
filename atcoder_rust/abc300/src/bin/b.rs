use proconio::{input, marker::Chars};

fn main() {
    input!{
        h: usize,
        w: usize,
        a: [Chars; h], 
        b: [Chars; h], 
    }

    let mut flag = false;

    for s in 0..h {
        for t in 0..w {
            let mut c = vec![vec!['.'; w]; h];

            for i in 0..h {
                for j in 0..w {
                    let new_i = (i + s) % h;
                    let new_j = (j + t) % w;
                    c[new_i][new_j] = a[i][j];
                }
            }

            if c == b {
                flag = true;
                break;
            }
        }
    }

    if flag {
        println!("Yes");
    } else {
        println!("No");
    }

}

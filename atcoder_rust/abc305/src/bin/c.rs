use::proconio::input;
use::proconio::marker::Chars;



fn main() {
    input!{
        h: i32,
        w: i32,
        s: [Chars;h],
    }

    let cookie_exist = |x: i32, y: i32| -> bool {
        if x < 0 || x >= w || y < 0 || y >= h {
            false
        }else if s[y as usize][x as usize] == '.'{
            false
        }else{
            true
        }
    };

    for j in 0..h{
        for i in 0..w{
            if s[j as usize][i as usize] == '.'{
                let vb = vec![
                    cookie_exist(i  , j-1), //upper
                    cookie_exist(i+1, j  ), //right
                    cookie_exist(i  , j+1), //lower
                    cookie_exist(i-1, j  ), //left
                ];
                let count = vb.iter().filter(|&value| *value).count();
                if count > 1 {
                    println!("{} {}", j+1, i+1);
                    return;
                }
            }
        }
    }

}

use::proconio::input;
use::proconio::marker::Chars;
use std::cmp;

fn main() {
    input!{
        x: u64,
        y: u64,
        z: u64,
        s: Chars,
    }
    let n = s.len();

    let mut dp: Vec<Vec<u64>> = vec![vec![0; 2]; n];

    //initialize dp
    dp[0][0] = if s[0]=='a' {x} else {y}; //stat => a
    dp[0][1] = if s[0]=='a' {z+y} else {z+x}; //stat => A

    for i in 1..n{
        //status => a
        dp[i][0] = if s[i]=='a' {
            cmp::min(dp[i-1][0] + x, dp[i-1][1] + z + x)
        }else{
            cmp::min(dp[i-1][0] + y, dp[i-1][1] + z + y)
        };

        //status => A
        dp[i][1] = if s[i]=='a' {
            cmp::min(dp[i-1][0] + z + y, dp[i-1][1] + y)
        }else{
            cmp::min(dp[i-1][0] + z + x, dp[i-1][1] + x)
        };
    }

    println!("{}", cmp::min(dp[n-1][0], dp[n-1][1]));
}

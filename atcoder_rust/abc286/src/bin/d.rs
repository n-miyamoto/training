use::proconio::input;


fn main() {
    input!{
        n: usize, x: usize,
        v: [[usize; 2]; n],
    }
    let mut dp=vec![0; x+1];
    dp[0] = 1;

    for i in 0..n {
        for j in (0..x+1).rev(){
            if dp[j]==1 {
                for k in 0..v[i][1]+1{
                    let idx = j+k*v[i][0];
                    if idx <= x{
                        dp[idx] = 1;
                    }
                }
            }
        }
    }

    if dp[x]==1 {
        println!("Yes");
    }else {
        println!("No");
    }
}

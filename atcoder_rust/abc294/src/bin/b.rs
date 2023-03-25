use proconio::input;

fn main() {
    input!{
        h: usize,
        w: usize,
        a: [[u8; w]; h], 
    }

    for i in 0..h{
        for j in 0..w{
            if a[i][j]==0{
                print!{"."}
            }else{
                print!("{}", ('A' as u8 + a[i][j]-1) as char)
            }
        }
        println!{}
    }
}

use proconio::input;

fn main() {
    input!{
        n: usize,
        m: usize,
        a: [i32; m]
    }

    let mut v = vec![false; n+1];
    
    for i in 0..m{ v[a[i] as usize]=true;}

    let mut k=1;
    let mut first_flag = true;
    for i in 1..=n{
        if !v[i] {
            for j in (k..=i).rev(){
                if first_flag{
                    print!("{}", j);
                    first_flag=false;
                }else{
                    print!(" {}", j);
                }
            }
            k=i+1;
        }
    }
    println!();
}

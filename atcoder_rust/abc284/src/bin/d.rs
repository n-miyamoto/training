use::proconio::input;

fn main() {
    
    input!{
        t: usize,
        v: [i64; t],
    }

    for i in  0..t{
        for j in 2..3*1000000{
            let p:i64;
            let q:i64;
            if v[i]%j==0 {
                if v[i]%(j*j)==0 {
                    p=j;
                    q=v[i]/p/p;
                }else{
                    q=j;
                    p=((v[i]/q) as f64).sqrt() as i64;
                }

                println!("{} {}", p, q);
                break;
            }
        }
    }
}

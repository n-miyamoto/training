use::proconio::input;


fn main() {
    input!{
        n: usize,
        a: [u32; n],
        m: usize,
        b: [u32; m],
        x: usize,
    }

    let mut v = vec![true;x+1];

    for i in 0..m{
        v[b[i] as usize]=false;
    }

    for i in 1..x+1{
        if !v[i]{
            continue;
        }
        let mut t=false;
        for j in 0..n{
            let tmp : i32 = i as i32 - a[j] as i32;
            if tmp >= 0 {
                if v[tmp as usize] {
                    t=true;
                }
            }
        }
        v[i]=t;
    }

    if v[x] {
        println!("Yes");
    }else{
        println!("No");
    }

}

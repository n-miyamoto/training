use proconio::input;

fn main() {
    input!{
        n: usize,
        m: usize,
        a: [u32;n],
        b: [u32;m],
    }

    let mut i=0;
    let mut j=0;
    let mut av = vec![0;n];
    let mut bv = vec![0;m];
    for k in 1..=n+m {
        if j==m {
            av[i] = k;
            i+=1;
            continue;
        }
        if i==n {
            bv[j] = k;
            j+=1;
            continue;
        }
        if a[i] < b[j] {
            av[i] = k;
            i+=1;
        }else{
            bv[j] = k;
            j+=1;
        }
    }

    let ans_a: Vec<String> = av.iter().map(|x| x.to_string()).collect();
    println!{"{}", ans_a.join(" ")};

    let ans_b: Vec<String> = bv.iter().map(|x| x.to_string()).collect();
    println!{"{}", ans_b.join(" ")};
}

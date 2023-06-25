use::proconio::input;

fn main() {
    input!{
        n: usize,
        a: [u64; 7*n],
    }

    let mut sum=0;
    for i in 0..n*7 {
        sum+=a[i];
        if i%7==6 {
            print!("{}", sum);
            sum=0;

            if i!=7*n-1 {print!(" ");}
        }
    }
}


use::proconio::input;
use superslice::Ext;

fn main() {
    input!{
        n: usize,
        a: [u32; n],
        q: usize,
        lr: [[u32; 2]; q],
    }

    // calc prefix in advace
    let mut s = vec!(0 as u64; n);
    for i in 1..n {
        s[i] = if i%2==0{
            s[i-1] + (a[i] - a[i-1]) as u64
        }else{
            s[i-1]
        };
    }

    let calc_sum = |x: u32| -> u64 {
        let upper= a.upper_bound(&x)-1;
        if upper%2 == 0{
            s[upper]
        }else {
            s[upper] + (x - a[upper]) as u64
        }
    };

    for i in 0..q {
        let l = lr[i][0];
        let r = lr[i][1];
        println!("{}", calc_sum(r) - calc_sum(l));
    }

}

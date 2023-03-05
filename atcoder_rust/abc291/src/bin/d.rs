use proconio::input;
const MOD :u64= 998244353;

fn main() {
    input!{
        n: usize,
        card: [[u64; 2]; n]
    }

    let mut a_prev = 1 as u64;
    let mut b_prev = 1 as u64;


    for i in 1..n{
        let a_cur = if card[i][0]!=card[i-1][0]{a_prev}else{0} + if card[i][0]!=card[i-1][1]{b_prev}else{0};
        let b_cur = if card[i][1]!=card[i-1][0]{a_prev}else{0} + if card[i][1]!=card[i-1][1]{b_prev}else{0};

        a_prev = a_cur%MOD; 
        b_prev = b_cur%MOD;
    }

    println!("{}", (a_prev+b_prev)%MOD);
}

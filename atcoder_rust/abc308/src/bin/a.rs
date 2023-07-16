use proconio::input;

fn check_monotonic(numbers: &[usize]) -> bool {
    numbers.windows(2).all(|pair| pair[0] <= pair[1])
}

fn main() {
    input!{
        s: [usize; 8],
    }

    let ans = s.iter().all(|x| x>=&100 && x<=&675 && x%&25==0);
    println!("{}", if ans && check_monotonic(&s) {"Yes"}else{"No"});
}

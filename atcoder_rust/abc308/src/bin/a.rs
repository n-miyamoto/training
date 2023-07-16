use proconio::input;

fn check_monotonic(numbers: &[usize]) -> bool {
    for i in 1..numbers.len() {
        if numbers[i] < numbers[i - 1] {
            return false;
        }
    }
    true
}

fn main() {
    input!{
        s: [usize; 8],
    }

    let ans = s.iter().all(|x| x>=&100 && x<=&675 && x%&25==0);
    println!("{}", if ans && check_monotonic(&s) {"Yes"}else{"No"});
}

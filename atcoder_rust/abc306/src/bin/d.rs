use::proconio::input;

fn main() {
    input!{
        n: usize,
        a: [[i64;2]; n]
    }

    let mut v = vec![[0 as i64; 2]; n];

    //initialize 
    v[0][0] = if a[0][0] == 0 { std::cmp::max(0, a[0][1]) } else { 0       };
    v[0][1] = if a[0][0] == 0 { std::i64::MIN }             else { a[0][1] };

    for i in 1..n {
        v[i][0] = if a[i][0] == 0 {
            if v[i-1][1] == std::i64::MIN {
                std::cmp::max(v[i-1][0], v[i-1][0] + a[i][1])
            }else{
                std::cmp::max(std::cmp::max(v[i-1][0], v[i-1][0] + a[i][1]), v[i-1][1] + a[i][1])
            }
        }else{ v[i-1][0] };
        v[i][1] = if a[i][0] == 0 { v[i-1][1] }else{ std::cmp::max(v[i-1][0] + a[i][1], v[i-1][1]) };

        //println!("{} {}", v[i][0], v[i][1]);
    }

    println!("{}", std::cmp::max(v[n-1][0], v[n-1][1]));
}

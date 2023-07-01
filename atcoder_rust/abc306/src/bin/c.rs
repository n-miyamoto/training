use::proconio::input;

fn main() {
    input!{
        n: usize,
        a: [usize; 3*n],
    }
    let mut v = vec![0; n+1];

    let mut count = 0;
    for i in a {
        v[i]+=1;
        if v[i]==2 {
            count += 1;
            if count == n {
                print!("{}", i);
            }else{
                print!("{} ", i);
            }
        }
    }
}

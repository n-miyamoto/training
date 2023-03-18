use proconio::input;
fn main() {
    input!{
        n: usize,
        a: [i32; n],
    }

    let mut called = vec![false; n];

    for i in 0..n {
        if !called[i]{
            called[a[i] as usize - 1] = true;
        }
    }

    let mut cnt=0;
    for c in &called{
        if !c {cnt+=1};
    }
    println!{"{}", cnt};

    let mut first = true;
    for i in 0..n{
        if !called[i] && first {
            print!{"{}", i+1};
            first=false;
        }else if !called[i] {
            print!{" {}", i+1};
        }
    }
    println!{};

}

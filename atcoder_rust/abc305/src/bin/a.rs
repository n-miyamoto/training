use::proconio::input;

fn main() {
    input!{
        n: u64,
    }

    if n%5 < 3 {
        println!("{}", n/5 * 5);
    }else {
        println!("{}", (n/5 + 1)*5 );
    }
 
}
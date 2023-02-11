use::proconio::input;
use::proconio::marker::Chars;

fn main() {
    
    input!{
        s: Chars,
        t: Chars,
    }

    let n = t.len();
    let m = s.len();

    let mut mb:usize = 0;
    let mut me:usize = 0;

    for i in 0..n{
        if s[i]!=t[i] && s[i]!='?' && t[i]!='?'{
            break;
        }
        mb+=1;
    }

    for i in (0..n) {
        if s[m-i-1]!=t[n-i-1] && s[m-i-1]!='?' && t[n-i-1]!='?'{
            break;
        }
        me+=1;
    }

    //println!("{}, {}", mb, me);

    for i in 0..n+1{
        if i <= mb &&  (n-i) <= me {
            println!("Yes");
        }else{
            println!("No");
        }
    }
}


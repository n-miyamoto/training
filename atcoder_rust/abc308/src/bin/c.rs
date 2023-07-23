use::proconio::input;
use ordered_float::OrderedFloat;

struct Data {
    index: usize,
    a: usize,
    b: usize,
}

fn main() {
    input!{
        n: usize, 
        c: [[usize;2];n],
    }
    
    let mut v:Vec<Data> = Vec::new();
    for (i, x) in c.iter().enumerate() {
        let tmp = Data {
            index: i,
            a: x[0],
            b: x[1],
        };
        v.push(tmp);
    }

    v.sort_by( |x, y| {
        let tmpx = x.b*(y.a + y.b);
        let tmpy = y.b*(x.a + x.b);
        tmpx.cmp(&tmpy)
        }
    );

    for (i,x) in v.iter().enumerate() {
        print!("{}", x.index+1);
        if i!=n-1 {
            print!(" ");
        }
    }
}

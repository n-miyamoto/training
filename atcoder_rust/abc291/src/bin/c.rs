use proconio::input;
use proconio::marker::Chars;
use std::collections::HashSet;

const MAX_AXIS: i64 = 200005;

struct Point{
    x: i32,
    y: i32
}

impl Point{
    fn new() -> Point {
        Point{x:0, y:0}
    }

    fn mov(&mut self, c: char) {
        match c {
            'L' => {self.x-=1}
            'R' => {self.x+=1}
            'U' => {self.y+=1}
            'D' => {self.y-=1}
             _  => unreachable!(),
        }
    }

    fn encode(&self) -> i64 {
        self.y as i64 * MAX_AXIS+self.x as i64
    }
}

fn main() {
    input!{
        n: usize,
        c: Chars
    }

    let mut passed = HashSet::new();

    let mut p = Point::new();
    passed.insert(p.encode());

    for i in 0..n {
        p.mov(c[i]);
        let encoded_point = p.encode();
        match passed.get(&encoded_point){
            Some(_) => {
                println!("Yes");
                return;
            }
            None => {
                passed.insert(encoded_point);
            }
        }
    }

    println!("No");
}

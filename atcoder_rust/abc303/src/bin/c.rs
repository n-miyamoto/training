use::proconio::input;
use::proconio::marker::Chars;
use std::collections::HashSet;

const XY_MAX: i32 = 4 * 100_000;

fn decode_coordinate(x: i32, y:i32) -> u64 {
    let dx = (XY_MAX + x) as u64;
    let dy = (XY_MAX + y) as u64;
    
    dx * 4*XY_MAX as u64 + dy
}

fn main() {
    input!{
        _n: usize,
        m: usize,
        h: i32,
        k: i32,
        s: Chars,
        x: [[i32;2]; m]
    }

    
    let mut hashset: HashSet<u64> = x.into_iter().map(|x| decode_coordinate(x[0], x[1])).collect();


    let mut hp = h;
    let mut cur_x = 0;
    let mut cur_y = 0;

    for c in s {

        //print!("{} {} => ", cur_x, cur_y);

        match c {
            'R' => {cur_x+=1},
            'L' => {cur_x-=1},
            'U' => {cur_y+=1},
            'D' => {cur_y-=1},
            _   => {panic!("unexpected character")}
        }
        hp -= 1;

        if hp < 0 {
            println!("{}", "No");
            return;
        }

        //print!("{} {}, ", cur_x, cur_y);
        //print!("{} => ", hp);

        if hp < k {
            let cd = decode_coordinate(cur_x, cur_y);
            if hashset.contains(&cd){
                hp = k;
                hashset.remove(&cd);
            }
        }

        //println!("{}", hp);


    }

    println!("{}", "Yes");
}

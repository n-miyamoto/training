use proconio::input;

fn main() {
    input! {
        n: usize,
        q: usize,
        events: [[usize; 2]; q],
    }

    let mut vy = vec![0; n + 1];
    let mut vr = vec![0; n + 1];

    for event in events {
        match event[0] {
            1 => {
                vy[event[1]] += 1;
            }
            2 => {
                vr[event[1]] += 1;
            }
            3 => {
                if vy[event[1]] > 1 {
                    println! {"Yes"}
                } else if vr[event[1]] > 0 {
                    println! {"Yes"}
                } else {
                    println! {"No"}
                }
            }
            _ => {}
        }
    }
}

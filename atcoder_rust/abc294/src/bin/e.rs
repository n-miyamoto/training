use proconio::input;

fn count_intersect (s1: i64, e1: i64, s2: i64, e2: i64) -> usize{
    let s = s1.max(s2);
    let e = e1.min(e2);
    return (e-s).max(0) as usize;
}

fn main() {
    input!{
        _l: usize,
        n1: usize,
        n2: usize,
        s1: [(i64, i64);n1],
        s2: [(i64, i64);n2],
    }

    let mut start1 = vec![0;n1];
    let mut end1   = vec![0;n1];
    let mut start2 = vec![0;n2];
    let mut end2   = vec![0;n2];

    let mut sum1=0;
    for i in 0..n1 {
        start1[i] = sum1;   
        end1[i] = sum1+s1[i].1;   
        sum1 = end1[i];
    }

    let mut sum2=0;
    for i in 0..n2 {
        start2[i] = sum2;   
        end2[i] = sum2+s2[i].1;   
        sum2 = end2[i];
    }

    let mut i2 = 0;
    let mut ans = 0;
    for i1 in 0..n1 {
        while end1[i1] > start2[i2] {
            if s1[i1].0 == s2[i2].0 {
                ans += count_intersect(start1[i1], end1[i1], start2[i2] , end2[i2]);
            }
            
            i2+=1;
            if i2==n2 {break;}
        }
        i2-=1;
    }
    println!{"{}", ans};
}




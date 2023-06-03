use::proconio::input;

fn main() {
    input!{
        n: usize,
        m: usize,
        a: [[usize; n]; m],
    }

    let mut matrix: Vec<Vec<bool>> = vec![vec![false; n]; n];

    for i in 0..n {
        matrix[i][i] = true;
    }

    for i in 0..m{
        for j in 1..n{
            matrix[a[i][j]-1][a[i][j-1]-1] = true;
            matrix[a[i][j-1]-1][a[i][j]-1] = true;
        }
    }

    let count = matrix.iter()
        .flatten()
        .filter(|&value| !*value)
        .count();

    println!("{}", count/2);
}


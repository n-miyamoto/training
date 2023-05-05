use proconio::input;
fn main() {
    input!{
        n: usize,
    }

    // Generate primes less than or equal to sqrt(n)
    let sqrt_n = (n as f64).sqrt() as usize;
    let primes = sieve(sqrt_n);
    let pn = primes.len();
    
    let mut ans = 0;
    for ci in (2..pn).rev() {
        let c = primes[ci];
        for ai in 0..ci-1 {
            let a = primes[ai];
            if c*c*a*a*a>n {
                break;
            } 
            for bi in ai+1..ci {
                let b = primes[bi];
                if c*c*a*a*b>n {
                    break;
                }else{
                    ans+=1;
                }
            }
        }
    }
    println!("{}", ans);

}

// Generate primes less than or equal to n using the sieve of eratosthenes algorithm
fn sieve(n: usize) -> Vec<usize> {
    let mut primes = vec![true; n+1];
    primes[0] = false;
    primes[1] = false;
    let mut p = 2;
    while p * p <= n {
        if primes[p] {
            let mut i = p * p;
            while i <= n {
                primes[i] = false;
                i += p;
            }
        }
        p += 1;
    }
    primes.iter().enumerate().filter(|(_, &is_prime)| is_prime).map(|(i, _)| i).collect()
}
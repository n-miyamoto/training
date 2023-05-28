use proconio::{input, marker::Chars};

const MAX_BITS : usize = 62;

fn get_bit(n: u64, i: usize) -> u64 {
    (n >> i) & 1
}

fn convert_binary_vec_char2int (vc: &Vec<char>) -> u64 {
    let mut ret = 0 as u64;
    let mut k = 1 as u64;
    for i in 0..MAX_BITS{
        if vc[i]=='1' {
            ret+= k;
        }

        k*=2;
    }
    ret
}

fn fix_and_finish(v: &Vec<char>, vc: &mut Vec<char>, i: usize) {
    for j in (0..i).rev(){
        if v[j] == '?' {
            vc[j] = '1';
        }
    }
}

fn main() {
    input!{
        s: Chars,
        n: u64,
    }

    let mut v  = vec!['0';MAX_BITS];
    let mut vc = vec!['0';MAX_BITS];
    for i in 0..s.len() {
        v[i] = s[s.len()-i-1];
        vc[i] = s[s.len()-i-1];
    }

    let mut last_set: Option<usize> = None;

    for i in (0..MAX_BITS).rev() {
        let si = vc[i];
        let ni = get_bit(n, i); 

        match (si, ni) {
            ('0', 1) => {
                fix_and_finish(&v, &mut vc, i);
                break;
            },
            ('1', 0) => { 
                match last_set {
                    None => {
                        println!("{}", -1);
                        return ;
                    },
                    Some(index) => {
                        vc[index] = '0';
                        fix_and_finish(&v, &mut vc, index);
                        break;   
                    },
                }
            },
            ('?', 0) => {
                vc[i] = '0'
            },
            ('?', 1) => {
                vc[i] = '1';
                last_set = Some(i);
            },
            ('0', 0) => {}, // Do nothing
            ('1', 1) => {}, // Do nothing
            (_, _) => {panic!("unexpected char")},
        }
    }

    println!("{}", convert_binary_vec_char2int(&vc));
}

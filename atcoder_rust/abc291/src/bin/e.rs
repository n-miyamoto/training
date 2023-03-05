use proconio::input;

fn main() {
    input!{
        n: usize,
        m: usize,
        x: [[u32;2]; m],
    }

    let mut v_to = vec![vec![0 as u32; 0]; n];
    let mut deg = vec![0 as u32; n];
    let mut first = vec![1 as u32; n];
    
    //create graph find first
    for i in x.iter(){
        let from = i[0]-1;
        let to   = i[1]-1;
        v_to[from as usize].push(to); 
        first[to as usize] = 0;
        deg[to as usize]+=1;
    }
    
    //find first node
    let fs:u32 = first.iter().sum(); 
    if fs!=1{println!{"No"};return;}
    let first_idx = first.iter().position(|&x| x==1).unwrap();

    let mut a = vec![0 as u32; n];
    let mut prev = first_idx;
    for i in 0..n{
        a[prev] = i as u32;
        if i==n-1 {break;} //last no need to search next

        //search next node
        let mut next_node = 0;
        for x in v_to[prev].iter(){
            deg[x.clone() as usize]-=1;
            if deg[x.clone() as usize]==0 {
                prev = x.clone() as usize;
                next_node+=1;
            }
        }

        if next_node!=1 {
            println!{"No"};
            return;
        }
    }

    println!{"Yes"};
    for i in 0..n{
        if i!=0 {print!{" "}};
        print!{"{}", a[i]+1};
    }
    println!{};
}

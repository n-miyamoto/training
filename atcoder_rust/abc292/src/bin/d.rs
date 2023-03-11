use proconio::input;
use std::collections::BTreeMap;
use std::collections::BinaryHeap;


fn main() {
    input!{
        n: usize,
        m: usize,
        edges: [[usize; 2]; m],
    }

    let mut g=vec![BTreeMap::new(); n+1];
    
    for edge in edges{
        let from = edge[0];
        let to   = edge[1];

        g[from].entry(to).and_modify(|x| *x +=1).or_insert(1);
        g[to].entry(from).and_modify(|x| *x +=1).or_insert(1);
    }

    //show graph
    //for i in 0..n+1{
    //    for (to, num) in &g[i]{
    //        println!{ "{} {} {}", i, to, num };
    //    }
    //}
    
    let mut used=vec![false; n+1];
    
    let mut ans = true;
    for i in 1..=n{

        let mut heap = BinaryHeap::new();
        if !used[i] {
            heap.push(i);
            used[i] = true;
        }else{
            continue;
        }

        let mut nodes = 1;
        let mut e = 0;
        while heap.len() > 0{
            let node = heap.pop().unwrap();

            let mut v=vec![0;0];
            for (to, _) in &g[node] {
               v.push(to.clone());
            }

            for x in &v{
                if !used[x.clone()] {
                    heap.push(x.clone());
                    nodes+=1;
                    used[x.clone()] = true;
                    //print!{"{} ", x};
                }
            }

            for x in v{
                if x==node {
                    e += g[x][&x]/2;
                }else{
                    e += g[node][&x];
                }

                g[x].remove(&node);
                g[node].remove(&x);
            }
        }
        //println!{};
        //println!{"n:{} e:{}", nodes, e};

        if nodes!=e {ans=false;}
    }
    
    if ans {
        println!{"Yes"};
    }else{
        println!{"No"};
    }
}
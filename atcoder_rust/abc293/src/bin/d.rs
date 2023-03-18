use proconio::input;
use proconio::derive_readable;

struct UnionFind {
    par: Vec<usize>,
    siz: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        UnionFind {
            par: (0..n).collect(),
            siz: vec![1; n],
        }
    }

    fn root(&mut self, x: usize) -> usize {
        if self.par[x] == x {
            return x;
        }
        self.par[x] = self.root(self.par[x]);
        self.par[x]
    }

    fn unite(&mut self, mut parent: usize, mut child: usize) -> bool {
        parent = self.root(parent);
        child = self.root(child);

        if parent == child {
            return false;
        }

        if self.siz[parent] < self.siz[child] {
            std::mem::swap(&mut parent, &mut child);
        }

        self.par[child] = parent;
        self.siz[parent] += self.siz[child];
        true
    }

}

#[derive_readable]
#[derive(Debug)]
struct Edge{
    from: usize,
    from_color: char,
    to: usize,
    to_color: char,
}

fn main() {
    input!{
        n: usize,
        m: usize,
        edges: [Edge; m],
    }

    let mut uft = UnionFind::new(n+1);
    let mut v=vec![0; n+1];

    for e in edges {
        //println!{"{} {} {} {} ", e.to, e.from, e.to_color, e.from_color};
        v[e.to]+=1;
        v[e.from]+=1;

        uft.unite(e.to, e.from);
    }

    let mut root=vec![0; n+1];
    let mut circle=vec![true; n+1];

    for i in 1..=n{
        //println!("{} {} {}",i, uft.root(i), uft.size(i));
        root[uft.root(i)]+=1;
        if v[i]<2 { 
            circle[uft.root(i)]=false;
        }
    }

    let mut x=0;
    let mut y=0;
    for i in 1..=n{
        if root[i]!=0 {
            if circle[i]{
                x+=1;
            }else{
                y+=1;
            }
        }
    }

    println!("{} {}", x, y);

}

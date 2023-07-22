use std::io::stdin;
use std::cmp;

pub struct DSU {
    pub parent: Vec<usize>,
    pub rank: Vec<usize>,
    pub size: Vec<usize>,
}

impl DSU {
    pub fn new(items: &usize) -> Self {
        let mut d = DSU{
            parent: vec![0; *items],
            rank: vec![0; *items], 
            size: vec![1; *items],
        };

        for i in 0..*items {
            d.parent[i] = i;
        }

        return d;
    }

    pub fn find(&mut self, item: usize) -> usize {
        if self.parent[item] == item {
            return item;
        }
        self.parent[item] = self.find(self.parent[item]);
        return self.parent[item];
    }

    pub fn unite(&mut self, x: usize, y: usize) {
        let p_x = self.find(x);
        let p_y = self.find(y);

        if p_x == p_y {
            return;
        }

        if self.rank[p_x] < self.rank[p_y] {
            self.parent[p_x] = p_y;
            self.size[p_y] += self.size[p_x];
        } else {
            self.parent[p_y] = p_x;    
            self.size[p_x] += self.size[p_y];
            if self.rank[p_x] == self.rank[p_y] {
                self.rank[p_x] += 1;
            }
        }
    }
    pub fn same(&mut self, x: usize, y: usize) -> bool {
        return self.find(x) == self.find(y);
    }
}

fn main() {
    let mut t = String::new();
    stdin().read_line(&mut t).expect("n");
    t = t.trim().into();

    let mut test = t.parse::<usize>().unwrap();

    while test > 0 {
        test -= 1;
        
        let mut n_k = String::new();
        stdin().read_line(&mut n_k).expect("n_k");

        let n_k_vec = n_k.trim()
            .split(" ")
            .collect::<Vec<_>>()
            .iter()
            .map(|val| val.parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let n = n_k_vec[0];
        let k = n_k_vec[1];

        let mut items = String::new();
        stdin().read_line(&mut items).expect("items");

        let mut items_vec = items.trim()
            .split(" ")
            .collect::<Vec<_>>()
            .iter()
            .map(|val| val.parse::<usize>().unwrap())
            .collect::<Vec<_>>();

        let mut d = DSU::new(&n);
        items_vec.sort();

        for i in 1..n {
            if items_vec[i] - items_vec[i - 1] <= k {
                d.unite(i.clone() - 1, i.clone() );
            }
        }

        let mut ans = 0;

        for i in 0..n {
            ans = cmp::max(ans, d.size[i.clone()]);
        }

        println!("{}", n - ans);

    }

}

#define INF (1000000006)

void uf_init(int n);
int find(int x);
void unite(int x, int y);
bool same(int x, int y);
void show_alld(void);
void show_allp(void);
int show_parent(int i);
int show_depth(int i);

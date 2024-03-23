#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int h, w;

void show(vector<std::vector<int>> &m){
	for(auto& v: m){
		for(auto& x: v){
			cout << x <<"\t";
		}
		cout << endl;
	}
}


vector<std::vector<int>> create_mat(vector<std::vector<int>> a, vector<int> row, vector<int> col){
	vector<std::vector<int>> t1(h, std::vector<int>(w, 0));
	for(int i=0;i<row.size(); i++){
		t1[i] = a[row[i]];
	}

	vector<std::vector<int>> t2(h, std::vector<int>(w, 0));
	//t2 = t1;
	for(int i=0;i<col.size(); i++){
		for(int j=0;j<h;j++){
			t2[j][i] = t1[j][col[i]];
		}
	}

	return t2;
}

bool compare_mat(const vector<std::vector<int>> &m1, const vector<std::vector<int>> &m2){
	bool ret = true;
	for(int i=0;i<h; i++){
		for(int j=0;j<w;j++){
			if(m1[i][j] != m2[i][j]) ret = false;
		}
	}
	return ret;
}

int count_swap(const vector<int> &v){
	vector<int> t = v;
	int swap_count = 0;
	for(int i=0;i<t.size();i++){
		while(t[i]!=i){
			//find and swap 
			const auto ite = std::find(t.begin(), t.end(), i);
			const auto prev = ite-1;
			*ite = *prev;
			*prev = i;
			swap_count++;
		}
	}

	return swap_count;
}

int main(void){
	cin >> h >> w;

	vector<std::vector<int>> a(h, std::vector<int>(w, 0));
	vector<std::vector<int>> b(h, std::vector<int>(w, 0));

	for(auto& v: a) for(auto& x: v) cin >> x;
	for(auto& v: b) for(auto& x: v) cin >> x;

	//show(a);
	//show(b);

	vector<int> v_row(h); 
	for(int i; i<h;i++) v_row[i] = i;
	vector<int> v_col(w); 
	for(int i; i<w;i++) v_col[i] = i;


	int ans = -1;
	do{
		do{
			auto m = create_mat(a, v_row, v_col);
			//show(m);
			//cout << "-----\n";
			if(compare_mat(b, m)){
				//cout << "-----\n";
				//for(const auto x : v_col) cout << x << " " ;
				//cout << "-----\n";
				//for(const auto x : v_row) cout << x << " " ;
				//cout << "-----\n";
				//cout << count_swap(v_row) <<  " " << count_swap(v_col) << endl;


				auto tmp = count_swap(v_row) + count_swap(v_col);
				if(ans<0) ans = tmp;
				else ans = min(ans, tmp);
			}
		} while (std::next_permutation(v_row.begin(), v_row.end()));
	} while (std::next_permutation(v_col.begin(), v_col.end()));

	cout << ans << endl;

	return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

#define INF INT_MAX
#define MAX_KEY 1005
#define MAX_STATE (1<<12)
int n,m;
int states[MAX_KEY];
int costs[MAX_KEY];

int total_costs[MAX_KEY][MAX_STATE];

int main(void){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int num;
		cin >> costs[i] >> num;
		for(int j=0;j<num;j++){
			int box;
			cin >> box;
			states[i] |= 1<<(box-1);
		}
		//cout << costs[i] << " " <<  states[i] << endl;
	}

	//initialize 
	for(int j=0;j<(1<<n);j++)total_costs[0][j] = INF;
	total_costs[0][0] = 0; //never chose 0
	total_costs[0][states[0]] = costs[0]; //chose 0

	for(int i=1;i<m;i++){
		// never chose i th key
		for(int j=0;j< 1<<n;j++){
			total_costs[i][j] = total_costs[i-1][j];
			//cout << total_costs[i][j] << " ";
		} 
		cout << endl;

		// user i th key
		for(int j=0;j< 1<<n;j++){
			int state = states[i]|j;
			if(total_costs[i-1][j] != INF){
				total_costs[i][state] = min(total_costs[i][state], total_costs[i-1][j]+costs[i]);
			} 
		} 
	}

	if(total_costs[m-1][ (1<<n) -1] == INF) cout << -1 << endl; 
	else cout << total_costs[m-1][(1<<n)-1] << endl;
	return 0;
}

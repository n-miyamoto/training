#include <bits/stdc++.h>

using namespace std;
#define BUF (205)
#define ll long long 
#define INF (100000000005)

ll n;
vector<ll> x,y,p;

struct edge{
	ll to;
	ll s_needed;
};
ll S[BUF];

vector<edge> edges[BUF];

int main(void){
	cin >> n;
	for(ll i=0; i<n;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		x.push_back(a);
		y.push_back(b);
		p.push_back(c);
	}

	// create graph
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			edge e;
			e.to = j;
			ll dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			e.s_needed = (dist+p[i]-1)/p[i];		//TODO 
			edges[i].push_back(e);
		}
	}

	using P = pair<ll,ll>;

	//try all start point. calc max S
	ll ans = -1;
	for(ll s=0;s<n;s++){
		//init
		for(ll i=0;i<n;i++){
			S[i] = INF;
		}

		priority_queue<P,vector<P>,greater<P>> que;
        S[s] = 0;
        que.push({S[s],s});

        while(!que.empty())
        {
            ll v = que.top().second;
            ll d = que.top().first;
            que.pop();

            if(S[v] < d) continue;

            for(auto& e : edges[v])
            {
                if(S[e.to] > max(d, e.s_needed))
                {
                    S[e.to] = max(d, e.s_needed);
                    que.push({S[e.to],e.to});
                }
            }
        }

		ll mx=0;
		//cout << s << ":";
		for(ll i=0;i<n;i++){
			//cout << S[i] << " ";
			mx = max(mx, S[i]);
		}
		//cout << mx << endl;
		if(ans<0 || mx<ans){
			ans = mx;
		}
	}

	cout << ans << endl;

	return 0;
}

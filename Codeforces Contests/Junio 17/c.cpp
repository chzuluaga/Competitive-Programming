#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100006;

vector< pll > graph[MAX];
ll total[MAX], cost[MAX], res = 0;

int counter(int idx, int p){
		int cont = 1;
		
		for(int i = 0; i < graph[idx].size(); i ++){
			int nei = graph[idx][i].first;
			if(nei != p)
				cont += counter(nei, idx);
		}
		
		return total[idx] = cont;
}

ll solve(int idx, int p, ll val){
		
		//cout << idx << " " << p << " " << val << endl;
		ll ans = 0;
		
		for(int i = 0; i < graph[idx].size(); i ++){
				int nei = graph[idx][i].first;
				ll c = graph[idx][i].second;
				if(nei != p){
					if( max(val + c, c) > cost[nei]){
						ans += total[nei];
					}else{
						ans += solve(nei, idx, max(val + c, c));
					}
				}
		}
		
		return ans;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 // freopen("c.in", "r",stdin);
  int n;
  ll u, d;
  cin >> n;
  
  for(int i = 0; i < n; i ++)
		cin >> cost[i];
		
	for(int i = 0; i < n - 1; i ++){
		cin >> u >> d;
		u --;
		graph[i + 1].pb(mp(u,d));
		graph[u].pb(mp(i + 1, d));
	}
	
	counter(0, 0);
	cout << solve(0, 0, 0) << endl;
	
	

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
vector<int> graph[MAX];
bool visit[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m, k, u, v, c;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i ++){
		scanf("%d%d%d", &u, &v, &c); 
		graph[u].pb(v);
		graph[u].pb(c);
		graph[v].pb(u);
		graph[v].pb(c);
	}
	vector<int> store;
	for(int i = 0; i < k; i ++){
		scanf("%d", &u);
		store.pb(u);
		visit[u] = true;
	}
	int ans = INT_MAX;
	for(int i = 0; i < (int)store.size(); i ++){
		int cur = store[i];
		for(int j = 0; j < (int)graph[cur].size(); j += 2){
			int nei = graph[cur][j];
			int cost = graph[cur][j + 1];
			if(!visit[nei])
				ans = min(ans, cost);
		}
	}
	
	if(ans < INT_MAX)
		printf("%d\n", ans);
	else
		printf("-1\n");
	
	
	

  return 0;
}

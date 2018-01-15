#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1005;
int parent[MAX], w[MAX];
int find(int x){
	if(x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("disjointWater.in", "r", stdin);
  int n, m, u, v;
  while(~scanf("%d%d", &n, &m)){
		memset(parent, 0, sizeof(parent));
		memset(w, 0, sizeof(w));
		vector<int> graph[MAX];
		for(int i = 0; i < m; i ++){
			scanf("%d%d", &u, &v);
			if(u != 1)
				graph[v].pb(u);
			else
				parent[v] = v;
			
		}
		
		for(int i = 2; i <= n; i ++){
			for(int j = 0; j < (int) graph[i].size(); j ++){
				int nei = graph[i][j];
				if(parent[i] == 0)
					parent[i] = nei;
				else
					if(find(i) != find(nei))
						parent[i] = i;
			}
		}
		
		for(int i = 2; i <= n; i ++){
			w[find(i)] ++;
		}
		int ans = 0;
		for(int i = 2; i <= n; i ++){
			if(parent[i] == i){
				ans += w[i] * (n - 1 - w[i]);
			}
		}
		
		printf("%d\n", ans/2 + n - 1);
		
	}
  

  return 0;
}

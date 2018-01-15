#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 10005;
vector<int> g[MAX];
int low[MAX], num[MAX], dfs_parent[MAX], dfsCnt, rootChildren, dfsRoot;
vector<int> ans;
void articulationPointAndBridge(int u){
	low[u] = num[u] = dfsCnt++;
	for(int j = 0; j < (int) g[u].size(); j += 2){
		int v = g[u][j];
		if(num[v] == -1){
			dfs_parent[v] = g[u][j + 1];
			if(u == dfsRoot) rootChildren ++;	//special case if u is a root
			
			articulationPointAndBridge(v);
			if(low[v] >= num[u])
				articulationPoint.pb(u);
			
			if(low[v] > num[u]){
				printf("Edge %d - %d is a bridge\n", u + 1, v + 1);
				ans.pb(g[u][j + 1]);
			}
			low[u] = min(low[u], low[v]);
		}else if(g[u][j + 1] != dfs_parent[u])
			low[u] = min(low[u], num[v]);
	}
}
void init(int n){
	dfsCnt = 0;
	ans.clear();
	for(int i = 0; i <= n; i ++){
		g[i].clear();
		num[i] = -1;
		low[i] = 0;
		dfs_parent[i] = 0;
	}
}
int main(){
  int t, n, m, u, v;
  scanf("%d", &t);
  
  while(t --){
		scanf("%d%d", &n, &m);
		map<int, int> idx;
		int cnt = 0;
		init(n);
		for(int i = 0; i < m; i ++){
			scanf("%d%d", &u, &v);
			u --, v --;
			if(!idx.count(u))
				idx[u] = cnt ++;
			u = idx[u];
			if(!idx.count(v))
				idx[v] = cnt ++;
			v = idx[v];
			
			g[u].pb(v);
			g[u].pb(i + 1);
			g[v].pb(u);
			g[v].pb(i + 1);
		}
		
		for(int i = 0; i < n; i ++){
			if(num[i] == -1){
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				if(rootChildren > 1) // special case
					articulationPoint.pb(i);
			}
		}
		printf("%d\n", (int)ans.size());
		sort(ans.begin(), ans.end());
		if((int)ans.size()){
			for(int i = 0; i < (int)ans.size(); i ++){
				if(i)	printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
		if(t)
			printf("\n");
	}

  return 0;
}

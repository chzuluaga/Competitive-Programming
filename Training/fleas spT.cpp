#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 5006;
int dis[MAX], lvl[MAX];
int sp[50][MAX];
vector<int> graph[MAX];

void dfs(int cur, int p, int l, int d){
	dis[cur] = d;
	lvl[cur] = l;
	sp[0][cur] = p;
	for(int i = 0; i < (int)graph[cur].size(); i ++){
		int nei = graph[cur][i];
		
		if(nei == p)	continue;
		
		dfs(nei, cur, l + 1, d + 1);
	}
}

int lca(int u, int v){
	if(lvl[u] < lvl[v])
		swap(u, v);
		
	int d = lvl[u] - lvl[v];
	
	for(int i = 0; i < 15; i ++)
		if((1<<i) & d)
			u = sp[i][u];
	if(u == v)
		return u;
		
	int lo = 0, hi = MAX, mit, newu = u, newv = v;
	while(lo < hi){
		mit = lo + hi + 1;
		mit /= 2;
		newu = u;
		newv = v;
		for(int i = 0; i < 15; i ++){
			if(mit & (1<<i)){
				newu = sp[i][newu];
				newv = sp[i][newv];
			}
		}
		if(newu == newv)
			hi = mit - 1;
		else
			lo = mit;
	}
	lo ++;
	for(int i = 0; i < 15; i ++){
		if(lo & (1<<i)){
			u = sp[i][u];
		}
	}
	return u;	
}

int main(){

	int n;
	while(~scanf("%d", &n) && n){
		for(int i = 0;i < n; i++)
			graph[i].clear();
		for(int i = 0; i < n - 1; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			u --, v --;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		dfs(0, 0, 0, 0);
		
		for(int h = 1; h < 15; h ++)
			for(int i = 0; i < n; i ++)
				sp[h][i] = sp[h - 1][sp[h - 1][i]];
		int m;
		scanf("%d", &m);
		while(m --){
			int u, v;
			scanf("%d%d", &u, &v);
			u --, v --;
			
			int idx = lca(u, v);
			
			int d = dis[u] + dis[v] - (2 * dis[idx]);
			
			if(lvl[u] < lvl[v])
				swap(u, v);
			
			if(d & 1){
				d /= 2;
				for(int i = 0; i < 15; i ++)
					if(d & (1<<i))
						u = sp[i][u];
				
				printf("The fleas jump forever between %d and %d.\n",min(u + 1, sp[0][u] + 1), max(u + 1, sp[0][u] + 1));
			}else{
				d /= 2;
				
				for(int i = 0; i < 15; i ++)
					if(d & (1<<i))
						u = sp[i][u];
						
				printf("The fleas meet at %d.\n", u + 1);
			}
		}
		
	}
	
	
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 400005;
int low[MAX], num[MAX], parent[MAX], comp[MAX], p[MAX], rnk[MAX]; 
int big = 1, idx = 1, dfsCounter = 0;
vector<int> graph[MAX];

int find(int x){
	if(x == p[x])
		return x;
	
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	
	if(rnk[x] > rnk[y]){
		p[y] = x;
		comp[x] += comp[y];
		if(comp[x] > big){
			big = comp[x];
			idx = x;
		}
	}else{
		p[x] = y;
		comp[y] += comp[x];
		if(comp[y] > big){
			big = comp[y];
			idx = y;
		}
		if(rnk[x] == rnk[y])
			rnk[y] ++;
	}
}

void bridge(int u){
	low[u] = num[u] = dfsCounter ++;
	for(int i = 0; i < (int)graph[u].size(); i += 2){
		int v = graph[u][i];
		if(num[v] == -1){
				parent[v] = u;
				
				bridge(v);
				
				if(low[v] > num[u]){
					//cout << u + 1 << " " << v + 1 << " es un puente" << endl;
				}else{
					//cout << "mezclando " << u + 1 << " " << v + 1 << endl;
					merge(v, u);
				}
				low[u] = min(low[u], low[v]);
		}
		else if (v != parent[u])
			low[u] = min(low[u], num[v]);
	}
}
pair<int,int> ans[MAX];
int visit[MAX];
void solve(int u){
	//cout << " u es " << u + 1 << endl;
	visit[u] = true;
	for(int i = 0; i < (int) graph[u].size(); i += 2){
		int v = graph[u][i];
		int pos = graph[u][i + 1];
		int x = find(u), y = find(v);
		if(ans[pos].first == 0 && ans[pos].second == 0){
			if(x == y){
				ans[pos] = mp(u + 1, v + 1);
			}else{
				ans[pos] = mp(v + 1, u + 1);
			}
		}
		if(!visit[v]){
			solve(v);
		}
	}
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	int n, m, u, v;
	//freopen("tourism.in", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(num, -1, sizeof(num));
	
	for(int i = 0; i < n; i ++)
		p[i] = i, rnk[i] = 0, comp[i] = 1;
	
	for(int i = 0; i < m; i ++){
		scanf("%d%d", &u, &v);
		u --, v --;
		graph[u].pb(v);
		graph[u].pb(i);
		graph[v].pb(u);
		graph[v].pb(i);
	}
	
	bridge(0);
	
	solve(idx);
	
	/*for(int i = 0; i < n; i ++)
		cout << find(i) << " " ;
		
	cout << endl;
	*/
	printf("%d\n", big);
	for(int i = 0; i < m; i ++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	
  return 0;
}

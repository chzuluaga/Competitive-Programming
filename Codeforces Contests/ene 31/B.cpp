#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 3005;
vector<int> g[MAX];
int visit[MAX], d[MAX][MAX];
priority_queue < pii > dis[MAX], dis2[MAX];
vector < pii > disV[MAX], dis2V[MAX];
vector < pii >:: reverse_iterator it1, it2;
void getDis(int cur){
	queue<int> q;
	visit[cur] = cur;
	q.push(cur);
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int c = q.front();
		q.pop();
		
		for(int i = 0; i < (int)g[u].size(); i ++){
			int v = g[u][i];
			if(visit[v] != cur){
				d[cur][v] = c + 1;
				dis[v].push(mp(-(c + 1), cur));
				dis2[cur].push(mp(-(c + 1), v));
				while(dis[v].size() > 4)
					dis[v].pop();
				while(dis2[cur].size() > 4)
					dis2[cur].pop();
				q.push(v);
				q.push(c + 1);
				visit[v] = cur;
			}
		}
	}
}
int main(){
	int n, m, u, v, a, b, c, D, ans = 0;
	//freopen("b.in", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(visit, -1, sizeof(visit));
	memset(d, -1, sizeof(d));
	for(int i = 0; i < m; i ++){
		scanf("%d%d", &u, &v);
		u --, v --;
		g[u].pb(v);
	}
	
	for(int i = 0; i < n; i ++)
		getDis(i);
	
	for(int i = 0; i < n; i ++){
		while(!dis[i].empty()){
			disV[i].pb(dis[i].top());
			dis[i].pop();
		}
		while(!dis2[i].empty()){
			dis2V[i].pb(dis2[i].top());
			dis2[i].pop();
		}
	}
	/*
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++)
			cout << d[i][j] << " ";
		cout << endl;
	}*/
		
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j)	continue;
			u = i, v = j;
			if(d[u][v] == -1)
				continue;
			int ii , jj;
			for(it1 = disV[u].rbegin(), ii = 0; it1 != disV[u].rend() && ii < 3; it1 ++, ii ++){
				int x = (*it1).second;
				int costA = -(*it1).first;
				for(it2 = dis2V[v].rbegin(), jj = 0; it2 != dis2V[v].rend() && jj < 3; it2 ++, jj ++){
					int y = (*it2).second;
					int costB = -(*it2).first;
					if(x != v && x != y && y != u){
						int sum = costA + costB + d[u][v];
						if(sum > ans){
							ans = sum;
							a = x, b = u, c = v, D = y;
						}
					}
				}
			} 
		}
	}
	//cout << ans << endl;
	printf("%d %d %d %d\n", a + 1, b + 1, c + 1, D + 1);
	
	

  return 0;
}

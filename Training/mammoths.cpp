#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <limits>  
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 255;
const int MAXN1 = 255;
const int MAXN2 = 255;
const int MAXM = 90000;
const int inf = 100000000;
pii a[MAX], b[MAX];
int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
vector<int> g[MAX];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

bool getTime(int x, int y, int d, int t){
	/*ll shipX = a[x].first + a[x].second;
	ll shipY = b[y].first + b[y].second;
	shipX -= d * b[y].second;
	if(shipX >= shipY && a[x].second <= b[y].second)
		return d <= t;*/
	return a[x].first + (t - d)*a[x].second >= b[y].first + t * b[y].second;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int d;
  
  while(~scanf("%d%d", &n1, &n2)){
		if(!n1 && !n2)	break;
		
		for(int i = 0; i < n1; i ++){
			scanf("%d%d", &a[i].first, &a[i].second);
			g[i].clear();
		}
		for(int i = 0; i < n2; i ++){
			scanf("%d%d", &b[i].first, &b[i].second);
		}
		
		init(n1, n2);
		
		for(int i = 0; i < n1; i ++){
			for(int j = 0; j < n2; j ++){
				scanf("%d", &d);
				bool t = getTime(i, j, d, inf);
				if(t){
					g[i].pb(j);
					g[i].pb(d);
					addEdge(i, j);
				}
			}
		}
		int res = maxMatching();
		
		if(res != n2){
			printf("IMPOSSIBLE\n");
			continue;
		}
		int lo = 0, hi = inf;
		while(lo < hi){
			init(n1, n2);	
			int mit = lo + hi;
			mit /= 2;
			for(int i = 0; i < n1; i ++){
				for(int j = 0; j < (int)g[i].size(); j += 2){
					int nei = g[i][j];
					int d = g[i][j + 1];
					bool t = getTime(i, nei, d, mit);
					if(t){
						addEdge(i, nei);
					}
				}
			}		
			res = maxMatching();
			if(res == n2){
				hi = mit;
			}else{
				lo = mit + 1;
			}
		}
		printf("%d\n", lo);
	}
  
  return 0;
}

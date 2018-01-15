#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 5005;
vector< ll > graph[MAX];
int path[MAX][MAX];

struct node{
	int idx, cont, p;
	ll cost;
	
	node(){}
	node(int _idx, int _cont, ll _cost, int _p){
		idx = _idx;
		cont = _cont;
		cost = _cost;
		p = _p;
	}
	bool operator <(node other)const{
		if(cont == other.cont)
			return cost > other.cost;
			
		return cont < other.cont;
	}
};

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("c.in", "r", stdin);
  
  int n, m, u, v;
  ll t, c;
  
  scanf("%d%d" LL, &n, &m, &t);
  
  for(int i = 0;i < m ; i ++){
		scanf("%d%d" LL,&u, &v, &c); 
		u --, v --;
		graph[u].pb(v);
		graph[u].pb(c);
	}
	
	priority_queue< node > q;
	q.push(node(0, 1, 0, -1));
	int ans = 0;
	while(!q.empty()){
		int cur = q.top().idx;
		int cont = q.top().cont;
		ll cost = q.top().cost;
		int p = q.top().p;
		q.pop();
		
	//	cout << cur << " " << cont << " " << cost << endl;
				
		path[cur][cont] = p;
		
		if(cur == n - 1 && cont > ans){
			ans = cont;
			continue;
		}
		
		for(int i = 0; i <(int) graph[cur].size(); i += 2){
			int nei = (int)graph[cur][i];
			ll w = graph[cur][i + 1];
			
			if(cost + w <= t){
				q.push(node(nei, cont + 1, cost + w, cur));
			}
		}
	}
	vector<int> V;
	int cur = n - 1;
	while(cur != -1){
		V.pb(cur);
		cur = path[cur][ans];
		ans --;	
	}
	printf("%d\n",(int)V.size());
	for(int i = (int)V.size() - 1; i >= 0; i --)
		printf("%d ", V[i] + 1);
		
	printf("\n");
	return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 5005;
struct ST{
	int c;
	ll k, p;
	ST(){}
	ST(int _c, ll _k, ll _p){
		c = _c;
		k = _k;
		p = _p;
	}
	bool operator<(ST other)const{
		return p < other.p;
	}
};
vector< ST > store;
vector<int> graph[MAX];
int visit[MAX], dis[MAX],label = 1;
int solve(int city, ll k, ll p){
		queue<int> q;
		q.push(city);
		q.push(0);
		visit[city] = label;
		dis[city] = 0;
		int maxi = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			int cost = q.front();
			q.pop();
			maxi = max(maxi, cost);
			for(int i = 0; i < (int) graph[cur].size(); i ++){
				int nei = graph[cur][i];
				if(visit[nei] == label)	
					continue;
				visit[nei] = label;
				q.push(nei);
				q.push(cost + 1);
				dis[nei] = cost + 1;
			}
		}
		int lo = 0, hi = maxi + 2, mit;
		//cout << "need to buy " << k << endl; 
		while(lo < hi){
			mit = hi + lo;
			mit /= 2;
			ll val = 0, total = k;
			for(int i = 0; i < (int)store.size(); i ++){
				if(total == 0)
					break;
				ll price = store[i].p;
				ll cant = store[i].k;
				ll t = dis[store[i].c];
				//cout << "cant = " << cant << " price = " << price  << " total =" << total << " distancia = " << t << endl;
				if(t <= mit && visit[store[i].c] == label){
					if(cant >= total){
						val += total * price;
						total = 0;
					}else{
						val += cant * price;
						total -= cant;
					}
				}else
					continue;
			}
			//cout << "mit " << mit << " val = " << val << " total = " << total << endl;
			if(total != 0 || val > p)
				lo = mit + 1;
			else{
				hi = mit;
			}
		}
		
		if(lo > maxi)
			return -1;
		return lo;
		
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("bulmart.in", "r", stdin);
	int n, m, u, v, c, q, w;
	ll k, p;
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < m; i ++){
		scanf("%d%d", &u, &v);
		u --, v --;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	scanf("%d", &w);
	
	for(int i = 0; i < w; i ++){
		scanf("%d" LL LL, &c, &k, &p);
		c--;
		store.pb(ST(c, k, p));
	}
	sort(store.begin(), store.end());
	scanf("%d", &q);
	while(q --){
		scanf("%d" LL LL, &c, &k, &p);
		c --;
		int ans = solve(c, k, p);
		printf("%d\n", ans);
		label ++;
	}
		

  return 0;
}

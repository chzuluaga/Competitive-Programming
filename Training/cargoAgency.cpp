#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 50005;
vector<ll> graph[MAX];
int n;
ll ans = 0;

ll solve(int cur, int p, ll c){
	ll son = 1;
	for(int i = 0; i < (int)graph[cur].size(); i += 2){
		int nei = graph[cur][i];
		ll w = graph[cur][i + 1];
		
		if(nei != p){
			son += solve(nei, cur, w);
		}
	}
	
	ans += son * c * (n - son);
	return son;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	//freopen("cargo.in", "r", stdin);
	scanf("%d", &n);
	ll a, b, c;
	for(int i = 0; i < n - 1; i ++){
		scanf("%lld%lld%lld", &a, &b, &c);
		a --, b --;
		graph[a].pb(b);
		graph[a].pb(c);
		graph[b].pb(a);
		graph[b].pb(c);
	}
	
	
	solve(0, 0, 0);
	double sol = ans * 2.0 / (1.0 * n *(n - 1));
	
	printf("%.4lf\n", sol);
	
  return 0;
}

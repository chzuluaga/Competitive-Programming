#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
ll mod = 1000000007ll;

struct node{
	node *L, *R;
	int lf, rg;
	ll val;
	
	node(){
			L = R = NULL;
			val = 0;
	}
	
	void create(int from, int to){
		lf = from, rg = to;
		
		if(from == to)
			return;
			
		int mit = (from + to) / 2;
		
		L = new node();
		L -> create(from, mit);
	
		R = new node;
		R -> create(mit + 1, to);
	}
	
	void insert(int from, int to, ll data){
		//cout << from << " " << to << " " << lf << " " << rg << endl;
		if(lf == from && rg == to){
			val = data;
			return;
		}
		
		if(to < R -> lf)
			L -> insert(from, to, data);
		else 
			R -> insert(from, to, data);
			
		val = ((L -> val + 1) * (R -> val + 1) - 1) % mod;
	}
	
	ll get(int from, int to){
		if(lf == from && rg == to)
			return val;
		if(to < R -> lf){
			return L -> get(from, to);
		}else{
			if(from > L -> rg){
				return R -> get(from, to);
			}else{
				ll x = L -> get(from, L->rg);
				ll y = R -> get(R -> lf, to);
				
				return ((x + 1) * (y + 1) - 1) % mod;
			}
		}
	
	}
	
};


ll fastPow(ll b, ll exp){
	ll ans = 1;
	
	if(exp == 0)
		return 1ll;
		
	if(exp == 1)
		return b;
	
	if(exp & 1){
		ans *= b;
		ans %= mod;
	}
	ll r = fastPow(b, exp/2); 
	ans *= r;
	ans %= mod;
	ans *= r;
	ans %= mod;
	return ans;
	
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, m;
	ll p;
	//freopen("subsets.in",  "r", stdin);
	
	while(~scanf("%d" LL, &n, &p)){
		node root;
		root.create(0, n - 1);
		for(int i = 0; i < n; i ++){
			ll x;
			scanf(LL, &x);
			ll val = fastPow(p, x);
			//cout << val << " " << x << endl;
			root.insert(i, i, val);
		}
		
		scanf("%d", &m);	
		while(m --){
			int u, v;
			scanf("%d %d", &u, &v);
			u --, v --;
			
			ll ans = root.get(u, v);
			printf(LL "\n", ans);
		}
			
	}
	
	
	
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int n, k;

struct trie{
	trie *a[2];
	ll cont;
	
	trie(){
		cont = 0;
		a[0] = a[1] = NULL;
	}
	
	void insert(int x, int pos){
		if(pos < 0){
			cont ++;
			return;
		}
		
		if(x & (1 << pos)){
			if(!a[1])
				a[1] = new trie();
			a[1] -> insert(x, pos - 1);
		}
		else{
			if(!a[0])
				a[0] = new trie();
			a[0] -> insert(x, pos - 1);
		}
		cont = 0;
		if(a[0])
			cont = a[0] -> cont;
		if(a[1])
			cont += a[1] -> cont;
	}
	
	int get(int x, int pos){
	
		if(pos < 0)
			return cont;
			
		int b = (x & (1<<pos)?1:0);
		int bitk (k & (1<<pos)?1:0);
		ll ans = 0;
		if(bitk){
			if(!a[b ^ 1])
				a[b ^ 1] = new trie();
				
			return a[b ^ 1] -> get(x, pos - 1);
		}else{
			
			if(!a[b])
				a[b] = new trie();
			
			if(a[b ^ 1])
				ans = a[b ^ 1] -> cont;
				
			return ans + a[b] -> get(x, pos - 1);
		}
		return ans;
	}
	
};

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("subarray.in", "r", stdin);
  scanf("%d%d", &n, &k);
  int xr = 0, x;
  trie root;
  root.insert(0, 30);
  ll ans = 0;
  for(int i = 0; i < n; i ++){
		scanf("%d", &x);
		xr ^= x;
		ans += root.get(xr, 30);
		//cout << xr << " dio " << root.get(xr, 30) << endl;
		root.insert(xr,30);
	}
	
	printf(LL "\n", ans);
  

  return 0;
}

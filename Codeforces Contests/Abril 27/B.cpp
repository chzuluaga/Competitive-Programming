#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

ll n, k, ans = 0;
vector<ll> f;
int mul(ll A, ll B){
	return ((A % n) * (B % n)) % n;
}

void solve(int idx){
	if(idx == n){
		for(ll i = 0; i < n; i ++){
			if(f[mul(k, i)] != mul(k , f[i])){
				return;
			}
		}
		ans ++;
		return;
	}
	
	for(int i = 0; i < n; i ++){
		f.pb(i);
		solve(idx + 1);
		f.pop_back();
	}
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  
  while( cin >> n >> k){
		ans = 0;
		solve(0);
		
		cout << ans << '\n';
	}
 
  return 0;
}

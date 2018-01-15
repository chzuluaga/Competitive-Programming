#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
ll two, mod = 1e9 + 7;

ll sum(ll from, ll to){
	from --;
	from %= mod;
	to %= mod;
	ll s1 = ((from  * (from + 1)) % mod);
	ll s2 = ((to * (to + 1)) % mod);
	//s1 %= mod;
	//s2 %= mod;
	//cout << "from " << from  << " dio " << s1 << " to " << to << " dio " << s2 << endl;
	return (( (s2 - s1 + mod) * two)) % mod;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll n, m;
  cin >> n >> m;
  two = 500000004ll;

  ll ans = (n % mod) * (m % mod);
  ans %= mod;
  
  ll rg = 0;
  ll cur = 1;
  int cont = 0;
  while(cur <= m){
		ll lo = cur, hi = m, mit;
		if(n / (cur+1) == n/cur)
			while(lo < hi){
				mit = hi + lo + 1;
				mit /= 2;
				if(n / mit == n / cur)
					lo = mit;
				else
					hi = mit - 1;
			}
		
		ll r = sum(cur, lo) * (n/cur % mod);
		//cout << cur << " " << lo << " " << n/cur << " " << r << endl;
		r %= mod;
		rg += r;
		rg %= mod;
		cur = lo + 1;
	//	cont ++;
	}
//	cout << cont << endl;
	cout << (ans - rg + mod) % mod << '\n';
  

  return 0;
}

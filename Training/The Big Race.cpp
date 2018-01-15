#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll t, x, y;
	
	cin >> t >> x >> y;
	ll gcd = __gcd(x, y);
	
	if(1.0 * t / x < 1.0 * y / gcd){
		ll r = min(t, min(x, y) - 1);
		cout << r / __gcd(r, t) << "/" << t / __gcd(r, t)<< endl;
		return 0;
	}
	ll mcm = (1.0 * x / gcd) * y;
	ll ans = (t / mcm) + (t / mcm) * (min(x, y) - 1);
	ll T = t % mcm;
	ans += min(min(x, y) - 1, T);
	
	cout << ans / __gcd(ans, t) << "/" << t / __gcd(ans, t)<< endl;
	
  return 0;
}

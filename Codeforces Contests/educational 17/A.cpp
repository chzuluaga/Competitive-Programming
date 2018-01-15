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
  
  ll n, k;
  cin >> n >> k;
  vector<ll> divisor;
  for(ll i = 1; i * i <= n; i ++){
		if(n % i == 0){
			divisor.pb(i);
			if(i * i != n)
				divisor.pb(n / i);
		}
	}
	if((int)divisor.size() < k)
		cout << -1 << '\n';
	else{
		sort(divisor.begin(), divisor.end());
		cout << divisor[k - 1] << '\n';
	}

  return 0;
}

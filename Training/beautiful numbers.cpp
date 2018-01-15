#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAX = 1000005;
ll a, b, n, mod = 1000000007;
ll fact[MAX];

ll fastPow(int base, int exp){
  if(exp == 0)
    return 1ll;

  ll ans = fastPow(base, exp / 2);
  ans *= ans;
  ans %= mod;
  if(exp & 1)
    ans *= base;
  ans %= mod;

  return ans;
}

ll check(int x, int y){
  ll cur = x * a + y * b;
  while(cur){
    if(cur % 10 != a && cur % 10 != b)
      return 0ll;
    cur /= 10;
  }
  return 1ll;
}

ll solve(int n, int k){
  ll ans = fact[n];
  ll div = fact[n - k] * fact[k];
  div %= mod;

  div = fastPow(div, mod - 2ll);

  return (ans * div) % mod;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b >> n;
  ll ans = 0;
  fact[0] = 1ll;
  for(int i = 1; i <= n; i ++){
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }

  for(int i = 0; i <= n; i ++){
    if(check(i, n - i)){
      ans += solve(n, i);
      ans %= mod;
    }
  }

  cout << ans << '\n';


  return 0;
}

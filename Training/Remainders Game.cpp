#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll lcm(ll a, ll b){return a * b / __gcd(a, b);}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  ll gcd = 1;
  cin >> n >> k;
  for(int i = 0; i < n; i ++){
    ll a;
    cin >> a;
    gcd = __gcd(k, lcm(gcd, a));
  }

  if(gcd == k)
    cout << "YES\n";
  else
    cout << "NO\n";




  return 0;
}

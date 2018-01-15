#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 5000;
ll toNum(char x){ return x -'0'; }
map<ll, ll> val;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  string num;
  cin >> n >> num;
  int cont = 0;
  int sz = num.size();
  for(int i = 1; i <= sz; i ++){
    ll sum = 0;
    for(int j = i; j <= sz; j ++){
      sum += toNum(num[j - 1]);
      cont ++;
      val[sum] ++;
    }
  }

  ll ans = 0;

  for(int i = 1; i <= sz; i ++){
    ll sum = 0;
    for(int j = i; j <= sz; j ++){
      sum += toNum(num[j - 1]);
      if(sum == 0){
        if(n == 0){
          ans += cont;
        }
      }else
      if(n % sum == 0)
        ans += val[n / sum];
    }
  }

  cout << ans << '\n';





  return 0;
}

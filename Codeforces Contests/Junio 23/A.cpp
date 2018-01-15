#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, m, x, ans = 0;
  string s;
  cin >> n >> m;

  for(int i = 0; i < n; i ++){
    cin >> s >> x;
    if(s == "+"){
      m += x;
    }else{
      if(x <= m){
        m -= x;
      }else
        ans ++;
    }
  }

  cout << m << " " << ans << '\n';





  return 0;
}

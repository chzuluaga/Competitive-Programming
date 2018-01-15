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
  ll t, s, x;

  cin >> t >> s >> x;

  ll up = x - t;
  if(up % s == 0){
    if(up >= 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  else{
    if((up - 1) % s == 0){
      ll t = (up - 1) / s;
      if(t > 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    else
      cout << "NO\n";
  }



  return 0;
}

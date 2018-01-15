#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100006;
ll point[MAX];

ll solve(int i, int j){
  //cout << i << " " << j << endl;
  ll x = j - i - 1;
  return x * (x + 1) / 2;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, d, ans = 0;

  cin >> n >> d;

  for(int i = 0;  i < n; i ++)
    cin >> point[i];

  for(int i = 0; i < n; i ++){
    int lo = i, hi = n - 1, mit;

    while(lo < hi){
      mit = lo + hi + 1;
      mit /= 2;
      if(point[mit] - point[i] <= d)
        lo = mit;
      else
        hi = mit - 1;
    }

    ans += solve(i, lo);
  }

  cout << ans << '\n';



  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, k;
  double l, v1, v2;

  cin >> n >> l >> v1 >> v2 >> k;
  cout << fixed << setprecision(10);
  if(v2 <= v1){
    cout << l / v1 << '\n';
    return 0;
  }

  double lo = 0.0, hi = l / v1, mit;

  for(int i = 0; i < 200; i ++){
    mit = lo + hi;
    mit /= 2;

    double x = mit * v1 * v2 - l * v1;
    x /= (v2 - v1);
    t = x * v1;
    if(x < 0){
    }

  }

  cout << lo << '\n';


  return 0;
}

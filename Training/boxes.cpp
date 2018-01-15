#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 10000005;
ll arr[MAX], cw[MAX], ccw[MAX];
int main(){
  ll n, k, l;
  //freopen("boxes.in", "r",stdin);
  scanf("%lld%lld%lld", &n, &k, &l);
  for(int i = 0; i < n; i ++)
    scanf("%lld", &arr[i]);

  for(int i = 0; i < n; i ++)
    cw[i] = (i - k >= 0?cw[i - k]:0) + 2 * arr[i];


  for(int i = n - 1; i >= 0; i --)
    ccw[i] = (i + k <= n - 1?ccw[i + k]:0) + 2 * (l - arr[i]);

  ll ans = ccw[0];
  for(int i = 0; i < n; i ++)
    ans = min(ans, cw[i] + ccw[i + 1]);

  for(int i = 0; i < n; i ++){
    int rg = min(n, i + k);
    if(i - 1 >= 0)
      ans = min(ans, l + cw[i - 1] + ccw[rg]);
    else
      ans = min(ans, l + ccw[rg]);
  }
  if(k >= n)  ans = min(ans, l);

  printf("%lld\n", ans);



  return 0;
}

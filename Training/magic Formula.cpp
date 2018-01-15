#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 1000005;
int xr[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, x, ans = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i ++){
    scanf("%d", &x);
    ans ^= x;
  }
  for(int i = 1; i <= n; i ++)
    xr[i] = xr[i - 1] ^ i;

  for(int i = 2; i <= n; i ++){
    int cant = ceil(1.0 * n / (1.0 * i));
    int mod = n % i;
    if(cant & 1){
      if(mod != 0)
        ans ^= xr[mod];
      else
        ans ^= xr[i - 1];
    }else{
      if(mod != 0)
        ans ^= (xr[i - 1] ^ xr[mod]);
    }
    //cout << ans << endl;
  }

  cout << ans << '\n';



  return 0;
}

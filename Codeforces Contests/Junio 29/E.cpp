#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 506;
bool dp[2][MAX][MAX];

int main(){

  int n, x, k;

  scanf("%d%d", &n, &k);
  dp[0][0][0] = true;
  for(int i = 0; i < n; i ++){
    scanf("%d", &x);
    int cur = i % 2;
    int nxt = 1 - cur;
    //cout << x << " "<< cur << " " << nxt << endl;
    for(int j = 0; j <= k; j ++){
      for(int l = 0; l <= k; l ++){
        if(dp[cur][j][l]){
          dp[nxt][j][l] = true;
          if(j + x <= k){
            dp[nxt][j + x][l] = true;
            if(l + x <= k)
              dp[nxt][j + x][l + x] = true;
          }
        }
      }
    }
  }
  vector<int> ans;
  for(int i = 0; i <= k; i++){
    if(dp[n % 2][k][i])
      ans.pb(i);
  }

  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i ++){
    printf("%d ",ans[i]);
  }

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAX = 100005;
int dp[2][MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  string cad, pal;
  cin >> cad >> k;
  int men = k + 1;
  int idx = 1;
  for(int l = 0; l < 5; l ++){
    cin >> pal;
    int n = cad.size();
    int m = pal.size();
    memset(dp, 1, sizeof(dp));

    for(int i = 0; i <= m; i ++)
      dp[0][i] = min(k + 1, i);

    for(int i = 1; i <= n; i ++){
      int cur = (i % 2);
      int prev = 1 - cur;
      dp[cur][0] = min(k + 1, i);
      for(int j = 1; j <= m; j ++ )
        dp[cur][j] = min(dp[prev][j] + 1, min(dp[cur][j - 1] + 1, dp[prev][j - 1] + (cad[i - 1] != pal[j - 1])));
    }
    if(dp[n % 2][m] < men){
      idx = l + 1;
      men = dp[n % 2][m];
    }
  }
  if(men == k + 1)
    cout << "-1\n";
  else
    cout << idx << "\n" << men << '\n';


  return 0;
}

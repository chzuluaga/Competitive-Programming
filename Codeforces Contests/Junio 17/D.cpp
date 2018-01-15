#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1004;
string s, t;
int dp[MAX][MAX][12];
int n, m, kk;
ll INF = 1005;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> kk;
  cin >> s >> t;
  if(n < m){
			swap(n, m);
			swap(s, t);
	}
		
	int ans = 0;
	for(int k = 1; k <= kk; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				if(s[i - 1] == t[j - 1]){
					dp[k][i][j] = max(dp[k - 1][i - 1][j - 1], dp[k][i - 1][j - 1]) +1;
				}else{
					dp[k][i][j] = max( dp[k - 1][i - 1][j - 1], max(dp[k - 1][i - 1][j], dp[k - 1][i][j - 1]));
				}
				ans = max(ans, dp[kk][i][j]);
			}
		}
	}
	
	/*for(int k = 1; k <= kk; k ++){
				for(int i = 1; i <= n; i ++){
					for(int j = 1; j <= m; j ++){
						cout << dp[k][i][j] << " ";
					}
					cout << endl;
				}	
				cout << "-------------------------" << endl;
	}*/
	
	cout << ans << '\n';
	

  return 0;
}

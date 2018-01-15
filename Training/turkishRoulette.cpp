#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 300;
int slot[2 * MAX], ball[MAX];
int dp[2][2 * MAX][2*MAX], inf = (130 * 64 * 300);

void init(int n, int m){
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j <= 2 * n + 2;j ++)
			for(int k = 0; k <= 2* n + 2 ; k ++)
			 dp[i][j][k] = inf;
				
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, m;
  //freopen("roulette.in", "r", stdin);
  while(true){
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
			break;
			
		for(int i = 0; i < n; i ++){
			scanf("%d", &slot[i]);
			slot[i + n] = slot[i];
		}
			
		for(int i = 0; i < m; i ++)
			scanf("%d", &ball[i]);
		
		init(n, m);
		for(int i = 0; i < m; i++){
			int cur = i % 2;
			int nxt = cur ^ 1;
			for(int j = 0; j < 2 * n;j ++){ // slot first ball
				if(i == 0){
					if(j >= n)
						break;
					dp[cur][j][j] = 0;
					dp[nxt][j][j + 2] = min(dp[nxt][j][j + 2], (slot[j] + slot[j + 1]) * ball[i]);
					continue;
				}
				for(int k = j + i * 2; k < j + n - 1; k ++){
					//put i ball in slot k, first ball in slot j
					dp[nxt][j][k + 2] = min(dp[nxt][j][k + 2], dp[cur][j][k] + (slot[k] + slot[k + 1]) * ball[i]);
					// no put i ball in k
					dp[cur][j][k + 1] = min(dp[cur][j][k + 1], dp[cur][j][k]);
				}
			}
			for(int j = 0;j <= 2 * n + 2 ; j ++){
				for(int k = 0; k <= 2 * n + 2; k ++){
					dp[cur][j][k] = inf;
				}
			}
			
			
		}
		
		int ans = inf;
				
		for(int j = 0; j < n; j ++){
			for(int k = 0; k <= j + n + 1; k ++){
				ans = min(ans, dp[m % 2][j][k]);
			}
		}
				
		printf("%d\n", ans * -1);
	}

  return 0;
}

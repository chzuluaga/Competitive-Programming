#include<bits/stdc++.h>
#define pb push_back
#define LL "%lld"
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 205;
int arr[MAX], n, Kmax;
ll memo[MAX][MAX][MAX], mod = 1000000007ll;
ll dp[2][MAX][1005];

/*
9 222

304 142 38 334 73 122 252 381 438
 
423

  */

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  scanf("%d%d", &n, &Kmax);
  for(int i = 0; i < n; i ++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + n);
	/*for(int i = 0; i < n; i ++)
		cout << arr[i] << " " ;
	cout << endl;*/
	
	dp[0][0][0] = 1ll;

	int cur = 0;
	ll ans = 0;
	for(int i = 0; i < n; i ++){
		int nxt = cur ^ 1;
		
		for(int j = 0; j <= n; j ++){ //  groups
			for(int k = 0; k <= Kmax; k ++){ //imbalance
					dp[nxt][j][k] = 0;
			}
		}		
		
		for(int k = 0; k <= Kmax; k ++){ //imbalance
			for(int j = 0; j <= n; j ++){ //  groups
				int newI = arr[i];
				if(i)
					newI -= arr[i - 1];
				else
					newI = 0;
					
				if(k + j * newI > Kmax)
					continue;
				
				//own group
				dp[nxt][j][k + j * newI] += (dp[cur][j][k]);
				dp[nxt][j][k + j * newI] %= mod;
				
				//start a new group
				dp[nxt][j + 1][k + j * newI] += (dp[cur][j][k]);
				dp[nxt][j + 1][k + j * newI] %= mod;
				
				// continue in a group
				if(j){
					dp[nxt][j][k + j * newI] += (dp[cur][j][k]) * j;
					dp[nxt][j][k + j * newI] %= mod;
				}
				// close a group
				if(j){
					dp[nxt][j - 1][k + j * newI] += (dp[cur][j][k]) * j;
					dp[nxt][j - 1][k + j * newI] %= mod;
				}
			}
		}
		cur ^= 1;
	}
	for(int i = 0; i <= Kmax; i ++){
		ans += dp[cur][0][i];
		ans %= mod;
	}
	
	
	printf(LL "\n", ans);
  

  return 0;
}

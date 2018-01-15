#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 105;
bool dp[2][2 * 500 * MAX];
int a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int t;
  
  scanf("%d", &t);
  
	while(t --){
		int n, sum = 0; 
		scanf("%d", &n);
		
		memset(dp, false, sizeof(dp));
		for(int i = 0; i < n; i ++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int mit = sum;
		dp[0][mit] = true;
		int ans = sum;
		for(int i = 0; i < n; i ++){
			int cur = i % 2;
			int nxt = cur ^ 1;
			for(int j = -sum; j <= sum; j ++){
				if(dp[cur][j + mit]){
					if(i + 1 == n){
						ans = min(ans, abs(j + a[i]));
						ans = min(ans, abs(j - a[i]));
					}
				//	cout << i << " " << j + a[i] << " " << j - a[i] << endl;
					dp[nxt][j + mit + a[i]] = true;
					dp[nxt][j + mit - a[i]] = true;
				}
			}
			for(int j = 0; j <= sum + mit ;j ++)
				dp[cur][j] = false;
		}
		printf("%d\n", ans);
		
	}

  return 0;
}

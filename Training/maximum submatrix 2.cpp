#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 5006;
char ma[MAX][MAX];
int ones[MAX][MAX];
int dp[MAX][MAX];
int total[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("submatrix.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for(int i = 0; i < n; i ++){
		scanf("%s", ma[i]);
		for(int j = 0; j < m; j ++)
			if(ma[i][j] == '1'){
				if(j)
					ones[j][i] = ones[j - 1][i] + 1;
				else
					ones[j][i] = 1;
					
				dp[j][ones[j][i]] ++;
				total[j] ++;
			}
	}
	for(int j = 0;j < m;j ++){
		for(int i = 0; i <= m; i ++){
		//	cout << dp[j][i] << " " << j << " ones " << i << endl;
			ans = max(ans, total[j] * i);
			total[j] -= dp[j][i];
		}
	}
	printf("%d\n", ans);
	
	
	
  return 0;
}

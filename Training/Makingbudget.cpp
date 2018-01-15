#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 30;
ll a[MAX];
ll dp[MAX][MAX];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("budget.in", "r", stdin);
	int n, tc = 1;
	ll costHire, costWage, costFire; 
	while(true){
		scanf("%d", &n);
		if(n == 0)	break;
		scanf("%lld%lld%lld", &costHire, &costWage, &costFire);
		
		for(int i = 0; i < n; i ++)
			scanf("%lld", &a[i]);
		
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				dp[i][j] = (ll) INT_MAX;
	
		for(int i = 0; i < n; i ++)
			if(a[i] >= a[0])
				dp[0][i] = (costHire + costWage) * a[i];
		ll ans = (ll) INT_MAX;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				if(i == n - 1 && a[j] >= a[n - 1])
					ans = min(ans, dp[i][j]);
				for(int k = 0; k < n && i + 1 < n; k ++){
					if(a[k] < a[i + 1])
						continue;
						
					ll cost = 0;
					if(a[k] > a[j])
						cost = costHire * (a[k] - a[j]) + costWage * a[k];
					else
						cost = costFire * (a[j] - a[k]) + costWage * a[k];
					
					dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cost);
				}
			}
		}
		
		printf("Case %d, cost = $%lld\n", tc ++,ans);
		
	}

		
	
	
  return 0;
}

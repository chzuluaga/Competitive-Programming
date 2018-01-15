#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 205;
double dp[MAX][MAX], a[MAX], inf = (double)INT_MAX, sum[2 * MAX];

void init(int n){
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= n; j ++)
			dp[i][j] = inf;
			
	for(int i = 0; i <= 2 * n; i ++)
		sum[i] = 0;
		
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("land.in", "r",stdin);
  int n;
  double f;
  
  while(true){
		scanf("%d%lf", &n, &f);
		if(n == 0)
			break;
			
		for(int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		
		init(n);
		for(int i = 0; i < 2 * n; i ++){
			sum[i] = sum[i - 1];
			sum[i] += a[i % n];
		}
		
			
		for(int d = 0; d < n; d ++){
			for(int i = 0; i < n; i ++){
				int j = (i + d) % n;
				if(i == j)
					dp[i][j] = 0; // max(a[i], (sum[n - 1] - a[i])) * f;
				for(int kk = i + 1; kk <= i + d; kk ++){
					int k = kk % n;
					double A = sum[i + d];
					A -= sum[kk - 1];
					double B = sum[kk - 1];
					if(i)
						B -= sum[i - 1];
					int k_1 = ((k - 1) + n) % n;
					double r = max(A, B);
					dp[i][j] = min(dp[i][j], dp[i][k_1] + dp[k][j] + r * f);
					
				}
			}
		}
		
		cout << setprecision(3) << fixed;
		double ans = inf;
		for(int i = 0; i < n; i ++){
			ans = min(ans, dp[i][(i + n - 1) % n]);
		}
		
		printf("%0.2lf\n", ans);
			
		
	}
  

  return 0;
}

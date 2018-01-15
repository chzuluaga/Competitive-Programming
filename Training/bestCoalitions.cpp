#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 105;
double v[MAX];
int a[MAX];
bool dp[MAX][MAX * 100];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
 // freopen("bestCoalitions.in", "r", stdin);
  int n, x, fs, sc;
  int vx;
  while(true){
		scanf("%d%d",&n, &x);
		if(n == 0 && x == 0)
			break;
		for(int i = 0; i < n; i ++){
			if(i == x - 1){
				scanf("%d.%d",&fs,&sc);
				vx = fs * 100 + sc;
			}else{
				scanf("%d.%d", &fs, &sc);
				v[i] = fs * 100 + sc;
				if(i > x - 1)
					a[i - 1] = v[i];
				else
					a[i] = v[i];
			}
		}
		n --;
		memset(dp, false, sizeof(dp));
		dp[0][vx] = true;
		int cien = 10000;
		double ans = vx > 5000?100.00:0.0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j <= cien; j ++){
				if(dp[i][j]){
					if(j > 5000){
						ans = max(ans, (vx * 100.0) / (1.0 * j));
					}
					if(j + a[i] <= cien){
						dp[i + 1][j + a[i]] = true;
						if(j + a[i] > 5000){
							ans = max(ans, (vx * 100.0) / (1.0 * (j + a[i])));
						}
					}
					dp[i + 1][j] = true;
				}
			}
		}
		printf("%.2lf\n", ans);
	}
	
  return 0;
}

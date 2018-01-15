#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
pair<int, double> pro[MAX];
double dp[2][MAX];
double inf = 100000ll*105ll;
int a[MAX];
void init(int m){
		for(int i = 0; i < 2; i ++)
			for(int j = 0; j <= m;j ++)
				dp[i][j] = inf;
			
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	char no[20];
	int n, m;
	strcpy(no, "Impossible");
	
	//freopen("supermarket.in", "r", stdin);
	
	while(true){
		scanf("%d%d", &n, &m);
		if(!n && !m)
			break;
		for(int i = 0; i < n; i ++)
			scanf("%d", &a[i]);
			
		for(int i = 0; i < m; i ++)
			scanf("%d%lf", &pro[i].first, &pro[i].second);
			
		init(m);
		
		dp[0][0] = 0;
		for(int i = 0; i < n; i ++){
			int cur = i % 2;
			int nxt = cur ^ 1;
			for(int j = 0; j < m;j ++){
				if(pro[j].first == a[i])
					dp[nxt][j + 1] = min(dp[nxt][j + 1], dp[cur][j] + pro[j].second);
				
				dp[cur][j + 1] = min(dp[cur][j + 1], dp[cur][j]);
			}
			for(int j = 0; j <= m;j ++){
				dp[cur][j] = inf;
			}
		}
		double ans = inf;
		for(int i = 0; i <= m; i ++)
			ans = min(ans, dp[n%2][i]);
		
		if(ans < inf)
			printf("%.2lf\n", ans);
		else
			printf("%s\n", no);
			
	}
	
	
	
	
	
	
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 104;

int a[MAX], doc[MAX], dp[MAX][(1<<16) + 10];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m, tam, x;
  //freopen("documentCompresion.in", "r", stdin);
  while(true){
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
			break;
			
		for(int i = 0; i < n; i ++){
			scanf("%d", &tam);
			int cur = 0;
			for(int j = 0; j < tam; j ++){
				scanf("%d", &x);
				x --;
				cur |= 1<<x;
			}
			a[i] = cur;
		}
		
		for(int i = 0; i < m; i ++){
			scanf("%d", &tam);
			int cur = 0;
			for(int j = 0; j < tam; j ++){
				scanf("%d", &x);
				x --;
				cur |= 1<<x;
			}
			doc[i] = cur;
		}
		
		memset(dp, 1, sizeof(dp));
			
		dp[0][0] = 0;
		
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < 1<<16;j ++){
				int nxt = j | a[i];
				dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + 1);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
		}
		
		for(int i = 0; i < m; i ++){
			if(i)
				printf(" ");
			printf("%d",(dp[n][doc[i]]<= n?dp[n][doc[i]]:0));
		}
		printf("\n");
	}

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 305;
char table[MAX][MAX];
int sum[MAX][MAX];

int getSum(int x1, int y1, int x2, int y2){
	
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("seats.in", "r", stdin);
	int n, m, seats;
	
	while(true){
		scanf("%d%d%d", &n, &m, &seats);
		if(n == 0 && m == 0 && seats == 0)
			break;
		for(int i = 0; i < n; i ++)
			scanf("%s", table[i]);
		memset(sum, 0, sizeof(sum));
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m;j ++){
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - 
														sum[i][j] + (table[i][j] == '.');
			}
		}
		int ans = n * m;
		for(int i = 1; i <= n; i ++){
			for(int j = i; j <= n; j ++){
				int from = 1, to = 1;
				while(to <= m){
					int curSum = getSum(i, from, j,to);
					if(curSum >= seats){
						ans = min(ans, (j - i + 1)*(to - from + 1));
						from ++;
						to = max(to, from);
					}else{
						to ++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
  return 0;
}

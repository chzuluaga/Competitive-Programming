#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 605;
int ma[MAX][MAX];
int sum[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m;
  freopen("longest.in", "r", stdin);
  while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0)	break;
		
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m;j ++)
				scanf("%d", &ma[i][j]);
		int ans = 0;
		for(int i = 0; i < m; i ++){
			for(int j = i; j < m;j ++){
				int w = j - i + 1, up = 0, down = 0;
				for(int k = 0; k < n; k ++){
					down = k;
					if(j == i){
						sum[k] = 1;
					}else{
						if(ma[k][j] > ma[k][j - 1]){
							sum[k] ++;
						}
					}
					if(sum[k] != w)
						up = k + 1;
					
					if(ma[k][i] <= ma[k - 1][j])
						up = max(up, k);
					
					ans = max(ans, w * (down - up + 1));
				}
			}
		}
		printf("%d\n", ans);
	}

  return 0;
}

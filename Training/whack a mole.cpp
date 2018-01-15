//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
bool whac[32][32][12];
int dp[32][32][12], n;

int __gcd(int a, int b){
	if(b == 0)
		return a;
		
	return __gcd(b, a%b);
}

int pot(int x){return x*x;}

int getDis(int x1, int y1, int x2, int y2){
	return pot(x1 - x2) + pot(y1 - y2);
}

int getSum(int x1, int y1, int x2, int y2, int t){
	pii slope = mp(y2 - y1, x2 - x1);
	int gcd = __gcd(abs(slope.first), abs(slope.second));
	
	if(slope.first != 0 &&slope.second != 0){
		slope.first /= gcd;
		slope.second /= gcd;
	}else{
		if(slope.first != 0)
			slope.first /= abs(slope.first);
		if(slope.second != 0)
			slope.second /= abs(slope.second);
	}
	
	int ans = 0;
	
//	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << slope.first << " " << slope.second << endl;
	while(x1 != x2 || y1 != y2){
		ans += (whac[x1][y1][t] == true);
		y1 += slope.first;
		x1 += slope.second;
	//	cout << x1 << " --- " << y1 << endl;
	}
	ans += (whac[x2][y2][t] == true);
//	cout << "dio " << ans << endl;
	
	return ans;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int d, m, t, x, y;
  //freopen("whac.in", "r",stdin);
  //freopen("whac.out", "w", stdout);
  while(true){
		scanf("%d%d%d", &n, &d, &m);
		if(n == 0 && d == 0 && m == 0)
			break;
			
		memset(whac, false, sizeof(whac));
		n ++;
		for(int i = 0; i < m; i ++){
			scanf("%d%d%d", &x, &y, &t);
			whac[x+8][y+8][t - 1] = true;
		}
		
		memset(dp, 0, sizeof(dp));
		for(int tm = 0; tm < 10; tm ++){
			for(int i = 0; i < n + 8; i ++){
				for(int j = 0; j < n + 8; j ++){
					for(int k = max(0, i - d); k <= min(n + 8 - 1, i + d); k ++){
						for(int l = max(0, j - d); l <= min(n + 8 - 1, j + d); l ++){
							//go from (i,j) to (k,l) in time tm
							int dis = getDis(i,j,k,l);
							if(dis > d * d)
								continue;
							int sum = getSum(i, j, k, l, tm);
							//cout << i << " " << j << " " << k << " " << l << " " << dis << " " << sum << endl;
							dp[k][l][tm + 1] = max(dp[k][l][tm + 1], dp[i][j][tm] + sum);
						}
					}
				}
			}
		}
		
		int ans = 0;
		for(int i = 0; i < n + 8; i ++)
			for(int j = 0;j < n + 8;j ++)
				ans = max(ans, dp[i][j][10]);
		printf("%d\n", ans);
		//break;
	}
		
  return 0;
}

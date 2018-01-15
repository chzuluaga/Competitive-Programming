#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 20;
//bitset<(1<<MAX)+1> vis[20];
//int vis[20][(1<<MAX)+1];
short a[MAX], t[MAX][MAX], lim = 420;

int main(){
	//freopen("longNight.in", "r", stdin);
	int x, ans, cur, nxt, n, nxtMask;
	int mask, i, j, k, cost;
	short v;
	char fin;
	vector<pair<char, pii> > prv[2];
	while(~scanf("%d", &n) && n){
		/*for(int i = 0; i < n; i ++)
			for(int j = 0; j <= (1<<n); j ++){
				vis[i][j] = false;
			}
		*/
		for(i = 0; i < n; i ++){
			scanf("%d", &x);
			if(x > lim)
				a[i] = lim + 1;
			else
				a[i] = (short) x;
		}
		
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				scanf("%d", &x);
				if(x > lim)
					t[i][j] = lim + 1;
				else
					t[i][j] = (short)x;
			}
		}
		
		for(k = 0; k < n; k ++){
			for(i = 0; i < n; i ++){
				for(j = 0; j < n; j ++){
					t[i][j] = min(t[i][j],
												(short)(t[i][k] + t[k][j]));
				}
			}
		}
		prv[0].clear();
		prv[1].clear();
		ans = 0;
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				t[i][j] += a[j];
				if(i == j && t[i][j] <= lim){
					ans = 1;
					//dp[i][1<<i] = min(dp[i][1<<i], (short)t[i][j]);
					prv[0].pb(mp((char)i, mp(1<<i,(short)t[i][j])));
				}
			}
		}
		cur = 0;
		for(i = 1; i < n; i ++){
			nxt = cur ^ 1;
			prv[nxt].clear();
			for(j = 0; j < (int) prv[cur].size(); j ++){
				mask = prv[cur][j].second.first;
				fin = prv[cur][j].first;
				cost = prv[cur][j].second.second;
				for(k = 0; k < n; k ++){
					if(mask & 1<<k)	continue;
					v = (short)(cost) + t[fin][k];
					if(v > lim)	continue;
					nxtMask = mask | (1<<k);
					ans = (i + 1);
					if((int)prv[nxt].size() < 100000)
						prv[nxt].pb(mp(k, mp(nxtMask, v)));
					
				}
			}
			cur ^= 1;
		}
		printf("%d\n", ans);
	}
	
  return 0;
}

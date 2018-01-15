#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 500;
int a[MAX];
pair<ll, int> block[MAX];
ll memo[MAX][MAX][MAX];
ll pot(ll x){return x*x;}
int nBlocks;

ll solve(int i, int j, int k){
	if(i > j)
		return 0;
		
	if(i == j){
	//	cout << i << " " << j << " " << k << " return " << pot(k) << endl;
		return pot(k);
	}
		
	ll &ans = memo[i][j][k];
	if(ans != -1)
		return ans;
		
	ans = pot(k) + solve(i + 1, j, block[i + 1].first);
	for(int l = i + 1; l <= j; l ++){
		if(block[i].second == block[l].second)
			ans = max(ans, solve(i + 1, l - 1, block[i+1].first) + solve(l, j, k + block[l].first));
	}
	
	//cout <<  i << " " << j << " " << k << " " << ans << endl;
	return ans;
}



int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("blocks.in", "r", stdin);
  int t;
  scanf("%d", &t);
  for(int tc = 1;tc <= t; tc ++){
		int n;
		scanf("%d", &n);
		nBlocks = 0;
		for(int i = 0; i < n; i ++){
			scanf("%d", &a[i]);
			if(i){
				if(a[i] == a[i - 1]){
					block[nBlocks - 1].first ++;
				}else{
					block[nBlocks ++] = mp(1, a[i]);
				}
			}else
				block[nBlocks ++] = mp(1, a[i]);
		}
		
		for(int i = 0; i < n; i ++)
			for(int j = 0;j < n; j ++)
				for(int k = 0; k < n; k ++)
					memo[i][j][k] = -1;
		
		ll ans = solve(0, nBlocks - 1, block[0].first);
		
		//cout << nBlocks << endl;
		
		printf("Case %d: %lld\n", tc, ans);
	
	}

  return 0;
}

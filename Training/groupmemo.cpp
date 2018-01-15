#include<bits/stdc++.h>
#define pb push_back
#define LL "%lld"
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 205;
int arr[MAX], n, k;
ll memo[MAX][MAX][1005], mod = 1000000007;

ll solve(int idx, int g, int imbalance){
	if(imbalance > k || g < 0)
		return 0ll;
	if(idx == n){
		if(g == 0 && imbalance <= k)
			return 1ll;
		return 0ll;
	}
	ll &ans = memo[idx][g][imbalance];
	if(ans != -1)
		return ans;
	ans = 0;	
	int newI = arr[idx] - (idx?arr[idx - 1]: 0);
	//own group
	ans += solve(idx + 1, g, imbalance + g * newI );
	ans %= mod;
	//continue sames groups
	if(g)	
		ans += ((ll)g) * solve(idx + 1, g, imbalance + g * newI);
	ans %= mod;
	// create group
	ans += solve(idx + 1, g + 1, imbalance + g * newI);
	ans %= mod;
	// close previous group
	if(g)
		ans += ll(g) * solve(idx + 1, g - 1, imbalance + g * newI);
	ans %= mod;
	
	return ans;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  memset(memo, -1 ,sizeof(memo));
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i ++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + n);
	
	ll r = solve(0,0,0);
	printf(LL "\n", r);
  

  return 0;
}

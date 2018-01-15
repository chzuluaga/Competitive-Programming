#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 205;
char dig[MAX];
int n;
ll memo[MAX][MAX], num[MAX][MAX];

void create(){
	for(int i = 0; i < n; i ++){
		ll val = 0;
		for(int j = i; j < n; j ++){
			if(i == j && dig[j] == '0'){
				num[i][j] = 0;
				break;
			}
			val *= 10;
			val += (dig[j] - '0');
			if(val > INT_MAX)
				break;
			num[i][j] = val;
		}
	}
}

ll solve(int idx, int prev){
	if(idx == n){
		if(prev == idx)
			return 0;
		return num[prev][idx];
	}
	
	ll &ans = memo[idx][prev];
	
	if(ans != -1)
		return ans;
	ans = 0;
	// stop here
	ans = max(ans, num[prev][idx] + solve(idx + 1, idx + 1));
	// continue
	if(num[prev][idx + 1] != -1)
		ans = max(ans, solve(idx + 1, prev));
	return ans;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int t;
  
  scanf("%d", &t);
  
  while(t --){
		scanf("%s", dig);
		n = strlen(dig);
		memset(num, -1, sizeof(num));
		memset(memo, -1, sizeof(memo));
		create();
		printf("%lld\n", solve(0, 0));
	}
	
	

  return 0;
}

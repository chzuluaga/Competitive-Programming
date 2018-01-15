#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 30000000;
ll dp[MAX], inf = LLONG_MAX / 10ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	ll n, x, y;
	cin >> n >> x >> y;
	
	for(int i = 0; i < MAX; i++)
		dp[i] = inf;
	
	dp[1] = x;
	int pow2 = 1;
	while( pow2 < n ){
		for(int i = pow2 + 1; i <= 2 * pow2;i ++){
			if(!(i & 1))
				dp[i] = min(dp[i], dp[i / 2] + y);
		}
		
		for(int i = pow2; i <= 2 * pow2 ; i ++)
			dp[i] = min(dp[i], dp[i - 1] + x);
			
		for(int i = 2 * pow2; i >= pow2; i --)
			dp[i] = min(dp[i], dp[i + 1] + x);
		
		pow2 *= 2;
	}
	
	
	
	cout << dp[n] << '\n';
  return 0;
}

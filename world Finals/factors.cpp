#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef unsigned long long ll;
ll inf = 1ULL<<63;
map<ll,ll> ans;
vector<ll> prime;
ll pascal[65][65];
void preWork()
{
    pascal[0][0] = 1;
    for (int i = 1; i <= 62; i++) {
        pascal[i][0] = 1;
        for (int j = 1; j <= 62; j++) {
            if (pascal[i-1][j] <= inf && pascal[i-1][j-1] <= inf)
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            else
                pascal[i][j] = inf;
        }
    }
}


void solve(ll num, ll n, ll cur, int idx, ll val, int maxi){
	if(cur == n){
		if((ans.count(num) <= 0 || val < ans[num]))
			ans[num] = val;
		return;
	}
	if(idx == (int)prime.size())
		return;
	
	ll p = prime[idx];
	ll acu = val;
	for(int i = 1; i <= maxi; i ++){
		//cout << inf / acu << " " << p << endl;
		if(1.0 * inf / acu < p)	break;
		if(1.0 * inf / num < pascal[cur + i][i])	continue;
		acu *= p;
		solve(num * pascal[cur + i][i], n, cur + i, idx + 1, acu, i);
	}
	
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("sal.out", "w", stdout);
  prime.pb(2);
	prime.pb(3);
	prime.pb(5);
	prime.pb(7);
	prime.pb(11);
	prime.pb(13);
	prime.pb(17);
	prime.pb(19);
	prime.pb(23);
	prime.pb(29);
	prime.pb(31);
	prime.pb(37);
	prime.pb(41);
	prime.pb(43);
	prime.pb(47);
	prime.pb(53);
	prime.pb(59);
	prime.pb(61);
	prime.pb(67);
	preWork();
  for(int i = 1; i < 64; i ++){
		solve(1ll, i, 0, 0, 1, i);
	} 	
	cout << ans.size() << endl;
	for(map<ll, ll>::iterator it = ans.begin(); it != ans.end(); it ++)
        if( (*it).first < 1ULL << 63 && (*it).second < 1ULL << 63)
        cout << (*it).first << " " << (*it).second << endl;
	ll n;
	while(~scanf("%llu", &n)){
		printf("%llu %llu\n", n, ans[n]);
	}

  return 0;
}

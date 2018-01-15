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
void solve(ll num, ll n, ll cur, int idx, ll val, int maxi){
    if(cur == n){
        if((ans.count(num) <= 0 || val < ans[num]))
            ans[num] = val;
        return;
    }
    if(idx == (int)prime.size())
        return;
    
    ll p = prime[idx];
    ll acu = val, fact = cur + 1;
    for(int i = 1; i <= maxi; i ++){
        //cout << inf / acu << " " << p << endl;
        if(1.0 * inf / acu < p) break;
        if(1.0 * inf / num < 1.0 * fact / i)  break;
        double aux = fact * 1.0 / (i * 1.0);
        fact ++;
        acu *= p;
        num = num * 1.0 * aux;
        solve(num, n, cur + i, idx + 1, acu, i);
    }
    
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("sal1.out", "w", stdout);
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

  for(int i = 1; i < 64; i ++){
        solve(1ll, i, 0, 0, 1, i);
    }   
    ll n;
    //cout << ans.size() << endl;
    /*for(map<ll, ll>::iterator it = ans.begin(); it != ans.end(); it ++)
        if( (*it).first < 1ULL << 63 && (*it).second < 1ULL << 63)
        cout << (*it).first << " " << (*it).second << endl;
    */
    while(~scanf("%llu", &n)){
        printf("%llu %llu\n", n, ans[n]);
    }

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
map< pair<ll, ll>, ll> road;

void increment(ll a, ll b, ll c){
  ll tmp;
  if(a > b)
    swap(a, b);
  while(a != b){
    tmp = b;
    b /= 2;
    road[mp(b, tmp)] += c;
    if(a > b)
      swap(a, b);
  }
}

ll solve(ll a, ll b){
  ll tmp, ans = 0;
  if(a > b)
    swap(a, b);
  while(a != b){
    tmp = b;
    b /= 2;
    ans += road[mp(b, tmp)];
    if(a > b)
      swap(a, b);
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 //freopen("c.in", "r", stdin);

  ll q, type, u, v, w;
  cin >> q;

  for(int i = 0; i < q; i ++){
      cin >> type;
      if(type == 1){
        cin >> u >> v >> w;
        increment(u, v, w);
      }else{
        cin >> u >> v;
        cout << solve(u, v) << '\n';
      }
  }



  return 0;
}

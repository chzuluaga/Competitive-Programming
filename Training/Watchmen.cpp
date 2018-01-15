#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%I64d"
using namespace std;
typedef long long ll;
const int MAX = 200005;
pair<int,ll> a[MAX];
map<int,ll> row, col;
map< pii , ll> eq;
map< pii , ll>::iterator it;
ll sum(ll x){
	return (x * (x + 1)) / 2;
}
int main(){
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n;i ++){
		scanf("%d" LL, &a[i].first, &a[i].second);
		row[a[i].first] ++;
		col[a[i].second] ++;
		eq[a[i]] ++;
	}
	ll ans = 0;
	for(pair<const int, ll> x: row)
		ans += sum(x.second - 1);
	
	for(pair<const int, ll> x: col)
		ans += sum(x.second - 1);
	
	for(it = eq.begin(); it != eq.end(); it ++)
		ans -= sum((*it).second - 1);
	
	printf(LL, ans);

  return 0;
}

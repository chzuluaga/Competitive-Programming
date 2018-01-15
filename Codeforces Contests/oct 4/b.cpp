#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define LL "%lld"
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;

pii a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	
	sort(a, a + n);
	ll ans = 0;
	for(int i = 1; i < n; i ++)
		ans += (ll)abs(a[i].second - a[i - 1].second);
		
	printf(LL "\n", ans);
	

  return 0;
}

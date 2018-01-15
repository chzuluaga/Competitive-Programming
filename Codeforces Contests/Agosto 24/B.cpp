#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
ll arr[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  ll n, a;
  
  scanf(LL LL, &n, &a);
  
  for(int i = 0; i < n; i ++)
		scanf(LL, &arr[i]);
	
	sort(arr, arr + n);
	ll ans = 	LLONG_MAX;
	if(n == 1){
		cout << 0 << '\n';
		return 0;
	}
	if(n == 2){
		ans = min(abs(a - arr[0]),abs(a - arr[1]));
		cout << ans << '\n';
		return 0; 
	}
		
	for(int i = 0; i < n; i ++){
			ll lf = i?arr[0]:arr[1];
			ll rg = (i < n - 1)?arr[n - 1]:arr[n - 2];
			
			ll r1 = abs(a - lf) + abs(rg - lf);
			ll r2 = abs(a - rg) + abs(rg - lf);
			//cout << lf << " " << rg << " " << r1 << " " << r2 << endl;
			ans = min(ans, r1);
			ans = min(ans, r2);
	}
	
	cout << ans << '\n';
		

  return 0;
}

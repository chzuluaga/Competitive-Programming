#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll bre, dinner, supper;
  
  cin >> bre >> dinner >> supper;
  
  ll ans = LLONG_MAX;
  for(int i = 0; i < 3; i ++){
		ll b, d, s;
		for(int j = 0; j < 3; j ++){
			if(i == 0){
				b = bre;
				d = dinner;
				s = supper;
			}
			if(i == 1){
				b = bre;
				d = dinner - 1;
				s = supper - 1;
			}
			if(i == 2){
				b = bre;
				d = dinner;
				s = supper - 1;
			}
			
			
			if(j == 0)
				b --;
			if(j == 1){
				b --;
				d --;
			}
			
			ll M = max(b, max(d, s));
			ll r = (M - b) + (M - d) + (M - s);
		
			ans = min(r, ans);
		}
	}
	cout << ans << "\n";
  return 0;
}

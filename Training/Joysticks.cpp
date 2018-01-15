#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int a, b, ans = 0;
	
	cin >> a >> b;
	
	while(true){
		if(a < b){
			a ++;
			b -= 2;
		}else{
			b ++;
			a -= 2;
		}
		a = min(a, 100);
		b = min(b, 100);
		if(a < 0 || b < 0)
			break;
		ans ++;
		if(a == 0 || b == 0)
			break;
	}
	cout << ans << '\n';
  return 0;
}

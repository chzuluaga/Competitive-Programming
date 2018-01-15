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
  
  int n, m, k;
  
  cin >> n >> m >> k;
  m -= n;
  
  int lf = k, rg = k, cur = 1, ans = 1;
  
  while(m > 0){
		if( m < cur )
			break;
		//cout << m << " " << cur << endl;
		m -= cur;
		ans ++;
		lf --;
		rg ++;
		if(lf <= 0 && rg > n){
			ans += (m / cur);
			break;
		}
		cur += 2;
		if(lf <= 0)
			cur --;
		
		if(rg > n)
			cur --;
	}
  
	cout << ans << '\n';

  return 0;
}

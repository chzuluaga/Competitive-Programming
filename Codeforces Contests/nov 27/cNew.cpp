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
  
  ll n, ans = 0, cont = 0;
  
  cin >> n;
  
  while(n != 1){
		//cout << n << endl;
		if(n & 1){
			n ++;
			cont ++;
		}
		
		n /= 2;
		ans ++;
	}
	
	cout << ans << '\n';

  return 0;
}

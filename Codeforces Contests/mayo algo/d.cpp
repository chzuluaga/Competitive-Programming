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
  
  string s;
  cin >> s;
  int n = (int)s.size();
  ll mod = 1000000007ll, b = 0, ans = 0;
  
  for(int i = n - 1; i >= 0; i --){
		if(s[i] == 'a'){
			ans = (ans + b) % mod;
			b *= 2;
			b %= mod;
		}else{
			b ++;
			b %= mod;
		}
		
	}
	
	cout << ans << '\n';

  return 0;
}

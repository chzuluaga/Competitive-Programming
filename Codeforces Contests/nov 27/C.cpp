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
  
  ll n;
  cin >> n;
  ll a = 2, b = 3;
  for(int i = 1;; i ++){
		//cout << a << " " << b << endl;
		if(n < b){
			cout << i << '\n';
			break;
		}
		ll t = a + b;
		a = b;
		b = t;
	}

  return 0;
}

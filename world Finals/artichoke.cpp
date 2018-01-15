#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
double p, a, b, c, d;
double price(double k){
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> p >> a >> b >> c >> d >> n;
  double prev, ans = 0;
  for(int i = 1; i <= n; i ++){
		double val = price(i);
		if(i == 1){
			prev = val;
			continue;
		}
		if(val > prev){
			prev = val;
		}else{
			ans = max(ans, prev - val);
		}
		
	}
	
	cout << fixed << setprecision(10);
	cout << ans << '\n';
  

  return 0;
}

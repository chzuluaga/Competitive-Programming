#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

double pot(double x){
	return x * x;
}
double dis(double x, double y, double a, double b){

	return sqrt(pot(x - a) + pot(y - b));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  double x, y, a, b, c;
  double ans = INT_MAX * 1.0;
  cin >> x >> y;
  
  int n;
  
  cin >> n;
  
  for(int i = 0; i < n; i ++){
		cin >> a >> b >> c;
		double d = dis(a, b, x, y);
		ans = min(ans, d / c);
	}
	
	cout << fixed << setprecision(10);
	cout << ans << '\n';
  
	
	
	
  return 0;
}

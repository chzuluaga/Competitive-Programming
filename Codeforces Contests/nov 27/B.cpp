#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 100005;
ll arr[MAX];

bool cmp(ll x, ll y){
	return x > y;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, a, b;
  
  cin >> n >> a >> b;
  
  for(int i = 0; i < n; i ++)
		cin >> arr[i];
		
	sort(arr, arr + n, cmp);
	ll sumA = 0, sumB = 0;
	
	for(int i = 0; i < a; i ++)
		sumA += arr[i];
	
	for(int i = a; i < a + b; i ++)
		sumB += arr[i];
	
	//cout << sumA << " " << sumB << endl;
	double ans = 0.0;
	
	ans = (1.0 * sumA * b + 1.0 * sumB * a) / (1.0 * a * b);
	sumA = sumB = 0;
	for(int i = 0; i < b; i ++)
		sumA += arr[i];
	
	for(int i = b; i < a + b; i ++)
		sumB += arr[i];
	
	//cout << sumA << " " << sumB << endl;
	ans = max(ans, (1.0 * sumA * a + 1.0 * sumB * b) / (1.0 * a * b));
	
	cout << fixed << setprecision(8);
	cout << ans << '\n';
  return 0;
}

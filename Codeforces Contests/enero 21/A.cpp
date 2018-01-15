#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 105;

int a[MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i ++)
		cin >> a[i];
		
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n;i ++)
		ans += a[n - 1] - a[i];
		
		
	cout << ans << "\n";
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 40005;
pii a[MAX];

bool cmp(pii x, pii y){
	return x.second < y.second;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int w, h, n;
	
	cin >> w >> h >> n;
	
	for(int i = 0; i < n; i ++)
		cin >> a[i].first >> a[i].second;
	
	sort(a, a + n);
	int big = a[0].first;
	big = max(big, 1 + w - a[n - 1].first);
	for(int i = 1; i < n; i ++){
		big = max(a[i].first - a[i - 1].first, big);
	}
	
	sort(a, a + n, cmp);
	int maxi = a[0].second;
	maxi = max(maxi, 1 + h - a[n - 1].second);
	for(int i = 1; i < n; i ++){
		maxi = max(a[i].second - a[i - 1].second, maxi);
	}
	
	cout << (big - 1) * (maxi - 1) << '\n';
  return 0;
}

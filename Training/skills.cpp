#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX	= 100005;
pll a[MAX];

bool cmp (pll x, pll y){
	return x.first > y.first;
}
bool cmp2(pll x, pll y){
	return x.second < y.second;
}


ll up[MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

	int n;
	ll A, m, cf, cm;
	//freopen("skills.in", "r", stdin);
	
	cin >> n >> A >> cf >> cm >> m;
	
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n, cmp);
	
	for(int i = n - 2; i >= 0; i --)
		up[i] = up[i + 1] + (a[i].first - a[i + 1].first) * (n - i - 1);
	
	/*for(int i = 0; i < n; i ++)
		cout << up[i] << " ";
	cout << endl;
	*/
	ll curA = 0, ans = 0, idx = 0, minVal = 0;
	
	for(int i = 0; i < n + 1; i ++){
		
		int lo = i, hi = n - 1, mit;
		
		if(i == n){
			if(curA + cm * A > ans){
				ans = curA + cm * A;
				idx = i;
				minVal = 0;
			}
			continue;
		}
		//cout << "With " << i << " to A " << curA << " m is " <<  m << endl;
		
		while(lo < hi){
			mit = hi + lo;
			mit /= 2;
			
			if(up[mit] <= m){
				hi = mit;
			}else
				lo = mit + 1;
		}
		
		//cout << "best is " << a[lo].first << " " << lo  << endl;
		
		ll curm = m - up[lo];
		ll cant = curm / (n - lo);
		ll curf = cm * (min(A, a[lo].first + cant));
		//cout << "cur A " << curA << " curm " << curm << " curf " << curf << " cant " << cant << endl;
		if(curA + curf > ans){
			ans = curA + curf;
			idx = i;
			minVal = (min(A, a[lo].first + cant));
		}
		
		if(A - a[i].first <= m){
				m -= A - a[i].first;
				curA += cf;
		}else
				break;
	}
	
	for(int i = 0; i < n; i ++){
		if(i < idx){
			a[i].first = A;
		}
		if(a[i].first < minVal)
			a[i].first = minVal;
	}
	
	sort(a, a + n, cmp2);
	cout << ans << '\n';
	for(int i = 0; i < n; i ++)
		cout << a[i].first << ' ';
		
  return 0;
}

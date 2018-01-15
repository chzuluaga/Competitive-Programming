#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 1000005;
char s[MAX];
ll n, a, b, t, w[MAX], h[MAX];
int solve(int idx){
	if(idx < n){
		//lf to rg
		int lo = idx, hi = lo + n - 1, mit;
		ll cost = (n - idx) * a;
		if(cost > t)
			return 0;
		while(lo < hi){
			 mit = lo + hi;
			 mit /= 2;
			 ll c = cost + (hi - lo) * a;
			 ll rotate = min(w[hi] - (lo > 0? w[lo - 1] : 0), c / b);
			 c += rotate * b;
			 cout << " lo = " << lo << " hi = " << hi << " mit = " << mit << " cost = " << c << endl;
			 if(c > t)
				hi = mit - 1;
			 else
				lo = mit;
		}
		if(lo > n)
			return (lo - idx) + 1;
		return (n - idx) + 1 + (lo - idx);
	}else{
		//rg to lf
		int lo = idx, hi = lo - (n - 1), mit;
		ll cost = (idx - n) * a;
		if(cost > t)
			return 0;
		while(lo > hi){
			 mit = lo + hi;
			 mit /= 2;
			 ll c = cost + (lo - hi) * a;
			 ll rotate = min(w[lo] - (hi > 0? w[hi - 1] : 0), c / b);
			 c += rotate * b;
			 
			 cout << mit << " " << c << endl;
			 if(c > t)
				lo = mit - 1;
			 else
				hi = mit;
		}
		if(lo < n)
			return (idx - lo) + 1;
		return (idx - n) + 1 + (idx - lo);
	}																																																																																																								
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("img.in", "r", stdin);
  scanf(LL LL LL LL, &n, &a, &b, &t);
  scanf("%s", s);
  strcat(s, s);
 
  int ans = 0;
  
  for(int i = 0; i < 2 * n; i ++){
		w[i] = (i? w[i - 1] : 0);
		h[i] = (i? h[i - 1] : 0);
		if(s[i] == 'w')
			w[i] ++;
		else
			h[i] ++;
	}
	
  for(int i = 0; i < 2 * n; i ++){
		ans = max(ans, solve(i));	
		cout << "para i= " << i << " " << solve(i) << endl;
	}
	
	printf("%d\n", ans);

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 300005;

ll forw[MAX], rev[MAX], point[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++)
		scanf(LL, &point[i]);
		
	sort(point, point + n);
	
	
	for(ll i = 1; i < n; i ++)
		forw[i] = forw[i - 1] + (i * (point[i] - point[i - 1]));
		
	for(ll i = n - 2; i >= 0; i --)
		rev[i] = rev[i + 1] + ( (n - i - 1) * (point[i + 1] - point[i]));
		
	ll ans = LLONG_MAX, idx = -1;
	
	for(int i = 0; i < n; i ++){
		//cout << forw[i] << " " << rev[i] << endl;
		if(forw[i] + rev[i] < ans){
				ans = forw[i] + rev[i];
				idx = i;
		}
	}
	
	cout << point[idx];
	
	

  return 0;
}

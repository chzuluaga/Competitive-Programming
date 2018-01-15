#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1000005;
ll x[6], y[6];
int main(){
  //ios_base::sycn_with_stdio(false);
  //cin.tie(0);
	int n, m;
  scanf("%d%d",&n, &m);
  if(n < m)
		swap(n,m);
		
  for(int i = 1; i <= n; i ++){
			x[i % 5] ++;
			if(i <= m)
				y[i % 5] ++;
	}
	ll ans = 0;
	for(int i = 0; i < 5; i ++){
		for(int j = 0; j < 5; j ++){
			if((i + j) % 5 == 0)
			{
				ans += x[i] * y[j];
			}
		}
	}
	
	cout << ans << '\n';
		
	
		
  return 0;
}

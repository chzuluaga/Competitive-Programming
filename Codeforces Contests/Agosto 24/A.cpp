#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  ll n, b, d, sum = 0, ans = 0, x;
  
  
  scanf(LL LL LL, &n, &b, &d);
  
  
  for(int i = 0; i < n; i ++){
		scanf(LL, &x);
		if(x > b)
			continue;
		
		sum += x;
		if(sum > d){
			ans ++;
			sum = 0;
		}
		
	}
	
	printf(LL"\n", ans);
		
  
  

  return 0;
}

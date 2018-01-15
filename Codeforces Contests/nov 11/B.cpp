#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;

int price[MAX];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, q, coins;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++)
		scanf("%d", &price[i]);
	sort(price, price + n);
	scanf("%d", &q);
	
	while(q --){
		scanf("%d", &coins);
		
		int lo = 0, hi = n - 1, mit;
		
		while(lo < hi){
			mit = lo + hi + 1;
			mit /= 2;
			
			if(coins >= price[mit])
				lo = mit;
			else
				hi = mit - 1;
		
		}
		int ans = lo + 1;
		if(price[lo] > coins)
			ans --;
			
		printf("%d\n", ans);
	}

  return 0;
}

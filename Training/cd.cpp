#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 30;
int track[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int length, n;
  
  while(~scanf("%d%d", &length, &n)){
		
			for(int i = 0; i < n; i ++)
				scanf("%d", &track[i]);
				
			int ans = 0, r = 0;
			for(int mask = 0; mask < (1<<n); mask ++){
				int sum = 0;
				for(int i = 0; i < n; i ++)
					if(mask & (1<<i))
						sum += track[i];
					
				if(sum <= length && sum > ans){
					ans = sum;
					r = mask;
				}
			}
			
			for(int i = 0; i < n; i ++)
				if(r  & (1<<i))
					printf("%d ", track[i]);
				
			printf("sum:%d\n", ans);
	}

  return 0;
}

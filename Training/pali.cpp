#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 3004;
char s[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int t;
  scanf("%d",&t);
  
  while(t --){
		scanf("%s", s);
		int n = strlen(s);
		int ans = 0, cnt = 0;
		for(int i = 0; i < n; i ++){
			int lf = i - 1, rg = i + 1;
			while(lf >= 0 && rg < n && s[lf] == s[rg])
				lf --, rg ++;
			lf ++, rg --;
			int r = (rg - lf) + 1;
			
			if(r == ans)
				cnt ++;
			else{
				if(r > ans){
					ans = r;
					cnt = 1;
				}
			}
			lf = i, rg = i + 1;
			while(lf >= 0 && rg < n && s[lf] == s[rg])
				lf --, rg ++;
			lf ++, rg --;
			r = (rg - lf) + 1;
			
			if(r == ans)
				cnt ++;
			else{
				if(r > ans){
					ans = r;
					cnt = 1;
				}
			}
		}
		
		printf("%d %d\n", ans, cnt);
	}

  return 0;
}

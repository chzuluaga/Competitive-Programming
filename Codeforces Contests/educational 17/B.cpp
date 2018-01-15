#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 300005;
pair<int, char> mouse[MAX];
char s[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	int a, b, c, n;
	
	scanf("%d%d%d%d", &b, &a, &c, &n);
	for(int i = 0; i < n; i ++){
		scanf("%d%s", &mouse[i].first, s);
		mouse[i].second = s[0];
	}
	
	sort(mouse, mouse + n);
	int cnt = 0;
	ll ans = 0;
	for(int i = 0; i < n; i ++){
		if(mouse[i].second == 'P'){
			if(a){
				cnt ++;
				ans += (ll) mouse[i].first;
				a --;
			}else{
				if(c){
					cnt ++;
					ans += (ll) mouse[i].first;
					c --;
				}
			}
		}else{
			if(b){
				cnt ++;
				ans += (ll)mouse[i].first;
				b --;
			}else{
				if(c){
					cnt ++;
					ans += (ll)mouse[i].first;
					c --;
				}
			}
		}
	}
	printf("%d " LL "\n", cnt, ans);
	
	return 0;
}

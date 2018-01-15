#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int cnt[30], cur[30];
char pass[MAX], ori[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int t;
	
	scanf("%d", &t);
	
	while(t --){
		memset(cur, 0, sizeof(cur));
		memset(cnt, 0, sizeof(cur));
		bool f = false;
		scanf("%s%s", pass, ori);
		int n = strlen(ori);
		int m = strlen(pass);
		for(int i = 0; i < n; i ++)
			cnt[ori[i] - 'a'] ++;
		int ans = 0;
		
		for(int i = 0; i < 26; i ++)
			ans += (cnt[i] == cur[i]);
			
		for(int i = 0; i < n; i ++){
			int c = pass[i] - 'a';
			cur[c] ++;
			if(cur[c] == cnt[c])
				ans ++;
			if(cur[c] - 1 == cnt[c])
				ans --;
		}
		
		if(ans == 26){
			printf("YES\n");
			continue;
		}
		for(int i = n; i < m && !f; i++){
			int c = pass[i] - 'a';
			int prev = pass[i - n] - 'a';
			// remove i - n;
			cur[prev] --;
			if(cur[prev] == cnt[prev])
				ans ++;
			if(cur[prev] + 1 == cnt[prev])
				ans --;
			
			// add i	
			cur[c] ++;
			if(cur[c] == cnt[c])
				ans ++;
			if(cur[c] - 1 == cnt[c])
				ans --;
			
			if(ans == 26){
				printf("YES\n");
				f = true;
			}
		}
		if(!f)
			printf("NO\n");
	}
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1005;
int a[MAX], vis[MAX];

void solve(int cur){
	if(vis[cur])
		return;
	vis[cur] = true;
	solve(a[cur]);
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, t;
  scanf("%d", &t);
  
  while(t --){
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			scanf("%d", &a[i]);
			a[i] --;
		}
			
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i ++){
			if(!vis[i]){
				ans ++;
				solve(i);
			}
			
		}
		printf("%d\n", ans);
	}

  return 0;
}

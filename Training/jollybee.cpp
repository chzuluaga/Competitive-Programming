#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
vector<int> seg[15];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int t, n, m, x;
	scanf("%d", &t);
	
	while(t --){
		scanf("%d%d", &n, &m);
		
		for(int i = 0; i <= n; i ++)
			seg[i].clear();
			
		for(int i = 0; i < (1<<n); i ++)
			seg[0].pb(1);

		for(int i = 0; i < m; i++){
				scanf("%d", &x);
				seg[0][x - 1] = 0;
		}
		int cur = 0, ans = 0;
		
		while(seg[cur].size() > 1){
		
			for(int i = 0; i < (int)seg[cur].size() ; i += 2){
				int fs = seg[cur][i];
				int sc = seg[cur][i + 1];
			//	cout << fs << " " << sc << endl;
				if(fs && !sc)
					ans ++;
				if(!fs && sc)
					ans ++;
				seg[cur + 1].pb(fs | sc);
			}
			cur ++;
		}
		printf("%d\n", ans);
	}
  return 0;
}

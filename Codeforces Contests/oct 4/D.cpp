#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1000006;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, k;
  
  scanf("%d%d", &n, &k);
	vector< pii > e;
  for(int i = 0; i < n; i ++){
		int st, fn;
		scanf("%d%d", &st, &fn);
		e.pb(mp(st,0));
		e.pb(mp(fn, 1));
	}
	
	sort(e.begin(), e.end());
	vector< pii > ans;
	int seg = 0, prev = 0;
	for(int i = 0; i < (int) e.size(); i ++){
		int cur = e[i].first;
		int type = e[i].second;
		
		if(type == 0){
			seg ++;
			if(seg == k)
				prev = cur;
		}else{
			seg --;
			if(seg == k - 1){
				ans.pb(mp(prev, cur));
			}
		}
		
	}
	
	printf("%d\n", (int)ans.size());
	
	for(int i = 0; i < (int)ans.size(); i ++)
		printf("%d %d\n", ans[i].first , ans[i].second);
	

  return 0;
}

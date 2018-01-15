#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
int c[MAX] ,ansSocket[MAX], ansPc[MAX];
pii s[MAX];
map<int, int> pc, idx; 
vector<int> comp[MAX];
int inf = 1e9 + 3;
int main(){
  //freopen("E.in", "r", stdin);
  int n, m, pos = 0, cont = 0, sol = 0;
  scanf("%d%d", &n, &m);
  
  for(int i = 0; i < n; i ++){
		scanf("%d", &c[i]);
		int id;
		if(idx.count(c[i])){
			id = idx[c[i]];
		}else{
			id = pos ++;
			idx[c[i]] = pos - 1;
		}
		
		comp[id].pb(i);
		pc[c[i]] ++;
	}
	for(int i = 0; i < m; i ++){
		scanf("%d", &s[i].first);
		s[i].second = i;
	}
	sort(s, s + m);
	for(int i = 0; i < m; i ++){
		int cur = s[i].first;
		while(cur > 1 && pc[cur] <= 0){
			if(cur & 1)	cur ++;
			cur /= 2;
			ansSocket[s[i].second] ++;
		}
		
		if(pc[cur]){
			cont ++;
			sol += ansSocket[s[i].second];
			pc[cur] --;
			int id = idx[cur];
			int last = comp[id].back();
			ansPc[last] = s[i].second + 1;
			comp[id].pop_back();
		}else
			ansSocket[s[i].second] = 0;
	}
	
	printf("%d %d\n", cont, sol);
	
	for(int i = 0; i < m; i ++)
		printf("%d ", ansSocket[i]);
	printf("\n");
	for(int i = 0; i < n; i ++)
		printf("%d ", ansPc[i]); 
  return 0;
}

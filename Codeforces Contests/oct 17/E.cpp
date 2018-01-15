#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
int c[MAX], s[MAX], ansSocket[MAX], ansPc[MAX];
map<int, int> pc, idx; 
vector<int> comp[MAX];
int inf = 1e9 + 3;

struct socket{
	int ind, val, used;
	
	socket(int _ind, int _val){
		used = 0;
		val = _val;
		ind = _ind;
	}
	
	bool operator <(socket other)const{
		return used > other.used;
	}
	
};
int main(){
  //freopen("E.in", "r", stdin);
  int n, m, s, pos = 0, cont = 0, sol = 0;
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
	
	priority_queue< socket > q;
	for(int i = 0; i < m; i ++){
		scanf("%d", &s);	
		q.push(socket(i + 1, s));
	}
	
	while(!q.empty()){
		socket cur = q.top();
		q.pop();
		if(pc[cur.val]){
			pc[cur.val] --;
			int id = idx[cur.val];
			int newId = comp[id].back();
			comp[id].pop_back();
			ansPc[newId] = cur.ind;
			cont ++;
			sol += cur.used;
			ansSocket[cur.ind - 1] = cur.used;
		}else{
			if(cur.val == 1)
				continue;
			
			cur.val = (cur.val + 1) / 2;
			cur.used ++;
			q.push(cur);
		}
	}
	printf("%d %d\n", cont , sol);
	for(int i = 0; i < m; i ++)
		printf("%d ", ansSocket[i]);
	printf("\n");
	for(int i = 0; i < n; i ++)
		printf("%d ", ansPc[i]);
	printf("\n");
	
	
  return 0;
}

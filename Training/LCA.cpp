#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 5005;
vector<int> graph[MAX];
vector<int> E, L;
int H[MAX];
int dis[MAX];

struct node{
	node *nl, *nr;
	int lf, rg;
	int val;
	
	node(){
		val = 0;
	}
	void create(int from, int to){
		lf = from;
		rg = to;
		
		if(from == to)
			return;
		
		nl = new node();
		nr = new node();
		nl -> create(from, (from + to) / 2);
		nr -> create(((from + to) / 2) + 1, to);
	}
	void insert(int from, int to, int idx){
		if(from == lf && to == rg){
			val = idx;
			return;
		}
		
		if(to < nr->lf){
			nl -> insert(from, to, idx);
		}else{
			nr -> insert(from, to, idx);
		}
		
		int ansL = nl -> val;
		int ansR = nr -> val;
		if(L[ansL] <= L[ansR])
			val = ansL;
		else
			val = ansR;
	}
	
	int get(int from, int to){
		if(from > to)
			while(true);
			
		if(from == lf && to == rg)
			return val;
		
		if(to < nr -> lf){
			return nl -> get(from, to);
			
		}
		
		if(from > nl->rg){
			return nr -> get(from, to);
		}
		int ansL = nl -> get(from, nl -> rg);
		int ansR = nr -> get(nr -> lf, to);
		if(L[ansL] <= L[ansR])
			return ansL;
		return ansR;
	
	}
	
};

int sp[50][MAX];

void dfs(int cur, int p, int lvl, int d){
	dis[cur] = d;
	H[cur] = (int) E.size();
	E.pb(cur);
	L.pb(lvl);
	sp[0][cur] = p;
	for(int i = 0; i < (int)graph[cur].size(); i ++){
		int nei = graph[cur][i];
		if(nei == p)
			continue;
		dfs(nei, cur, lvl + 1, d + 1);
		E.pb(cur);
		L.pb(lvl);
	}
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, m, u, v;
  
  while(~scanf("%d", &n)){
		if(!n)
			break;
			for(int i = 0; i < n; i ++)
				graph[i].clear();
				
			for(int i = 0; i < n - 1; i ++){
				scanf("%d %d", &u, &v);
				u --, v --;
				graph[u].pb(v);
				graph[v].pb(u);
			}
			L.clear();
			E.clear();
			scanf("%d", &m);
		//	cout << n << " " << m<< endl;
			
			dfs(0, 0, 0, 0);
			
			node root;
			
			root.create(0, (int)E.size() - 1);
			
			for(int i = 0; i < (int)E.size(); i ++){
				root.insert(i, i, i);
			}
			
			for(int i = 0; i < m;  i++){
				scanf("%d %d", &u, &v);
				u -- , v --;
				int idx = root.get(min(H[u], H[v]), max(H[u], H[v]));
				idx = E[idx];
				
				cout <<idx + 1 <<" es lca entre u y v"<< endl; 
			}
	}
  return 0;
}

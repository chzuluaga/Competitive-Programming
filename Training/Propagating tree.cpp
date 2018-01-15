#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
int a[MAX], start[MAX], finish[MAX], nxt[MAX], nxtFinish[MAX], group[MAX];
vector<int> g[MAX], v0, v1;

void plainGraph(int cur, int p){
	if(group[cur] == 1){
		group[cur] = 1;
		//v1.pb(cur);
		v1.pb(a[cur]);
		start[cur] = (int)v1.size() - 1;
	}else{
		group[cur] = 0;
		//v0.pb(cur);
		v0.pb(a[cur]);
		start[cur] = (int)v0.size() - 1;
	}
	
	
	for(int i = 0; i < (int) g[cur].size(); i ++){
		int nei = g[cur][i];
		if(nei != p){
			if(nxt[cur] == -1)
				nxt[cur] = nei;
				
			group[nei] = group[cur] ^ 1;
			plainGraph(nei, cur);
		
			nxtFinish[cur] = finish[nei];
		}
	}
	if(group[cur] == 0)
		finish[cur] =	(int)v0.size() - 1;
	else
		finish[cur] = (int)v1.size() - 1;
}

struct node{
	node *L, *R;
	int lf, rg;
	ll sum;
	ll lazy;
	
	node(){
		lazy = 0;
		sum = 0;
		L = NULL;
		R = NULL;
	}
	
	void create(int from, int to, int gr){
		//cout << "creando " << from << " " << to << " group " << gr << endl;
		lf = from;
		rg = to;
		if(from == to){
			if(gr == 0)
				sum = v0[from];
			else
				sum = v1[from];
			return;
		}
		
		L = new node();
		R = new node();
		L -> create(from, (from + to)/2, gr);
		R -> create((from + to) / 2 + 1, to, gr);
	}
	
	void expand(){
		if(lazy == 0)
			return;
			
		if(L != NULL){
			if(L -> lf == L -> rg)
				L -> sum += lazy;
			L -> lazy += lazy;
		}
		if(R != NULL){
			if(R -> lf == R -> rg)
				R -> sum += lazy;
			R -> lazy += lazy;
		}
		lazy = 0;
	}
	
	void update(int from, int to, ll val){
		//cout << "buscando " << from << " - " << to << " en el nodo " << lf << " " << rg << endl;
		expand();
		if(from == lf && to == rg){
			if(from == to){
				sum += val;
			//	cout << "sumamos " << val << " " << from << " sum = " << sum << endl;
			}
			lazy += val;
			return;
		}
		
		if(to < R -> lf){
			L -> update(from, to, val);
		}else{
			if(from > L -> rg){
				R -> update(from, to, val);
			}else{
				L -> update(from, L -> rg, val);
				R -> update(R -> lf, to, val);
			}
		}
	}
	
	int get(int from){
		int to = from;
		
		expand();
		
		if(from == lf && to == rg)
			return sum;
			
		
		if(to < R -> lf)
			return L -> get(from);
	
		return R -> get(from);
	
	}
	
};

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	//freopen("ptree.in", "r", stdin);
	int n, m, x, y, u, v, type;
	
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
		
	for(int i = 0; i < n - 1; i ++){
		scanf("%d %d", &u, &v);
		u --, v --;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(nxt, -1, sizeof(nxt));
	plainGraph(0, 0);
	node even, odd;
	even.create(0, v0.size() - 1, 0);
	if(v1.size())
		odd.create(0, v1.size() - 1, 1);
	for(int i = 0; i < m; i ++){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d%d", &x, &y);
			x --;
			if(group[x] == 0){
				even.update(start[x], finish[x], y);
				if(nxt[x] != -1)
					odd.update(start[nxt[x]], nxtFinish[x], -y);
			}else{
			//	cout << " ENTRO " << start[x] << " " << finish[x] << endl;
				odd.update(start[x], finish[x], y);
				
				if(nxt[x] != -1)
					even.update(start[nxt[x]], nxtFinish[x], -y);
			}
		}else{
			scanf("%d", &x);
			x --;
			//cout << "x = " << x << endl;
			if(group[x] == 0){
				//cout << " buscando even " << start[x] << endl;
				printf("%d\n", even.get(start[x]));
			}else{
				//cout << " buscando odd " << start[x] << endl;
				printf("%d\n", odd.get(start[x]));
			}
		}
	}
	
	
	/*for(int i = 0; i <(int) v0.size(); i ++)
		cout << v0[i] + 1 << " ";
	cout << endl;
	
	for(int i = 0; i < (int) v1.size(); i ++)
		cout << v1[i] + 1<< " ";
	cout << endl;
	
	for(int i = 0; i < n; i ++)
		cout << start[i] << " ";
		
	cout << endl;
	
	for(int i = 0; i < n; i ++)
		cout << finish[i] << " ";
		
	cout << endl;
	
	for(int i = 0; i < n; i ++)
		cout << nxt[i] << " ";
		
	cout << endl;
  */
  return 0;
}

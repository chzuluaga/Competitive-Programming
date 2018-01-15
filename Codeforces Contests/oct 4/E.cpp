#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1000006;
int p[MAX], cont[MAX], ans[MAX], parent[MAX], rnk[MAX];
bool visit[MAX], seen[MAX];
vector<int> comp[MAX];
int dis[20][MAX];

int find(int x){
	if(x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	
	if(x == y)
		return;
	
	if(rnk[x] > rnk[y]){
		parent[y] = x;
		cont[x] += cont[y];
	}
	else{
		parent[x] = y;
		cont[y] += cont[x];
		if(rnk[y] == rnk[x])
			rnk[y] ++;
	}
}

bool cmp(pii x, pii y){
	return x.first > y.first;
}

void solveOdd(int c){
	int sz = (int) comp[c].size();
	int d = (sz + 1) / 2;
	//cout << "d es " << d << endl;
	for(int i = 0; i < (int)comp[c].size(); i ++){
		int cur = comp[c][i];
		for(int j = 0; j < 20; j ++){
			if(d & (1<<j))
				cur = dis[j][cur];
		}
	//	cout << comp[c][i] + 1 << " da " << cur + 1 << endl; 
		ans[comp[c][i]] = cur;
	}
}

void solveEven(int a, int b){
	int sz = (int)comp[a].size();
	for(int i = 0; i <sz; i ++){
		int curA = comp[a][i];
		int curB = comp[b][i];
		ans[curA] = curB;
		ans[curB] = p[curA];
	}
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("e.in", "r", stdin);
  int n, x;
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++){
		parent[i] = i;
		rnk[i] = 0;
		cont[i] = 1;
	}
  
  for(int i = 0; i < n; i ++){
		scanf("%d", &x);
		x --;
		p[i] = x;
		dis[0][i] = x;
		merge(x, i);
	}
	
	for(int h = 1; h < 20; h ++){
		for(int i = 0; i < n; i ++){
			dis[h][i] = dis[h - 1][dis[h - 1][i]];
		}
	}
	
	vector< pii > v;
	for(int i = 0; i < n; i ++){
		int x = find(i);
		//cout << i + 1 << " " << x + 1 << " " << cont[x] << endl;
		if(visit[x])	continue;
		while(!seen[i]){
			seen[i] = true;
			comp[x].pb(i);	
			i = p[i];
		}
		visit[x] = true;
		v.pb(mp(cont[x], x));
	}
	
	sort(v.begin(), v.end(), cmp);
	//cout << (int)v.size() << '\n';
	for(int i = 0; i < (int)v.size(); i ++){
		int cur = v[i].second;
		int c = v[i].first;
		
		//cout << cur << " -- " << c << endl;
		if(c & 1){
			solveOdd(cur);
		}else{
			//cout << c << " _ " << v[i + 1].first << endl;
			if(i + 1 < (int)v.size() && v[i + 1].first == c){
				solveEven(cur, v[i + 1].second);
				i ++;
			}else{
				cout << "-1\n";
				return 0;
			}
		}
	}
	
	for(int i = 0; i < n; i ++)
		printf("%d ", ans[i] + 1);
	
	
  return 0;
}


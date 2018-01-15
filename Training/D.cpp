#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 100005;
int ins[MAX][4], ans[MAX], ma[1005][1005], total[1005], cont = 0;
bool flip[1005];
vector<int> g[MAX];
int n, m, q;

void go(int u){
	ans[u] = cont;
	for(int i = 0; i < (int)g[u].size(); i ++){
		int v = g[u][v];
		int t = ins[v][0];
		if(t == 1){
			int row = ins[v][1];
			int col = ins[v][2];
			int val = ma[row][col];
			if(flip[row])	val ^= 1;
			
			if(val == 0){
				cont ++;
				total[row] ++;
				ma[row][col] ^= 1;
				go(v);
				ma[row][col] ^= 1;
				total[row] --;
				cont --;
			}else{
				go(v);
			}
		}
		if(t == 2){
			int row = ins[v][1];
			int col = ins[v][2];
			int val = ma[row][col];
			if(flip[row])	val ^= 1;
			
			if(val == 1){
				cont --;
				total[row] --;
				ma[row][col] ^= 1;
				go(v);
				ma[row][col] ^= 1;
				total[row] ++;
				cont ++;
			}else{
				go(v);
			}
		}
		if(t == 3){
			int row = ins[v][1];
			flip[row] ^= 1;
			cont -= total[row];
			total[row] = m - total[row];
			cont += total[row];
			go(v);
			flip[row] ^= 1;
			cont -= total[row];
			total[row] = m - total[row];
			cont += total[row];
		}
		if(t == 4){
			go(v);
		}
	}
}
int main(){
	freopen("d.in", "r", stdin);
  scanf("%d%d%d", &n, &m, &q);
  
  for(int i = 1; i <= q; i ++){
		scanf("%d", &ins[i][0]);
		if(ins[i][0] == 1 || ins[i][0] == 2){
			scanf("%d%d", &ins[i][1], &ins[i][2]);
			g[i - 1].pb(i);
		}else{
			scanf("%d", &ins[i][1]);
			if(ins[i][0] == 3)	
				g[i - 1].pb(i);
			else
				g[ins[i][1]].pb(i);
		}
	}
	//memset(ans, -1, sizeof(ans));
	go(0);
	
	for(int i = 1; i <= q; i ++)	printf("%d\n", ans[i]);
	

  return 0;
}

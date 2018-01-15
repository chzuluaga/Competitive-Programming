#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 15;
char puzzle[MAX][MAX];
int table[MAX][MAX], n, m;
vector< pair<int, string> > across, down;
string cur = "";
void solveA(int x, int y, int val){
	if(y == m){
		if(val != -1)
			across.pb(mp(val, cur));
		val = -1;
		cur = "";
		y = 0, x ++;
	}
	if(x == n){
		if(val != -1)
			across.pb(mp(val, cur));
		return;
	}
	if(cur.size() == 0 && puzzle[x][y] != '*')
		val = table[x][y];
	
	if(puzzle[x][y] == '*'){
		if(val != -1)
			across.pb(mp(val, cur));
		cur = "";
		val = -1;
	}else{
		cur += puzzle[x][y];
	}
	solveA(x, y + 1, val);
}
void solveD(int x, int y, int val){
	if(x == n){
		y ++, x = 0;
		if(val != -1)
			down.pb(mp(val, cur));
		cur = "";
		val = -1;
	}
	if(y == m){
		if(val != -1)
			down.pb(mp(val, cur));
		return;
	}
	if(cur.size() == 0 && puzzle[x][y] != '*')
		val = table[x][y];
	
	if(puzzle[x][y] == '*'){
		if(val != -1)
			down.pb(mp(val, cur));
		cur = "";
		val = -1;
	}else{
		cur += puzzle[x][y];
	}
	solveD(x + 1, y, val);
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	//freopen("cross.in", "r", stdin);
  
  int tc = 1;
  while(~scanf("%d", &n) && n){
		scanf("%d", &m);
		across.clear();
		down.clear();
		if(tc > 1) printf("\n");
		for(int i = 0; i < n; i ++)
			scanf("%s", puzzle[i]);
			
		char ac[] = "Across", puz[] = "puzzle #", dow[] = "Down";
		
		int cnt = 1;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(puzzle[i][j] == '*')
					continue;
				if(i == 0 || j == 0 || puzzle[i][j - 1] == '*' || puzzle[i - 1][j] == '*')
					table[i][j] = cnt ++;
			}
		}
		solveA(0, 0, -1);
		cur = "";
		solveD(0, 0, -1);
		
		printf("%s%d:\n",puz, tc ++);
		printf("%s\n",ac);
		sort(across.begin(), across.end());
		sort(down.begin(), down.end());
		for(int i = 0; i < (int)across.size(); i ++){
			printf(" ");
			if(across[i].first < 10)
				printf(" ");
			printf("%d.%s\n", across[i].first, across[i].second.c_str());
		}
		
		printf("%s\n", dow);
		for(int i = 0; i < (int)down.size(); i ++){
			printf(" ");
			if(down[i].first < 10)
				printf(" ");
			printf("%d.%s\n", down[i].first, down[i].second.c_str());
		}
	}

  return 0;
}

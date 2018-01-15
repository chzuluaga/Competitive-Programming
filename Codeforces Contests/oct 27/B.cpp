#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 505;
int ma[MAX][MAX];
char s[100005];
int ans[100005];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m, x0, y0;
  scanf("%d%d%d%d", &n, &m, &x0, &y0);
  scanf("%s", s);
  int N = strlen(s);
	ans[0] = 1;
	ma[x0][y0] = 1;
	vector< int > bomb;
	bomb.pb( 0 );
	int cont = 1;
	for(int i = 0; i < N; i ++){
		if(s[i] == 'U'){
			if(x0 > 1){
				x0 --;
			}
		}
		if(s[i] == 'D'){
			if(x0 < n)
				x0 ++;
		}
		if(s[i] == 'L'){
			if(y0 > 1)
				y0 --;
		}
		if(s[i] == 'R'){
			if(y0 < m)
				y0 ++;
		}
		if(ma[x0][y0] == 0){
			bomb.pb(i + 1);
			cont ++;
		}
		ma[x0][y0] = 1;
	}
	ans[N] = (n * m) - cont;
	int cur = N;
	while(bomb.size() && cur){
		//cout << bomb.back() << " " << cur << endl;
		if(bomb.back() == cur){
			ans[cur] ++;
			bomb.pop_back();
		}
		cur --;
	}
	
	for(int i = 0; i <= N; i ++)
		printf("%d ", ans[i]);
		
  return 0;
}

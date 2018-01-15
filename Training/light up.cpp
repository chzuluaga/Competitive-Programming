#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 8;
int ma[MAX][MAX], n, m;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int x, y, z;
	while(true){
		scanf("%d%d", &n, &m);
		
		if(n == 0 && m == 0)
			break;
		
		for(int i = 0; i < m; i ++){
			scanf("%d%d%d", &x, &y, &z);
			ma[x][y] = z;
		}
	}
  return 0;
}

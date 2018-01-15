#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int solve(int x, int y){
	if(x > y) swap(x, y);
	if(x == 1)	return y;
	if(x == 2){
		return (((y + 3) / 4) * 4) + ((y - 1) % 4 == 0 ? -2: 0);
	}	
	return (x * y + 1) / 2;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m;
  while(scanf("%d%d",&n, &m)){
		if(n == 0 && m == 0)	break;
		int ans =	solve(n, m);
		printf("%d knights may be placed on a %d row %d column board.\n", ans, n, m);
	}

  return 0;
}

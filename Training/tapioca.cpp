#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 2005;
struct coor{
	int x, y, t;
	bool operator <(coor o)const{
		return t < o.t;
	}
}a[MAX];
int memo[MAX][MAX], n;
int dis(int i, int j){
	return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

int solve(int cur, int idx){
	if(idx == n){
		return 0;
	}
	int &ans = memo[cur][idx];
	if(ans != -1)
		return ans;
	ans = solve(cur, idx + 1);
	if(dis(cur, idx) <= a[idx].t - a[cur].t){
		ans = max(ans, 1 + solve(idx, idx + 1));
	}
	return ans;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("tapioca.in", "r", stdin);
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  a[0].x = a[0].y = 6;
  a[0].t = 0;
  for(int i = 1; i <= n; i ++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].t);
	n ++;
	sort(a + 1, a + n);
	
	int ans = solve(0, 1);
	printf("%d\n", ans);

  return 0;
}

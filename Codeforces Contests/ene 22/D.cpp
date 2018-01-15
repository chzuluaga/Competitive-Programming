#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 100005;
ll a[MAX], inf = LLONG_MAX / 10, memo[MAX];;
int n, cont = 0;
int get(ll val){
	
	int lo = 0, hi = n, mit;
	
	while(lo < hi){
		mit = lo + hi + 1;
		mit /= 2;
		
		if(a[mit] < val)
			lo = mit;
		else
			hi = mit - 1;
	}
	
	if(a[lo] >= val) lo --;
	//cout << "buscando menor para " << val <<  " " << lo << endl;
	return lo;
}
ll solve(int cur){
	if(cur == n)
		return 0;
		
	if(cur < 0)
		return 0;
		
	ll &ans = memo[cur];
	if(ans != -1)
		return ans;
		
	ans = inf;
	// one trip
	ll fs = 20 + solve(cur - 1);
	// 90 min
	int prev = get(a[cur] - 89);
	ll sc =  50 + solve(prev);
	// 1 day
	prev = get(a[cur] - 1439);
	ll th =  120 + solve(prev);
	
	ans = min(fs, min(sc, th));
	
	return ans;
}

int main(){
  //freopen("d.in", "r",stdin);
  scanf("%d", &n);
  memset(memo, -1, sizeof(memo));
  for(int i = 0; i < n; i ++)
		scanf(LL , &a[i]);
			
	
	//printf(LL"\n",solve(0));
	ll sum = 0;
	for(int i = 0; i < n; i ++){
		printf(LL "\n", solve(i) - sum );
		sum += solve(i) - sum;
	}
	
  return 0;
}

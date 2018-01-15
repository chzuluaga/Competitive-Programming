#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;

ll a[MAX], cont[MAX], ans = 0;
bool des[MAX];
int perm[MAX], parent[MAX], rnk[MAX];

int find(int x){
	if(x == parent[x])
		return x;
		
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	
	int xr = find(x);
	int yr = find(y);
	
	if(xr == yr)
		return;
		
	if(rnk[xr] > rnk[yr]){
		parent[yr] = xr;
		cont[xr] += cont[yr];
		ans = max(cont[xr], ans);
	}else{
		parent[xr] = yr;
		cont[yr] += cont[xr];
		ans = max(cont[yr], ans);
		if(rnk[xr] == rnk[yr])
			rnk[yr] ++;
	}
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
		scanf(LL, &a[i]);
		parent[i] = i;
		rnk[i] = 0;
		cont[i] = a[i];
	}
		
	for(int i = n - 1; i >= 0; i --)
		scanf("%d", &perm[i]);
		
	vector<ll> v;
	v.pb(0);
	
	for(int i = 0; i < n; i ++){
		int cur = perm[i];
		cur --;
		des[cur] = 1;
		ans = max(ans, a[cur]);
		
		if(cur - 1 >= 0 && des[cur - 1]){
			merge(cur, cur - 1);
		}
		if(des[cur + 1]){
			merge(cur, cur + 1);
		}
		v.pb(ans);
	}
	
	for(int i = (int)v.size() - 2; i >= 0; i --)
		printf(LL "\n", v[i]);
	
  

  return 0;
}

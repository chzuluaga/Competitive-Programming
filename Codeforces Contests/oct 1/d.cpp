#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 50005;
vector< pair<ll, int> > num;
ll a[MAX];
bool visit[MAX];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++)
		scanf(LL , &a[i]);
		
	sort(a, a + n);
	for(int i = 0; i < n; i ++){
		ll cur = a[i];
		num.pb(mp(cur, i));
			
		while(cur > 1){
			if(cur & 1){
				cur --;
			}
			cur /= 2ll;
			num.pb(mp(cur, i));
		}
	}
	
	sort(num.begin(), num.end());
	
	int lo = 0, hi = (int)num.size() - 1, mit;
	
	while(lo < hi){
		mit = (lo + hi) / 2;
		memset(visit, 0, sizeof(visit));
		ll cur = num[mit].first + 1;
		int cont = 0;
		for(int i = mit; i >= 0; i --){
			ll val = num[i].first;
			int idx = num[i].second;
			if(!visit[idx] && val < cur){
				visit[idx] = true;
				cur = val;
				cont ++;
			}
			
			if(cont == n)
				break;
		}
		if(cont == n)
			hi = mit;
		else
			lo = mit + 1;
	}
	
	
	memset(visit, 0, sizeof(visit));
	
	ll cur = num[lo].first + 1;
	int cont = 0;
	for(int i = lo; i >= 0; i --){
		ll val = num[i].first;
		int idx = num[i].second;
		if(!visit[idx] && val < cur){
			visit[idx] = true;
			cur = val;
			printf(LL "\n", val);
			cont ++;
		}
		if(cont == n)
			break;
	}
	

  return 0;
}

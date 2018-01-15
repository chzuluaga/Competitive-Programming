#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, x;
  scanf("%d", &n);
  vector<int> v;
  for(int i = 0; i < n; i ++){
		scanf("%d", &x);
		v.pb(x);
	}
	sort(v.begin(), v.end());
	int ans = 0, cur = 0, cont = 0;
	for(int i = 1; i < (int)v.size(); i ++){
		if(cont > n)
			break;
		if(v[i] > v[cur]){
			ans ++;
			cur = i;
			cont = 0;
		}else{
			if(v[i] == v[cur]){
				v.pb(v[i]);
				cont ++;
			}else{
				cur = i;
				cont = 0;
			}
		}
	}
	
	printf("%d\n", ans);

  return 0;
}

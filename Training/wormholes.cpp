/*
 PROB: wormhole
 LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 14;
pii w[MAX];
vector<int> v;
int n, ans = 0, par[MAX];
bool vis[MAX];
bool solve(){
	
	for(int i = 0; i < n; i += 2){
		par[v[i]] = v[i + 1];
		par[v[i + 1]] = v[i];
	}
	
	for(int i = 0; i < n; i ++){
		int cur = v[i];
		memset(vis, false, sizeof(vis));
	//	cout << "proabando con " << v[i] << endl;
		while(true){
			//cout << cur << endl;
			vis[cur] = true;	
			cur = par[cur];
			//cout << cur << endl;
			
			if(cur + 1 == n || w[cur + 1].first != w[cur].first)
				break;
			if(vis[cur + 1]){
		//		cout << "yes en " << v[i] << endl;
				return true;
			}
			
			cur ++;	
		}
	}
	
	return false;
}

void go(int u, int mask){
	if(u == n){
		if(solve()){
			ans ++;
		/*	cout << "encontro respuesta " << endl;
			for(int i = 0; i < n; i ++){
				cout << w[v[i]].first << " " << w[v[i]].second << endl;
			}
			cout << "fin respuesta " << endl;*/
		}
		
		return;
	}
	if(mask & (1<<u)){
		go(u + 1, mask);
		return;
	}
	v.pb(u);
	for(int i = u + 1; i < n; i ++){
		if(mask & (1<<i))
			continue;
		v.pb(i);
		mask |= 1<<i;
		go(u + 1, mask);
		mask ^= 1<<i;
		v.pop_back();
	}
	v.pop_back();
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("wormhole.in","r", stdin);
  freopen("wormhole.out", "w",stdout);
  scanf("%d", &n);
  for(int i = 0; i < n; i ++)
		scanf("%d%d", &w[i].second, &w[i].first);
	
	sort(w, w + n);
	
	/*for(int i = 0; i < n; i ++)
		cout << w[i].first << " "<< w[i].second << endl;
	*/
	go(0, 0);
	
	printf("%d\n", ans);
	
  return 0;
}

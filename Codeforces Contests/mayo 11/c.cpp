#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
struct f{
	int b, cost;
	char t[3];
}arr[MAX];

bool cmp(int x, int y){
	return arr[x].cost < arr[y].cost;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, c, d;
	
	scanf("%d%d%d", &n, &c, &d);
	
	for(int i = 0; i < n; i ++)
		scanf("%d%d%s", &arr[i].b, &arr[i].cost, arr[i].t);
	set< pair<pii, int> > dia, coin;
	set< pair<pii, int> >::iterator it;
	vector<int> vdia, vcoin;
	
	for(int i = 0; i < n; i ++){
		if(arr[i].t[0] == 'D'){
			dia.insert(mp(mp(-arr[i].b,arr[i].cost), i));
			vdia.pb(i);
		}else{
			coin.insert(mp(mp(-arr[i].b,arr[i].cost), i));
			vcoin.pb(i);
		}
	}
	
	sort(vdia.begin(), vdia.end(), cmp);
	sort(vcoin.begin(), vcoin.end(), cmp);
	int ans = 0;
	for(int i = 0; i < (int)vcoin.size(); i ++){
		int cur = vcoin[i];
		int price = arr[cur].cost;
		int beauty = arr[cur].b;
		int curC = c - price;
		int curD = d;
		if(curC < 0)
			break;
			
		it = coin.find(mp(mp(-beauty, price), cur));
		if(it != coin.end())
			coin.erase(it);
		
		while(!coin.empty() && (*coin.begin()).first.second > curC){
			coin.erase(coin.begin());
		}
		while(!dia.empty() && (*dia.begin()).first.second > curD){
			dia.erase(dia.begin());
		}
		
		if(!coin.empty()){
			ans = max(beauty + (-(*coin.begin()).first.first), ans);
		}
		if(!dia.empty()){
			ans = max(beauty + (-(*dia.begin()).first.first), ans);
		}
	}
	
	dia.clear();
	coin.clear();
	
	for(int i = 0; i < n; i ++){
		if(arr[i].t[0] == 'D'){
			dia.insert(mp(mp(-arr[i].b,arr[i].cost), i));
		}else{
			coin.insert(mp(mp(-arr[i].b,arr[i].cost), i));
		}
	}
	
	
	for(int i = 0; i < (int)vdia.size(); i ++){
		int cur = vdia[i];
		int price = arr[cur].cost;
		int beauty = arr[cur].b;
		int curD = d - price;
		int curC = c;
		if(curD < 0)
			break;
		it = dia.find(mp(mp(-beauty, price), cur));
		if(it != dia.end())
			dia.erase(it);
		
		while(!coin.empty() && (*coin.begin()).first.second > curC){
			coin.erase(coin.begin());
		}
		while(!dia.empty() && (*dia.begin()).first.second > curD){
			dia.erase(dia.begin());
		}
		
		if(!coin.empty()){
			ans = max(beauty + (-(*coin.begin()).first.first), ans);
		}
		if(!dia.empty()){
			ans = max(beauty + (-(*dia.begin()).first.first), ans);
		}
	}
	
	printf("%d\n", ans);
	

  return 0;
}

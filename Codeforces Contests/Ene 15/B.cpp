#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1005;

string a[MAX], b[MAX];

map<string, int> rep, used;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  
  cin >> n >> m;
  
  vector<string> v;
  
  for(int i = 0; i < n; i ++){
		cin >> a[i];
		rep[a[i]] = 1;
	}
	
	for(int i = 0; i < m; i ++){
		cin >> b[i];
		if(rep.count(b[i])){
			v.pb(b[i]);
			rep[b[i]] = 2;
		}
	}
	int lf = 0, rg = 0;
	for(int i = 0; ; i ++){
		//cout << lf << " " << rg << endl;
		if(i & 1){
			if((int)v.size() != 0){
				used[v.back()] = 1;
				v.pop_back();
			}else{
				//cout << "entro" << endl;
				while(rg < m && (used.count(b[rg]) != 0  || rep[b[rg]] == 2)){
					rg ++;
				}
				if(rg == m){
					cout << "YES\n";
					return 0;
				}
				rg ++;
			}
		}else{
			if((int)v.size() != 0){
				used[v.back()] = 1;
				v.pop_back();
			}else{
				while(lf < n && (used.count(a[lf]) != 0  || rep[a[lf]] == 2)){
					lf ++;
				}
				if(lf == n){
					cout << "NO\n";
					return 0;
				}
				lf ++;
			}
		}
	}
	
		return 0;
}

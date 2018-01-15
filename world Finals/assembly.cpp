#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAX = 40005;
string a[MAX];
int oo = 2 * 26 + 2;

int get(char x, char y){
	if(x == '0' && y == '0')
		return oo;
	
	if(y == '+')
		return x - 'A';
	
	return (x - 'A') + 26;
	
}
set<int> g[60];
int vis[60];

bool solve(int cur){
	if(vis[cur])
		return true;
	vis[cur] = true;
	
	int op;
	if(cur >= 26)
		op = cur - 26;
	else
		op = cur + 26;
		
	for(set<int>:: iterator it = g[op].begin(); it != g[op].end(); it ++){
		if(solve((*it)))
			return true;
	}
	vis[cur] = false;
	return false;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n;
  string no = "unbounded", yes = "bounded";
  cin >> n;
  set<int> test;
  
  for(int i = 0; i < n; i ++){
		cin >> a[i];
		//cout << a[i] << endl;
		for(int j = 0; j < 8; j += 2){
			int cur = get(a[i][j], a[i][j + 1]);
			if(cur == oo)
				continue;
			test.insert(cur);
			for(int k = (j + 2) % 8; k != j; k += 2){
				k %= 8;
				if(k == j)
					break;
				//cout << k << " " << j << endl;
				if(get(a[i][k],a[i][k + 1] != oo))
					g[cur].insert(get(a[i][k],a[i][k + 1]));
			}
		}
	}
	for(set<int>::iterator it = test.begin(); it != test.end(); it ++){
		//cout << (*it) << endl;
		if(solve((*it))){
			cout << no << endl;
			return 0;
		}
	}
	
	cout << yes << endl;
	
  return 0;
}

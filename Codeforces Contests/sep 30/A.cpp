#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  string s;
  cin >> n >> s;
  
  int cont = 0;
  vector<int> v;
  
  for(int i = 0; i < n; i ++){
		if(s[i] == 'W'){
			if(cont)
				v.pb(cont);
			cont = 0;
		}else
			cont ++;
	}
	if(cont)
		v.pb(cont);
	
	cout << (int)v.size() << '\n';
	
	for(int i = 0; i < (int)v.size(); i ++)
		cout << v[i] << ' ';
		
	cout << '\n';

  return 0;
}

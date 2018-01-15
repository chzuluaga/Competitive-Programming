#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
string table;

int visit[105], n, k;

bool ok(int idx){
	return idx >= 0 && idx < n && table[idx] != '#';
}

bool solve(int idx){
	if(table[idx] == 'T')
		return true;
		
	if(visit[idx])
		return false;
	
	visit[idx] = 1;
	
	if(ok(idx + k)){
		if(solve(idx + k))
			return true;
	}
	
	if(ok(idx - k)){
		if(solve(idx - k))
			return true;
	}
	return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int idx;
  cin >> n >> k;
  
  cin >> table;
  
  for(int i = 0; i < (int)table.size(); i ++){
		if(table[i] == 'G'){
			idx = i;
			break;
		}
	}
	
	if(solve(idx))
		cout << "YES\n";
	else
		cout << "NO\n";
  
  

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
bool cmp(int x, int y){
	int r = rand() % 2;
	
	return r == 0;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  srand(time(NULL));
	vector<int> v;
	freopen("perm.out", "w", stdout);
	for(int i = 0; i <= 63; i ++)
		v.pb(i);
		
	sort(v.begin(), v.end(), cmp);	
	
	cout << "{";
	for(int i = 0; i <(int) v.size(); i ++){
		cout << v[i]<<",";
	}
	cout << "}";
  return 0;
}

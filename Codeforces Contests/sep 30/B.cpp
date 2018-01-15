#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 105;
string a[MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k;
  string pass;
  cin >> n >> k;
  
  for(int i = 0; i < n; i ++)
		cin >> a[i];
	cin >> pass;
	
	int sz = (int)pass.size();
	int le = 0, eq = 0;
	
	for(int i = 0; i < n; i ++){
		if((int)a[i].size() < sz)
			le ++;
				
		if((int)a[i].size() == sz)
			eq ++;
	}	
	
	int ans1 = ((le / k) * 5 + le) + 1;
	int ans2 = ( (le + eq - 1) / k ) * 5 + (le + eq);
	
	cout << ans1 << " " << ans2 << '\n';
	
	
  return 0;
}

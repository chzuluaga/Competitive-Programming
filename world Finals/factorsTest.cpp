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
  freopen("test.in", "r", stdin);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i ++)
		cin >> a[i];
	set< vector<int> > mySet;
	do{
		mySet.insert(a);
	}while(next_permutation(a.begin(), a.end()));
  
	cout << mySet.size() << endl;
	
	
  return 0;
}

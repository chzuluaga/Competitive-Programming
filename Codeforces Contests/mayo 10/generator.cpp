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
  freopen("a.in", "w", stdout);
	int n = 31;
	srand(time(NULL));
  cout << n << endl;
  
  for(int i = 0; i < n; i ++){
		cout << rand() % 2 << " ";
	}
	cout << endl;

  return 0;
}

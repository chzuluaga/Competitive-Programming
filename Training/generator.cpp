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
  srand(time(NULL));
  freopen("enjoy.in", "w", stdout);
	int s = 1;
	
	int n = 50;
	int m = n * (n - 1);
	
	cout << n << " " << m << " " << 200 << " " << s << " " << n << endl;
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(i == j)	continue;
			cout << i << " " << j << " " << rand() % 100 + 1 << endl;
		}
	}
	cout << "0 0 0 0 0" << endl;
  return 0;
}

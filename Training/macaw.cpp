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
  
  int m, e;
  
  while(cin >> m >> e){
		for(int i = 0; i < 1<<e; i ++){
			for(int j = 0; j < 1<<m; j ++){
				cout << 1.0 * i *(j / 10.0) << endl;
			}
		}
	}

  return 0;
}

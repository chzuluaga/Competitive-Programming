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
  
  int k, r;
  
  cin >> k >> r;
  
  for(int i = 1; i <= 10; i ++){
		int cost = k * i;
		if(cost % 10 == r || (cost % 10) == 0){
			cout << i << '\n';
			break;
		}
	}

	return 0;
}

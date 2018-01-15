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
  
  int n = 30, sum = 0;
  for(int i = n; i >= 0; i --)
		sum += (i + i) + n - i;
		
	cout << sum << endl;
		

  return 0;
}

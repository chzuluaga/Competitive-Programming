#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int limit[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	int month, day, ans = 1;

	cin >> month >> day;
	
	for(int i = 0; i < limit[month - 1]; i ++){
		if(day == 8)
			ans ++, day = 1;
		day ++;
	}
	
	cout << ans << '\n';
	
	
  return 0;
}

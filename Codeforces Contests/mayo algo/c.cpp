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
  
  int n;
  cin >> n;
  int from = 1, to = n, cur = 1, nxt = n, cnt = 0, ans = 0;
  n ++;
  while(from < to){
		//cout << cur << " " << nxt << endl;
		ans += ((cur + nxt) % n);
		cur = nxt;
		if(cnt % 2 == 0){
			from ++;
			nxt = from;
		}else{
			to --;
			nxt = to;
		}
		cnt ++;
	}
	
	cout << ans << '\n';

  return 0;
}

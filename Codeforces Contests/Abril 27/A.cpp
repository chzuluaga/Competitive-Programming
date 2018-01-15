#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int memo[MAX][2][2];
int n;
string s;
int solve(int idx, bool change, bool done){
	if(idx == n){
		return 0;
	}
	int &ans = memo[idx][change][done];
	if(ans != -1)
		return ans;
	ans = 0;
	if(change){
		// continue change
		int sum = 0;
		if(s[idx - 1] != s[idx])
			sum = 1;
		ans = max(ans, sum + solve(idx + 1, true, true));
		// stop change
		if(s[idx - 1] == s[idx])
			sum = 1;
		else
			sum = 0;
		ans = max(ans, sum + solve(idx + 1, false, true));
	}else{
		// change
		int sum = 0;
		if(s[idx - 1] == s[idx])
			sum = 1;
		if(done == false)
			ans = max(ans, sum + solve(idx + 1, true, true));
		// stop change
		if(s[idx - 1] != s[idx])
			sum = 1;
		else
			sum = 0;
		ans = max(ans, sum + solve(idx + 1, false, done));
	}
	
	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(memo, -1, sizeof(memo));
  cin >> n >> s;
  
  int ans = solve(0, 0, 0);
  
  cout << ans << "\n";

  return 0;
}

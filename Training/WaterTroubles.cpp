#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 8;
ll h[MAX], inf = LLONG_MAX, ans, t;
int n;

void solve(int cur, ll sum){
	if(cur == n){
		if(sum >= t)
			ans = min(ans, sum);
		return;
	}

	if(sum >= t)
		ans = min(ans, sum);
	
	if(ans == t)
		return;
		
	//sum
	solve(cur + 1, sum + h[cur]);
	if(ans == t)
		return;
	//substract
	if(sum != h[cur])
		solve(cur + 1, max(0ll, sum - h[cur]));
	if(ans == t)
		return;
	//divide
	//cout << "divide"<<endl;
	if(sum % h[cur] == 0)
		solve(cur + 1, sum  / h[cur]);
	if(ans == t)
		return;
	//multiply
	solve(cur + 1, sum * h[cur]);
	if(ans == t)
		return;
}

void go(){
	solve(1, h[0]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string line;
  //freopen("water.in", "r", stdin);
  //freopen("water.out", "w", stdout);
  while(true){
		getline(cin, line);
		istringstream ss;
		ss.str(line);
		
		ss >> t;
		if(t == 0)	break;
		
		n = 0;
		ans = inf;
		while(ss >> h[n]){n ++;}
		sort(h, h + n);
		
		do{
			go();
		}while(next_permutation(h, h + n));
		
		if(ans < inf)
			cout << ans << '\n';
		else
			cout << "0\n";
		
	}

  return 0;
}

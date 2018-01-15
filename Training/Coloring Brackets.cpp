#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

const int MAX = 705;
int n = 0;
ll memo[MAX][MAX][3][3];
int fin[MAX], start[MAX];
string s;

ll solve(int from, int to, int dir, int color){
	
	//cout << from << " " << to << " " << dir << " " << color<< endl;	
	if(from >= n || from > to || from < 0 || to < 0){
		//cout << "retorno 1 " << endl;
		return 1ll;
	}
	
	ll& ans = memo[from][to][dir][color];
	if(ans != -1){
	//	cout << "retorno " << endl;
		return ans;
	}
	ans = 0;
	
	// paint left
	ll r;
	for(int i = 1; i <= 2; i ++){
		if(dir == 1 || color != i){
			r = solve(from + 1, fin[from + 1], 0, i);
			if(dir == 0){
				r = (r * (s[to + 1] == '(' ?solve(to + 1, fin[to + 1], dir, 0):1)) % mod;
			}else{
				r = (r * (from - 1 >=0 && s[from - 1] == ')'?solve(start[from - 1],from - 1, dir, i):1)) % mod;
			}
			ans = (ans + r) % mod;
		}
	}
	
	//paint right
	for(int i = 1; i <= 2; i ++){
		if(dir == 0 || color != i){
			ll r = solve(start[to - 1], to - 1, 1, i);
			if(dir == 0){
				r = (r * (s[to + 1] == '(' ?solve(to + 1, fin[to + 1], dir, i):1)) % mod;
			}else{
				r = (r * (from - 1 >= 0 && s[from - 1] == ')'?solve(start[from - 1],from - 1, dir, 0):1)) % mod;
			}
			ans = (ans + r) % mod;
		}
	}
	
	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(start, -1 ,sizeof(start));
  memset(fin, -1, sizeof(fin));
 // freopen("brackets.in", "r", stdin);
  cin >> s;
  n = s.size();
  memset(memo, -1, sizeof(memo));
  stack<int> st;
  s +="##";
  for(int i = 0; i < n; i ++){
		if(s[i] == '(')
			st.push(i);
		else{
			int last = st.top();
			st.pop();
			fin[last] = i;
			start[i] = last;
		}
	}
	
	cout << solve(0, fin[0], 0, 0) << '\n';
  

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;
typedef long long ll;
const int MAX = 100005;
string s[MAX], rs[MAX];
int n;
ll memo[MAX][2], inf = LLONG_MAX / 10ll, c[MAX];
string revv(string &ss){

	int sz = (int)ss.size();
	string ret = "";
	for(int i = sz - 1; i >= 0; i --){
		ret += ss[i];
	}
	
	return ret;
}


ll solve(int idx, int r){
	if(idx == n)
		return 0;
		
	ll &ans = memo[idx][r];
	
	if(ans != -1)
		return ans;
	
	ans = inf;
		
	if(idx == 0){
			ans = solve(idx + 1, 0);
			ans = min(ans, c[idx] + solve(idx + 1, 1));
	}else{
		if(r == 0){
			if(s[idx] >= s[idx - 1]){
				ans = min(ans, solve(idx + 1, 0));
			} 
			if(rs[idx] >= s[idx - 1]){
				ans = min(ans, c[idx] + solve(idx + 1, 1));
			} 
			
		}else{
			if(s[idx] >= rs[idx - 1]){
				ans = min(ans, solve(idx + 1, 0));
			} 
			if(rs[idx] >= rs[idx - 1]){
				ans = min(ans, c[idx] + solve(idx + 1, 1));
			} 
			
		}
	}
	
	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  
  for(int i = 0; i < n; i ++)
		cin >> c[i];
		
	for(int i = 0; i < n; i ++){
		cin >> s[i];
		rs[i] =  revv(s[i]);
	}
	memset(memo, -1 , sizeof(memo));
	
	ll ans = solve(0, 0);
	
	if( ans < inf )
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	
  return 0;
}

	#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
ll arr[MAX];
ll a, b, h, w, n;
map< pll, int > memo[MAX];
int solve(ll x, ll y, int idx){
	if(x >= a && y >= b)
		return 0;
	if(idx == n || arr[idx] <= 1){
		return n + 1;
	}
	if(memo[idx].count(mp(x, y)))
		return memo[idx][mp(x, y)];
	
	int &ans = memo[idx][{x, y}] = n + 1;
	
	if(x < a){
		ans = min(ans, 1 + solve(x * arr[idx], y, idx + 1));
	}
	
	if(y < b){
		ans = min(ans, 1 + solve(x, y * arr[idx], idx + 1));
	}
	//ans = min(ans, solve(x, y, idx + 1));
	
	return ans;
	
}

bool cmp(ll x, ll y){
	return x > y;
}
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b >> h >> w >> n;
  
  if(a > b)
		swap(a, b);
	if(h < w)
		swap(h, w);
		
	for(int i = 0; i < n; i ++)
		cin >> arr[i];
	sort(arr, arr + n, cmp);
	int ans = min(solve(w, h, 0), solve(h, w, 0));
	if(ans > n)
		ans = -1;
	
	cout <<  ans << endl;
  
  
  

  return 0;
}

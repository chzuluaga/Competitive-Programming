#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX	= 204;

string s[MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	int n;
	ll p, ans = 0;
	cin >> n >> p;
	
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	
	ll apple = 0;
	
	for(int i = n - 1; i >= 0; i --){
		if(s[i] == "half"){
			ans += (apple) * p / 2;
			apple *= 2;
		}else{
			apple ++;
			ans += (apple) * p / 2;
			apple *= 2;
			
		}
	}
	
	cout << ans << '\n';
  return 0;
}

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
  
  string s, ans = "";
  cin >> s;
  int n = s.size();
  bool change = false;
  bool fin = false;
  for(int i = 0; i < n; i ++){
		if(s[i] == 'a'){
			if(change)
				fin = true;
			if(!change && i == n - 1)
				ans += 'z';
			else 
			ans += s[i];
		
		}else{
			if(!fin){
				change = true;
				ans += (s[i] - 1);
			}else
			 ans += s[i];
		}
		
	}
	
	cout << ans << '\n';

  return 0;
}

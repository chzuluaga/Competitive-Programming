#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

bool isVowel(char x){
	
	return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y';

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  
  cin >> s;
  int n = s.size();
  int cur = 0, maxi = 0;
  for(int i = 0; i < n; i ++){
		if(isVowel(s[i])){
			maxi = max(maxi, (i + 1) - cur);
			cur = i + 1;
		}
	}
	maxi = max(maxi, (n + 1) - cur);

	cout << maxi << '\n';
  

  return 0;
}

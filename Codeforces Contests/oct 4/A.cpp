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
  
  int n, p, q;
  string s;
  cin >> n >> p >> q;
  cin >> s;
  
  for(int i = 0; i < n; i ++){
		for(int j = 0;j < n; j ++){
			if(i == 0 && j == 0)	continue;
			
			if(i * p + q * j == n){
				cout << i + j << '\n';
				int cur = 0;
				for(int k = 0; k < i; k ++){
					for(int l = 0; l < p; l ++)
						cout << s[cur ++];
					cout << '\n';
				}
				for(int k = 0; k < j; k ++){
					for(int l = 0; l < q; l ++)
						cout << s[cur ++];
					cout << '\n';
				}
				
				return 0;
			}
		}
	}
	
  cout << "-1\n";
  
	
	
	
  

  return 0;
}

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
  
  ll n;
  cin >> n;
  bool f = true;
  for(int i = 2; i * i <= n && f; i ++){
		if(n % i == 0){
			f = false;
		}
	}
	
	if(f){
		cout << "1\n";
		return 0;
	}
	
  if(n % 2 == 0){
		cout << "2\n";
		return 0;
	}
	
	if(n > 5){
		
		ll y = n - 2;
		bool f = true;
		for(int i = 2; i * i <= y && f; i ++){
			if(y % i == 0){
				f = false;
			}
		}
		if(f){
			cout << "2\n";
			return 0;
		}
		
		cout << "3\n";
		return 0;
	}
	
  

  return 0;
}

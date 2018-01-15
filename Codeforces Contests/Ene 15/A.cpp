#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

bool isPrime(int x){
	for(int i = 2; i * i <= x; i ++){
		if(x % i == 0)
			return false;
	}
	return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  
  cin >> n;
  
  for(int i = 1; ; i ++){
		if(!isPrime(n * i + 1)){
			cout << i << '\n';
			break;
		}
	}

  return 0;
}

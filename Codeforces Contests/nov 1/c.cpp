#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

bool root(ll x){
	
	ll rx = sqrt(x);
	return rx * rx == x;
}

bool isTriangle(ll a, ll b, ll c){
	return a + b > c && a + c > b && c + b > a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll n, a, b;
  cin >> n;
  if(n <= 2){
		cout << -1 << '\n';
		return 0;
	}
  
  if(root(n)){
		for(int i = 1; i * i <= n ; i ++){
			a = i;
			b = n - (a * a);
			if(root(b)){
				b = sqrt(b);
				if(isTriangle(a, b, n)){
					cout << a << " " << b << '\n';
					return 0;
				}
			}
		}
	}
	
	if(n & 1){
		a = (n*n - 1) / 2;
		b = (n*n + 1) / 2;
	}else{
		a = (n/2)*(n/2) - 1;
		b = (n/2)*(n/2) + 1;
	}
	
	cout << a << " " << b << endl;
	
  
  

  return 0;
}

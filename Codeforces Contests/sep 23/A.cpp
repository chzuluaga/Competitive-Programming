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
  
  int n,fs, x;
  string up = "UP", down = "DOWN";
  int no = -1;
  cin >> n >> fs;
  
  if(n == 1){
		if(fs == 0)
			cout << up << '\n';
		else
			if(fs == 15)
				cout << down << '\n';
				else
					cout << no << '\n';
		return 0;
	}
  int diff;
  for(int i = 1; i < n; i ++){
		cin >> x;
		diff = x - fs;
		fs = x;
	}

	if(diff > 0){
		if(x == 15)
			cout << down << '\n';
		else
			cout << up << '\n';
	}else{
		if(x == 0)
			cout << up << '\n';
		else
			cout << down << '\n';
	}
	
		

  return 0;
}

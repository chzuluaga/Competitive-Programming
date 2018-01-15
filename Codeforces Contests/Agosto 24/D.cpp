#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
map <ll, int> sq;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  ll a, b, c, d;
  string no = "Im15fdafsdpossible";
  cin >> a >> b >> c >> d;
  if(a == 0 && b == 0 && c == 0 && d == 0){
		cout << "1\n";
		return 0;
	}
	
	if(a == 0 && b == 1 && c == 1 && d == 1){
		cout << "101\n";
		return 0;
	}
	if(a == 1 && b == 1 && c == 1 && d == 0){
		cout << "010\n";
		return 0;
	}
  
	if(a == 0 && d == 0){
		if(b == 1 && c == 0){
			cout << "01\n";
		}else{
			if(b == 0 && c == 1){
				cout << "10\n";
			}else{
				cout << no << '\n';
			}
		}
		return 0;
	}
  
  
  for(ll i = 0; ; i ++){
			sq[(i * (i + 1)) / 2ll] = i + 1;
			if((i * (i + 1)) / 2ll > 1000000000ll)
				break;
	}
	
	if(sq.count(a) <= 0 || sq.count(d) <= 0){
		cout << no << '\n';
		return 0;
	}
	int x = sq[a];
	int y = sq[d];
	
	ll sumMit = x * y;
	
	string ans = "";
	//cout << x << " " << y << endl;
	
	if(b + c != sumMit && a != 0 && d != 0){
			cout << no << '\n';
			return 0;
	}
	
	if(a == 0 && b == 0 && c == 0)
		x = 0;
	
	if(d == 0 && b == 0 && c == 0)
		y = 0;
	
	for(int i = 0; i < x; i ++)
		ans += '0';
	for(int i = 0; i < y; i ++)
		ans += '1';
		
	//cout << x << " " << y << endl;
		
	int last = x;
	
	int curb = x * y;
	int curc = 0;
	int st = 0;
	
	if(a == 0 || d == 0){
		if( max(x, y) != b + c && b != 0 && c != 0){
			cout << no << '\n';
			return 0;
		}
			
	}
	
	while(curb != b || curc != c){
		if(curb - (last - st) > b){
			swap(ans[st], ans[last]);
			st ++;
			last ++;
			curb -= (last - st);
			curc += (last - st);
		}else{
			int diff = curb - b;
			swap(ans[last], ans[last - diff]);
			curb = b;
			curc = c;
		}
	}
		
  cout << ans << '\n';

  return 0;
}

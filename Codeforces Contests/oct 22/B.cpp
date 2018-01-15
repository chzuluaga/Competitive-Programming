#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

ll toNum(string s){
	
	int n = s.size();
	ll dec = 1ll, num = 0;
	for(int i = n - 2; i >= 0; i --){
		num += (s[i] -'0') * dec;
		dec *= 10ll;
	}
	return num;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	
	string line;
	
	cin >> line;
	int n = (int)line.size();
	ll c = line[n - 1] - 'a';
	ll row = toNum(line);
	ll ans = 0;
	row --;
	if((row % 4) <= 1){
		ans += row + (row / 2ll) * 6ll;
		if(row & 1)
			ans += 6ll;
			
		if(c >= 3)
			ans += 5ll - c + 1ll;
		else
			ans += c + 4ll;
		
	}else{
		row -= 2ll;
		ans += row + (row / 2ll) * 6ll;
		if(row & 1)
			ans += 6ll;
			
		if(c >= 3)
			ans += 5ll - c + 1ll;
		else
			ans += c + 4ll;
	}
	cout << ans << '\n';
	return 0;
}

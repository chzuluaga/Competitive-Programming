#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int men[20][MAX];
int rg[MAX], cont[30];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("d.in", "r", stdin);
  int m;
  string s;
  cin >> m >> s;
  int n = s.size();
  for(int i = 0; i < n; i ++){
		men[0][i] = i;
		cont[s[i] - 'a'] ++;
	}
	
	for(int h = 1; (1<<h) <= m; h ++){
		for(int i = 0; i < n; i ++){
			int nxt = i + (1<<(h - 1));
			
			if(s[men[h - 1][nxt]] <= s[men[h - 1][i]]){
				men[h][i] = men[h - 1][nxt];
			}else{
				men[h][i] = men[h - 1][i];
			}
		}
	}
	
	for(int i = 0; i < n; i ++){
		int cur = i, idx = i;
		char ans = 'z';
		for(int j = 0; (1<<j) <= m; j ++){
			if(m & (1<<j)){
				char c = s[men[j][cur]];
				if(c <= ans){
					ans = c;
					idx = men[j][cur];
				}
				cur += (1<<j);
			}
		}
		rg[i] = (idx != i?idx:-1);
	}
	
	for(int i = 0; i < n; i ++){
		if(rg[i] == 0)
			rg[i] = -1;
	
	}
	
	
	int cur = 0;
	
	if(rg[0] == -1)
		cur = 0;
	else
		cur = rg[0];
	
	vector<char> v;
	while(cur < n){
		v.pb(s[cur]);
		if(rg[cur] == -1 || s[rg[cur]] == s[cur]){
			if(cur + m >= n)
				break;
		}
		if(rg[cur] == -1){
			cur ++;
			if(rg[cur] == -1)
				continue;
			cur = rg[cur];
		}else{
			cur = rg[cur];
		}
	}
	
	sort(v.begin(), v.end());
	
	char last = v[(int)v.size() -1];
	for(int i = 0; i < 26; i ++){
		if(char(i + 'a') < last){
			for(int j = 0;j < cont[i];j ++)
				cout<<(char)( i + 'a');
		}
	}	
	for(int i = (v.size() - 1); i >= 0; i --){
		if(last == v[i])
			cout << last;
	}
	cout << '\n';
	

	
  return 0;
}

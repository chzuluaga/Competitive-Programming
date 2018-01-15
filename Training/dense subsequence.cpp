#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int cont[MAX];

struct pp{
	char letter;
	int pos;
	
	pp(char _x, int _pos){
		letter = _x;
		pos = _pos;
	}
	
	bool operator <(pp other)const{
		if(other.letter == letter){
			return pos < other.pos;
		}
		return letter > other.letter;
	}
};
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int m;
	string s;
	cin >> m;
	cin >> s;
	char men = 'z';
	priority_queue< pp > q;
	for(int i = 0; i < (int)s.size(); i ++){
		cont[s[i] -'a'] ++;
		if(i < m){
			q.push(pp(s[i], i));
			men = min(s[i], men);
		}
	}
	
	int cur = m;
	string ans = "";
	if(cur >= (int)s.size())
		ans = men;
		
	while(!q.empty() && cur < (int)s.size()){
		char c = q.top().letter;
		int p = q.top().pos;
		q.pop();
		ans += c;
		
		//cout << c << " " << p << " " << cur << endl;
		
		for(int i = cur; i <= p + m && i < (int)s.size(); i ++){
			q.push(pp(s[i], i));
		}
		cur = max(cur, p + m + 1);
	}
	
	sort(ans.begin(), ans.end());
	char last = ans[ (int)ans.size() - 1];
	string sol = "";
	for(char i = 'a'; i <= 'z'; i ++){
		if(i == last)
			break;
		else{
			for(int j = 0; j < cont[i - 'a']; j ++){
				sol += i;
			}
		}
	}
	
	for(int i = 0; i < (int) ans.size(); i ++)
		if( ans[i] == last)
			sol += ans[i];
	
	cout << sol << '\n';
	
  return 0;
}

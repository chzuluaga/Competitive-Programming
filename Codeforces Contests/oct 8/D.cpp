#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int rg[MAX], cont[MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("d.in", "r", stdin);
  int m;
  string s;
  cin >> m >> s;
  memset(rg, -1, sizeof(rg));
  int n = (int)s.size();
  stack<char> st;
  stack<int> pos;
  cont[0] = 1;
  for(int i = 1; i < n; i ++){
		cont[i] = 1;
		if(s[i] == s[i - 1])
			cont[i] += cont[i - 1];
	}
	
	for(int i = n - 2; i >= 0; i --){
		if(s[i] == s[i + 1])
			cont[i] = cont[i + 1];
	}
	for(int i = 0; i < n; i ++)
		cout << cont[i] << " ";
	cout << endl;
	
	for(int i = 0; i < n; i ++){
		while(!st.empty() && (st.top() >= s[i] || i - pos.top() >= m)){
			if(i - pos.top() < m){
				if(st.top() == s[i]){
					rg[pos.top()] = min(pos.top() + m - 1, pos.top() + cont[i] - 1);
				}else
					rg[pos.top()] = i;
			}
			st.pop();
			pos.pop();
		}
		st.push(s[i]);
		pos.push(i);
	}
	int cur = 0;
	vector<char> v;
	
	for(int i = 0; i < n; i++)
		cout << rg[i] << " ";
	cout << endl;
	
	
	if(rg[0] == -1)
		cur = 0;
	else
		cur = rg[0];
	
	while(cur < n){
		//cout << cur << endl;
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
	
	for(int i = 0; i < (int)v.size(); i ++)
		cout << v[i];
		
	cout << '\n';

	
  return 0;
}

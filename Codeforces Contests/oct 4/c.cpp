#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1000006;
char s[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  scanf("%s", s);
  n = (int)strlen(s);
  string no = "Impossible";
  stack<char> st;
  int ans = 0;
  for(int i = 0; i < n; i ++){
		if(s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '('){
			st.push(s[i]);
		}else{
			if(st.empty()){
				cout << no << "\n";
				return 0;
			}
			int tp = st.top();
			if(tp == '<'){
				if(s[i] == '>')
					st.pop();
				else{
					ans ++;
					st.pop();
				}
			}
			if(tp == '{'){
				if(s[i] == '}')
					st.pop();
				else{
					ans ++;
					st.pop();
				}
			}
			if(tp == '['){
				if(s[i] == ']')
					st.pop();
				else{
					ans ++;
					st.pop();
				}
			}
			if(tp == '('){
				if(s[i] == ')')
					st.pop();
				else{
					ans ++;
					st.pop();
				}
			}
		}
	}
  
  if(st.empty())
		cout << ans << '\n';
	else
		cout << no << '\n';

  return 0;
}

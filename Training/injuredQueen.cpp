#include<bits/stdc++.h>

using  namespace std;
typedef long long ll;
string s;
ll memo[30][30];

int toNum(char c){
  if(c >= '0' && c <= '9')
    return c - '0';
  return (c - 'A') + 10;
}

ll solve(int idx, int prev){
  if(idx == s.size())
    return 1ll;

  ll& ans = memo[idx][prev];
  if(ans != -1)
    return ans;

  ans = 0;

  if(s[idx] == '?'){
    for(int i = 1; i <= s.size(); i ++){
      if(abs(idx - prev) >= 2)
        ans += solve(idx + 1, i);
    }
  }else{
    if(abs(toNum(s[idx]) - prev) >= 2){
      ans += solve(idx + 1, toNum(s[idx]));
    }
  }
  return ans;
}

int main(){

  while(cin >> s){
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 29) << '\n';
  }
  return 0;
}

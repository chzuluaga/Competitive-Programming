#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  string s;
  cin >> n >> p >> s;

  for(int i = n - 1; i >= 0; i --){
    for(char c = s[i] + 1; c < 'a' + p; c ++){
      if(i - 1 >= 0 && c == s[i - 1])
        continue;
      if(i - 2 >= 0 && c == s[i - 2])
        continue;

      for(int j = 0; j < n; j ++){
        if(j < i){
          cout << s[j];
          continue;
        }
        if(j == i){
          s[j] = c;
          cout << s[j];
          continue;
        }
        for(char cc = 'a'; cc < 'a' + p; cc ++){
          if(j - 1 >= 0 && cc == s[j - 1])
            continue;
          if(j - 2 >= 0 && cc == s[j - 2])
            continue;
          s[j] = cc;
          break;
        }
        cout  << s[j];
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}

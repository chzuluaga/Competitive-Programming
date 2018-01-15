#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
map<char, int> idx;
map<int, int> last;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  int cont = 0;
  for(int i = 0; i < n; i ++){
    char c = s[i];
    if(idx.count(c))
      continue;
    idx[c] = cont ++;
  }
  ll total = (1ll << cont) - 1;
  ll cur = 0;
  int ans = n;
  for(int i = 0; i < n; i ++){
    cur |= 1ll << idx[ s[i] ];
    last[ idx[ s[i] ] ] = i;
    if(cur == total){
      int menor = last[0];
      int mayor = last[0];
      for(int j = 1; j < cont; j ++){
        menor = min(last[j], menor);
        mayor = max(last[j], mayor);
      }
      ans = min(ans, mayor - menor + 1);
    }
  }

  cout << ans << '\n';



  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 103;
int day[MAX];
string s[MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, d, ans = 0, cont = 0;

  cin >> n >> d;

  for(int i = 0; i < d; i ++){
    cin >> s[i];
    for(int j = 0; j < n; j ++){
      if(s[i][j] == '1')
        day[i] ++;
    }
    if(day[i] < n){
      cont ++;
      ans = max(cont, ans);
    }else{
      cont = 0;
    }
  }

  cout << ans << '\n';





  return 0;
}

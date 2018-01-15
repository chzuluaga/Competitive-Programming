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
  int n, x;
  cin >> n;
  string yes = "YES";
  string no = "NO";
  if(n == 1){
    cin >> x;
    if(x)
      cout << yes << '\n';
    else
      cout << no << '\n';
    return 0;
  }
  int ans = 0;
  for(int i = 0; i < n; i ++){
    cin >> x;
    if(x)
      ans ++;
  }

  if(ans == n - 1)
    cout << yes << '\n';
  else
    cout << no << '\n';




  return 0;
}

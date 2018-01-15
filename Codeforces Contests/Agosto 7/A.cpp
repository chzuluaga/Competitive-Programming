#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  string that = "that", hate = "I hate", love = "I love", it = " it";
  int n;
  cin >> n;

  for(int i = 0; i < n; i ++){
    if(i)
      cout << that << ' ';
    if(i % 2 == 0)
      cout << hate << " ";
    else
      cout << love << ' ';
  }

  cout << it << '\n';


  return 0;
}

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
  string n;
  cin >> n;
  deque<int> ans;
  for(int i = n.size() - 1; i >= 0; i --){
    ans.push_back(n[i] - '0');
    ans.push_front(n[i] - '0');
  }

  while(!ans.empty()){
    cout << ans.front();
    ans.pop_front();
  }

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100005;
int row[MAX], col[MAX];
ll cont = 0;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int n, m, rx, ry;
  scanf("%d%d", &n, &m);
  ll total = n;
  for(int i = 0; i < m; i ++){
    scanf("%d%d", &rx, &ry);
    if(!row[rx]){
      row[rx] = true;
      total --;
    }
    if(!col[ry]){
      col[ry] = true;
      cont ++;
    }
    ll val = n - cont;
    //cout << total * val << endl;
    printf("%I64d ", total * val);
  }


  return 0;
}

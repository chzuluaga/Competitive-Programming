#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int hm, am, dm, ph, pa, pd, hy, ay, dy;

int solve(int a, int d){
  int diffY = max(am - d, 0);
  int diffM = max(a - dm, 0);
  if(diffM == 0)
    return -1;

  int turnY, turnM;

  if(diffY == 0)
    return 0;

  turnM = ceil (hm * 1.0 / diffM);

  int newH = (turnM + 1) * diffY - diffY + 1;

  return max(newH - hy, 0);

}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n = 7000;

  scanf("%d%d%d", &hy, &ay, &dy);
  scanf("%d%d%d", &hm, &am, &dm);
  scanf("%d%d%d", &ph, &pa, &pd);

  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j ++){
      int r = solve(ay + j, dy + i);
      if(r != -1)
        ans = min(ans, r * ph + j * pa + i * pd);
    }
  }

  printf("%d\n", ans);


  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100005;
int w[MAX], sum[MAX], sumr[MAX];

int main(){

  int n, l, r, ql, qr, ans = INT_MAX;

  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);

  for(int i = 0; i < n; i ++){
    scanf("%d", &w[i]);
    sum[i] = w[i];
    if(i)
      sum[i] += sum[i - 1];
  }

  for(int i = n - 1; i >= 0; i --)
    sumr[i] = w[i] + sumr[i + 1];

  for(int i = 0; i < n; i ++){
    int rr = sumr[i] * r;
    int ll = (i?sum[i - 1]:0) * l;
  //  cout << ll << " --- " << rr << endl;
    int lf = i;
    int rg = n - i;
    int diff = lf - rg;
   // cout << diff << endl;
    if(diff > 1){
      ll += ql * (abs(diff) - 1);
    }
    if(diff < -1){
      rr += qr * (abs(diff) - 1 );
    }
    //cout << "para i = " << i << " ans = " << rr + ll << endl;
    ans = min(ans, rr + ll);

  }

  ans = min(sum[n - 1] * l + ql * (n - 1), ans);

  printf("%d\n", ans);




  return 0;
}

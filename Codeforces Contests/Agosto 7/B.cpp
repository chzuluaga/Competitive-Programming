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

  int n, odd = 0, even = 0;
  int x;
  scanf("%d", &n);

  for(int i = 0; i < n; i ++){
    scanf("%d", &x);
    if(x & 1)
      odd ++;
    else
      even ++;

    if(even & 1)
      printf("%d\n", 1);
    else
      printf("%d\n", 2);
  }



  return 0;
}

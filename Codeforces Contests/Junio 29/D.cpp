#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 1000005;
bool visit[MAX];
int mark[MAX], k, cont = 0, x[MAX];
vector<int> prime;

void make_sieve(){
  for(int i = 2; i < MAX; i ++){
    if(!mark[i]){
      if(k % i == 0)
        cont ++;
      prime.pb(i);
      for(int j = i; j < MAX ;j += i)
        mark[j] ++;
    }
  }
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n;
  scanf("%d%d", &n, &k);

  make_sieve();
 // cout << cont << endl;
  for(int i = 0; i < n; i ++){
    scanf("%d", &x[i]);
  }
  int cur = 0;

  for(int i = 0; i < prime.size(); i ++){
    if
  }
  if(cont == 0)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}

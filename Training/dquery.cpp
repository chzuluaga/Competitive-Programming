#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 30005;
int arr[MAX], block, seen[1000006], ans[200005];

struct query{
  int pos, from , to;
}q[200005];

bool cmp(query a, query b){
  if(a.from / block == b.from / block)
    return a.to < b.to;
  return a.from / block < b.from / block;
}

int main(){
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++)
    scanf("%d", &arr[i]);
  scanf("%d", &m);
  for(int i = 0; i < m; i ++){
    scanf("%d%d", &q[i].from, &q[i].to);
    q[i].from --, q[i].to --;
    q[i].pos = i;
  }
  block = 150;
  sort(q, q + m, cmp);
  int lf = -1, rg = -1, cont = 0;
  for(int i = 0; i < m; i ++){
    int L = q[i].from;
    int R = q[i].to;

    while(lf < L){
      if(lf < 0){
        lf ++;
        continue;
      }
      if(seen[arr[lf]]){
        seen[arr[lf]] --;
        if(seen[arr[lf]] == 0)
          cont --;
      }
      lf ++;
    }

    while(lf > L){
      lf --;

      if(seen[arr[lf]] == 0){
        cont ++;
      }
      seen[arr[lf]] ++;
    }

    while(rg < R){
      rg ++;

      if(rg < lf)
        continue;
      if(seen[arr[rg]] == 0)
        cont ++;
      seen[arr[rg]] ++;
    }

    while(rg > R){
      seen[arr[rg]] --;
      if(seen[arr[rg]] == 0)
        cont --;
    }

    ans[q[i].pos] = cont;
  }

  for(int i = 0; i < m; i ++)
    printf("%d\n", ans[i]);

  return 0;
}

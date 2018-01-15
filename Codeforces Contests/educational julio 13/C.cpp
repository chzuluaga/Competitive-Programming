#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 1000006;

int rnk[MAX], parent[MAX], ans[MAX], arr[MAX];
vector<int> comp[MAX];
priority_queue<int> q[MAX];
int find(int x){
  if(x == parent[x])
    return x;

  return parent[x] = find(parent[x]);
}

void merge(int x, int y){
  x = find(x);
  y = find(y);

  if(x == y)
    return;

  if(rnk[x] > rnk[y])
    parent[y]= x;
  else{
    parent[x] = y;
    if(rnk[x] == rnk[y])
      rnk[y] ++;
  }
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int n, m, a, b;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i ++){
    scanf("%d", &arr[i]);
    parent[i] = i;
    rnk[i] = 0;
  }

  for(int i = 0; i < m; i ++){
    scanf("%d%d", &a, &b);
    a --, b --;
    merge(a, b);
  }
  int maxc = 0;
  for(int i = 0; i < n; i ++){
    comp[find(i)].pb(i);
    maxc = max(maxc, find(i));
    q[find(i)].push(arr[i]);
  }

  for(int i = 0; i <= maxc; i++){
    for(int j = 0; j < comp[i].size(); j ++){
      ans[comp[i][j]] = q[i].top();
      q[i].pop();
    }
  }

  for(int i = 0; i < n; i ++)
    printf("%d ", ans[i]);

  return 0;
}

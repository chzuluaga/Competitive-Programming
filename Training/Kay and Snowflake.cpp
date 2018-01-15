#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 300005;
int ans[MAX], dad[MAX], sum[MAX], big[MAX];
vector<int> graph[MAX];

bool centroid(int v, int c){
  if((sum[v] - sum[c]) * 2 <= sum[v] && big[c] * 2 <= sum[v])
    return true;
  return false;
}

pair<int,int> go(int cur){
  int may = 0, res = cur;
  sum[cur] = 1;
  big[cur] = 0;
  for(int i = 0; i < graph[cur].size(); i ++){
    int nei = graph[cur][i];
    pair<int,int> r = go(nei);
    sum[cur] += r.first;
    if(may < r.first){
      may = r.first;
      res = r.second;
    }
  }
  big[cur] = may;
  ans[cur] = cur;
  if(sum[cur] >= may * 2)
    return mp(sum[cur], cur);

  while(!centroid(cur, res)){
    res = dad[res];
  }
  ans[cur] = res;
  return mp(sum[cur], res);
}


int main(){

  int n, m, x;
  //freopen("input.in","r",stdin);
  scanf("%d%d", &n, &m);

  for(int i = 1; i < n; i ++){
    scanf("%d", &x);
    x --;
    graph[x].pb(i);
    dad[i] = x;
  }

  go(0);


  for(int i = 0; i < m; i ++){
    scanf("%d", &x);
    printf("%d\n", ans[x - 1] + 1);
  }

  return 0;
}

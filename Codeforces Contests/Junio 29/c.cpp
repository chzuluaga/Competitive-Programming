#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 100005;
vector<int> graph[MAX], fs, sc;
int w[MAX], color[MAX];

bool solve(int cur, int c){
  if(c == 0)
    fs.pb(cur + 1);
  else
    sc.pb(cur + 1);

  color[cur] = c;

  for(int i = 0; i < graph[cur].size(); i ++){
    int nei = graph[cur][i];
    if(color[nei] == c){
      return false;
    }
    if(color[nei] == -1){
      bool r = solve(nei, (c + 1) % 2);
      if(!r)
        return false;
    }

  }
  return true;
}


int main(){
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);

  int n, m, u, v, idx = 0;
  memset(color, -1, sizeof(color));
  scanf("%d%d", &n, &m);

  for(int i = 0; i < m; i ++){
    scanf("%d%d",&u, &v);
    u --;
    v --;
    graph[u].pb(v);
    graph[v].pb(u);

  }

  for(int i = 0; i < n; i ++){
    if(color[i] != -1)
      continue;
    if(!solve(i, 0)){
      printf("-1\n");
      return 0;
    }

  }

  printf("%d\n", fs.size());
  for(int i = 0; i < fs.size(); i ++)
    printf("%d ",fs[i]);
  printf("\n");

  printf("%d\n", sc.size());
  for(int i = 0; i < sc.size(); i ++)
    printf("%d ",sc[i]);
  printf("\n");

  return 0;
}

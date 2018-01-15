#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 500005;
ll ans[MAX];
vector<int> graph[MAX];
vector<int> topo;
ll state[MAX], dad[MAX];
void topoSort(){
  for(int i = 0; i < topo.size(); i ++){
    int cur = topo[i];
    for(int j = 0; j < graph[cur].size(); j ++){
      int son = graph[cur][j];
      dad[son] --;
      if(dad[son] == 0)
        topo.pb(son);
    }
  }
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("digi.in", "r", stdin);
  ll n, m, l, r;
  char dir[3];
  while(~scanf("%lld%lld", &n, &m)){

    memset(ans, 0, sizeof(ans));
    memset(state,0, sizeof(state));
    memset(dad, 0, sizeof(dad));
    topo.clear();
    for(int i = 1; i <= m; i ++){
      graph[i].clear();
      scanf("%s%lld%lld", dir, &l, &r);
      ans[i] = (dir[0] == 'L'?0:1);
      dad[l] ++;
      dad[r] ++;
      graph[i].pb(l);
      graph[i].pb(r);
    }
    for(int i = 1; i <= m; i ++){
      if(dad[i] == 0)
        topo.pb(i);
    }
    topoSort();
    state[1] = n;
    for(int i = 0; i < topo.size(); i ++){
      int cur = topo[i];
      //cout << "cur " << cur << " " << state[cur] << endl;
      if(graph[cur].size()){
        int son1 = graph[cur][0];
        int son2 = graph[cur][1];
        state[son1] += state[cur] / 2ll;
        state[son2] += state[cur] / 2ll;
        if(state[cur] & 1){
          if(ans[cur])
            state[son2] ++;
          else
            state[son1] ++;
        }
      }
      if(state[cur] & 1)
        ans[cur] ^= 1;
    }

    for(int i = 1; i <= m; i ++){
      printf("%c",ans[i]?'R':'L');
    }
    printf("\n");
  }

  return 0;
}

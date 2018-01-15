#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 200005;
int u[MAX];
int lvl[MAX];
int up[MAX];
int cont[MAX];
bool inqueue[MAX];
vector<int> graph[MAX];

void go(int cur, int dad, int l){
  lvl[cur] = l;
  up[cur] = dad;
  for(int i = 0; i < graph[cur].size(); i ++){
    int nei = graph[cur][i];
    if(nei != dad){
      go(nei, cur, l + 1);
    }
  }
}

int main(){
  int n, k,a ,b;
  //freopen("d.in","r",stdin);
  scanf("%d%d", &n, &k);

  k *= 2;
  for(int i = 0; i < k; i ++){
      scanf("%d", &u[i]);
      u[i] --;
  }
  for(int i = 0; i < n - 1; i ++){
    scanf("%d%d", &a, &b);
    a --, b --;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  go(0, 0, 0);

  priority_queue< pii > q;

  for(int i = 0; i < k; i ++){
    int cur = u[i];
    if(!inqueue[cur]){
      inqueue[cur] = true;
      q.push(mp(lvl[cur], cur));
    }
    cont[cur] ++;
  }

  ll total = k;
  ll ans = 0;
  while(!q.empty()){
    int l = q.top().first;
    int cur = q.top().second;
    q.pop();
    inqueue[cur] = false;
    ll sum = cont[cur];
    if(cont[cur] * 2 > total){
      sum = total - cont[cur];
      total = sum * 2;
    }
    ans += sum;
    if(sum > 0){
      if(!inqueue[up[cur]]){
        inqueue[up[cur]] = true;
        q.push(mp(lvl[up[cur]], up[cur]));
      }
      cont[up[cur]] += sum;
    }
  }

  cout << ans << '\n';



  return 0;
}

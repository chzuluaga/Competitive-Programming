#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100005;
int son[MAX];
double ans[MAX];
double fact[MAX];
vector<int> graph[MAX], ng[MAX];

int getSon(int u, int dad){
  son[u] = 1;
  for(int i = 0; i < graph[u].size(); i ++){
    int v = graph[u][i];
    if(v == dad)
      continue;
    ng[u].pb(v);
    son[u] += getSon(v, u);
  }
  return son[u];
}

void solve(int u){
  double sum = son[u] - 1;
  //cout << "sum es " << son[u] << " " << sum << endl;
  for(int i = 0; i < ng[u].size(); i ++){
    int v = ng[u][i];
    ans[v] += ans[u] + (sum - son[v]) * 0.5 + 1;
  }
  for(int i = 0; i < ng[u].size(); i ++){
    int v = ng[u][i];
    solve(v);
  }

}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, x;
  scanf("%d", &n);
  for(int i = 1; i < n;i  ++){
    scanf("%d", &x);
    x --;
    graph[i].pb(x);
    graph[x].pb(i);
  }
  double cur = 0;

  fact[1] = 1;
  fact[2] = 0.5;
  for(int i = 3; i <= n ;i ++){
    fact[i] = 1.0 / i + (1.0 / i) * fact[i - 1];
   // cout << fact[i] << " ";
  }
//  cout << endl;

  getSon(0, 0);
  ans[0] = 0.0;
  solve(0);

  for(int i = 0; i < n; i ++){
    printf("%.1lf ", ans[i] + 1);
  }



  return 0;
}

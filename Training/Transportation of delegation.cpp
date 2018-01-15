#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 2605;
const int MAXN = 2605; // maximo numero de vertices
const int INF = 1000000000; // infinito
struct edge {
    int a, b, cap, flow;
};

int cont = 0,n, s, t, d[MAXN], ptr[MAXN], q[MAXN], id[MAXN];
string state[MAX];
bool exist[MAX][MAX];
map<string, int> idx;
vector<edge> e;
vector<int> g[MAXN];
void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;

    }

    return flow;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("delegation.in", "r", stdin);

  string name;
  int total, nraw, nfactory, m;
  cin >> n >> nraw >> nfactory >> m;
  cont = 1;
  s = 0;
  t = n + m + m + 1;
  n = n + m + m + 2;
  for(int i = 0; i < nraw; i ++){
    cin >> name;
    idx[name] = cont;
    add_edge(s, cont, 1);
    cont ++;
  }
  for(int i = 0; i < nfactory; i ++){
    cin >> name;
    idx[name] = cont;
    add_edge(cont, t, 1);
    cont ++;
  }
  for(int i = 0; i < m; i ++){
    cin >> total;
    for(int j = 0; j < total; j ++){
      cin >> state[j];
      if(idx.count(state[j]) == 0)
        idx[state[j]] = cont ++;
      id[j] = idx[state[j]];
    }
    int in = cont ++;
    int out = cont ++;
    add_edge(in, out, 1);
    for(int j = 0; j < total; j ++){
      add_edge(id[j], in, 1);
      add_edge(out, id[j], 1);
    }
  }
 /* for(int i = 0; i < e.size(); i ++){
    cout << e[i].a << " " << e[i].b << endl;
  }*/
  int ans = dinic();

  cout << ans << '\n';


  return 0;
}

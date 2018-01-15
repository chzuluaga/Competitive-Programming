#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair

using namespace std;
typedef long long ll;
const int MAXN1 = 3000;
const int MAXN2 = 6000;
const int MAXM = 150000;
const int MAX = 5000;

int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1], visit[MAX];

void init(int _n1, int _n2){
  n1 = _n1;
  n2 = _n2;
  edges = 0;
  fill(last, last + n1, -1);
}

void addEdge(int u, int v){
  head[edges] = v;
  prv[edges] = last[u];
  last[u] = edges ++;
}

void bfs(){
  fill(dist, dist + n1, -1);
  int sizeQ = 0;
  for(int u = 0; u < n1; ++ u){
    if(!used[u]){
      Q[sizeQ++] = u;
      dist[u] = 0;
    }
  }

  for(int i = 0; i < sizeQ; i ++){
    int u1 = Q[i];
    for(int e = last[u1]; e >= 0; e = prv[e]){
      int u2 = matching[head[e]];
      if(u2 >= 0 && dist[u2] < 0){
        dist[u2] = dist[u1] + 1;
        Q[sizeQ++] = u2;
      }
    }
  }
}

bool dfs(int u1){
  vis[u1] = true;
  for(int e = last[u1]; e >= 0; e = prv[e]){
    int v = head[e];
    int u2 = matching[v];
    if(u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)){
      matching[v] = u1;
      used[u1] = true;
      return true;
    }
  }
  return false;
}


int maxMatching(){
  fill(used, used + n1, false);
  fill(matching, matching + n2, -1);
  for(int res = 0;;){
    bfs();
    fill(vis, vis + n1, false);
    int f = 0;
    for(int u = 0; u < n1; u++)
      if(!used[u] && dfs(u))
        ++f;
      if(!f)
        return res;
      res += f;
  }
}

int getRowCol(char silla[], int col){
  int r = silla[0] - 'A';
  int l = strlen(silla);
  int c;
  if(l == 2){
    c = silla[1] - '0';
  }else{
    c = silla[2] - '0';
    c += (silla[1] - '0') * 10;
  }
  c --;

  return r * col + c;
}

int getArm(char silla[], string pos, int col){
  int r = silla[0] - 'A';
  int l = strlen(silla);
  int c = 0;
  if(l == 2){
    c = silla[1] - '0';
  }else{
    c = silla[2] - '0';
    c += (silla[1] - '0') * 10;
  }
  c --;
  if(pos[0] == '+')
    return r * (col + 1) + c + 1;
  return r * (col + 1) + c;
}



int main(){

    int r, c;
   //freopen("c.in", "r", stdin);

    char silla[7], pos[7];
    string mas = "+", menos = "-";
    while(true){
      scanf("%d%d", &r, &c);

      if(r == 0 && c == 0)
        break;
      memset(visit, 0, sizeof(visit));
      int n;
      init(r * c, r * (c + 1));

      scanf("%d", &n);

      for(int i = 0; i < n; i ++){
        scanf("%s%s",silla, pos);
        int idx = getArm(silla, pos, c);
        //cout << "arm occupied "<< idx << endl;
        visit[idx] = true;
      }

      scanf("%d", &n);

      for(int i = 0; i < n; i ++){
        scanf("%s", silla);
        int leftArm = getArm(silla, mas,  c);
        int rightArm = getArm(silla, menos,  c);
        //cout << leftArm << " " << rightArm << endl;
        if(!visit[leftArm]){
          //cout << " add edge between " << i << " "  << leftArm << endl;
          addEdge(i, leftArm);
        }
        if(!visit[rightArm]){
          //cout << " add edge between " << i << " "  << rightArm << endl;
          addEdge(i, rightArm);
        }
    }

    bool ans = (maxMatching() == n);
    if(ans)
      printf("YES\n");
    else
      printf("NO\n");



    }
    return 0;
}

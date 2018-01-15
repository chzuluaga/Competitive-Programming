#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 300005;
queue<int> q[MAX];
int bit[MAX];

void update(int pos, int val){
  for(int i = pos; i < MAX; i += i & -i)
    bit[i] += val;
}

int get(int pos){
  int r = 0;
  for(int i = pos; i; i -= i &-i)
    r += bit[i];

  return r;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  //freopen("c.in", "r", stdin);
  int n, m, read = 0, x, type;

  scanf("%d%d", &n, &m);
  int cont = 1;
  for(int i = 1; i <= m; i ++){
    scanf("%d%d", &type, &x);
    if(type == 1){
      update(cont, 1);
      q[x].push(cont);
      cont ++;
    }
    if(type == 2){
      while(!q[x].empty()){
        int cur = q[x].front();
        q[x].pop();
        if(cur <= read)
          continue;

        update(cur, -1);

      }
    }
    if(type == 3){
      if(x > read){
        int cur = get(x);
        //cout << x << " " << cur << endl;
        read = max(x, read);
        update(1, -cur);
      }
    }
    int r = get(m + 1);
    printf("%d\n", r);
  }

  return 0;
}

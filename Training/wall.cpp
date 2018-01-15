#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100005;
struct node{
  int lf, rg;
  node *L, *R;
  int up, down;
  node(){
    up = 0;
    down = MAX;
  }
  void create(int from, int to){
    lf = from, rg = to;

    if(from == to)
      return;
    int mit = (from + to) / 2;

    L = new node();
    R = new node();

    L->create(from, mit);
    R->create(mit + 1, to);
  }

  void add(int from, int to, int val){
    if(lf == from && rg == to){
      if(val >= up){
        if(val > down)
          down = val;
        up = val;
      }
      return ;
    }
    this -> expand();
    int mit =  L -> lf;
    if(to <= mit){
      L -> add(from, to, val);
      return;
    }
    if(from >= mit + 1){
      R -> add(from, to, val);
      return;
    }
    L -> add(from, mit, val);
    R -> add(mit + 1, to, val);
  }

  void remove(int from, int to, int val){
    if(lf == from && rg == to){
      if(val < down){
        if(val < up)
          up = val;
        down = val;
      }
      return ;
    }
    this -> expand();
    int mit =  L->rg;
    if(to <= mit){
      L -> remove(from, to, val);
      return;
    }
    if(from >= mit + 1){
      R -> remove(from, to, val);
      return;
    }
    L -> remove(from, mit, val);
    R -> remove(mit + 1, to, val);
  }


  void expand(){
    if(up > L->up){
      if(up > L->down){
        L->down = up;
      }
      L->up = up;
    }

    if(up > R->up){
      if(up > R->down){
        R->down = up;
      }
      R->up = up;
    }

    if(down < L->down){
      if(down < L->up){
        L->up = down;
      }
      L->down = down;
    }

    if(down < R->down){
      if(down < R->up){
        R->up = down;
      }
      R->down = down;
    }
    up = 0;
    down = MAX;
  }

  int answer(int from, int to){
    if(lf == from && rg == to){
      return up;
    }
    this -> expand();
    int mit =  L -> rg;
    if(to <= mit)
      return L -> answer(from, to);
    return R -> answer(from, to);
  }

};

int main(){
  //freopen("wall.in", "r", stdin);
  int n, k, type, from, to, val;
  scanf("%d%d",&n, &k);
  node root;
  root.create(0, n - 1);
  while(k --){
    scanf("%d%d%d%d", &type, &from, &to, &val);

    if(type == 1){
      root.add(from, to, val);
    }else{
      root.remove(from, to, val);
    }
  }

  for(int i = 0; i < n; i ++){
    printf("%d\n", root.answer(i,i));
  }

  return 0;
}

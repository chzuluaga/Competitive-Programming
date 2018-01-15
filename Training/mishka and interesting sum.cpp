#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

const int MAX = 1000005;
int arr[MAX], bit[MAX], ans[MAX];
map<int, int> prv;
struct query{
  int from, to, idx;

  bool operator <(query other)const{
    return to < other.to;
  }
}q[MAX];

void update(int pos, int val){
  for(int i = pos; i < MAX; i += i & -i)
    bit[i] ^= val;
}

int get(int pos){
  int r = 0;
  for(int i = pos; i ; i -= i &-i)
    r ^= bit[i];

  return r;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, m;
  scanf("%d", &n);

  for(int i = 1; i <= n; i ++)
    scanf("%d", &arr[i]);

  scanf("%d", &m);
  for(int i = 0; i < m; i ++){
    scanf("%d%d",&q[i].from,&q[i].to);
    q[i].idx = i;
  }

  sort(q, q + m);
  int end = 0;
  for(int i = 1; i <= n; i ++){
    int cur = arr[i];
    if(prv.count(cur)){
      int pos = prv[cur];
      update(pos, cur);
    }
    prv[cur] = i;

    while(end < m && i >= q[end].to){
      query aux = q[end];
      int r = get(aux.to) ^ get(aux.from - 1);
      ans[aux.idx] = r;
      end ++;
    }
  }

  for(int i = 0; i < m; i ++)
    printf("%d\n", ans[i]);

  return 0;
}

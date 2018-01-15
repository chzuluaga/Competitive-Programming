#include<bits/stdc++.h>

using namespace std;
const int MAX = 100005;
int bit[MAX], pos[MAX], arr[MAX],start[MAX], idx[MAX];
pair<int,int> tmp[MAX];

int mod = 9901;
inline int sub(int a, int b){return ((a - b) + mod) % mod;}
inline int sum(int a, int b){return (a + b) % mod;}

void update(int p, int val){
	val %= mod;
  for(int i = p; i < MAX; i += i & -i){
    bit[i] += val;
    bit[i] %= mod;
  }
}
int get(int p){
  int s = 0;
  for(int i = p; i > 0; i -= i & -i)
    s = sum(s, bit[i]);
  return s;
}
int main(){

  int n, m;
  freopen("travers.in", "r", stdin);

  scanf("%d%d", &n,&m);

  for(int i = 1; i <= n; i ++){
    scanf("%d", &arr[i]);
    tmp[i].first = arr[i];
    tmp[i].second = i;
  }

  sort(tmp + 1, tmp + n + 1);
	
	for(int i = 1; i <= n; i ++)
		idx[tmp[i].second] = i;
		
  int cur = n;

  for(int i = n; i > 0; i --){
  //  cout << tmp[cur].first << " -- " << tmp[i].first << endl;
    while(tmp[cur].first - tmp[i].first > m){
      cur --;
    }
  //  cout << tmp[cur].first << " -*-" << tmp[i].first << endl;
    pos[tmp[i].second] = cur;
  }
  cur = 1;
  for(int i = 1; i <= n; i ++){
  //  cout << tmp[cur].first << " -- " << tmp[i].first << endl;
    while(tmp[i].first - tmp[cur].first > m){
      cur ++;
    }
  //  cout << tmp[cur].first << " -*-" << tmp[i].first << endl;
    start[tmp[i].second] = cur;
  }

  for(int i = n; i > 0; i --){
   // cout << i << " " << arr[i] << " " << pos[i] << " " << start[i] << endl;
    int s = sub(get(pos[i]), get(start[i] - 1));
   // cout << s << endl;
    update(idx[i], (s + 1) % mod);
  }

  int ans = sub (get(n), n);

  printf("%d\n", ans);
  return 0;
}

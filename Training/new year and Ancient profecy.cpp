#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 5006;
int lessThan[MAX][MAX];
ll bit[MAX][MAX], mod = 1000000007ll;

ll add(ll a, ll b){return (a + b) % mod;}
ll sub(ll a, ll b){return (a - b + mod) % mod;}

void update(int idx, int pos, ll val){
  for(int i = pos; i < MAX; i += i & -i){
    bit[idx][i] += val;
    bit[idx][i] %= mod;
  }
}

ll get(int idx, int pos){
  ll ans = 0;
  for(int i = pos; i; i -= i & -i){
    ans += bit[idx][i];
    ans %= mod;
  }

  return ans;
}
char num[MAX];
bool isSmaller(int x, int y, int tam){
	return lessThan[x][y] < tam && num[x + lessThan[x][y]] < num[y + lessThan[x][y]];
}
int main(){
	
	//freopen("profecy.in", "r", stdin);
  

  int n;
  scanf("%d%s", &n, num);
  
 // cout << n << " " << num << endl;

  for(int i = n; i >= 0; i --){
		for(int j = n; j >= 0; j --){
			if(i == n || j == n)
				lessThan[i][j] = 0;
			else
				if(num[i] != num[j])
					lessThan[i][j] = 0;
				else
					lessThan[i][j] = lessThan[i + 1][j + 1] + 1;
		}
	}
	
	ll ans = 0;
  for(int i = n - 1; i >= 0; i --){
    for(int j = 1; j <= n; j ++){
      int nxt = i + j;
      if(num[nxt] == '0')
				continue;
      ll sol = 0;
      if(nxt == n)
        sol ++;
			if(nxt + j <= n){
				if(!isSmaller(i, nxt, j)){
					if(nxt + j < n)
						sol = add(sol, sub (get(nxt, MAX) , get(nxt, nxt + j)));
				}else{
					 sol = add(sol, sub (get(nxt, MAX) , get(nxt, nxt + j - 1)));
				}
			}
      update(i, i + j, sol);
      if(i == 0){
        ans = add(ans, sol);
      }
    }


  }

  printf("%d", ans);
  return 0;
}

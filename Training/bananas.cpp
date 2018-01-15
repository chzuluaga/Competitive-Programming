#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
ll mod = 1000000007ll;
const int MAX = 3, n = 2;
struct matrix{ ll ma[MAX][MAX];};
matrix matMul(matrix a, matrix b) {
  matrix ans;  int i, j, k;
  for(i = 0; i < n; i ++)
    for(j = 0; j < n; j ++)
      for(ans.ma[i][j] = k = 0; k < n; k ++){
        ans.ma[i][j] += (a.ma[i][k] * b.ma[k][j]) % mod;
        ans.ma[i][j] %= mod;
      }
  return ans;
}
matrix matPow(matrix base, ll p){
  matrix ans;
  for (int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++) // cosntruct identity matrix
      ans.ma[i][j] = (i == j);
  while(p){
    if(p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}

int main(){
  int t;
  
  scanf("%d", &t);
  
  while(t --){
		ll k;
		scanf("%lld", &k);
		matrix cur; //fill matrix cur
		cur.ma[0][0] = 0;
		cur.ma[0][1] = cur.ma[1][0] = cur.ma[1][1] = 1;
		matrix ans = matPow(cur, k);
		
		matrix b;
		b.ma[0][1] = b.ma[1][1] = 0;
		b.ma[0][0] = 1;
		b.ma[1][0] = 1;
		ans = matMul(ans, b);
		printf("%lld\n", ans.ma[1][0]);
	}
  
  
 
 return 0;
}


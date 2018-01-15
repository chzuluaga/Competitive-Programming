#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 103;
ll arr[MAX], n, mod = 1000000007ll;
struct matrix{
  ll ma[MAX][MAX];
};

matrix matMul(matrix a, matrix b) {
  matrix ans;
  int i, j, k;
  for(i = 0; i < n; i ++){
    for(j = 0; j < n; j ++){
      for(ans.ma[i][j] = k = 0; k < n; k ++){
        ans.ma[i][j] += (a.ma[i][k] * b.ma[k][j]) % mod;
        ans.ma[i][j] %= mod;
      }
    }
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
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
  ll k;
  cin >> n >> k ;

  for(int i = 0; i < n; i ++)
    cin >> arr[i];

  matrix cur;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      if((__builtin_popcountll(arr[i] ^ arr[j])) % 3 == 0)
        cur.ma[i][j] = 1ll;
      else
        cur.ma[i][j] = 0ll;
    }
  }


  if(k == 0){
    cout << n << "\n";
    return 0;
  }

  matrix ans = matPow(cur, k - 1);
  ll sol = 0;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      sol += ans.ma[i][j];
      sol %= mod;
    }
  }

  cout << sol << '\n';
  return 0;
}

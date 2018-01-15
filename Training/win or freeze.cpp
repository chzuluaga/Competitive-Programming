#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("win.in","r", stdin);
  ll n;
  cin >> n;
  bool isPrime = true;

  ll ans = 1, cont = 0;
  queue<ll> q;
  ll tmp = n;
  for(ll i = 2ll; i <= n && i < tmp; i ++){
    if(i * i > n){
        cont ++;
        if(cont <= 2)
          ans *= n;

        break;
    }
    while(n % i == 0){
      //cout << n << endl;
      isPrime = false;
      n /= i;
      ans *= i;
      cont ++;
      if(cont > 2){
        ans /= i;
        n = 0;
        break;
      }
     // cout << n << endl;
  //    cout << i << " "<< endl;
    }
 //   cout << n << endl;
  }


  if(isPrime){
    cout << "1 0\n";
    return 0;
  }
  if(cont >= 3){
      cout << "1\n" << ans << '\n';
  }else{
    cout << "2\n";
  }



  return 0;
}

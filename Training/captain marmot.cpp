#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll  pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll ;
const ll MAX = 103;
struct MOLE{
  ll x, y, a, b;
}mole[4];
void rot(ll cur){
  ll s = 1;
  ll c = 0;
  ll px = mole[cur].x - mole[cur].a;
  ll py = mole[cur].y - mole[cur].b;
  ll xnew = px * c - py * s;
  ll ynew = px * s + py * c;

  mole[cur].x = xnew + mole[cur].a;
  mole[cur].y = ynew + mole[cur].b;
}

ll pot(ll x){return x*x;}
ll dis(ll i, ll j){
  return pot(mole[i].x - mole[j].x) + pot(mole[i].y - mole[j].y);
}

bool square(){
  set<ll> s;
  set<ll>::iterator it;
  int a = 0, b, c, d;
  for(int i = 1; i < 4; i ++)
    s.insert(dis(0,i));

  if(s.size() != 2)
    return false;

  it = s.begin();
  ll z = *it;
  it ++;
  ll x = *it;
  for(int i = 1; i < 4; i ++){
    if(dis(0, i) == x){
      c = i;
      if(i == 1){
        b = 2;
        d = 3;
      }
      if(i == 2){
        b = 1;
        d = 3;
      }
      if(i == 3){
        b = 1;
        d = 2;
      }
      break;
    }
  }
/*  cout << endl << endl;
  for(int i = 0; i < 4; i ++){
    cout << mole[i].x << " " << mole[i].y << endl;
  }
  cout << "z es = " << z << " x es = " << x << endl;
  cout << a << " - " << b << " - " << c << " - " << d << endl;
*/
  if(dis(a, b) == z && dis(a, d) == z && dis(a, c) == x)
    if(dis(b, d) == x && dis(b, c) == z)
      if(dis(d, c) == z)
        return true;
  return false;

}
int main(){
  int n;
  //freopen("cuad.in", "r",stdin);
 // freopen("cuad.out", "w",stdout);
  scanf("%d", &n);

  for(ll i = 0; i < n; i ++){
    ll sum = INT_MAX;
    for(ll j = 0; j < 4; j ++)
      scanf("%lld%lld%lld%lld", &mole[j].x, &mole[j].y, &mole[j].a, &mole[j].b);
    for(ll j = 0; j < 4; j ++){
      if(j)
        rot(0);
      for(ll k = 0; k < 4; k ++){
        if(k)
          rot(1);
        for(ll l = 0; l < 4; l ++){
          if(l)
            rot(2);
          for(ll m = 0; m < 4; m ++){
            if(m)
              rot(3);
           // cin >> n;
           // cout << j + k + l + m << endl;
            if(square()){
              sum = min(sum, j + k + l + m);
              /*if(j + k + l + m == 1){
                cout << endl << j << " " << k << " " << l << " " << m << " " << endl;
                for(int w = 0; w < 4; w ++)
                  cout << mole[w].x << " " << mole[w].y << endl;
                cout << endl;
              }*/
            }

          }
          rot(3);
        }
        rot(2);
      }
      rot(1);
    }
    rot(0);
    if(sum < INT_MAX)
      printf("%d\n", sum);
    else
      printf("-1\n");
  }

  return 0;
}

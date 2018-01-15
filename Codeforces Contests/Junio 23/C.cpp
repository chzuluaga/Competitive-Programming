#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

ll n, m, sev[15];
vector<int> hh;
map<string, bool> ans;

bool okH(int a, int b){
  int cont = 0;
  ll val = 0;
  int sz = hh.size();
  for(int i = sz - 1 - b; i > sz - 1 - a - b ; i --){
    val += sev[cont ++] * hh[i];

  //  cout << hh[i] << " - ";
  }
//  cout << endl;
  //if(val <= n)
  //cout << val << " en ok hora " << endl;
  return val < n;
}

bool okM(int a){
  int cont = 0;
  ll val = 0;
  int sz = hh.size();
  for(int i = sz - 1; i > sz - 1 - a ; i --){
    val += sev[cont ++] * hh[i];

    //cout << hh[i] << " * ";
  }
//  cout << endl;
  //cout << val << "en ok min\n";

  return val < m;
}

ll solve(int a, int b){


  for(int i = 0; i < 7; i ++)
    hh.pb(i);
  string s = "";
  do{
    if(okH(a, b) && okM(b)){
      s = "";
      for(int i = hh.size() - 1; i > (int)(hh.size()) - 1 - a - b; i --){
        s += hh[i] + '0';
      }

      if(s.size()){
        ans[s] = true;
      //  cout << s << endl;
      }
    }

  }while(next_permutation(hh.begin(), hh.end()));

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  ll pot = 1ll, tmpn = n - 1, tmpm = m - 1;

  for(int i = 0; i < 13; i ++){
    sev[i] = pot;
    pot *= 7ll;
    //cout << sev[i] << endl;
  }

  int contn = 0, contm = 0;

  while(tmpn){
    tmpn /= 7;
    contn ++;
  }
  while(tmpm){
    tmpm /= 7;
    contm ++;
  }
  contn = max(contn, 1);
  contm = max(contm, 1);


  if(contn + contm > 7){
    cout << 0 << '\n';
    return 0;
  }
 // cout << contn << " " << contm << endl;

  solve(contn, contm);

  cout << ans.size() << '\n';


  return 0;
}

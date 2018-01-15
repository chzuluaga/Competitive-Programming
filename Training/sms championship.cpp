#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pdd pair<double, double>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
int tc = 0;
int visit[1000][12][12];
double memo[1000][12][12];
string cad;
map<char, pdd > pos;

string change(char cur){
  string ans = "";
  if(cur == ' ')
    return "0";
  if(cur >= 'a' && cur <= 'c')
    for(int i = 0; i <= (cur - 'a'); i ++)
      ans += "2";
  if(cur >= 'd' && cur <= 'f')
    for(int i = 0; i <= (cur - 'd'); i ++)
      ans += "3";
  if(cur >= 'g' && cur <= 'i')
    for(int i = 0; i <= cur - 'g'; i ++)
      ans += "4";
  if(cur >= 'j' && cur <= 'l')
    for(int i = 0; i <= (cur - 'j'); i ++)
      ans += "5";
  if(cur >= 'm' && cur <= 'o')
    for(int i = 0; i <= (cur - 'm'); i ++)
      ans += "6";
  if(cur >= 'p' && cur <= 's')
    for(int i = 0; i <= (cur - 'p'); i ++)
      ans += "7";
  if(cur >= 't' && cur <= 'v')
    for(int i = 0; i <= (cur - 't'); i ++)
      ans += "8";
  if(cur >= 'w' && cur <= 'z')
    for(int i = 0; i <= (cur - 'w'); i ++)
      ans += "9";

  return ans;
}


void convert(string& s){
  cad = "";
  string aux, last = "";
  for(int i = 0; i < s.size(); i ++){
    aux = change(s[i]);
    if(aux[0] == last[0])
      cad += "#";
    cad += aux;
    last = aux[0];
  }
  return;
}

void fillPos(){
  pos['2'] = mp(0.5,1.5);
  pos['3'] = mp(0.5,2.5);
  pos['4'] = mp(1.5,0.5);
  pos['5'] = mp(1.5,1.5);
  pos['6'] = mp(1.5,2.5);
  pos['7'] = mp(2.5,0.5);
  pos['8'] = mp(2.5,1.5);
  pos['9'] = mp(2.5,2.5);
  pos['0'] = mp(3.5,1.5);
  pos['#'] = mp(3.5,2.5);

}

double pot(double x){return x*x;}

double dis(char from, char to){

  pdd p1 = pos[from];
  pdd p2 = pos[to];

  return sqrt( pot(p1.first - p2.first) + pot(p1.second - p2.second) );

}

double solve(int idx, char lf, char rg){
  if(idx == cad.size())
    return 0.0;
  int L, R;
  if(lf == '#')
    L = 1;
  else
    L = lf - '0';

  if(rg == '#')
    R = 1;
  else
    R = rg - '0';

 // cout << idx << " " << L << " " << R << endl;

  double& ans = memo[idx][L][R];
  if(visit[idx][L][R] == tc)
    return ans;
  visit[idx][L][R] = tc;
  ans = 0.0;

  ans = dis(lf, cad[idx]) + solve(idx + 1, cad[idx], rg);
  ans = min(ans, dis(rg, cad[idx]) + solve(idx + 1, lf, cad[idx]));

  return ans;
}

int main(){
  //freopen("sms.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  fillPos();
  while(getline(cin, s)){
    //cout << s << endl;
    tc ++;
    convert(s);
    //cout << cad << endl;
    //return 0;
    double r = solve(0,'4','6');
    //cout << "r es " << endl;
    int sz = cad.size();

    double ans = r / 30.0 + sz * 0.2;
    cout << fixed << setprecision(2);
    cout << ans << '\n';

  }

  return 0;
}

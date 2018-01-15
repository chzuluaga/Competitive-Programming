#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

bool rev(char a, char b){
  if(a == 'b' && b == 'd')
    return true;

  if(b == 'b' && a == 'd')
    return true;

  if(a == 'x' && b == 'x')
    return true;

  if(a == 'o' && b == 'o')
    return true;

  if(a == 'O' && b == 'O')
    return true;

  if(a == 'H' && b == 'H')
    return true;
  if(a == 'T' && b == 'T')
    return true;

  if(a == 'v' && b == 'v')
    return true;

  if(a == 'V' && b == 'V')
    return true;

  if(a == 'Y' && b == 'Y')
    return true;

  if(a == 'I' && b == 'I')
    return true;
  if(a == 'X' && b == 'X')
    return true;

  if(a == 'p' && b == 'q')
    return true;
  if(a == 'q' && b == 'p')
    return true;

  if(a == 'w' && b == 'w')
    return true;

  if(a == 'W' && b == 'W')
    return true;

  if(a == 'M' && b == 'M')
    return true;

  if(a == 'U' && b == 'U')
    return true;

  if(a == 'A' && b == 'A')
    return true;

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s, yes = "TAK", no = "NIE";

  cin >> s;
  int prev = s.size() - 1;
  for(int i = 0; i < s.size(); i ++){
    if(!rev(s[i], s[prev])){
      cout << no << '\n';
      return 0;
    }
    prev --;
  }

  cout << yes << '\n';

  return 0;
}

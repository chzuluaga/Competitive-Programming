#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 1000006;

int main(){
  string s, fs = "", sc = "";
  cin >> s;

  bool f = false;

  for(int i = 0; i < s.size(); i ++){
    if(s[i] == '.')
      f = true;
    else{
      if(!f)
        fs += s[i];
      else
        sc += s[i];
    }
  }

  cout << fs << " " << sc << endl;


  return 0;
}

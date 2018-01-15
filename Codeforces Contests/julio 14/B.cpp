#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;

int toNum(string pal){
  char * cstr = new char [pal.length()+1];
  strcpy (cstr, pal.c_str());
  return atoi(cstr);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;

  cin >> s;
  string num = "", e = "";
  for(int i = 0; i < s.size(); i ++){
    if(s[i] == 'e'){
      for(int j = i + 1; j < s.size(); j ++){
        e += s[j];
      }
      break;
    }else{
      num += s[i];
    }
  }

  int ee = toNum(e);
  int cur = 1;
  while(ee){
    if(cur == num.size() - 1){
      num += '0';
    }
    swap(num[cur], num[cur + 1]);
    cur ++;
    ee --;
  }
  int sz = num.size();

  if(num[num.size() - 1] == '.'){
    num[num.size() - 1] = ' ';
    sz --;
  }
  num += " ";
  bool flag = true, f2 = true;
  for(int i = 0; i < sz; i ++){
    if(num[i] == '0'){
      if(!(num[i + 1] == '.') && flag)
        continue;
    }
    if(num[i] == '.'){
      for(int j = num.size() - 1; j > i ; j --){
        if(num[j] == '0' || num[j] == ' ')
          num[j] = ' ';
        else
          break;
      }
      if(num[i + 1] == ' ')
        break;
    }

    flag = false;
    cout << num[i];

  }

  return 0;
}

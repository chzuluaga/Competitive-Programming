#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

map<string, int> day;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string d1, d2;
  cin >> d1 >> d2;
  
  day["monday"] = 0;
  day["tuesday"] = 1;
  day[ "wednesday"] = 2;
  day["thursday"] = 3;
  day["friday"] = 4;
  day["saturday"] = 5;
  day["sunday"] = 6;
  
  int diff = (day[d2] - day[d1] + 7) % 7;
  
  if(diff == 0 || diff == 3 || diff == 2)
		cout << "YES\n";
	else
		cout << "NO\n";
  

  return 0;
}

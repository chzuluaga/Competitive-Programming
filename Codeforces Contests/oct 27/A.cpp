#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, cont = 0;
  int x, y, z;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  
  if(a > x)
		cont += (a - x) / 2;
	
	if(b > y)
		cont += (b - y) / 2;
	
	if(c > z)
		cont += (c - z) / 2;
		
	
	if(a < x)
		cont -= (x - a);
	
	if(b < y)
		cont -= (y - b);
	
	if(c < z)
		cont -= (z - c);
		
	if(cont >= 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	
	
	
	
  return 0;
}

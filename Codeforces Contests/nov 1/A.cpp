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
  
  int n, m;
  cin >> n >> m;
  string isColor = "#Color", black = "#Black&White", pixel;
  bool color = false;
  for(int i = 0; i < n; i  ++)
		for(int j = 0; j < m; j ++){
			cin >> pixel;
			if(pixel[0] != 'W' && pixel[0] != 'B' && pixel[0] != 'G')
				color = true;
		}
		
	if(color)
		cout << isColor << '\n';
	else
		cout << black << '\n';
	
  

  return 0;
}

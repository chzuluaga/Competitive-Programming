#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
pii a[5];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  
  cin >> s;
  int n = (int)s.size();
  
  for(int i = 0; i < n;i ++){
		if(s[i] == '!')
			a[i%4].second ++;
		else{
			if(s[i] == 'R')
				a[i%4].first = 0;
			if(s[i] == 'B')
				a[i%4].first = 1;
			if(s[i] == 'Y')
				a[i%4].first = 2;
			if(s[i] == 'G')
				a[i%4].first = 3;
		}
	}
	
	sort(a, a + 4);
	
	for(int i = 0; i < 4; i ++)
		cout << a[i].second << "\n";
			
	

  return 0;
}

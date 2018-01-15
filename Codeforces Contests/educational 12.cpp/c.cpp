#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

char diff(char a, char b){
	int r;
	char x;
	do{
	 r = rand() % 26;
	 x = r + 'a';
	}while(x == a || x == b);
	
	return x;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	srand(time(NULL));
	string s;
	cin >> s;
	
	for(int i = 1; i < (int) s.size(); i ++){
		if(s[i] == s[i - 1]){
			if(i + 1 < (int)s.size()){
				s[i] = diff(s[i + 1], s[i - 1]);
			}else{
				s[i] = diff(s[i - 1], 'a');
			}
		}
	}
	cout << s << '\n';
  return 0;
}

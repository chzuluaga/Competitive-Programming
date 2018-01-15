#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int mrk[30];
char ma[3][14];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  string s, no = "Impossible";
  cin >> s;
  int a, b;
  int n = s.size();
  memset(mrk, -1, sizeof(mrk));
  for(int i = 0; i < 27; i ++){
		int c = s[i] - 'A';
		if(mrk[c] != -1){
			a = mrk[c];
			b = i;
			break;
		}
		mrk[c] = i;
	}
	
	if(a == b - 1){
		cout << no << '\n';
		return 0;
	}
	//cout << a << " " << b << endl;
  int dis = ((b - a) - 1) / 2;
  int idx = a;
  //cout << dis << endl;
  for(int i = 12 - dis; i < 13; i ++){
		//cout << s[idx] << endl;
		ma[0][i] = s[idx];
		idx ++;
	}
	
	for(int i = 12; i >= 0; i --){
		ma[1][i] = s[idx ++];
		if(idx == b)
			idx ++;
		if(idx == n)
			idx = 0;
	}
	
	for(int i = 0; ; i ++){
		if(idx == a)
			break;
		ma[0][i] = s[idx ++];
		if(idx == n)
			idx = 0;
		if(idx == a)
			break;
	}
	
	for(int i = 0; i < 2; i ++){
		for(int j = 0; j < 13; j ++)
			cout << ma[i][j];
		cout << '\n';
	}
	
  return 0;
}

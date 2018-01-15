#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1 , -1};

int replace(char x){
	return x - 'a';
}

bool ok(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int ans = 0;
  string move;
  cin >> move;
  
  int c = replace(move[0]);
  int r = move[1] - '0';
  r --;
  
  
  for(int i = 0; i < 8; i ++){
		if(ok(r + dx[i], c + dy[i]))
			ans ++;
	}
	
	cout << ans << '\n';

  return 0;
}

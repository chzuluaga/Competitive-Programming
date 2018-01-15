#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

int ma[50][50];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n;
	cin >> n;
  int r = 0, c = n / 2;
  for(int i = 1; i <= n * n; i ++){
		ma[r][c] = i;
		
		int newr = (r - 1 + n) % n;
		int newc = (c + 1) % n;
		if(ma[newr][newc] == 0)
			r = newr, c = newc;
		else
			r = (r + 1) % n;
	}
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			printf("%d ", ma[i][j]);
		}
		printf("\n");
	}
  
  

  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 103;
int ans[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
		
	int n, m;
	
	scanf("%d%d", &n, &m);
	int sol = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			int x;
			cin >> x;
			if(j == 0)
				ans[i] = x;
			ans[i] = min(x, ans[i]);
		}
		sol = max(sol, ans[i]);
	}
	
	printf("%d\n", sol);

  return 0;
}

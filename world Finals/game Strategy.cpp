#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAX = 30;
vector<int> g[30];
int ans[MAX][MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  memset(ans, -1, sizeof(ans));
  int n;
  string s;
  cin >> n;
  for(int i = 0; i < n; i ++){
		int m;
		cin >> m;
		for(int j = 0; j < m; j ++){
			cin >> s;
			int tmp = 0;
			for(int k = 0; k < (int) s.size(); k ++){
				tmp |= (1<<(int)(s[k] - 'a'));
			}
			g[i].pb(tmp);
		}
	}
	
	for(int i = 0; i < n; i ++){
		ans[i][i] = 0;
		int cur = 1 << i;
		for(int r = 1; ; r ++){
			int newMask = cur;
			for(int j = 0; j < n; j ++){
				if(cur & 1<<j)	continue;
				for(int k = 0; k < (int) g[j].size(); k ++){
					if((cur & g[j][k]) == g[j][k]){
						ans[j][i] = r;
						newMask |= 1<<j;
						break;
					}
				}
			}
			if(newMask == cur)
				break;
			cur = newMask;
		}
	}
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(j)	cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	

  return 0;
}

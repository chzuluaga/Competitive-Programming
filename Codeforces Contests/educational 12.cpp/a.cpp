#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 103;

int a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, m, k, x;
  
  cin >> n >> m >> k;
  
  for(int i = 0; i < k; i ++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i ++){
		
		for(int j = 0;j < m; j ++){
			cin >> x;
			
			for(int l = 0; l < k; l ++){
				if(a[l] == x){
					ans += l + 1;
					for(int o = l; o > 0; o --){
						swap(a[o], a[o - 1]);
					}
					
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	

  return 0;
}

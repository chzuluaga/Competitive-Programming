#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 22;
int ma[MAX][MAX], a[MAX][MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, m;
  
  scanf("%d%d", &n, &m);
  
  for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++){
			scanf("%d", &ma[i][j]);
			ma[i][j] --;
		}
			


	
	for(int k = 0; k < m; k ++){
		for(int l = k; l < m; l ++){
			bool ans = true;
			
			for(int i = 0;i < n; i ++)
				for(int j = 0;j < m;j ++)
					a[i][j] = ma[i][j];
					
			for(int i = 0; i < n && ans; i ++){
				bool f = true;
				swap(a[i][k], a[i][l]);
				for(int j = 0; j < m ;j ++){
					if(a[i][j] != j){
						if(f){
							f = false;
							swap(a[i][j], a[i][a[i][j]]);
							if(a[i][j] != j){
								ans = false;
								break;
							}
						}else{
							ans = false;
							break;
						}
					}
				}
			}
			
			if(ans){
				cout << "YES\n";	
				return 0;
			}
		}
	}
	
	cout << "NO\n";
	

  return 0;
}

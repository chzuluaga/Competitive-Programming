#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1004;
int	ma[MAX][MAX], eq[MAX][MAX], up[MAX][MAX], down[MAX][MAX];

int main(){
  
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				scanf("%d", &ma[i][j]);
				ma[i][j] -= (i + j);
				eq[i][j] = 1;
				if(j && ma[i][j - 1] == ma[i][j])
					eq[i][j] += eq[i][j - 1];
			}
		}
		
		for(int j = 0; j < m;j ++){
			
			vector<int> st;
			for(int i = 0; i < n; i ++){
				if(!st.empty() && ma[st.back()][j] != ma[i][j]){
					while(!st.empty())
						st.pop_back();
					up[i][j] = i;
				}else{
					if(st.empty())
						up[i][j] = i;
					else{
						while(!st.empty() && eq[st.back()][j] >= eq[i][j]){
							up[i][j] = up[st.back()][j];
							st.pop_back();
						}
						if(!st.empty())
							up[i][j] = st.back() + 1;
					}
				}
				
				st.push_back(i);
			}
		}
		
		for(int j = 0; j < m;j ++){
			vector<int> st;
			for(int i = n - 1; i >= 0; i --){
				if(!st.empty() && ma[st.back()][j] != ma[i][j]){
					while(!st.empty())
						st.pop_back();
					down[i][j] = i;
				}else{
					if(st.empty())
						down[i][j] = i;
					else{
						while(!st.empty() && eq[st.back()][j] >= eq[i][j]){
							down[i][j] = down[st.back()][j];
							st.pop_back();
						}
						if(!st.empty())
							down[i][j] = st.back() - 1;
					}
				}
				st.push_back(i);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				ans = max(ans, eq[i][j] * (down[i][j] - up[i][j] + 1));
			}
		}
		printf("%d\n", ans);
		
	}
  return 0;
}

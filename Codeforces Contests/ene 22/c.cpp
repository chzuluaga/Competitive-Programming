#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;

int p[MAX], b[MAX], visit[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, ans = 0, cont = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", &p[i]);
		p[i] --;
	}
	for(int i = 0; i < n; i ++){
		scanf("%d", &b[i]);
		if(b[i])
			cont ++;
	}
	for(int i = 0; i < n; i ++){
		if(!visit[i]){
			ans ++;
			int cur = i;
			while(!visit[cur]){
				visit[cur] = 1;
				cur = p[cur];
			}
		}
	}
	if(ans == 1)
		ans --;
	
	
	if(cont % 2 == 0)
		ans ++;

	printf("%d\n", ans);
  return 0;
}

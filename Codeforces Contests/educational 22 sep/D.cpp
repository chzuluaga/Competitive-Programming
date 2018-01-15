#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1000005;
int finish[MAX];
map<int,int> app;
int a[MAX], tmp[MAX];

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, m, x;
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		tmp[i] = a[i];
		if(a[i] > m)
			continue;
		
		app[a[i]] ++;
		
		if(app[a[i]] > 1)
			a[i] = m + 1;
	}
	int ans = 0, idx = 0;
	for(int i = 0; i < n; i ++){
		x = a[i];
		int r = app[x];
		if(a[i] > m)
			continue;
		for(int j = x; j <= m; j += x){
			finish[j] += r;
			if(finish[j] > ans){
				ans = finish[j];
				idx = j;
			}
		}
	}
	if(ans == 0){
		printf("1 0\n");
		return 0;
	}
	printf("%d %d\n", idx, ans);
	for(int i = 0; i < n; i ++){
		if(idx % tmp[i] == 0)
			printf("%d ", i + 1);
	}
	printf("\n");
	

	
		
	
  return 0;
}

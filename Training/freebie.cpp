#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 105;
int a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	sort(a, a + n);
	int rg = 0, ans = 1;
	for(int i = 0; i < n ; i ++){
		while(rg < n && a[rg] - a[i] <= t){
			rg ++;
		}
		ans = max(ans, rg - i);
	}
	
	printf("%d\n", ans);
	
  return 0;
}

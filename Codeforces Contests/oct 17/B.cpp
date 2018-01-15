#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 505;

int a[MAX];
int n, k;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	scanf("%d%d", &n, &k);
	
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
		
	int ans = 0;
	
	for(int i = 1; i < n; i ++){
		if(a[i] + a[i - 1] < k){
			ans += k - a[i] - a[i - 1];
			a[i] += k - a[i] - a[i - 1];
		}
	}
	
	printf("%d\n", ans);
	for(int i = 0; i < n; i ++)
		printf("%d ", a[i]);
	return 0;
}

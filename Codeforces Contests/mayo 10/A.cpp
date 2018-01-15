#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAX = 500005;
int a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("a.in", "r", stdin);
  //freopen("a2.out", "w", stdout);
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	
	int prv = -1, cnt = 0, ans = 0;
	for(int i = 1; i < n - 1; i ++){
		if(a[i] != a[i - 1] && a[i] != a[i + 1]){
			cnt ++;
			if(prv == -1)
				prv = i;
		}else{
			if(prv != -1){
				for(int j = prv; j < i; j ++){
					if(j < (i + prv) / 2)
						a[j] = a[prv - 1];
					else
						a[j] = a[i];
				}
			}
			ans = max(ans, (cnt + 1) / 2 );
			cnt = 0;
			prv = -1;
		}
	}
	if(prv != -1){
		ans = max(ans, (cnt + 1) / 2 );
		for(int j = prv; j < n - 1; j ++){
			if(j < (n - 1 + prv) / 2)
				a[j] = a[prv - 1];
			else
				a[j] = a[n - 1];
		}
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i ++){
		if(i)	printf(" ");
		printf("%d",a[i]);
	}
	printf(endl);

  return 0;
}

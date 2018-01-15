#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define LL "%I64d"
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 500004;
ll a[MAX];
char s[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf(LL, &a[i]);
	
	scanf("%s", s);
	
	ll sum = 0, ans = 0;
	
	for(int i = 0; i < n; i ++){
		if(s[i] == 'B')
			sum += a[i];
	}
	ll tmp = sum;
	ans = sum;
	for(int i = 0; i < n; i ++){
		if(s[i] == 'A'){
			sum += a[i];
		}else{
			sum -= a[i];
		}
		ans = max(ans, sum);
	}
	sum = tmp;
	for(int i = n - 1; i >= 0; i --){
		if(s[i] == 'A'){
			sum += a[i];
		}else{
			sum -= a[i];
		}
		ans = max(ans, sum);
	}
	
	printf(LL "\n", ans);
	
	return 0;
}

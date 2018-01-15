#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1000005;
ll a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	int N = 2 * n * k;
	for(int i = 0; i < N; i ++)
		scanf("%lld", &a[i]);
	
	sort(a, a + N);
	
	ll lo = 0, hi = a[N - 1], mit;
	
	while(lo < hi){
		ll need = 0, r = n;
		mit = lo + hi;
		mit /= 2;
		for(int i = 0; i < N; i ++){
			if(i + 1 < N && a[i + 1] - a[i] <= mit && r){
				need += (k - 1) * 2;
				i ++;
				r --;
			}else{
				need --;
				if(need < 0)
					break;
			}
		}
		if(r == 0 && need == 0)
			hi = mit;
		else
			lo = mit + 1;
		//cout << mit << " " << r << " " << need << endl;	
	}
	
	printf("%lld\n", lo);
	
  return 0;
}

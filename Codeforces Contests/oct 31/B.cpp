#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int a[MAX], b[MAX];
int main(){
	//ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, suml = 0, sumr = 0, ans , idx = 0;
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++){
		scanf("%d%d", &a[i], &b[i]);
		suml += a[i];
		sumr += b[i];
	}
	ans = abs(suml - sumr);
	
	for(int i = 0; i < n; i ++){
		suml -= a[i];
		suml += b[i];
		
		sumr -= b[i];
		sumr += a[i];
		
		if(abs(suml - sumr) > ans){
			ans = abs(suml - sumr);
			idx = i + 1;
		}
		
		suml += a[i];
		suml -= b[i];
		
		sumr += b[i];
		sumr -= a[i];
	}
	//cout << ans << endl;
	printf("%d\n", idx);

  return 0;
}

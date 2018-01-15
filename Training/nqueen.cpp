#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 305;
int n, col[MAX], dia1[2*MAX], dia2[2*MAX];
void solve(){
	int r = n % 6;
	if(r == 2 || r == 3){
		vector<int> even, odd;
		if(r == 2){
			for(int i = 2; i <= n; i += 2)
				even.pb(i);
			odd.pb(3);
			odd.pb(1);
			for(int i = 7; i <= n; i += 2)
				odd.pb(i);
			odd.pb(5);
		}else{
			for(int i = 4; i <= n;i += 2)
				even.pb(i);
			even.pb(2);
			for(int i = 5; i <= n; i += 2)
				odd.pb(i);
			odd.pb(1);
			odd.pb(3);
		}
		for(int i = 0; i < (int)even.size(); i ++)
			printf(" %d\n", even[i] - 1);
		for(int i = 0; i < (int)odd.size();i ++)
			printf(" %d\n", odd[i] - 1);
	}else{
		for(int i = 2; i <= n; i += 2)
			printf(" %d\n", i - 1);
		for(int i = 1; i <= n; i += 2)
			printf(" %d\n", i - 1);
	}
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int t;
  scanf("%d", &t);
  while(t --){
		scanf("%d", &n);
		printf("%d\n", n);
		solve();
	}

  return 0;
}

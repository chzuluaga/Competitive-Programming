#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAX = 10000000;
int arr[2][MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, t, k, d;
  int ans1 = 0, ans2 = 0;
  cin >> n >> t >> k >> d;
  int N = n;
  while(n > 0){
		n -= k;
		ans1 += t;
	}
	n = N;
	
	arr[0][0] = 1;
	arr[1][d] = 1;
	for(int i = 0; i < MAX; i++){
		if(arr[0][i]){
			n -= k;
			arr[0][i + t] = 1;
			ans2 = max(ans2, i + t);
			if(n <= 0)
				break;
		}
		if(arr[1][i]){
			n -= k;
			arr[1][i + t] = 1;
			ans2 = max(ans2, i + t);
			if(n <= 0)
				break;
		}
	}
	if(ans1 > ans2)
		cout << "YES\n";
	else
		cout << "NO\n";
  
  return 0;
}

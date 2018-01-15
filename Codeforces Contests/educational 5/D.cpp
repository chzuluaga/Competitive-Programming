#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 500005;
int a[MAX];
int last[1000005];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, k;
  
  scanf("%d%d", &n, &k);
  
  for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	
	int l = 0, ans = 1, idx = 0,diff = 1;
	last[a[0]] = 1;
	for(int i = 1; i < n; i ++){
		int cur = a[i];
		if(last[cur] == 0)
			diff ++;
		last[cur] ++;
		
		if(diff > k){
			while(diff > k){
				//cout << "sacando " << a[l] << " " << diff << endl;
				last[a[l]] --;
				if(last[a[l]] == 0)
					diff --;
				l ++;
			}
		}
		
		if(i - l + 1 > ans){
			ans = i - l + 1;
			idx = l;
		}
		//cout << l << " " << i << endl;
		
	}
	
	printf("%d %d\n", idx + 1, idx + ans);

  return 0;
}

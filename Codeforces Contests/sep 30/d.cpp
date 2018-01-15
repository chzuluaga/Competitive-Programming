#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 200005;
int a[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, k, x;
  
  scanf("%d%d%d", &n, &k, &x);
  int zero = 0, neg = 0, pos = 0;
  for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 0)
			zero ++;

		if(a[i] < 0)
			neg ++;		
		
		if(a[i] < 0)
			pos ++;
		
	}
	
	for(int i = 0; i < n; i ++){
		if(a[i] == 0){
		}
		if(a[i] > ){
		}
		if(a[i] < 0){
		}
			
	}
	
  return 0;
}

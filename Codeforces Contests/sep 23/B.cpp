#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
    
  int n;
  cin >> n;
  
  string s;
  
  cin >> s;
  //b even
  int sum1 = 0, sum2 = 0, swapb = 0, swapr = 0;
  for(int i = 0; i < n; i ++){
		if(i % 2 == 0){
			if(s[i] == 'r'){
				swapr --;
				if(swapr < 0){
					sum1 ++;
					swapb ++;
					swapr = 0;
				}
			}
		}else{
			if(s[i] == 'b'){
				swapb --;
				if(swapb < 0){
					sum1 ++;
					swapr ++;
					swapb = 0;
				}
			}
		}
	}
	
	swapb = swapr = 0;
	
	for(int i = 0; i < n; i ++){
		if(i & 1){
			if(s[i] == 'r'){
				swapr --;
				if(swapr < 0){
					sum2 ++;
					swapb ++;
					swapr = 0;
				}
			}
		}else{
			if(s[i] == 'b'){
				swapb --;
				if(swapb < 0){
					sum2 ++;
					swapr ++;
					swapb = 0;
				}
			}
		}
	}
  
  
  cout << min (sum1, sum2) << '\n';
  
		
  

  return 0;
}

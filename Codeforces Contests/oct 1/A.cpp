#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  
  cin >> n;
  
  string hour;
  
  cin >> hour;
  
  if(n == 12){
		if(hour[0] == '0' && hour[1] == '0')
			hour[1] = '1';
		
		if(hour[0] == '1' && hour[1] > '2')
			hour[0] = '0';
		
		if(hour[0] > '1'){
				if(hour[1] > '2')
					hour[0] = '0';
				else
					hour[0] = '1';
		}
			
		if(hour[3] > '5')
			hour[3] = '0';
			
	}else{
		if(hour[0] == '2' && hour[1] > '3')
			hour[0] = '0';
			
		if(hour[0] > '2')
			hour[0] = '0';
		
			
		if(hour[3] > '5')
			hour[3] = '0';
	}
	
	
	cout << hour <<'\n';

  return 0;
}

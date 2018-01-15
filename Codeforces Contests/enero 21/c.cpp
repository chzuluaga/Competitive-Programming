#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  ll n, m, k, x, y;
  
  cin >> n >> m >> k >> x >> y;
  ll qmx = 0, qmn = 0, ser = 0;
  if(n == 1){
		qmx = k / m + ((k % m)  > 0 ? 1 : 0);
		qmn = k / m + ((k % m) > 0 ? 0 : -1);
		if((k % m) >= y)
			ser = qmx;
		else
			ser = qmn;
		cout << qmx << " " << qmn << " " << ser << "\n";
		return 0;
	}
  
  if(k < n * m){
		qmx = 1;
		if(k >= (x - 1) * n + y)
			ser ++;
	}else{
		k -= n * m;
		qmx = qmn = ser = 1;
		ll cycle = ((n - 1) * m);
		ll newK = k % cycle;
		qmx += k / cycle + (newK > 0);
		qmn += (k / cycle) / 2;
		ll r = k / cycle;
		ll forwSer = (x - 1) * m + y;
		ll revSer = (n - x - 1) * m + (y);
		
		//cout << cycle << " " << newK << " " << forwSer << " " << revSer << endl;
		//cout << r << endl;
		if(x == 1 || x == n){
			ser = max(ser, qmn);
			if(r & 1 ){
				if(newK && newK >= y && x == n)
					ser ++;
			}else{
				if(newK && x == 1 && newK >= y){
					ser ++;
				}	
			}
		}else{
			ser = max(ser, qmx - 1);
			if(r & 1){
				if(newK && newK >= forwSer)
					ser ++;
			}else{
				if(newK && newK >= revSer){
					ser ++;
				}	
			}
		}
	}
  
  
  
	cout << qmx << " " << qmn << " " << ser << "\n";

  return 0;
}

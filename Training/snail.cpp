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
  
  int h, u, d, f;
  char yes[] = "success on day ";
  char no[] = "failure on day ";
  while(true){
		scanf("%d%d%d%d", &h, &u, &d, &f);
		if(u == 0)	break;
		f *= u;
		h *= 100;
		u *= 100;
		d *= 100;
		int cur = 0, day = 1;
		//cout << h << " " << u << " " << d << " " << f << endl;
		while(true){
			//cout << cur << " day " << day << endl;
			cur += u;
			if(cur > h){
				printf("%s%d\n", yes, day);
				break;
			}
			cur -= d;
			u -= f;
			u = max(u, 0);
			if(cur < 0){
				printf("%s%d\n",no,day);
				break;
			}
			day ++;
		}
	}

  return 0;
}

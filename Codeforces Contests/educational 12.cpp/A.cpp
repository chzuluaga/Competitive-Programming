#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int a, ta, b, tb, hh, mm, hf, mf;

int ok(int curh, int curm, int hend, int mend){
	
	if(hf < curh)
		return 0;
	
	if(hf == curh){
		if(mf <= curm)
			return 0;
	}
	
	if(hend < hh)
		return 0;
	
	if(hend == hh){
		if(mend <= mm)
			return 0;
	}
	
	
	return 1;

}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	scanf("%d %d %d %d", &a, &ta, &b, &tb);
	scanf("%d:%d", &hh, &mm);
	mf = mm + ta;
	hf = hh;
	while(mf >= 60){
		mf -= 60;
		hf ++;
	}
	
	int curh = 5, curm = 0;
	int ans = 0;
	//cout << hh << " " << mm << " -> " << hf << " " << mf << endl;
	while(true){
		if(curh >= 24)
			break;
		
		if(curh > hf){
			break;
		}
		if(curh == hf)
			if(curm > mf)
				break;
				
		int newm = curm + tb;
		int newh = curh;
		while(newm >= 60){
			newm -= 60;
			newh ++;
		}
		
		//cout << curh << " " << curm << " ----- " << newh << " " << newm << endl;
		
		ans += ok(curh, curm, newh, newm);
		
		curm += b;
		while(curm >= 60){
			curm -= 60;
			curh ++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

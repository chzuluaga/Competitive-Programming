#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1005;
int ma[MAX][MAX];

void setma(int x, int y){
	//cout << "x " << x << " " << y << endl;
	ma[x][y] = ma[y][x] = 1;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int k;
	scanf("%d", &k);
	int n = 2, big , small, cur = 2, last;
	
/*	if(k == 1){
		printf("2\nNY\nYN\n");
		return 0;
	}
	*/
	for(int i = 0; i < 30; i ++){
		if(k & (1 << i)){
			small = i;
			break;
		}
	}
	for(int i = 30; i >= 0; i --){
		if(k & (1 << i)){
			big = i;
			break;
		}
	}
	if(small == 0)	small ++;
	for(int i = small; i < big; i ++){
			n ++;
			if(i + 1 < big)
				setma(cur, cur + 1);
			else
				setma(cur, 1);
			cur ++;
			last = cur - 1;
	}
	for(int i = 30; i >= 0; i --){
		if(k & (1<<i)){
			int fin = last - (big - (i?i:1) - 1);
			if(i == big)
				fin = 1;
				
		//	cout << "fin es " << fin << endl;
			if(i == 0){
				n ++;
				setma(0, cur);
				setma(cur, fin);
				continue;
			}
			
			int prv1 = 0, prv2 = 0;
			for(int j = 0; j < i; j ++){
				int a = cur ++, b = cur ++;
				n += 2;
				setma(prv1, a);
				setma(prv2, b);
				setma(prv1, b);
				setma(prv2, a);
				prv1 = a;
				prv2 = b;
			}
			setma(prv1,fin);
			setma(prv2,fin);
		}
	}
	
	printf("%d\n",n);
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n; j ++){
			printf("%c",(ma[i][j] == 1?'Y':'N'));
		}
		printf("\n");
	}
	
	

  return 0;
}

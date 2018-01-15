#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
ll tmp[MAX], arr[MAX], dp[8][MAX][8], n, a, b, c;

ll ok(int x, int y){
		if(x == 0)
			return y == 0 || y == 3 || y == 4 || y == 6;
		if(x == 1)
			return y == 1 || y == 3 || y == 5 || y == 6;
		if(x == 2)
			return y == 2 || y == 4 || y == 5 || y == 6;
		if(x == 3)
			return y == 0 || y == 3 || y == 4 || y == 6 ||
						 y == 1 || y == 3 || y == 5 || y == 6;
		if(x == 4)
			return y == 0 || y == 3 || y == 4 || y == 6 ||
						 y == 2 || y == 4 || y == 5 || y == 6;
		if(x == 5)
			return y == 1 || y == 3 || y == 5 || y == 6 ||
						 y == 2 || y == 4 || y == 5 || y == 6;
		if(x == 6)
			return y == 1 || y == 3 || y == 5 || y == 6 ||
						 y == 2 || y == 4 || y == 5 || y == 6 ||
						 y == 0 || y == 3 || y == 4 || y == 6;
		return 0;
}

int getBinary(int x){
	if(x == 0)
		return 1;
	
	if(x == 1)
		return 2;
	
	if(x == 2)
		return 4;
		
	if(x == 3)
		return 3;
	
	if(x == 4)
		return 5;
	
	if(x == 5)
		return 6;
		
	return 7;
}

ll strength(int idx){
	if(idx == 0)
		return a;
	
	if(idx == 1)
		return b;
		
	if(idx == 2)
		return c;
		
	if(idx == 3)
		return a + b;
		
	if(idx == 4)
		return a + c;
	
	if(idx == 5)
		return b + c;
		
	if(idx == 6)
		return a + b + c;
	
	return 0;	
	
}

int main(){
  
	freopen("tresMosqueteros.in" , "r" ,stdin);
//	freopen("tresMosqueteros.out" , "w" ,stdout);
	scanf("%lld %lld %lld %lld",&n, &a, &b, &c);
	int least = min(a, min(b, c)), cont = 0;
	int i = 0;
	for(int ii = 0; ii < n; ii ++, i ++){
		scanf("%lld",&tmp[i]);
		if(tmp[i] > a + b + c){
			printf("-1\n");
			return 0;
		}
		if(tmp[i] > a + b + c - least){
			cont ++;
			i --;
		}
	}
	
	n = i;
	sort(tmp, tmp + n);
	int fr = 0, to = n - 1;
	for(int i = 0; i < n / 2; i ++){
		arr[i * 2] = tmp[fr ++];
		arr[i * 2 + 1] = tmp[to --];
	}
	
	if(n & 1)
		arr[n] =  tmp[fr];
		
	/*for(int i = 0; i < n; i ++)
		cout << arr[i] << " ";
	cout << endl;
	*/
	
	for(int i = 0; i < 7; i ++)
		for(int j = 0; j <= n; j ++)
			for(int k = 0; k < 8; k ++)
				dp[i][j][k] = n;
				//dp[i][j][k] = LLONG_MAX / 9LL;
				
	for(int i = 0; i < 7; i ++)
		dp[i][0][7] = 0;
	
	
	
	ll ans = LLONG_MAX;
	
	for(int j = 1; j <= n; j ++){
		ll cur = arr[j - 1];
		for(int i = 0; i < 7; i ++){
			if(strength(i) >= cur){
				int bit = getBinary(i);
				for(int k = 0; k < 7; k ++){
					for(int l = 0; l < 8; l ++){
						dp[i][j][bit] = min(dp[i][j][bit], dp[k][j - 1][l] + 1);
						if(j == n)
							ans = min(ans, dp[i][j][bit]);
						
						int other = l;
						bool ok = true;
						if(bit & 1){
							if(other & 1)
								ok = false;
						}
						if(bit & 2){
							if(other & 2)
								ok = false;
						}
						
						if(bit & 4){
							if(other & 4)
								ok = false;
						}
						
						if(ok){
							dp[i][j][bit | other] = min(dp[i][j][bit | other], dp[k][j - 1][l]);
							if(j == n)
								ans = min(ans, dp[i][j][bit | other]);
						}
					}
				}
			}
			
		}
	}
	
	/*for(int k = 0; k < 8; k ++){
		cout <<((k & 4)?1:0) << ((k & 2)?1:0)<< ((k&1)?1:0)<<endl;
		for(int i = 0; i <= 6; i ++){
			for(int j = 0; j <= n; j ++)
				cout << dp[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}*/
	
	
	printf("%lld\n", ans + cont);
	
  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 10;
int ncomp[MAX];
ll inf = 1ll;

long long llgcd(long long x, long long y) {
        long long t;
        while (x%y)
            t = x, x = y, y = t % y;
        return y;
}
struct fraction{
	ll num, div;
	
	
	 fraction(long long a = 0, long long b = 1) {
			num = a, div = b;
			normal();
	}
	void normal() {
			if (div < 0)  num = -num, div = -div;
			long long g = llgcd(num, div);
			num /= g, div /= g;
			if (div < 0)  num = -num, div = -div;
	}
	fraction operator-(const fraction &a) const {
			long long va = 0, vb = a.div / llgcd(div, a.div) * div;
			va = vb / div * num - vb / a.div * a.num;
			return fraction(va, vb);
	}
	fraction operator+(const fraction &a) const {
			long long va = 0, vb = a.div / llgcd(div, a.div) * div;
			va = vb / div * num + vb / a.div * a.num;
			return fraction(va, vb);
	}
	fraction operator*(const fraction a) const {
			long long g1 = llgcd(num, a.div), g2 = llgcd(a.num, div);
			long long va = 0, vb = 0;
			va = (num / g1) * (a.num / g2);
			vb = (div / g2) * (a.div / g1);
			return fraction(va, vb);
	}
	fraction operator/(const fraction a) const {
			long long g1 = llgcd(div, a.div), g2 = llgcd(num, a.num);
			long long va = 0, vb = 0;
			va = (a.div / g1) * (num / g2);
			vb = (div / g1) * (a.num / g2);
			return fraction(va, vb);
	}
	bool operator==(const fraction &a) const {
			return num - a.num == 0 && div - a.div == 0;
	}
	bool operator<(const fraction &a) const {
		double f1, f2;
		f1 = 1.0 * num / div, f2 = 1.0 * a.num / a.div;
		if (fabs(f1 - f2) < 1e-9)	return false;
		return f1 < f2;
		
	}
	
}dp[MAX][1005];

struct component{
	fraction f;
	ll cost;
	component(){}
	component(ll _a, ll _b, ll _cost){
		f.num = _a;
		f.div = _b;
		cost = _cost;
	}
}comp[MAX][20];



int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("designing.in", "r", stdin);
  freopen("designing.out", "w",stdout);
  int n, budget;
  
  while(~scanf("%d%d", &n, &budget)){
		for(int i = 0; i < n; i ++)
			scanf("%d", &ncomp[i]);
			
		for(int i = 0; i < n; i ++){
			comp[i][0] = component(1,1,0);
			for(int j = 0; j < ncomp[i]; j ++){
				scanf("%lld%lld%lld",	&comp[i][j + 1].f.num, &comp[i][j + 1].f.div, &comp[i][j + 1].cost);
			}
			ncomp[i] ++;
		}
		
		for(int i = 0; i < n;i ++){
			for(int k = 0; k <= budget; k ++){
				dp[i][k] = fraction(inf, 1ll);
			}
		}
		//idx, ncomp, cost
		for(int i = 0; i < ncomp[0]; i ++){
			if(comp[0][i].cost <= budget){
				dp[0][comp[0][i].cost] = comp[0][i].f;
			}
		}
		fraction f1 = fraction (1,1);
		fraction ans = fraction(inf, 1ll);
		for(int i = 0; i < n; i ++){
			for(int k = 0; k <= budget; k ++){
				if(i == n - 1){
				//	cout << dp[i][j][k].num << " // " << dp[i][j][k].div << endl;
					ans = min(ans, dp[i][k]);
					continue;
				}
				for(int l = 0; l < ncomp[i + 1]; l ++){
					ll newCost = (ll)k + comp[i + 1][l].cost;
					if(newCost > budget)
						continue;
					fraction &nxtComp = dp[i + 1][newCost];
					nxtComp = min(nxtComp, dp[i][k] + ( (f1 - dp[i][k]) * comp[i + 1][l].f));
				}
				
			}
		}
		
		printf("%lld/%lld\n", ans.num, ans.div);
	}
	

 return 0;
}

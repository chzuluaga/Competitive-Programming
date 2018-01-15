#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;

ll a[MAX], mod = 1000000007ll;

ll add(ll a, ll b){
	ll c = a + b;
	if(c >= mod)
		c -= mod;
	return c;
}

ll mul(ll a, ll b){
	ll c =  a * b;
	if( c>= mod)
		c %= mod;
	return c;
}

struct matrix{ 
	ll ma[2][2];
	matrix(){
		ma[0][0] = ma[0][1] = ma[1][0] = ma[1][1] = 0;
		
		//memset(ma, 0, sizeof(ma));
	}
	matrix(ll fa, ll fb){
		ma[0][0] = ma[0][1] = ma[1][0] = ma[1][1] = 0;
		//memset(ma, 0, sizeof(ma));
		ma[0][0] = fa;
		ma[0][1] = fb;
	}
}base;

matrix matMul(matrix &a, matrix &b){
	matrix ans;
	int k;
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 2;j ++)
			for(ans.ma[i][j] = k = 0; k < 2; k ++){
				ans.ma[i][j] = add( ans.ma[i][j], mul(a.ma[i][k], b.ma[k][j]));
				//ans.ma[i][j] %= mod;
			}
	return ans;
}

matrix matPow(matrix base, ll p){
	matrix ans;
	ans.ma[0][0] = ans.ma[1][1] = 1;
	while(p){
		if(p & 1)	ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}

struct node{
	node *L, *R;
	int lf, rg;
	ll fa, fb;
	matrix lazy;
	node(){
		L = NULL;
		R = NULL;
		lazy.ma[0][0] = lazy.ma[1][1] = 1;
	}
	
	node(int _lf, int _rg){
		lf = lf;
		rg = rg;
		L = NULL;
		R = NULL;
		lazy.ma[0][0] = lazy.ma[1][1] = 1;
	}
	
	void create(int from, int to){
		lf = from;
		rg = to;
		fa = 0ll, fb = 1ll;
		if(lf == rg){
			return;
		}
			
		int mit = (from + to) / 2;
		
		L = new node();
		R = new node();
		L -> create(from, mit);
		R -> create(mit + 1, to);
		fa = add(L -> fa , R -> fa);
		fb = add(L -> fb , R -> fb);
	}
	
	void expand(){
		if(L != NULL)
			L -> lazy = matMul(L -> lazy, lazy);
		if(R != NULL)
			R -> lazy = matMul(R -> lazy, lazy);
		
		matrix cur = matrix(fa, fb);
		matrix ans = matMul(cur, lazy);
		
		fa = ans.ma[0][0];
		fb = ans.ma[0][1];
		lazy.ma[0][0] = lazy.ma[1][1] = 1;
		lazy.ma[0][1] = lazy.ma[1][0] = 0;
	}
	void update(int from, int to, matrix val){
		if(from == lf && to == rg){
			lazy = matMul(lazy, val);
			expand();
			return;
		}
		expand();
		//left
		if(to < R -> lf){
			 L -> update(from, to, val);
			 R -> expand();
		}else{//right
			if(from > L->rg){
				R -> update(from, to, val);
				L -> expand();
			}else{//both
				L -> update(from, L -> rg, val);
				R -> update(R -> lf , to, val);
			}
		}
		//L -> expand();
		//R -> expand();
		fa = add(L -> fa , R -> fa);
		fb = add(L -> fb , R -> fb);
	}
	
	pll get(int from, int to){
		if(from == lf && to == rg){
			expand();
			return mp(fa, fb);
		}
		expand();
		//left
		pll rl, rr;
		rl = rr = mp(0,0);
		if(to < R -> lf){
			 rl = L -> get(from, to);
			 R -> expand();
		}else{//right
			if(from > L->rg){
				rr =  R -> get(from, to);
				L -> expand();
			}else{//both
				rl = L -> get(from, L -> rg);
				rr = R -> get(R -> lf , to);
			}
		}
		fa = add(L -> fa, R -> fa);
		fb = add(L -> fb, R -> fb);
		return mp(add(rl.first , rr.first), add (rl.second , rr.second));
	}
	
};

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n, m, x, y, t;
	ll val;
	
	//freopen("sasha.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	base.ma[0][0] = 0;
	base.ma[0][1] = 1;
	base.ma[1][0] = 1;
	base.ma[1][1] = 1;
	node root;
	
	root.create(0, n - 1);
	
	for(int i = 0; i < n; i ++){
		scanf(LL, &a[i]);
		root.update(i, i, matPow(base, a[i]));
	}
	
	while(m --){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d" LL ,&x, &y, &val);
			x --, y --;
			matrix newVal = matPow(base, val);
			root.update(x, y, newVal);
		}else{
			scanf("%d%d", &x, &y);
			x --, y --;
			printf(LL "\n", root.get(x, y).first);
		}
		
	}
	
  return 0;
}

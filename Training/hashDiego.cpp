#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

#define MODS    		2
int mods[MODS];
#define FOR				for(int i=0;i<MODS;++i)

inline int fmpow(int b, ll e, int mod){
	int r = 1;
	while(e){
		if(e&1LL) r=ll(r)*ll(b)%ll(mod);
		b=ll(b)*ll(b)%ll(mod);
		e>>=1;
	}
	return r;
}


class mint {
#define X				x[i]
#define MOD				mods[i]
	int x[MODS];
	public:

	inline mint inv()const{mint r;FOR r.X=fmpow(X,MOD-2,MOD);return r;}
	ll encode(){return (ll(x[0])<<32)+ll(x[1]);} //for unordered_map/set

	inline int operator()(int i)const{return X;}
	inline mint operator-()const{mint r(*this);FOR r.X=(X?MOD-X:0);return r;}
	inline mint operator+(const mint a)const{mint r;FOR r.X=(X+a.X)%MOD;return r;}
	inline mint operator-(const mint a)const{mint r;FOR{r.X=X-a.X;if(r.X<0)r.X+=MOD;}return r;}
	inline mint operator*(const mint a)const{mint r;FOR r.X=int(ll(X)*ll(a.X)%ll(MOD));return r;}
	inline mint operator/(const mint a)const{return (*this)*a.inv();}

	inline mint&operator+=(const mint a){*this=*this+a;return*this;}
	inline mint&operator-=(const mint a){*this=*this-a;return*this;}
	inline mint&operator*=(const mint a){*this=*this*a;return*this;}
	inline mint&operator/=(const mint a){*this=*this/a;return*this;}

	inline mint&operator=(const mint&a){FOR X=a.X;return*this;}

	inline bool operator==(const mint&a)const{FOR if(X!=a.X)return 0;return 1;}
	inline bool operator!=(const mint&a)const{FOR if(X==a.X)return 0;return 1;}
	inline bool operator<(const mint&a)const{FOR if(X!=a.X)return X<a.X;return 0;}

	mint(){FOR X=0;}
	mint(ll v){FOR{X=int(v%ll(MOD));if(X<0)X+=MOD;}}
	mint(const mint&a){FOR X=a.X;}
};

ostream&operator<<(ostream&o,const mint&m){return o<<"{ "; FOR o<<m(i)<<' '; o<<" aca }\n";}
istream&operator>>(istream&i,mint&m){ll x;i>>x;m=mint(x);return i;}

void findMOD( ) {
	srand(time(nullptr));
	FOR {
		MOD = 1000000000 + rand()%5000000;
		while ( true ) {
			bool isPrime = true;
			for ( int j = 2; j*j <= MOD; ++j )
				if ( MOD%j == 0 ) {
					isPrime = false;
					break;
				}
			if ( isPrime ) break;
			MOD++;
		}
	}
}

#undef FOR
#undef MOD 
#undef X

mint bpow[100], h1[100], h2[100];
int main(){
	
		string A, B;
		
		cin >> A >> B;
		int n = A.size();
		
		findMOD();
		bpow[0] = mint(1ll);
		mint b = mint(30ll);
		
		for(int i = 1; i < n; i ++)
			bpow[i] = bpow[i - 1] * b;
		
		for(int i = 0; i < n; i ++){
			h1[i] = mint((ll)(A[i] - 'a')) * bpow[i];
			h2[i] = mint((ll)(B[i] - 'a')) * bpow[i];
			
			if(i){
				h1[i] += h1[i - 1];
				h2[i] += h2[i - 1];
			}
		}
		
		for(int i = 0; i < n; i ++)
			cout << h1[i] << " ";
		cout << endl;
		
		for(int i = 0; i < n; i ++)
			cout << h2[i] << " ";
		cout << endl;
		
		if(h1[n - 1] == h2[n - 1])
			cout << "YES\n";
		else
			cout << "NO" << endl;
		return 0;
}

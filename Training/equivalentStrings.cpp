#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;

char AA[MAX], BB[MAX];
string A, B;
int n;
ll mod1, mod2, b = 26ll;
ll hashA[2][MAX], hashB[2][MAX], bpow1[MAX], bpow2[MAX];
ll prodH(ll a, ll b, ll mod){return a * b % mod;}
ll addH(ll a, ll b, ll mod){return ( a + b ) % mod;}
ll subH( ll a, ll b, ll mod ){return ( a - b + mod ) % mod;}

bool isPrime(long long x){
    for(long long i = 2ll; i * i <= x; i ++){
        if(x % i == 0)
            return false;
    }
    return true;
}

void init(){
		mod1 = mod2 = 1000000007;
    mod1 += (long long)rand() % 1000000ll;
   // mod2 += (long long)rand() % 1000000ll;

    while(!isPrime(mod1))
        mod1 ++;
    /*while(!isPrime(mod2))
        mod2 ++;*/
}

void fillbPow(){
	bpow1[0] = bpow2[0] = 1ll;
	
	for(int i = 1; i <= n; i ++){
		bpow1[i] = prodH(bpow1[i - 1], b, mod1);
	//	bpow2[i] = prodH(bpow2[i - 1], b, mod2);
	}
}

ll fastPow( ll base, ll exp, ll mod ){
    if(exp == 1)
        return base;

    ll r = fastPow( base, exp / 2, mod );
    r = prodH( r, r, mod );
    if( exp & 1)
       r = prodH( r, base, mod );

    return r;
}

ll getHash( int i, int j, ll *hash, ll *bp, ll mod ){

    ll ans = hash[j];
    ans = ( i > 0?subH( ans, hash[i - 1], mod ):ans );
    ans = prodH( ans, fastPow(bp[i], mod - 2, mod), mod );

    return ans;
}

void createHash(){
	
	for(int i = 0; i < n; i ++){
		hashA[0][i] = prodH( ( ll )(A[i]), bpow1[i], mod1 );
	//	hashA[1][i] = prodH( ( ll )(A[i]), bpow2[i], mod2 );

		hashB[0][i] = prodH( ( ll ) (B[i]), bpow1[i], mod1 );
		//hashB[1][i] = prodH( ( ll ) (B[i]), bpow2[i], mod2 );
		
		if(i > 0){
				hashA[0][i] = addH( hashA[0][i], hashA[0][i - 1], mod1 );
			//	hashA[1][i] = addH( hashA[1][i], hashA[1][i - 1], mod2 );

				hashB[0][i]= addH( hashB[0][i], hashB[0][i - 1] , mod1 );
			//	hashB[1][i] = addH( hashB[1][i], hashB[1][i - 1] , mod2 );

		}
	}
}

bool solve(int x1, int y1, int x2, int y2){
	
	
	ll h1A = getHash(x1, y1 - 1,hashA[0],bpow1, mod1);
//	ll h2A = getHash(x1, y1 - 1,hashA[1],bpow2, mod2);
	ll h1B = getHash(x2, y2 - 1,hashB[0],bpow1, mod1);
	//ll h2B = getHash(x2, y2 - 1,hashB[1],bpow2, mod2);
	
	//cout << h1A << " " << h1B << " --- " << h2A << " --- " << h2B<< endl;
	if(h1A == h1B)// && h2A == h2B)
		return true;
	
	
	if((y1 - x1 ) & 1 || (y2 - x2) & 1)
		return false;	
		
	return (solve(x1, (y1 + x1) / 2, x2, (y2 + x2)/2) && solve((y1 + x1) / 2, y1, (y2 + x2) / 2, y2))
						||  (solve(x1, (y1 + x1) / 2, (y2 + x2 )/ 2, y2) && solve((y1 + x1)/ 2, y1, x2, (y2 + x2) / 2));
		
	
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  srand(time(NULL));
  scanf("%s%s", AA, BB);
  
  A = string(AA);
  B = string(BB);
  n = strlen(AA);
  
  if(A == B){
		cout << "YES\n";
		return 0;
	}
	
	if(n & 1){
		cout << "NO\n";
		return 0;
	}
  init();
  fillbPow();
  createHash();
  /*for(int i = 0; i < n; i ++)
		cout << hashA[0][i] << " ";
	
	cout << endl;
	
	for(int i = 0; i < n; i ++)
		cout << hashB[0][i] << " ";
	
	cout << endl;
	*/
  
  cout << (solve(0, n, 0, n) == true?"YES\n":"NO\n");
  
	
  

  return 0;
}

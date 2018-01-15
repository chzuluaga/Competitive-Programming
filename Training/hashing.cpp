#include<bits/stdc++.h>
#define mp(x, y) make_pair(x, y)
#define pi pair <int,int>
using namespace std;

typedef long long ll;


const int MAX = 5000;
ll mod1, mod2;

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
    mod2 += (long long)rand() % 1000000ll;

    while(!isPrime(mod1))
        mod1 ++;
    while(!isPrime(mod2))
        mod2 ++;
}

ll b = 26LL, bpow1[MAX], bpow2[MAX], n, tam;
ll hashf[2][MAX], hashr[2][MAX];

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

int bit[MAX];

void update(int x, int val){
    for(; x <= 5000; x += x&-x)
        bit[x] += val;
}

int get(int x){
    int sum = 0;

    for(;x > 0; x -= x&-x){
        sum += bit[x];
    }
    return sum;
}

int ans[1000006];
int main(){

    int rg, lf;
   // freopen( "queries.in", "r", stdin );
    srand (time(NULL));

    string s, sr;
		char tmp[5005];
		scanf("%s", tmp);
		sr = string(tmp);
    s = sr;
    reverse(sr.begin(), sr.end());
    init();

    n = s.size();
    bpow1[0] = bpow2[0] = 1ll;

    for(int i = 1; i < n; i ++){
        bpow1[i] = prodH(bpow1[i - 1], b, mod1);
        bpow2[i] = prodH(bpow2[i - 1], b, mod2);
    }

    for(int i = 0; i < n; i ++){
        hashf[0][i] = prodH( ( ll )( s[i] ), bpow1[i], mod1 );
        hashf[1][i] = prodH( ( ll )( s[i] ), bpow2[i], mod2 );

        hashr[0][i] = prodH( ( ll ) ( sr[i] ), bpow1[i], mod1 );
        hashr[1][i] = prodH( ( ll ) ( sr[i] ), bpow2[i], mod2 );

        if(i > 0){
            hashf[0][i] = addH( hashf[0][i], hashf[0][i - 1], mod1 );
            hashf[1][i] = addH( hashf[1][i], hashf[1][i - 1], mod2 );

            hashr[0][i]= addH( hashr[0][i], hashr[0][i - 1] , mod1 );
            hashr[1][i] = addH( hashr[1][i], hashr[1][i - 1] , mod2 );

        }
    }
    pair<ll, ll> hf, hr;
    vector<pi> pal;
    vector< pair< pi, int > > q;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - i; j ++){
            //cout << "probando " << s.substr(i,(n - j - 1) - i + 1) << " " << sr.substr(j, n - i - j)<< endl;;

            hf.first = getHash(i, n - j - 1, hashf[0], bpow1, mod1);
            hf.second = getHash(i, n - j - 1, hashf[1], bpow2, mod2);

            hr.first = getHash(j, n - i - 1, hashr[0], bpow1, mod1);
            hr.second = getHash(j, n - i - 1, hashr[1], bpow2, mod2);

            //cout << hf.first << " " << hf.second << endl;
            //cout << hr.first << " " << hr.second << endl;

            if(hf.first == hr.first && hf.second == hr.second){
            //    cout << "Palindromo en " << i + 1 << " " << n - j << endl;
              //  cout << "probando " << s.substr(i,(n - j - 1) - i + 1) << " " << sr.substr(j, n - i - j)<< endl;;
                //update(tam - 1, 0, i, n - j - 1, 1);
                rg = n - j - 1;
                lf = i;
                pal.push_back(mp(rg + 1, lf + 1));
            }


        }
    }
    int Q, l , r;
    scanf("%d", &Q);

    for(int i = 0; i < Q; i ++){
        scanf("%d%d", &l, &r);
        q.push_back(make_pair( mp ( r, l ) , i));
    }

    sort( pal.begin(), pal.end() );
    sort( q.begin(), q.end() );

    int posp = 0, posq = 0;
    for(int i = 1; i <= n; i ++){
        while(posp < pal.size() && pal[ posp ].first == i){
           // cout << "haciendo update de "<<pal[posp].second << " " << i << endl;
            update(pal[posp].second, 1);
            posp ++;
        }

        while(posq < q.size() && q[ posq ].first.first == i){
            //cout << "consultado "<< q[posq].first.second << " " << i<< endl;
            ans[q[posq].second] = get(i) - get(q[posq].first.second - 1);
            posq ++;
        }

    }

    for(int i = 0; i < Q; i ++){
        printf("%d\n", ans[i]);
    }




    return 0;
}

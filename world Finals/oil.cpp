#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;

typedef long long ll;
typedef complex<ll> pt;
#define x(A)            real(A)
#define y(A)            imag(A)
#define cross(A,B)      imag(conj(A)*(B))

struct Event {
  pt p;
  ll val;
  Event ( pt p, ll v ) : p(p), val(v) { }
  Event ( ) { }
};

bool cmp ( const Event& a, const Event& b ) {
  ll c = cross(a.p,b.p);
  if ( c != 0 ) return c < 0;
  return a.val > 0 && b.val < 0;
}

ll sweep ( vector<Event>& events ) {
  sort ( events.begin(), events.end(), cmp );
  ll ans = 0, cur = 0;
  for ( int i = 0; i < events.size(); ++i )
    ans = max ( ans, cur += events[i].val );
  return ans;
}

int main ( )
{
  freopen ( "G.in", "r", stdin );
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pt> A, B;
  for ( int i = 0; i < n; ++i ) {
    ll x0, x1, y;
    cin >> x0 >> x1 >> y;
    if ( x0 == x1 ) continue;
    if ( x0 > x1 ) swap ( x0, x1 );
    A.push_back ( pt(x0,y) );
    B.push_back ( pt(x1,y) );
  }
  n = A.size();

  ll ans = 0;
  for ( int i = 0; i < n; ++i ) {
    for ( int flag = 0; flag < 2; ++flag ) {
      pt O = ( flag ? B[i] : A[i] );
      vector<Event> events;
      for ( int j = 0; j < n; ++j )
        if ( y(A[j]) > y(A[i]) ) {
          events.push_back ( Event ( (A[j]-O), abs(x(A[j])-x(B[j])) ) );
          events.push_back ( Event ( (B[j]-O), -abs(x(A[j])-x(B[j])) ) );
        } else if ( y(A[j]) < y(A[i]) ){
          events.push_back ( Event ( -(A[j]-O), -abs(x(A[j])-x(B[j])) ) );
          events.push_back ( Event ( -(B[j]-O), abs(x(A[j])-x(B[j])) ) );
        }
      ans = max ( ans, sweep ( events ) + abs ( x(A[i]) - x(B[i]) ) );
    }
  }

  cout << ans << endl;
  return 0;
}

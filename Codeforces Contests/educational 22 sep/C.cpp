#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 50005;
string s[MAX];
string tmp1, tmp2;
bool cmp(string &A, string &B){
	tmp1 = A + B;
	tmp2 = B + A;
	
	return tmp1 < tmp2;
	
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	sort(s, s + n, cmp);
	
	for(int i = 0; i < n; i++)
		cout << s[i];
	cout << '\n';
		
  return 0;
}

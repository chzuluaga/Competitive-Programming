#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int LEN = 1e5 + 5;
char s[LEN];
int rad[2 * LEN], n;

//WARNING: n = 2 * strlen(s)
void build_rad ()
{
	n = strlen(s) * 2;
	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for (; i >= j && i + j + 1 < n && s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
		
		rad[i] = j;
		
		for (k = 1; i >= k && rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}
}

//WARNING: n = strlen(s)
bool is_palindrome (int b, int e)
{
	n = strlen(s);
	return b >= 0 && e < n &&  rad[b + e] >= e - b + 1;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  while(cin >> s){
		build_rad();
		
		for(int i = 0; i < 2* (int)strlen(s); i ++)
			cout << rad[i] << " ";
	}

  return 0;
}

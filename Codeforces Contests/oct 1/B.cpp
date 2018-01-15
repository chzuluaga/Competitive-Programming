#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 105;

int a[MAX];
string s[MAX];
string cur;

bool vowel(char x){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y';
}


bool ok(int idx){
	cur = s[idx];
	int cont = 0;
	
	for(int i = 0; i <(int)cur.size(); i ++)
		if(vowel(cur[i]))
			cont ++;
			
	if(cont == a[idx])
		return true;
	return false;
}
int main(){
	
	//freopen("b.in",  "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  
  cin >> n;
  
  for(int i = 0; i < n; i ++)
		cin >> a[i];
		
	getline(cin, cur);
	
	for(int i = 0; i < n; i ++){
		getline(cin, s[i]);
		//cout << s[i] << endl;
	}
		
	for(int i = 0; i < n; i ++){
		if(!ok(i)){
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
  

  return 0;
}

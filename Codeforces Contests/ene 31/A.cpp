#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 10005;
set<string> words;
bool memo[4][MAX], visit[4][MAX];
string s;
int n;
bool solve(int idx, int tam){
	//cout << idx << " " << tam << " N - " << n << endl;
	if(idx + tam == n){
		string A = s.substr(idx, tam);
		reverse(A.begin(), A.end());
		words.insert(A);
		return true;
	}
	
	if(idx + tam > n)
		return false;
		
	if(idx > n)
		return false;
	
	if(visit[tam][idx])
		return memo[tam][idx];
	
	bool &ans = memo[tam][idx];
	visit[tam][idx] = true;
	
	string A = s.substr(idx, tam);
	reverse(A.begin(), A.end());
	words.insert(A);
	reverse(A.begin(), A.end());
	if(idx + tam + 2 > n){
		ans = true;
		return ans;
	}
	
	string B = s.substr(idx + tam, 2);
	if(tam == 2){
		if(A != B)
			ans |= solve(idx + tam, 2);
		ans |= solve(idx + tam, 3);
	}else{
		ans |= solve(idx + tam, 2);
		if(idx + tam + 3 <= n){
			B = s.substr(idx + tam, 3);
			if(A != B)
			 ans |= solve(idx + tam, 3);
		}
	}
	if(ans){
		reverse(A.begin(), A.end());
		words.insert(A);
	}
	
	return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  s = s.substr(5);
  n = (int)s.size();
  
  reverse(s.begin(), s.end());
  
  if(n >= 2)
		solve(0, 2);
		
	
	if(n >= 3)
		solve(0, 3);
	
	cout << words.size() << '\n';
	for(string word : words)
		cout << word << '\n';
  
	

  return 0;
}

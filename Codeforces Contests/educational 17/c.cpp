#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int forw[MAX], rev[MAX];
queue<int> Qletter[30];
stack<int> Sletter[30];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  
  memset(forw, -1, sizeof(forw));
  memset(rev, -1 ,sizeof(rev));
  
  for(int i = 0; i < (int)a.size(); i ++){
		Qletter[a[i] - 'a'].push(i);
		Sletter[a[i] - 'a'].push(i);
	}
	
	int cur = -1;
	for(int i = 0; i < (int)b.size(); i ++){
		int pos = (int)(b[i] - 'a');
		while(!Qletter[pos].empty()){
			int f = Qletter[pos].front();
			if(f > cur){
				break;
			}
			Qletter[pos].pop();
		}
		if(Qletter[pos].size()){
			cur = Qletter[pos].front();
			Qletter[pos].pop();
			forw[i] = cur;
		}else{
			break;
		}
	}
	cur = ((int)a.size());
	for(int i = (int)b.size() - 1; i >= 0; i --){
		int pos = (int)(b[i] - 'a');
		while(!Sletter[pos].empty()){
			int f = Sletter[pos].top();
			if(f < cur){
				break;
			}
			Sletter[pos].pop();
		}
		if(Sletter[pos].size()){
			cur = Sletter[pos].top();
			Sletter[pos].pop();
			rev[i] = cur;
		}else{
			break;
		}
	}
	
	int rg = (int)b.size() - 1;
	cur = -1;
	for(; rg >= 0; rg --){
		if(rev[rg] == -1){
			break;
		}
	}
	rg ++;
	int ans = (int)b.size() - rg;
	int idxL = 0, idxR = rg;
	
	
	/*
	for(int i = 0; i < (int)b.size(); i ++)
		cout << forw[i] << " ";
	cout << endl;
	
	for(int i = 0; i < (int)b.size(); i ++)
		cout << rev[i] << " ";
	cout << endl;
	*/
	for(int i = 0; i < (int)b.size() && forw[i] != -1; i ++){
		if(i >= rg || forw[i] >= rev[rg]){
			rg ++;
			rg = min(rg, (int)b.size());
		}
		if(i + 1 + (int)b.size() - rg > ans){
			ans = i + 1 + (int)b.size() - rg;
			idxL = i + 1;
			idxR = rg;
		}
	}
	//cout << idxL << " " << idxR << endl;
	if(ans == 0)
		cout << "-\n";
	else
		cout << b.substr(0, idxL) << b.substr(idxR);
	
	
	
  return 0;
}

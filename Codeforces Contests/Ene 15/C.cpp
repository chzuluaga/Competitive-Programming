#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 10005;
int NC, p[MAX], rnk[MAX];

int find(int x){
	if(p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)	return;
	
	NC --;
	
	if(rnk[x] > rnk[y])
		p[y] = x;
	else{
		p[x] = y;
		if(rnk[x] == rnk[y])
			rnk[y] ++;
	}
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  
  cin >> n;
  NC = n;
  for(int i = 0; i < n;i ++){
		rnk[i] = 0;
		p[i] = i;
	}
  for(int i = 0; i < n; i ++){
		cin >> x;
		merge(i, x - 1);
	}
	
	cout << NC << '\n';

  return 0;
}

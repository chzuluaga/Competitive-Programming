#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1234567;

char s[MAX];

struct node{
	node *L, *R;
	int lf, rg, open, close;
	
	node(){
		open = 0, close = 0;
		L = NULL, R = NULL;
	}
	
	void create(int from, int to){
		lf = from;
		rg = to;
		if(from == to){	
			if(s[from] == '(')
				open = 1;
			else
				close = 1;
			return;
		}
		L = new node();
		R = new node();
		L -> create(from, (from + to) / 2);
		R -> create((from + to) / 2 + 1, to);
	
		if(L -> open >= R -> close){
			open = L -> open - R -> close + R -> open;
			close = L -> close;
		}else{
			open = R -> open;
			close = R -> close - L -> open + L -> close;
		}
	}
	
	pii get(int from, int to){
		if(from == lf && to == rg)
			return mp(open, close);
		
		if( to < R -> lf){
			return L -> get(from, to);
		}else{
			if(from > L -> rg)
				return R -> get(from, to);
			else{
				pii A = L -> get(from, L -> rg);
				pii B = R -> get(R->lf, to);
				pii ret;
				if(A.first >= B.second){
					ret.first = A.first - B.second + B.first;
					ret.second = A.second;
					//open = L -> open - R -> close + R -> open;
					//close = L -> close;
				}else{
					ret.first = B.first;
					ret.second = B.second - A.first + A.second;
					//open = R -> open;
					//close = R -> close - L -> open + L -> open;
				}
				return ret;
			}
		}
		return mp(0, 0);
	}
	
};
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	//freopen("sbrackets.in", "r", stdin);
  scanf("%s", s);
  
  int n, lf, rg;
  
  scanf("%d", &n);
  node root;
  root.create(0, (int)strlen(s));
  for(int i = 0; i < n; i ++){
		scanf("%d%d", &lf, &rg);
		lf --, rg --;
		pii ans = root.get(lf, rg);
		
		printf("%d\n", (rg - lf + 1) - (ans.first + ans.second));
	
	}

  return 0;
}

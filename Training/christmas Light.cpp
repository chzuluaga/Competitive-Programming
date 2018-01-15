#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1000006;
int a[MAX], n, m;
char num[MAX];
string s;
int hexToInt(char x){
	if(x >= 'A' && x <= 'F')
		return (int)(x - 'A') + 10;
	
	return x - '0';
}

char intToHex(int x){
	if(x > 9)
		return (x - 10) + 'A';
	return ('0' + x);
}
void toHex(){
	s = "";
	for(int i = n - 1; i >= 0; i -= 4){
		int val = 0;
		for(int j = i - 3, p = 3; j <= i; j ++, p --){
			if(a[j]){
				val |= (1<<p);
			}
		}
		s += intToHex(val);
	}
	reverse(s.begin(), s.end());
	
	int i = 0;
	for(; i < (int)s.size(); i ++)
		if(s[i] != '0')
			break;
	bool f = false;
	for(; i < (int)s.size(); i ++){
		printf("%c",s[i]);
		f = true;
	}
	if(!f)
		printf("0");
	
	printf("\n");
}
void toBit(){
	int cur = strlen(num) - 1;
	for(int i = n - 1; i >= 0; i -= 4){
		if(cur >= 0){
			int x = hexToInt(num[cur --]);
			for(int j = 0; j < 4;j ++){
				if(x & (1<<j))
					a[i - j] = 1;
				else
					a[i - j] = 0;
			}
		}
		else{
			for(int j = 0; j < 4;j ++)
				a[i - j] = 0;
		}
	}
}

struct node{
	int lf, rg;
	int cont;
	int lazy;
	node *L, *R;
	node(){
		cont = 0;
		lazy = 0;
		L = R = NULL;
	}
	
	void create(int from, int to){
		lf = from;
		rg = to;
		
		if(from == to){
			if(a[from])
				cont = 1;
			return;
		}
		int mit = (from + to) / 2;
		
		L = new node();
		R = new node();
		
		L -> create(from, mit);
		R -> create(mit + 1, to);
		
		cont = L -> cont + R -> cont;
	}
	
	void expand(){
		if(lazy){
			if(L != NULL)
				L -> lazy ^= 1;
			
			if(R != NULL)
				R -> lazy ^= 1;
			int total = (rg - lf) + 1;
			cont = total - cont;
			lazy = 0;
		}
	}
	
	void modify(int from, int to){
		if(lf == from && rg == to){
			lazy ^= 1;
			expand();
			return;
		}
		expand();
		//left
		if(to < R -> lf){
			L -> modify(from, to);
			R -> expand();
		}else{
			if(from > L -> rg){ // right
				R -> modify(from, to);
				L -> expand();
			}
			else{//both
				L -> modify(from, L->rg);
				R -> modify(R -> lf, to);
			}
		}
		cont = L -> cont + R -> cont;
	}
	
	int get(int from, int to){
		if(lf == from && rg == to){
			expand();
			return cont;
		}
		expand();
		if(to < R -> lf){
			int val = L -> get(from, to);
			R -> expand();
			cont = L -> cont + R -> cont;
			return val;
		}
		int val = R -> get(from, to);
		L -> expand();
		cont = L -> cont + R -> cont;
		return val;
	}
	
	pii searchLeft(int from, int to){
		//cout << "busca " << from + 1 << " " << to + 1<< endl;
		if(from > to)
			return mp(-1,-1);
		
		if(lf == from && rg == to){
			expand();
			if(cont == 0){
				//cout << "retorna en " << from + 1<< " " << to + 1<< endl;
				return mp(from, to);
			}
			
			if(from < to){
				pii rr = R -> searchLeft(R -> lf, R -> rg);
				if(rr.first == -1 && rr.second == -1)
					return mp(-1, -1);
					
				pii ii = L -> searchLeft(L -> lf, L -> rg);
				
				cont = L -> cont + R -> cont;
				//cout << "por dos lados " << ii.first << " " << ii.second << " --- " << rr.first << " " << rr.second << endl;
				if(rr.first - 1 == ii.second){
					//cout << "retorna creando par " << ii.first + 1<< " " << rr.second + 1<< endl; 
					return mp(ii.first, rr.second);
				}
			//cout << " retorna SIN par " << rr.first + 1 << " " << rr.second + 1<< endl;
				return rr;
			}
			else
				return mp(-1, -1);
		}
		expand();
		//left
		if(to < R -> lf){
			pii ans = L -> searchLeft(from, to);
			R -> expand();
			cont = L -> cont + R -> cont;
			return ans;
		}else{
			if(from > L -> rg){ // right
				pii ans = R -> searchLeft(from, to);
				L -> expand();
				cont = L -> cont + R -> cont;
				return ans;
			}
			else{//both
				pii rr = R -> searchLeft(R -> lf, to);
				if(rr.first == -1 && rr.second == -1)
					return rr;
					
				pii ii = L -> searchLeft(from, L->rg);
				
				cont = L -> cont + R -> cont;
				if(rr.first - 1 == ii.second)
					return mp(ii.first, rr.second);
				return rr;
			}
		}
	}
	
	
	pii searchRight(int from, int to){
		if(from > to)
			return mp(-1,-1);
		
		if(lf == from && rg == to){
			expand();
			if(cont == 0)
				return mp(from, to);
			
			if(from < to){
				pii ii = L -> searchRight(L -> lf, L -> rg);
				if(ii.first == -1 && ii.second == -1)
					return ii;
					
				pii rr = R -> searchRight(R -> lf, R -> rg);
				cont = L -> cont + R -> cont;
				if(ii.second + 1 == rr.first)
					return mp(ii.first, rr.second);
				return ii;
			}
			else
				return mp(-1, -1);
		}
		expand();
		//left
		if(to < R -> lf){
			pii ans = L -> searchRight(from, to);
			R -> expand();
			cont = L -> cont + R -> cont;
			return ans;
		}else{
			if(from > L -> rg){ // right
				pii ans = R -> searchRight(from, to);
				L -> expand();
				cont = L -> cont + R -> cont;
				return ans;
			}
			else{//both
				pii ii = L -> searchRight(from, L->rg);
				if(ii.first == -1 && ii.second == -1)
					return ii;
					
				pii rr = R -> searchRight(R -> lf, to);
				cont = L -> cont + R -> cont;
				if(ii.second + 1 == rr.first)
					return mp(ii.first, rr.second);
				return ii;
			}
		}
	}
	
	
};




int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int t, u, v;
  //freopen("light.in", "r", stdin);
  //freopen("light.out", "w", stdout);
  scanf("%d", &t);
  
  while(t --){
		scanf("%d%d", &n, &m);
		scanf("%s", num);
		toBit();
		
		
		node root;
		root.create(0, n - 1);
		
		while(m --){
			scanf("%d%d", &u, &v);
			u --, v --;
			int vu = root.get(u, u);
			int vv = root.get(v,v);
			
			pii lf = mp(-1,-1);
			pii rg = mp(-1, -1);
			
			if(!vu)
				lf = root.searchLeft(0, u);
			
			if(!vv)
				rg = root.searchRight(v, n - 1);
				
			int from = u, to = v;
			if(lf.first != -1 && lf.second != -1){
				if(lf.first != 0)
					from = lf.first - 1;
			}
			
			if(rg.first != -1 && rg.second != -1){
				if(rg.second != n - 1)
					to = rg.second + 1;
		
			}
		
			root.modify(from, to);
		}
		
		for(int i = 0; i < n; i++)
			a[i] = root.get(i,i) ;
		
		toHex();	
	}
  
  

  return 0;
}

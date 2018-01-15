#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

struct trie{
	trie *one, *zero;
	int bit;
	int cnt1, cnt0;
	trie(){
		bit = 31;
		cnt1 = cnt0 = 0;
	}
	trie(int tam){
		bit = tam;
		cnt1 = 0, cnt0 = 0;
	}
	void insert(int &n){
		if(bit < 0)
			return;
		bool b = (n & (1<<bit));
		if(b){
			cnt1 ++;
			if(!one)
				one = new trie(bit - 1);
			one -> insert(n);
		}else{
			cnt0 ++;
			if(!zero)
				zero = new trie(bit - 1);
				
			zero -> insert(n);
		}
	}
	
	void del(int &n){
		if(bit < 0)
			return;
		bool b = (n & (1<<bit));
		if(b){
			cnt1 --;
			if(!one)
				one = new trie(bit - 1);
			one -> del(n);
		}else{
			cnt0 --;
			if(!zero)
				zero = new trie(bit - 1);
				
			zero -> del(n);
		}
	}
	
	int get(int &n){
		if(bit < 0)
			return 0;
		bool b = (n & (1<<bit));
		if(b){ //bit 1
			if(cnt0){
				return (1<<bit) ^ zero -> get(n);
			}else{
				return one -> get(n);
			}
		}else{ // bit 0
			if(cnt1){
				return (1<<bit) | one -> get(n);
			}else{
				return  zero -> get(n);
			}
		}
	}
	
};
int main(){
  int q, n;
  char ins[2];
  //freopen("d.in", "r", stdin);
	scanf("%d", &q);
  trie root;
  int x = 0;
  root.insert(x);
  while( q -- ){
		scanf("%s%d", ins, &n);
		
		if(ins[0] == '+'){
			root.insert(n);
		}
		if(ins[0] == '-'){
			root.del(n);
		}
		if(ins[0] == '?'){
			printf("%d\n",root.get(n));
		}
	}
  

  return 0;
}

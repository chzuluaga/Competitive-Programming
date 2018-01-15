#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define maxn 100005
using namespace std;
typedef long long ll;

char t[maxn];
int n;
int ra[maxn], tmpra[maxn],phi[maxn],LCP[maxn], PLCP[maxn];
int sa[maxn],tmpsa[maxn];
int c[maxn];
void countingSort(int k){
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for(i = 0; i < n; i ++)
		c[i + k < n ? ra[i + k] : 0] ++;
	
	for(i = sum = 0; i < maxi; i ++){
		int t = c[i]; c[i] = sum; sum += t;
	}
	
	for(i = 0; i < n; i ++)
		tmpsa[c[sa[i] + k < n ? ra[sa[i] + k] : 0] ++] = sa[i];
	
	for (i = 0; i < n; i ++)
	sa[i] = tmpsa[i];
}

void constructSA(){
	int i , k , r;
	for(i = 0; i < n; i ++)	ra[i] = t[i];
	for(i = 0; i < n; i ++)	sa[i] = i;
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tmpra[sa[0]] = r = 0;
		for(i = 1; i < n; i ++)
			tmpra[sa[i]] = 
			(ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] ==ra[sa[i - 1] + k]) ? r: ++ r;
		for(i = 0; i < n; i ++)
			ra[i] = tmpra[i];
		if(ra[sa[n - 1]] == n - 1)	break;
	}
}

void computeLCP(){
	int i, L;
	phi[sa[0]] = -1;
	for(i = 1; i < n; i ++)
		phi[sa[i]] = sa[i - 1];
	for(i = L = 0; i < n; i ++){
		if(phi[i] == -1){ PLCP[i] = 0; continue; }
		while(t[i + L] == t[phi[i] + L]) L ++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for(i = 0; i < n; i ++)
		LCP[i] = PLCP[sa[i]];
}
int main(){
	int m;
  while(scanf("%d", &m) && m){
		scanf("%s", t);
		n = (int)strlen(t);
		t[n ++] = '$';
		if(m == 1){
			printf("%d %d\n", n - 1, 0);
			continue;
		}
		constructSA();
		computeLCP();
		multiset<int> tam;
		set<int> idx;
		if(m > n){
			printf("none\n");
			continue;
		}
		int maxi = 0, last;
		idx.insert(-sa[0]);
		for(int i = 1; i < m; i ++){
			idx.insert(-sa[i]);
			tam.insert(LCP[i]);
		}
		//for(int i = 0; i < n; i ++)	printf("%2d\t%2d\t%2d\t%s\n", i, sa[i], LCP[i], t + sa[i]);
		if(tam.size() && (*tam.begin()) > maxi){
			maxi = (*tam.begin());
			last = -(*idx.begin());
		}
		for(int i = m; i < n; i ++){
			tam.erase(tam.lower_bound(LCP[i - m + 1]));
			idx.erase(idx.lower_bound(-sa[i - m]));
			tam.insert(LCP[i]);
			idx.insert(-sa[i]);
			
			if((*tam.begin()) == maxi){
				last = max(-(*idx.begin()), last);
			}
			if((*tam.begin()) > maxi){
				maxi = (*tam.begin());
				last = -(*idx.begin());
			}
		}
		if(maxi <= 0)
			printf("none\n");
		else
			printf("%d %d\n", maxi, last);
		
	}
	return 0;
}

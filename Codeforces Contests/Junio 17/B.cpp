#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 100005;
ll arr[MAX];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i ++){
		cin >> arr[i];
	}
		
	sort(arr, arr + n);
	
	int cur = 1;
	
	for(int i = 0; i < n; i ++){
		if(arr[i] >= cur){
			cur ++;
		}
	}
	//cout << cur << endl;
	cout << cur <<'\n';
  return 0;
}

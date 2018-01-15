#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1005;
string name[MAX];
ll dp[MAX][MAX], att[MAX], lostE[MAX], def[MAX];
unordered_map<string, int> idx;
bool beat[MAX][MAX];

void init(ll val){
	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++)
			dp[i][j] = val;
	
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("batman.in", "r", stdin);
  int Npower, Nvillian;
  ll energy;
  
  while(true){
		cin >> Npower >> Nvillian >> energy;
		
		if(Npower == 0 && Nvillian == 0 && energy == 0)
			break;
			
		memset(beat, false, sizeof(beat));	
		
		for(int i = 0; i < Npower; i ++){
				cin >> name[i] >> att[i] >> lostE[i];
				idx[name[i]] = i;
		}
		string nameV, powers;
		for(int i = 0; i < Nvillian; i ++){
			cin >> nameV >> def[i] >> powers;
			string cur = "";
			for(int j = 0; j < (int) powers.size(); j ++){
				if(powers[j] == ','){
					int id = idx[cur];
					beat[i][id] = (att[id] >= def[i]);
				//	cout << nameV << " lost " << cur << endl;
					cur = "";
					
				}else
					cur += powers[j];
			}
			int id = idx[cur];
			beat[i][id] = (att[id] >= def[i]);
		}
		
		init(energy + 1);
		
		for(int i = 0; i < Npower; i ++){
			if(beat[0][i])
				dp[0][i] = 0;
		}
		
		for(int i = 0; i < Nvillian; i ++){
			for(int j = 0; j < Npower; j ++){
					if(beat[i][j]){
						dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + lostE[j]);
					}
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			}
		}
		
		bool ans = false;
		for(int i = 0; i <= Npower; i ++)
			if(dp[Nvillian][i] <= energy)
				ans = true;
				
		cout << (ans?"Yes":"No") << '\n';
		
		
	}

  return 0;
}

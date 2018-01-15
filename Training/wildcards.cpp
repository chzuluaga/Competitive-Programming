#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define MAX_N 100010
using namespace std;
typedef long long ll;
const int MAX = 100005;
int idx = 0;
int val[MAX];
queue<int> app[MAX];
namespace Aho { // Aho-Corasick's algorithm
    const int MAXN = 1000005;
    map<char, int> g[MAXN];
    int f[MAXN]; // failure
    vector<int> output[MAXN];
    int n; // state count

    // n should be the sum of the lenghts of all substrings
    void reset() {
        n = 1;
        g[0].clear();
        output[0].clear();
        f[0] = 0;
    }

    void add(const char * s, int id) {
        int state = 0;
        //cout << " llego " << s << " con id "<< id << endl;
        for (int i = 0; s[i]; i++) {
            char c = s[i];
            if (g[state].count(c) == 0) {
                g[state][c] = n;
                g[n].clear();
                output[n].clear();
                f[n] = -1;
                n++;
            }
            state = g[state][c];
        }
        output[state].push_back(id);
    }

    void prepare() { // the BFS step
        queue<int> q;
        f[0] = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (g[0].count(c) == 0) {
                g[0][c] = 0;
            } else {
                int s = g[0][c];
                f[s] = 0;
                q.push(s);
            }
        }

        while (q.size() > 0) {
            int u = q.front(); q.pop();
            for (map<char, int>::iterator i = g[u].begin(); i != g[u].end(); ++i) {
                char label = i->first;
                int node = i->second;
                f[node] = f[u];
                while (g[f[node]].count(label) == 0) {
                    f[node] = f[f[node]];
                }
                f[node] = g[f[node]][label];
                output[node].insert(output[node].end(), output[f[node]].begin(), output[f[node]].end());
                q.push(node);
            }
        }
    }

    int next_state(int state, char label) {
        while (g[state].count(label) == 0) {
            state = f[state];
        }
        return g[state][label];
    }
}

string t, p;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	string s;
	int M;
	//freopen("wildcards.in", "r", stdin);
	while(cin >> t >> s){
		p = "";
		Aho::reset();
		vector<string> patterns;
		vector<int> fs;
		M = s.size();
		int cont = 0, idx = 0;
		bool ok = true;
		for(int i = 0; i < (int)s.size(); i ++){
			if(s[i] == '?'){
				if((int)p.size() >= 1){
				  while(!app[idx].empty()) app[idx].pop();
				  Aho::add(p.c_str(), idx ++);
				  patterns.pb(p);
				  
				}
				p = "";
				cont ++;
			}else{
				p += s[i];
				if(ok){
					ok = false;
					val[idx] = cont;
				}else{
					if(cont != 0)
						val[idx] = cont;
				}
				cont = 0;
			}
		}
		if((int)p.size()){
			while(!app[idx].empty()) app[idx].pop();
			Aho::add(p.c_str(), idx ++);
			patterns.pb(p);
		}
		
		Aho::prepare();
		int state = 0;
		for (int k = 0; k < (int)t.size(); ++k) {
				char next = t[k];
				state = Aho::next_state(state, next);
				for (int e = 0; e < (int)Aho::output[state].size(); ++e) {
						int to = Aho::output[state][e];
						if (patterns[to].size() < t.size()) { // found matching
								int pos = k - patterns[to].size() + 1;
								if(to)
									app[to].push(pos);
								else
									fs.pb(pos);
								//cout << " word with idx " << to << " " << patterns[to] << " appears from " <<  k - patterns[to].size() + 1 << " to " << k << endl;
						}
				}
		}
		
		int ans = 0, n = t.size();
		for(int i = 0; i < (int)fs.size(); i ++){
			int cur = fs[i];
			//cout << cur<< " " << val[0] << endl;
			if(cur - val[0] < 0)
				continue;
			
			for(int j = 1; j < idx; j ++){
				cur += val[j] + patterns[j - 1].size();
				//cout << cur << endl;
				int fr = app[j].front();
				while(fr < cur && !app[j].empty()){
					app[j].pop();
					if(!app[j].empty())
						fr = app[j].front();
				}
				
				if(fr != cur){
					cur = -1;
					
					break;
				}
			}
			
			if(cur == -1 || cur + (int)patterns[idx - 1].size()+ cont > n)
				ans --;
			ans ++;
		}
		
		if(idx == 0){
			ans = max(0, n - M + 1);
		}
		cout << ans << '\n';
	
	}
  return 0;
}

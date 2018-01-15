#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

namespace Aho { // Aho-Corasick's algorithm
    const int MAXN = 1000005; //sum of the lengths of all strings
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
const int MAX = 500005;
char buffer[MAX];

ll ans[100005][27];
int pos[MAX];
ll c[MAX];
int main() {
    int n;
    string t = "";
    scanf("%d", &n);
    
    Aho::reset();
    
    for(int i = 0; i < n; i ++){
			scanf("%s", buffer);
			for(int j = (int)t.size(); j < (int)t.size() + (int)strlen(buffer); j ++)
				pos[j] = i;
			
			t += (string) buffer;
		}
		
		for(int i = 0; i < n; i ++)
			scanf(LL,&c[i]);
		
		
		
		string s = "";
		vector<string> patterns;
		for(char c = 'a'; c <='z'; c ++){
			s = c;
			patterns.pb(s);
			Aho::add(s.c_str(), (int)c - 'a');
		}
		
		
		Aho::prepare();
		int state = 0;
		
		for(int k = 0; k < (int)t.size(); ++k){
			char next = t[k];
			state = Aho::next_state(state, next);
			for(int e = 0; e <(int) Aho::output[state].size(); ++ e){
				int to = Aho::output[state][e];
				if(patterns[to].size() < t.size()){
					//cout << "word with idx " << to << " " << patterns[to] << " appears in " << k << endl;
					int idx = pos[k];
					ans[idx][to] ++;
				}
			}
		}
		
		ll sol = 0;
		for(int i = 0; i < 26; i ++){
			ll sum = 0;
			for(int j = 0; j < n; j ++){
				sum += c[j] * ans[j][i];
			}
			sol = max(sol, sum);
		}
		printf(LL "\n", sol);
    return 0;
}

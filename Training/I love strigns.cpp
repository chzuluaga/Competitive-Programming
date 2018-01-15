#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 1005;
char cad[100006], word[MAX];
char s[MAX][MAX];
bool ans[MAX];

// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 1005;
// Maximum number of characters in input alphabet
const int MAXC = 26;
// FAILURE FUNCTION IS IMPLEMENTED USING f[]
int f[MAXS];
// OUT
vector<int> out[MAXS];

// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
int g[MAXS][MAXC];


int buildMatchingMachine(int k)
{

   // memset(g, -1, sizeof g);
    int states = 1;
    for (int i = 0; i < k; ++i)
    {
        strcpy(word,s[i]);
        int currentState = 0;

        for (int j = 0; j < strlen(word); ++j)
        {
            int ch = word[j] - 'a';
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;

            currentState = g[currentState][ch];
        }
        out[currentState].pb(i);
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);

    queue<int> q;

    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
    while (q.size())
    {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch <= MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];

                while (g[failure][ch] == -1)
                      failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;

                //out[g[state][ch]] |= out[failure];
                q.push(g[state][ch]);
            }
        }
    }

    return states;
}

int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';

    while (g[answer][ch] == -1){
        for(int i = 0; i < out[answer].size(); i ++)
          ans[out[answer][i]] = true;

        answer = f[answer];
    }

    return g[answer][ch];
}



void searchWords(int k, char *text)
{

    buildMatchingMachine(k);

    int currentState = 0;
    for (int i = 0; i < strlen(text); ++i)
      currentState = findNextState(currentState, text[i]);


}

int main(){
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
//  freopen("love.in", "r",stdin);

  int t, n;
  scanf("%d", &t);
  memset(g, -1, sizeof(g));
  while(t --){
    scanf("%s%d", cad, &n);

    for(int i = 0; i < n; i++)
      scanf("%s", s[i]);

    searchWords(n, cad);
    for(int i = 0; i < n; i ++)
      cout << (ans[i]?'y':'n') << '\n';

  }



  return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 10005;
string s[MAX];
int ans[MAX], sol;
int size;
string patron;
struct Node{

    Node *padre;
    Node *fall;
    map<char,Node*> hijos;
    char c;
    bool isPal;
    vector<int> nPatron;

    Node(){
        isPal = false;
    }

    Node(char ch){
        this->c = ch;
        isPal = false;
    }

    void insert(int ind,int num){
        Node *n;
        if(getChild(patron[ind]) == NULL){
            n = new Node(patron[ind]);
            hijos[patron[ind]] = n;
            n->padre = this;
        } else {
            n = this->getChild(patron[ind]);
        }
        if(size - ind > 1) n->insert(ind+1,num);
        else{
            n->isPal = true;
            n->nPatron.push_back(num);
        }
    }

    Node* getChild(char c){
        return hijos[c];
    }

};

bool cmp(string a, string b){  return a.size() < b.size();}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  //freopen("growing.in","r", stdin);
  while(true){
    cin >> N;
    if(!N)
      break;
    Node *trie = new Node();
    sol = 1;
    memset(ans, 0,sizeof(ans));
    for(int i = 0; i < N; i ++)
      cin >> s[i];
    //sort by length
    sort(s, s + N, cmp);
    for(int i = 0; i < N; i ++){
      size = s[i].size();
      patron = s[i];
      trie -> insert(0, i);
    }
  // Make Fall Functions
    trie->fall = trie; // falla de la raiz es la raiz
    queue <Node*> Q;
    Q.push(trie);       //se aÃ±ade la raiz a la cola
    map<char,Node*>::iterator it;
    while(!Q.empty()){
        Node* n = Q.front();
        Node* no;
        Q.pop();
        for(it=n->hijos.begin();it!=n->hijos.end();it++)
            Q.push((*it).second);
        if(n == trie) continue;

        Node* fall = n->padre->fall;

        while(fall->getChild(n->c) == NULL && fall != trie) fall = fall->fall;

        n->fall  = fall->getChild(n->c);
        if(n->fall == NULL) n->fall = trie;
        if(n->fall == n) n->fall = trie;
    }

    //Search
    //string text = "ahishers";
    for(int ii = 0; ii < N; ii ++){
      ans[ii] = 1;
      Node* cState = trie; // current state
      Node* n;
      Node* no;       // some other pointers
      char b;      // the character which we read
      int tam = s[ii].size();
      for(int i = 0; i < tam; i++){
          n = cState;
          //b = s[ii][i];
          b = s[ii][i];
          // I move on falls until I find the right child or reach the root
          while (n->getChild(b) == NULL && n != trie) n = n->fall;

          // I got into the root
          if (n == trie){
              n = n->getChild(b);
              if(n == NULL) n = trie;
          }
          else{
            n = n->getChild(b); // or I found the right child
          }
         // cout << n -> c << " aca " << n ->isPal << endl;
          no = n; // I move on falls to root and report all sufices I found
          if(no->isPal){
            for(int k = 0; k < n->nPatron.size() ; k++){
              int prev = n -> nPatron[k];
             // cout << "encontro substring en " << s[prev] << "\n";
              if(prev == ii)
                continue;
              ans[ii] = max(ans[ii], ans[prev] + 1);

              sol = max(sol, ans[ii]);
            }
          }
          while(no != trie){
            no=no->fall;
            if(no->isPal){
              for(int k = 0; k < no->nPatron.size() ; k++){
                int prev = no -> nPatron[k];
               // cout << "encontro NNN substring en " << s[prev] << "\n";
                if(prev == ii)
                  continue;
                ans[ii] = max(ans[ii], ans[prev] + 1);
                sol = max(sol, ans[ii]);
              }
            }
          }
          cState = n;
      }
      //cout << "----------------\n";
    }
    cout << sol << '\n';

  }


  return 0;
}

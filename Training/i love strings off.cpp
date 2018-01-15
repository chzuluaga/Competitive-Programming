#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

char patron[2000];
char cadena[200000];
int size;

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



int main(){

//    freopen("10679.in","r",stdin);
//    freopen("10679.out","w",stdout);

    int k,m;
    char ba;
    cin>>k;
    bool patrones[1010];
    while(k--){
        Node *trie = new Node();
        scanf("%s",cadena);
        cin>>m;
        memset(patrones,0,sizeof(patrones));
        for(int i=0;i<m;i++){
            scanf("%s",patron);
            size = strlen(patron);
            trie->insert(0,i);
        }

        // Make Fall Functions

        trie->fall = trie; // falla de la raiz es la raiz
        queue <Node*> Q;
        Q.push(trie);       //se aÃ±ade la raiz a la cola
        map<char,Node*>::iterator it;
        while(!Q.empty()){
            Node* n = Q.front();
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

        bool ok = false;
        //Search

        Node* cState = trie; // current state
        Node* n;
        Node* no;       // some other pointers
        char b;      // the character which we read
        int tam = strlen(cadena);
        for(int i=0; i < tam && !ok; i++){
            n = cState;
            b = cadena[i];

            // I move on falls until I find the right child or reach the root
            while (n->getChild(b) == NULL && n != trie) n = n->fall;

            // I got into the root
            if (n == trie){
                n = n->getChild(b);
                if(n == NULL) n = trie;
            }
            else n = n->getChild(b); // or I found the right child

            no = n; // I move on falls to root and report all sufices I found
            while(no != trie){

                if(no->isPal){
                    for(int k = 0; k < n->nPatron.size() ; k++)
                        patrones[n->nPatron[k]] = true;
                }
                no=no->fall;
              }
            cState = n;
        }
        for(int i=0;i<m;i++){
            if(patrones[i]) printf("y\n");
            else printf("n\n");
        }
    }
}

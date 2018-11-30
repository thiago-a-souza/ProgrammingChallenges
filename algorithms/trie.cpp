/*****************************************************************************************/
/* AUTHOR: Thiago Alexandre Domingues de Souza                                           */
/* DESCRIPTION: TRIE                                                                     */
/*****************************************************************************************/
#include <iostream>

#define MAXN 26 // MAX LENGTH OF THE ALPHABET
#define INVALID -1
#define INDEX(c) ((int)c - (int)'a')

using namespace std;

#define TRACE(x...)  
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

struct Trie {
  int value;          // value for the key
  int cnt;            // number of children nodes
  Trie *child[MAXN];  // children nodes
  Trie(){
      cnt = 0;
      value = INVALID;
      for(int i=0; i<MAXN; i++)
          child[i] = NULL;
  }
};

void insert(Trie *root, string s, int value){
Trie *p = root;
int len = s.length();

    for(int i=0; i<len; i++){
        if(p->child[INDEX(s[i])] == NULL){
            p->child[INDEX(s[i])] = new Trie();
            p->cnt++;
        }
        p = p->child[INDEX(s[i])];
    }
    p->value = value;
}

int find(Trie *root, string s){
Trie *p = root;
int len = s.length();

    for(int i=0; i<len; i++){
        if(p->child[INDEX(s[i])] == NULL)
            return -1;
        p = p->child[INDEX(s[i])];
    }
    return p->value;
}

int remove(Trie *p, string s, int length, int height){

    if(p == NULL)
        return 0;

    if(height == length){
       p->value = INVALID;
       if(p->cnt <= 0)
          return 1;
       return 0;
    } else if(remove(p->child[INDEX(s[height])], s, length, height + 1)){
                delete p->child[INDEX(s[height])];
                p->child[INDEX(s[height])] = NULL;
                p->cnt--;
                if(p->cnt <= 0 && p->value == INVALID)
                    return 1;
                return 0;
    }
    return 0;
}

int hasPreffix(Trie *root, string s){
    Trie *p = root;
    int len = s.length();

    for(int i=0; i<len; i++){
        if(p->child[INDEX(s[i])] == NULL)
            return 0;
        p = p->child[INDEX(s[i])];
    }
    return 1;
}

void showAllWords(Trie *p, string s){
    if(p == NULL)
        return;
    
    if(p->value > 0 INVALID)
        cout << s << " => " << p->value << endl;

    for(int i=0; i<MAXN; i++){
        if(p->child[i] != NULL){
            char ch = i + (int)'a';
            showAllWords(p->child[i], s + ch);
        }
    }
}



int main(){
string s[] = {"she", "sells", "sea", "shells", "by", "the", "sea", "shore"};
int sz = 8;
Trie *root = new Trie;
    
    root->value = INVALID;

    cout << "===== inserting words =====================" << endl;
    for(int i=0; i<sz; i++){
        cout << s[i] << " => " << i << endl;
        insert(root, s[i], i);
    }

    cout << "===== all words in the TRIE ===============" << endl;
    showAllWords(root, "");

    cout << "===== testing find ========================" << endl;
    for(int i=0; i<sz; i++)
        cout << s[i] << " =>  " << find(root, s[i]) << endl;

    cout << "===== testing prefix ======================" << endl;
    string preffix[] = {"se", "sed"};
    for(int i=0; i<2; i++)
        cout << "found " << preffix[i] << " = " << hasPreffix(root, preffix[i]) << endl;

    cout << "===== removing words ======================" << endl;
    string rm[] = {"shells", "the"};
    for(int i=0; i<2; i++){
        cout << rm[i] << endl;
        remove(root, rm[i], rm[i].length(), 0);
    }

    cout << "===== all words in the TRIE ===============" << endl;
    showAllWords(root, "");

    return 0;
}
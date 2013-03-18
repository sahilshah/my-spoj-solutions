#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

typedef struct _trieNode trieNode;
typedef trieNode* tnp;
typedef tnp Trie;
struct _trieNode{
	tnp edges[26];
	char s[200];	
};

tnp initTrieNode(){
	int i;
	tnp x=(tnp)malloc(sizeof(trieNode));
	for(i=0;i<26;i++)
		x->edges[i]=NULL;
	x->s[0]='\0';
	return x;
}

Trie initTrie(){
    tnp x;
    x=initTrieNode();
    return x;
}

void destroyTrie(Trie t){
	tnp temp;
	int i;
	temp=t;
	for(i=0;i<26;i++){
		if(temp->edges[i]!=NULL)
			destroyTrie(temp->edges[i]);
	}
	free(temp);
}

char* trieBFS(Trie T, int k, int m){
    queue<Trie> q;
    int i;
    q.push(T);
    tnp t;
    char* s=(char*)malloc(sizeof(char)*(m+1));
    while(!q.empty()){
        t=q.front();
        q.pop();
        for(i=0;i<k;i++){
            if(t->edges[i]==NULL){
                strcpy(s,t->s);
                int l=strlen(s);
                s[l]=(char)('a'+i);
                s[l+1]='\0';
                while(!q.empty())
                    q.pop();
                return s;
            }
            else
                q.push(t->edges[i]);
        }
    }
}

tnp addString(Trie t, char* rem){
	char cur[10010];
	int curIndex=0;
	while((*rem)!='\0'){
		int ei=(*rem)-'a';
		cur[curIndex++]=*rem++;
		cur[curIndex]='\0';
		if(t->edges[ei])
			t=t->edges[ei];
		else{
			tnp ntn=initTrieNode();
			strcpy(ntn->s,cur);
			t->edges[ei]=ntn;
			t=ntn;
		}
	}
	return t;
}

tnp findString(Trie t, char* fs){
	while(*fs!='\0'){
		int ei=(*fs)-'a';
		if(t->edges[ei]){
			t=t->edges[ei];
			fs++;
		}
		else
			return NULL;
	}
	return t;
}

int main(){
    char text[10010],s[110];
    int t,n,m,k;
    Trie T;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%s\n",text);
        char* s;
        T=initTrie();
        s=text;
        int st=0,end=0;
        int l=strlen(text);
        end=st+m+1;
        while(st<l){
            char temp=*(s+end);
            *(s+end)='\0';
        	addString(T,s);
            *(s+end)=temp;
            st++;
            s++;
        }
        char* ans=trieBFS(T,k,m);
        printf("%s\n",ans);
        destroyTrie(T);
    }
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef struct _trieNode trieNode;
typedef trieNode* tnp;
typedef tnp Trie;
struct _trieNode{
	tnp edges[26];
};

tnp initTrieNode(){
	int i;
	tnp x=(tnp)malloc(sizeof(trieNode));
	for(i=0;i<26;i++)
		x->edges[i]=NULL;
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

tnp addString(Trie t, char* rem){
	while((*rem)!='\0'){
		int ei=(*rem++)-'a';
		if(t->edges[ei])
			t=t->edges[ei];
		else{
			tnp ntn=initTrieNode();
			t->edges[ei]=ntn;
			t=ntn;
		}
	}
	return t;
}

int getLCS(Trie t, char* fs){
    int count=0;
    while(*fs!='\0'){
        int ei=(*fs)-'a';
        if(t->edges[ei]){
            t=t->edges[ei];
            fs++;
            count++;
        }
        else
            return count;
    }
    return count;   
}

char t1[250010],t2[250010];
int main(){
    int i,l,l1,l2,ans=-1;
    Trie T;
    char *s,*t,*f;
    scanf("%s\n",t1);
    scanf("%s\n",t2);
    T=initTrie();
    l1 = strlen(t1);
    l2 = strlen(t2);
    if(l1>l2){
        t=t2;
        l=l2;
        f=t1;
    }
    else{
        t=t1;
        l=l1;
        f=t2;
    }
    for(i=l;i>=0;i--)
    	addString(T,t+i);
    while(*f!='\0')
        ans = max(ans,getLCS(T,f++));
    printf("%d\n",ans);
    destroyTrie(T);
}

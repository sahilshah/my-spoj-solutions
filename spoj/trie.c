#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _trieNode trieNode;
typedef trieNode* tnp;
typedef tnp Trie;
struct _trieNode{
	tnp edges[26];
	// char s[200];	
};

tnp initTrieNode(){
	int i;
	tnp x=(tnp)malloc(sizeof(trieNode));
	for(i=0;i<26;i++)
		x->edges[i]=NULL;
	// x->s[0]='\0';
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
	//return temp;
}

Trie initTrie(){
	tnp x;
	x=initTrieNode(x);
	return x;
}

tnp addString(Trie t, char* rem){
	char cur[200];
	int curIndex=0;
	while((*rem)!='\0'){
		int ei=(*rem)-'a';
		cur[curIndex++]=*rem++;
		cur[curIndex]='\0';
		if(t->edges[ei]){
			t=t->edges[ei];
		}
		else{
			tnp ntn=initTrieNode();
			// strcpy(ntn->s,cur);
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
		else{
			return NULL;
		}
	}
	return t;
}	
/*
int main(){
    char text[10010],s[110];
    int t,n,m,k;
    Trie T;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%s\n",text);
        printf("TEXT is: %s\n",text);
        // printAllStrings(text,s,m,k,0,0);
        // cout << "next\n";
        char* s;
        T=initTrie();
        s=text;
        while((*s)!='\0')
        	addString(T,s++);
       	int count=0;
       	s=text;
       	// while(findString(T,s))
       	while(*s!='\0' && findString(T,s)){
       		printf("YES! %s is in trie\n",s);
       		s++;
       	}
       	for(l=1;l<m;l++){
       		for()
       	}
       	destroyTrie(T);
    }
}*/

int printAllStrings(Trie T, char* s, int m, int k, int lev, int flag){
    int i;
    char c;
    if(flag)
        return flag;
    if(lev==m){
        int x;
        s[m]='\0';
        //string s1(s);
        if(!findString(T,s)){
            printf("%s\n",s);
            flag=1;
        }
        else{
            flag=0;
        }
        return flag;
    }
    //string s("");
    for(i=0;i<k;i++){
        c='a'+i;
        s[lev]=c;
        flag=printAllStrings(T,s,m,k,lev+1,flag);
    }
    return flag;
}

int main(){
    char text[10010],s[110];
    int t,n,m,k;
    Trie T;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%s\n",text);
        // printf("TEXT is: %s\n",text);
        char* s;
        T=initTrie();
        s=text;
        while((*s)!='\0')
        	addString(T,s++);

        // cout << "TEXT is: " << text <<'\n';
        printAllStrings(T,s,m,k,0,0);
        destroyTrie(T);
        // cout << "next\n";
    }
}

#include <stdio.h>
#include <stdlib.h>
#define N 20000
#define T 30
typedef struct _stacknode *StackLink;
typedef struct _stacknode
{
	long int element;
	StackLink next;
} StackNode;

typedef struct
{
	StackLink head;
	int size;
} Stack;

Stack createStack(Stack s)
{
	s.head = NULL;
	s.size =0;
	return s;
}
Stack push(Stack s, long int a)
{
	StackLink link;
	link = (StackNode *)malloc(sizeof(struct _stacknode));
	link->next = s.head;
	link->element = a;
	s.head = link;
	s.size++;
	return s;
}
long int pop(Stack *s)
{
	long int elem;	
	StackLink temp;
	temp = s->head;
	s->head = temp->next;
	s->size--;
	elem = temp->element;
	free(temp);
	return elem;
}

void merge (long int *a, int p, int q, int r){

	int i,j,k;
	long int b[N];
	for(i=p;i<=r;i++)
		b[i]=a[i];

	i=p;
	j=q+1;
	k=p;

	while(i<=q && j<=r)
		if (b[i]<=b[j])
			a[k++]=b[i++];
		else
			a[k++]=b[j++];

	while(i<=q)
		a[k++]=b[i++];
	while(j<=r)
		a[k++]=b[j++];
}

void msort(long int *a, int p, int q){

	int i,start,end;
	Stack s,s1;
	start = p;end=q;
	s = createStack(s);
	s1 = createStack(s1);
	s = push(s,p); s = push(s,q);
	while(s.size!=0)
	{	
		q = pop(&s); p = pop(&s);		
		while(p<q){
			i=(p+q)/2;
			s = push(s, i+1); s = push(s,q);
			s1 = push(s1, p); s1 = push(s1, q);
			q = i;
		}
		
	}
	while(s1.size!=0)
	{
		q = pop(&s1); p = pop(&s1);
		i = (p+q)/2;
		merge(a,p,i,q);
	}
}

int main(){
	int i,j,l,n,k,t;
	long int temp,height[N],mindiff[T];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%ld",&height[j]);
		msort(height,0,n-1);
		mindiff[i]=height[k-1]-height[0];
		for(l=0;l<=(n-k);l++){
			temp=height[k+l-1]-height[l];
			if(temp<mindiff[i])
				mindiff[i]=temp;
		}
	}
	for(i=0;i<t;i++)
		printf("%ld\n",mindiff[i]);
	return 0;
}



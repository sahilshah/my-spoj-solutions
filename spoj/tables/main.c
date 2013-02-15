#include <stdio.h>
#include<stdlib.h>

//***************************  STACK STARTS ****************************//

typedef struct link link;
struct link {
   int num;
   link *next;
};
typedef struct stack stack;
struct stack {
   link *head;
   int size;
};
void print_stack(stack s)
{
  link *i;
  for(i=s.head;i!=NULL;i=i->next)
  {
     printf("%d  ",i->num);
  }
  printf("\n");
}
int isempty(stack s)
{
  if(s.head==NULL)
  return (1);
  else
  return (0);
}
stack initialize_stack(stack s)
{
   s.head=NULL;
   s.size=0;
   return s;
}
stack push(stack s,int n)
{
  link *temp=(link *)malloc(sizeof(link));
  if(s.head==NULL)
  {
    s.head=(link *)temp;
    temp->num=n;
    temp->next=NULL;
    s.size++;
  }
  else
  {
    temp->num=n;
    temp->next=(link *)s.head;
    s.head=(link *)temp;
    s.size++;
  }
  return (s);
}
int top(stack s)
{
   int num=s.head->num;
   return(num);
}
stack pop(stack s)
{
   link *temp=s.head;
   s.head=s.head->next;
   free(temp);
   s.size--;
   return (s);
}

//***************************  STACK ENDS ****************************//

int print_array(int a[],int size)
{
   int i;
   for(i=0;i<size;i++)
   {printf("%d  ",a[i]);}
   printf("\n");
   return 0;
}
int swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
  return 0;
}
int choose_pivot(int a[],int l,int h)
{
   return(h);
}
int partition(int a[],int p,int l,int h)
{
   while(l<h)
   {
      while(a[l]<=a[p] && l!=h)
      l++;
      while(a[h]>a[p] && l!=h)
      h--;
      swap(&a[l],&a[h]);
   }
   swap(&a[l],&a[p]);
   return l;
}
int quicksort(int a[],int l,int h)
{
  stack s;
  s=initialize_stack(s);
  s=push(s,l);s=push(s,h);
  while(!isempty(s))
  {
    h=top(s);s=pop(s);l=top(s);s=pop(s);
    while(l<h)
    {
    int p=choose_pivot(a,l,h);
    int k=partition(a,p,l,h);
    s=push(s,l);s=push(s,k-1);
    l=k+1;
    }
  }
  return 0;
}

int main(){
	int i,n,k,s,count=0,sum=0,screws;
	scanf("%d %d %d",&n,&k,&s);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	screws=k*s;

	quicksort(a,0,n-1);
	i=n-1;
	while(sum<screws){
		sum=sum+a[i];
		i--;
		count++;
	}
	//for(j=0;j<n;j++)
		//printf("%d\n",a[j]);
	printf("%d",count);
		
}



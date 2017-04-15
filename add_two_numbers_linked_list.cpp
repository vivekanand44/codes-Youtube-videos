#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int a;
	struct node *next;
}node;

node *reverse(node *head)   //reverse the linked list
{
node *p , *q;
if(head == NULL)
return head;
p = head;
q = p->next;
if(q == NULL)
return p;
q = reverse(q);
p->next->next = p;
p->next = NULL;
return q;
}

int main()
{
node *p , *q , *f ,*s,*answer,*final_answer,*start_digit;
int n1 , n2 , i , carry_over , ans , cnt , flag, cnt_extra , diff = 0;
printf("Enter the digits in the first number");
scanf("%d",&n1);

printf("\n Enter the digits separated by space");
p = (node *)malloc(sizeof(node));
p->next = NULL;
scanf("%d",&p->a);
f = p;    // F POINTS TO THE START OF THE FIRST NUMBER LINKED LIST

for(i=1;i<n1;i++)
{
	q = (node*)malloc(sizeof(node));
	q->next = NULL;
	scanf("%d",&(q->a));
	p->next = q;
	p = p->next;
}

p = NULL;
printf("\n Enter the number of digits in the second number");
scanf("%d",&n2);

printf("\n Enter the number separated by space");
p = (node *)malloc(sizeof(node));
p->next = NULL;
scanf("%d" , &(p->a));
s = p; // S POINTS TO THE START OF THE FIRST NUMBER LINKED LIST

for(i=0;i<n2-1;i++)
{
	q = (node*)malloc(sizeof(node));
	q->next = NULL;
	scanf("%d",&(q->a));
	p->next = q;
	p = p->next;
}

//REVERSE THE LINKED LIST NUMBERS
f = reverse(f);
s = reverse(s);

//ADD THE EXTRA ZEROES IF NEEDED
if (n1 > n2)
	{
	diff = n2 - n1;
	flag = 1;
	}
else if(n2 > n1)
	{
		diff = n2 - n1;
		flag = 2;
	}	

if(flag == 1)
	p = f;
else if(flag == 2)
	p = s;

cnt_extra = 0;
while(cnt_extra < diff)
	{
		q = (node*)malloc(sizeof(node));
		q->next = NULL;
		q->a = 0;
		q->next = p;
		p = q;
		cnt_extra++;
	}

if(flag == 1)
	f = p;
else if(flag == 2)
	s = p;

//ADD THE TWO LINKED LISTS
carry_over = 0;
cnt = 0;
while(f!=NULL && s!=NULL)
{
	ans = f->a + s->a;
	ans = ans + carry_over;
	if((ans/10) > 0)
		carry_over = ans/10;
	else
		carry_over = 0;
	answer = (node*)malloc(sizeof(node));
	answer->next = NULL;	
	answer->a = ans%10;
	if(cnt == 0)
	{
	start_digit = answer;	
	final_answer = answer;
	cnt++;
	}
	else
	{
		final_answer->next = answer;
		final_answer = final_answer->next;
	}

f = f->next;
s = s->next;
}
	printf("\n");
	
	if(f!=NULL && s==NULL)
		{
			while(f!=NULL)
			{
			ans = f->a + carry_over;
			if((ans/10) > 0)
				carry_over = ans/10;
			else
				carry_over = 0;
			answer = (node*)malloc(sizeof(node));
			answer->next = NULL;	
			answer->a = ans%10;
			final_answer->next = answer;
			final_answer = final_answer->next;
			f = f->next;
			}
		}
	else if(s!=NULL && f==NULL)
		{
			while(s!=NULL)
			{
			ans = s->a + carry_over;
			if((ans/10) > 0)
				carry_over = ans/10;
			else
				carry_over = 0;
			answer = (node*)malloc(sizeof(node));
			answer->next = NULL;	
			answer->a = ans%10;
			final_answer->next = answer;
			final_answer = final_answer->next;
			s = s->next;
			}
		}
	
//PRINT THE ANSWER
	start_digit = reverse(start_digit);
	printf("%d",carry_over);
	while(start_digit!=NULL)
			{
				printf("->%d",start_digit->a);
				start_digit = start_digit->next;
			}
				
return 0;
}

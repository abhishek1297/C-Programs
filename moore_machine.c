#include<stdio.h>
#include<string.h>

struct tuple
{
	int Q[20];
	char input[10];
	int Qf[10];
	
}dfa;

struct node
{
	int state;
	char op[100];
	int cnt;
	int final;
	struct node *trans[10];
}node[20];

int nodecnt=0,ipcnt=0,tcnt=0,fcnt=0;

void accept();
void delta(struct node*,struct node*);
void display();
void processString();
int main()
{
	accept();
	display();
	processString();
	return 0;
}

void accept()
{
	int i=0,j=0;
	int state;
	printf("Number Of States : ");
	scanf("%d",&nodecnt);
	printf("\nNumber Of Input Symbols : ");
	scanf("%d",&ipcnt);
	
	for(i=0;i<ipcnt;i++)
	{
		printf("\nInput Symbol %d :",i+1);
		scanf(" %c",&dfa.input[i]);
	}
	
	for(i=0;i<nodecnt;i++)
	{
		dfa.Q[i]=node[i].state=i;
		printf("\nOutput Symbol/String for Q%d: ",dfa.Q[i]);
		scanf(" %s",&node[i].op);
	}
	
	for(i=0;i<nodecnt;i++)
	{
		tcnt=0;
		for(j=0;j<ipcnt;j++)
		{
			printf("\nFor Input = %c , Q%d goes to Q",dfa.input[j],dfa.Q[i]);
			scanf("%d",&state);
			delta(&node[i],&node[state]);
		}
		node[i].cnt=tcnt;
	}
	
	printf("\nNumber of Final states : ");
	scanf("%d",&fcnt);
	
	for(i=0;i<fcnt;i++)
	{
		printf("\nEnter the %d final state : Q",i+1);
		scanf("%d",&dfa.Qf[i]);
		node[dfa.Qf[i]].final=1;
	}
}

void delta(struct node *curr,struct node *next)
{
	curr->trans[tcnt++]=next;
}
void display()
{
	int i=0,j=0,k=0;
	char *str;
	printf("\n---------------------------------\nDFA Tuples\n");
	//printf("\nM = { Q %c %c %c %c Q0 F }\n",207,167,221,229);
	printf("\nQ = {");
	for(i=0;i<nodecnt;i++)
		printf(" Q%d",i);
	printf(" }\n");
	
	printf("\nEpsilon = {");
	for(i=0;i<ipcnt;i++)
		printf(" %c",dfa.input[i]);
	printf(" }\n");
	
	printf("\nOutput Symbols = {");
	for(i=0;i<nodecnt;i++)
		printf(" %s",node[i].op);
	printf(" }\n");
	
	printf("\nInitial state = Q0\n");
	
	printf("\nFinal States = {");
	for(i=0;i<fcnt;i++)
		printf(" Q%d",dfa.Qf[i]);
	printf(" }\n");
	
	printf ("\n\tTransition Table\n-----------------------------------\n d\tlamda\t");
	for(i=0;i<ipcnt;i++)
		printf("\t%c   ",dfa.input[i]);
	for(i=0;i<nodecnt;i++)
	{
		if(node[i].final)
			printf("\n*Q%d\t%s\t",node[i].state,node[i].op);
		else
			printf("\n Q%d\t%s\t",node[i].state,node[i].op);
		for(j=0,k=0;j<ipcnt,k<node[i].cnt;j++,k++)
		{
			printf("\tQ%d",node[i].trans[k]->state);
		}
	}

}

void processString()
{
	int i=0,size=0,j=0,k=0,z=0,cnt=0,invalid=0,buffer[10];
	struct node *ptr;
	char temp,str[20];
	printf("\n\nEnter a String : ");
	scanf("%s",&str);
	for(j=0;j<ipcnt;j++)
	{
		buffer[j]=dfa.input[j];
		if(!strchr(str,dfa.input[j]))
		{
			invalid=1;break;
		}
			
	}
	size=strlen(str);
	if(!invalid)
	{
		for(i=0;i<size;i++)
		{
			temp=str[i];
			for(j=0;j<ipcnt;j++)
				if(temp==dfa.input[j]) break;
			cnt=j;
			if(k<nodecnt)
			{
				ptr=node[k].trans[cnt];
				ptr=&node[ptr->state];
				buffer[z++] = k = ptr->state;
			}
		}
		printf("\n\nConclusion :\t");
		if(node[ptr->state].final)
		{
			printf("String is VALID!!!");
			printf("\nOutput of Moore Machine :\n %s  ",node[0].op);
			for(i=0;i<z;i++)
				printf("%s  ",node[buffer[i]].op);
		}
		else
			printf("String is INVALID!!!");
	}
}

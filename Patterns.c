#include<stdio.h>
int i,j,k;
void pattern_1()
{	
/*
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
*/
	for(i=1;i<=5;i++)
	{
		for(j=i;j<=5;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void pattern_2()
{
/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
	for(i=5;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void pattern_3()
{
/*
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
*/
	for(i=1;i<=5;i++)
	{
		for(j=i;j>=1;j--)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void pattern_4()
{
/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",i);
		}
		printf("\n");
	}
}

void pattern_5()
{
/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/
	for(i=1;i<=5;i++)
	{
		for(j=i;j>=1;j--)
		{
			printf("%d ",j%2);
		}
		printf("\n");
	}
}

void pattern_6()
{
/*
1 3 5 7 9
3 5 7 9
5 7 9
7 9
9
*/
	for(i=1;i<=9;i+=2)
	{
		for(j=i;j<=9;j+=2)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void pattern_7()
{
/*
1
2 4
1 3 5
2 4 6 8
1 3 5 7 9
*/
	for(i=1;i<=5;i++)
	{
		if(i%2==0) k=2;
		else k=1;
		for(j=1;j<=i;j++,k+=2)
		{
			printf("%d ",k);
		}
		printf("\n");
	}
}

void pattern_8()
{
/*
1
1 2 3
1 2 3 4 5
1 2 3 4 5 6 7
*/
	for(i=1;i<=7;i+=2)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void pattern_9()
{
/*
1
2 6
3 7 10
4 8 11 13
5 9 12 14 15
*/
	for(i=1;i<=5;i++)
	{
		k=i;
		for(j=1;j<=i;j++)
		{
			printf("%d ",k);
			k+=5-j;
		}
		printf("\n");
	}
}

void pattern_10()
{
/*
    1
  2 3 4
5 6 7 8 9
*/
	k=1;
	for(i=1;i<=5;i+=2)
	{
		for(j=5;j>=1;j--)
		{
			if(j>i)
				printf(" ");
			else
				printf("%d ",k++);
		}
		
		printf("\n");
	}
}

void pattern_11()
{
/*
12344321
123  321
12    21
1      1
*/
  int i,j,k;
  for(i=4;i>=1;i--)
  {
    for(j=1;j<=4;j++)
    {
      if(j<=i)
        printf("%d",j);
      else
        printf(" ");
    }
    for(j=4;j>=1;j--)
    {
      if(j<=i)
        printf("%d",j);
      else
        printf(" ");
    } 
    printf("\n");
  }
}

void pattern_12()
{
/*
11111
2222
333
22
1
*/
	//k=5;
	for(i=1;i<=5;i++)
	{
		for(j=5;j>=i;j--)
		{
			if(i<=3)
				printf("%d",i);
			else
				printf("%d",6-i);
		}
		printf("\n");
	}
	/*
	for(i=2;i>=1;i--)
	{
		for(j=k--;j>=1;j--)
		{
			printf("%d",i);
		}
		printf("\n");
	}*/
	
}

void pattern_13()
{
/*
5432*
543*1
54*21
5*321
*4321
*/
	for(i=1;i<=5;i++)
	{
		for(j=5;j>=1;j--)
		{
			if(i==j)
				printf("*");
			else
				printf("%d",j);
		}
		printf("\n");
	}
}

int main()
{
	int ch;
	
	while(1)
	{
		printf(">>> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:pattern_1();break;
			case 2:pattern_2();break;
			case 3:pattern_3();break;
			case 4:pattern_4();break;
			case 5:pattern_5();break;
			case 6:pattern_6();break;
			case 7:pattern_7();break;
			case 8:pattern_8();break;
			case 9:pattern_9();break;
			case 10:pattern_10();break;
			case 11:pattern_11();break;
			case 12:pattern_12();break;
			case 13:pattern_13();break;
			default :exit(0);
		}
	}
	return 0;
}

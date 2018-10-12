#include<stdio.h>
#include<math.h>

int main()
{
    //01000100 01000011 01000010 01000001
    int i = (int)
	(pow(2,0) + pow(2,6) + pow(2,9) + pow(2,14) + pow(2,16) + pow(2,17) + pow(2,22) + pow(2,26) + pow(2,30));
    int tmp = i, k;
    for(k = 0; k <= 3;)
    {
        char c = *(char *) &i;
        printf("%c\t",c);
        i = tmp;
        i = i >> 8 * (++k);
    }
    return 0;
}
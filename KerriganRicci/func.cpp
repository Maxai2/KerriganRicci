#include <stdio.h>

#define MAXLINE 1000

int hCtoi(char c);
char itoHc(int num);

int getline()
{
    int c, i;
    char line[MAXLINE];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return (i);
}

int _pow(int x, int n) {
    int p;

    for (p = 1; n > 0; --n)
        p = p * x;
    
    return p;
}

void copy()
{
    int i;
    char line[MAXLINE], save[MAXLINE];

    i = 0;
    while ((save[i] = line[i]) != '\0')
        ++i;
}

int strlen(char str[])
{
    int count = 0;

    while (str[count] != '\0')
        ++count;

    return count;
}

bool isLeap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int atoi(char s[])
{
    int i, n = 0;

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + s[i] - '0';

    return n;
}

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int htoi(char *s)
{
	int res = 0;

	while (*s)
	{
		char c = *s++;

		if (c >= '0' && c <= '9')
			c -= '0';
		else
		if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		else
		if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else
			return res;

		res <<= 4;
		res += c;
	}

	return res;
}

int htoi()
{
    int i = 0, result = 0, k = 0, hNum = 0;
    char hArray[10];
    char c;

    while ((c = getchar()) != '\n')
    {
        hArray[i++] = c;
    }

    hArray[i] = '\0';
        
    k = i - 1;
    for (int j = 0; j < i; j++, k--) 
    {
        if (('a' <= hArray[j] && hArray[j] <= 'f') || ('A' <= hArray[j] && hArray[j] <= 'F'))
        {
            hNum = hCtoi(hArray[j]);
            result += hNum * _pow(16, k);
        }
        else
            result += (hArray[j] - '0') * _pow(16, k);
    }

    //printf("%s %i %i\n", hArray, i, result);

    return result;
}

char *itoh(int num)
{
	static char resultChar[] = "00000000";
	static char Hex[] = "0123456789ABCDEF";

	int index = sizeof(resultChar)-1;

	do
	{
		resultChar[--index] = Hex[num & 0xF];
		num >>= 4;
	}
	while (num);

	return &resultChar[index];
}

void itoh()
{
    char num[10], resultChar[10];
    int i = 0, index = 0;
    char c;

    while ((c = getchar()) != '\n') {
        num[i++] = (int)c;
    }

    num[i] = '\0';
    int _num = atoi(num);
    i = 0;
    int delNum[10], tempNum = 0;
    delNum[i++] = _num;

    while (true) {
        tempNum = _num / 16;
        if (tempNum > 15)
        {
            delNum[i++] = tempNum;
            _num /= 16;
        }
        else
        {
            delNum[i] = tempNum;
            resultChar[index++] = tempNum + '0';
            break;
        }
    }

    int itoHcVal = 0, j = i - 1;
    int tempSymb;

    while (true) {
        if (j == -1)
            break;

        itoHcVal = delNum[j--] - (delNum[i--] * 16);

        if (10 <= itoHcVal && itoHcVal <= 15)
            resultChar[index++] = itoHc(itoHcVal);
        else
            resultChar[index++] = itoHcVal + '0';
    }

    resultChar[index] = '\0';

    printf("%s\n", resultChar);
}





















void countNumSymAndETC()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf("\nwhite space = %d, other = %d\n", nwhite, nother);

}

int hCtoi(char c)
{
    switch (c)
    {
        case 'a':
        case 'A':
            return 10;
        case 'b':
        case 'B':
            return 11;
        case 'c':
        case 'C':
            return 12;
        case 'd':
        case 'D':
            return 13;
        case 'e':
        case 'E':
            return 14;
        case 'f':
        case 'F':
            return 15;
    }
}

char itoHc(int num)
{
    switch (num)
    {
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }
}





















//#include <stdio.h>
//#define MAXLINE 1000
//
//char line[MAXLINE];
//char save[MAXLINE];
//int max;
//
//int getline()
//{
//    int c, i;
//    extern char line[];
//
//    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//        line[i] = c;
//
//    if (c == '\n') {
//        line[i] = c;
//        ++i;
//    }
//    line[i] = '\0';
//    return (i);
//}
//
//void copy()
//{
//    int i;
//    extern char line[], save[];
//
//    i = 0;
//    while ((save[i] = line[i]) != '\0')
//        ++i;
//}

/*
main()
{
    int len;
    extern int max;
    extern char save[];

    max = 0;
    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0)
        printf("%s", save);
}
*/


//#include <iostream>
//
//using namespace std;
//
////#define LOWER 0
////#define UPPER 300
////#define STEP 20
//
//void main()
//{
    //printf("Hello World!\n");

    //int lower, upper, step;
    //float fahr, celsius;

    //lower = 0;
    //upper = 300;
    //step = 20;

    //fahr = lower;

    //printf("Program for printing Celsius by Fahr\n\n");

    ////printf("   F\tC\n");
    //printf("   C\tF\n");
    //while (fahr <= upper)
    //{
    //    celsius = (5.0 / 9.0) * (fahr - 32.0);
    //    //printf("%4.0f %6.1f\n", fahr, celsius);
    //    printf("%6.1f %4.0f\n", celsius, fahr);
    //    fahr = fahr + step;
    //}

    //int fahr;

    //for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    //{
    //    printf("%4d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    //}

    //int c;

    //while ((c = getchar()) != EOF)
    //{
    //    putchar(c);
    //}

    //int nc = 0;

    //while (getchar() != EOF)
    //    ++nc;

    //printf("%ld\n", nc);

    //double nc;

    //for (nc = 0; getchar() != EOF; nc++)
    //    printf("%.0f\n", nc);

    //int c, nl = 0;

    //for (c = 0; (c = getchar()) != EOF; c++)
    //{
    //    if (c == '\n')
    //        nl++;

    //    printf("%d\n", nl);
    //}

    //int spaceC, tabC, newLineC;
    //char c;

    //spaceC = tabC = newLineC = 0;

    //for (c = 0; (c = getchar()) != EOF; c++)
    //{
    //    if (c == '\t')
    //    {
    //        tabC++;
    //    }
    //    else
    //    if (c == ' ')
    //    {
    //        spaceC++;
    //    }
    //    else
    //    if (c == '\n')
    //    {
    //        newLineC++;
    //    }
    //}
/*
    system("pause");
}*/

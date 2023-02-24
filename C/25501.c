#include <stdio.h>  // ¿Á±Õ¿« ±Õ¿Á
#include <string.h>

int Index = 0;

int recursion(const char* s, int l, int r)
{
    Index += 1;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
    return recursion(s, 0, strlen(s) - 1);
}


int main()
{
    int t;
    scanf("%d", &t);

    char str[1001];
    for (int i = 0; i < t; i++)
    {
        scanf("%s", str);
        printf("%d ", isPalindrome(str));
        printf("%d\n", Index);
        Index = 0;
    }
}
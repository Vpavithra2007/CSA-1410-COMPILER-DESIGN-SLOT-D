
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100], id[20][30], num[20][30], op[30];
    int i = 0, a = 0, b = 0, c = 0, j;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (isalpha(str[i]) || str[i] == '_')
        {
            j = 0;
            while (isalnum(str[i]) || str[i] == '_')
                id[a][j++] = str[i++];
            id[a++][j] = '\0';
        }
        else if (isdigit(str[i]))
        {
            j = 0;
            while (isdigit(str[i]))
                num[b][j++] = str[i++];
            num[b++][j] = '\0';
        }
        else if (strchr("+-*/%=", str[i]))
            op[c++] = str[i++];
        else
            i++;
    }

    printf("\nIdentifiers: ");
    for (i = 0; i < a; i++)
        printf("%s ", id[i]);

    printf("\nConstants: ");
    for (i = 0; i < b; i++)
        printf("%s ", num[i]);

    printf("\nOperators: ");
    for (i = 0; i < c; i++)
        printf("%c ", op[i]);

    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nIdentifiers: ");
    while (str[i] != '\0')
    {
        if (isalpha(str[i]) || str[i] == '_')
        {
            while (isalnum(str[i]) || str[i] == '_')
                printf("%c", str[i++]);
            printf(" ");
        }
        else if (isdigit(str[i]))
        {
            while (isdigit(str[i]))
                printf("%c", str[i++]);
            printf(" ");
        }
        else if (strchr("+-*/%=", str[i]))
        {
            printf("%c ", str[i]);
            i++;
        }
        else
            i++;
    }

    printf("\n");
    return 0;
}

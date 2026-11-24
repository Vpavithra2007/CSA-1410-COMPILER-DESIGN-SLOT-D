#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[1000];
    int i = 0;

    printf("Enter the source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0')
    {
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        if (input[i] == '/' && input[i + 1] == '/')
            break;

        if (input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;
            while (input[i] != '\0' &&
                   !(input[i] == '*' && input[i + 1] == '/'))
                i++;
            i += 2;
            continue;
        }

        if (isalpha(input[i]) || input[i] == '_')
        {
            printf("Identifier: ");
            while (isalnum(input[i]) || input[i] == '_')
                putchar(input[i++]);
            printf("\n");
        }
        else if (isdigit(input[i]))
        {
            printf("Number: ");
            while (isdigit(input[i]))
                putchar(input[i++]);
            printf("\n");
        }
        else if (strchr("+-*/%=<>!", input[i]))
        {
            printf("Operator: %c\n", input[i++]);
        }
        else if (strchr(";,(){}[]", input[i]))
        {
            printf("Special Symbol: %c\n", input[i++]);
        }
        else
        {
            i++;
        }
    }

    return 0;
}
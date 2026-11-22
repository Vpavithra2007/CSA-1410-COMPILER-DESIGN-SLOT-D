
#include <stdio.h>
#include <string.h>

int main()
{
    char com[100];
    int len;

    printf("Enter comment: ");
    fgets(com, sizeof(com), stdin);

    len = strlen(com);

    if (len >= 2 && com[0] == '/' && com[1] == '/')
        printf("It is a comment");
    else if (len >= 4 && com[0] == '/' && com[1] == '*'
             && strstr(com, "*/") != NULL)
        printf("It is a comment");
    else
        printf("It is not a comment");

    return 0;
}

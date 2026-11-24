include<stdio.h> 
#include<ctype.h>
#include<string.h>
int limit, x = 0;
char production[10][10], array[10];
 
void find_first(char ch);
void find_follow(char ch);
void Array_Manipulation(char ch);
 
int main()
{
      int count;
      char option, ch;
      printf("\nEnter Total Number of Productions:\t");
      scanf("%d", &limit);
      for(count = 0; count < limit; count++)
      {
            printf("\nValue of Production Number [%d]:\t", count + 1);
            scanf("%s", production[count]);
      }
      do
      {
            x = 0;
            printf("\nEnter production Value to Find Follow:\t");
            scanf(" %c", &ch);
            find_follow(ch);
            printf("\nFollow Value of %c:\t{ ", ch);
            for(count = 0; count < x; count++)
            {
                  printf("%c ", array[count]);
            }
            printf("}\n");
            printf("To Continue, Press Y:\t");
            scanf(" %c", &option);
      }while(option == 'y' || option == 'Y');
      return 0;
}
 
void find_follow(char ch)
{
      int i, j;
      int length = strlen(production[i]);
      if(production[0][0] == ch)
      {
            Array_Manipulation('$');
      }
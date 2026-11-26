Input Source Program: (sample.c)
#define PI 3.14
#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
void main()
{

int a,b,c = 30;
printf(&quot;hello&quot;);
}
Program: (count_macro.l)
%{
int nmacro, nheader;
%}
%%
^#define { nmacro++; }
^#include { nheader++; }
.|\n { }
%%
int yywrap(void) {
return 1;
}
int main(int argc, char *argv[]) {
yyin = fopen(argv[1], &quot;r&quot;);
yylex();
printf(&quot;Number of macros defined = %d\n&quot;, nmacro);
printf(&quot;Number of header files included = %d\n&quot;, nheader);
fclose(yyin);
}
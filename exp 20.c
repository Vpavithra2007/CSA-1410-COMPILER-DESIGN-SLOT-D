&lt;html&gt;
&lt;body&gt;
&lt;h1&gt;My First Heading&lt;/h1&gt;
&lt;p&gt;My first paragraph.&lt;/p&gt;
&lt;/body&gt;
&lt;/html&gt;
Program: (html.l)
%{
int tags;
%}
%%
&quot;&lt;&quot;[^&gt;]*&gt; { tags++; printf(&quot;%s \n&quot;, yytext); }
.|\n { }
%%
int yywrap(void) {
return 1; }
int main(void)
{
FILE *f;
char file[10];
printf(&quot;Enter File Name : &quot;);
scanf(&quot;%s&quot;,file);
f = fopen(file,&quot;r&quot;);
yyin = f;
yylex();
printf(&quot;\n Number of html tags: %d&quot;,tags);
fclose(yyin);
}

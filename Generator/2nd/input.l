%{
#include <string>
int a;
%}

%tokens
NUMBER
OR
XOR
AND
NOT
LB
RB
%tokens

%%

[ \n\t\r]+
;

[0-9]+
{
    a = std::stoi(cur_string);
    return NUMBER;
}
;

\|
{
    return OR;
}
;

\^
{
    return XOR;
}
;

\&
{
    return AND;
}
;

\!
{
    return NOT;
}
;

\(
{
    return LB;
}
;

\)
{
    return RB;
}
;

%%
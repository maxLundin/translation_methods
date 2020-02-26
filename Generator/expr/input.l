%{
#include <string>
int a;
%}

%tokens
NUMBER
ADD
SUB
DIV
MUL
LB
RB
POW
%tokens

%%

[ \n\t]+
;

[0-9]+
{
    a = std::stoi(cur_string);
    return NUMBER;
}
;

\+
{
    return ADD;
}
;

\/
{
    return DIV;
}
;

\*\*
{
    return POW;
}
;

\*
{
    return MUL;
}
;

\-
{
    return SUB;
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
%{
#include <iostream>
#include "pow.h"
extern int a;




%}

%type`int32_t

%attr`int32_t`num

%%

E
:`X`EE`
{
        !1
        num = $1;
        !2
        $$ = $2;
}
;

EE
:
{
    $$ = num;
}
:`ADD`X`EE
{
        !1
        uint32_t v = num;
        !2
        v += $2;
        num = v;
        !3
        $$ = $3;
}
:`SUB`X`EE
{
        !1
        uint32_t v = num;
        !2
        v -= $2;
        num = v;
        !3
        $$ = $3;
}
;


X
:`B`XX
{
        !1
        num = $1;
        !2
        $$ = $2;
}
;


XX
:
{
   $$ = num;
}
:`MUL`B`XX`
{
        !1
        uint32_t v = num;
        !2
        v *= $2;
        num = v;
        !3
        $$ = $3;
}
:`DIV`B`XX`
{
       !1
       uint32_t v = num;
       !2
       v /= $2;
       num = v;
       !3
       $$ = $3;
}
;


B
:`P`BB`
{
    !1
    !2
    $$ = pow1($1,$2);
}
;

BB
:`POW`P`BB`
{
    !1
    !2
    !3
    $$ = pow1($2,$3);
}
:
{
    $$ = 1;
}
;


P
:`NUMBER`
{
    !1
    $$ = a;
}
:`LB`E`RB`
{
    !1
    !2
    !3
    $$ = $2;
}
;


%%
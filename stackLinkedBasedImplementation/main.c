#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main()
{
stack s ;
CreateStack(&s);
StackEntry e = 5 ;
Push(&s,e);

return 0 ;
}

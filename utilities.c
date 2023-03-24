#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "control.h"
#include "utilities.h"

int main() {
  Cliente cliente;
  char szResposta[16];
  char szEntradaValidada[16] = "S";
  char szEntradaProibida[16] = "N";

   do {
       vVerifAge(&cliente);

       printf(" CONFIRME: (S|N): ");
       scanf("%s",&szResposta);
  
        if(strcmp(szEntradaProibida, "N"));
	  continue;
        if(strcmp(szResposta, "S"));
	  break;
      
   } while(strcmp(szEntradaValidada,szResposta));

   if (iValida(&cliente))
     iDept();
   else
     abort();

   return 0;
}

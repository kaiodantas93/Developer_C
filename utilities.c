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
  int iRet = 0;
  int iVerifica = 0;

  do {
    vVerifAge(&cliente);

    printf(" CONFIRME: (S|N): ");
    scanf("%s",&szResposta);
  
    if(strcmp(ENTRADAPROIBIDA, szResposta));
	    continue;
    if(strcmp(ENTRADAVALIDADA, szResposta));
	    break;

   } while(strcmp(ENTRADAVALIDADA,szResposta));

   if (iValida(&cliente))
     iVerifica = 1;
   else
     abort();

   while(iVerifica) {

    iRet = iDept();

   switch (iRet) {

       case 1:
         vDN_Cerveja();
         break;

       default:
         break;
   }

   if (iDN_ConfirmaTransacao()) {
     iVerifica = -1;
     break;
   }
 }
   return 0;
}

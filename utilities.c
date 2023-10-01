#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "control.h"

int main() {
  Cliente cliente;
  char szResposta[2];
  Total total;
  int iRet = 0;
  int iVerifica = 0;
  int iCerveja = 0;
  int iWhisky = 0;
  int iGin = 0;

  memset(&total, 0, sizeof(Total));

  do {
    vVerifAge(&cliente);

    printf(" CONFIRME: (S|N): ");
    scanf("%s", &szResposta);
 
    if(strcmp(ENTRADAPROIBIDA, szResposta) == 0)
     continue;
    else if(strcmp(ENTRADAVALIDADA, szResposta) == 0)
     break;
    else {
     printf(" CONFIRME COM: (S|N): ");
     continue;
    }

   } while(strcmp(ENTRADAVALIDADA, szResposta));

   if (iValida(&cliente))
     iVerifica = 1;
   else
     abort();
 
  while(iVerifica) {    
 
    iRet = iDept();

    switch (iRet) {

      case 1:
        vDN_Cerveja(&total);
        iCerveja = 1;
        break;

      case 2:
        vDN_Whisky(&total);
        iWhisky = 1;
        break;

      case 3:
        vDN_Gin(&total);
        iGin = 1;
        break;

      default:
        break;
    }

   if (iDN_ConfirmaTransacao()) {
     iVerifica = -1;
     break;
   }

  }
  
   if (iCerveja)
     iDN_TransacaoCerveja(&total);

   if (iWhisky)
    iDN_TransacaoWhisky(&total);
  
   if (iGin)
    iDN_TransacaoGin(&total);

   return 0;
}


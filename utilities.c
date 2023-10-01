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

    if(iRet == 0)
      vVerifAge(&cliente);

    printf(" CONFIRME: (S|N): ");
    scanf("%s", &szResposta);

    iRet = strcmp(ENTRADAVALIDADA, szResposta);

    if(iRet == 0)
      iRet = 1;
    else if(strcmp(ENTRADAPROIBIDA, szResposta) == 0)
      iRet = 0;
    else
      iRet = 2;

  } while (iRet == 2 || iRet == 0);
 
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

    iDN_FinalTransacao(&total);

   return 0;
}


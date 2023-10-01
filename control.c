#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "control.h"
#include "utilities.h"

struct tm *atual;
DATA date;
static int giCerveja = 0;
static int giWhisky = 0;
static int giGin = 0;

void vVerifAge(Cliente *p) {
  time_t temp = time(NULL);
  char szDia,szMes,szAno,szNome[512];
  int iDia, iMes, iAno;

  atual = localtime(&temp);
  memset(&date, 0, sizeof(date));

  date.iDay = atual->tm_mday;
  date.iMes = atual->tm_mon+=1;
  date.iYear = atual->tm_year+=1900;

  memset(&szNome, 0, sizeof(szNome));
  memset(&szDia, 0, sizeof(szDia));
  memset(&szMes, 0, sizeof(szMes));
  memset(&szAno, 0, sizeof(szAno));

  printf("\n", date.iDay);
  printf("Data Atual: %d/", date.iDay);
  printf("%.0d/", date.iMes);
  printf("%d\n", date.iYear);

  printf("Qual e o seu nome: ");
  scanf("%s", &szNome);

  strcpy(p->szName, szNome);

  do {
    printf("Digite o dia do seu nascimento: ");
    scanf("%s",&szDia);
    p->iDia = atoi(&szDia);
  } while(p->iDia < 1 || p->iDia > 31);

  do {
    printf("Digite o mes do seu nascimento: ");
    scanf("%s",&szMes);
    p->iMes = atol(&szMes);
  } while(p->iMes < 1 || p->iMes > 12);

  do {
    printf("Digite o ano do seu nascimento: ");
    scanf("%s",&szAno);
    p->iAno = atol(&szAno);
  } while(p->iAno < 1900 || p->iAno >= date.iYear);

  printf("%s sua data de nascimento informada esta correta? %d/%d/%d\n", p->szName, p->iDia, p->iMes,p->iAno);
}

int iDept(void) {
  int iRet = 0;
  char szCodigo;

  memset(&szCodigo, 0 ,sizeof(szCodigo));

  printf(" ESCOLHA O DEPARTAMENTO:\n\n");
  printf(" 1: BEBIDA ALCOOLICA - (CERVEJA)\n");
  printf(" 2: BEBIDA ALCOOLICA - (WHISKY)\n");
  printf(" 3: BEBIDA ALCOOLICA - (GIN)\n\n");

  do {
    printf(" Digite o codigo do departamento: ");
    scanf("%s", &szCodigo);
    fflush(stdin);
    iRet = atoi(&szCodigo);
  } while (iRet < 1 || iRet > 3);

}

int iCodigo(void) {
  int iRet = 0;
  char szCodigo;

  memset(&szCodigo, 0 ,sizeof(szCodigo));

	do {
    printf(" Digite o codigo do produto: ");
    scanf("%s", &szCodigo);
    fflush(stdin);
    iRet = atoi(&szCodigo);
	} while (iRet < 1 || iRet > 8);
}

int iQuant(int iCount) {
  int iRet = 0;
  char szQuant;

  memset(&szQuant, 0 ,sizeof(szQuant));

	do {
    printf(" Digite a quantidade: ");
    scanf("%s",&szQuant);
    fflush(stdin);
    iRet = atoi(&szQuant);
  } while (iRet < 1 || iRet > iCount);
}

int iValida(Cliente *k) {
  int iVerifica = 0;
  int iRet = 0;

  iVerifica = date.iYear - k->iAno;

  if(date.iMes < k->iMes ||
     (date.iMes == k->iMes && date.iDay < k->iDia))
    iVerifica--;

  if(iVerifica >= IDADE) {
    printf("\n ***** SEJA BEM VINDO %s *****\n\n", k->szName);
    iRet = 1;
  }
  else
    printf(" VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",iVerifica);

  return iRet;
}

int iDN_Codigo(void) {
  char szCodigo[32];
  int iRet = 0;

  memset(szCodigo, 0, sizeof(&szCodigo));

  do {
    printf(" Digite o codigo do produto: ");
    scanf("%s", &szCodigo);
    fflush(stdin);
    iRet = atoi(szCodigo);
  } while (iRet < 1 || iRet > 8);

  return iRet;
}

int iDN_Quant(void) {
  char szQuant[32];
  int iRet = 0;

  memset(szQuant, 0, sizeof(&szQuant));
  iRet = 0;

  do {
    printf(" Digite a quantidade: ");
    scanf("%s",&szQuant);
    fflush(stdin);
    iRet = atoi(szQuant);
  } while (iRet < 1 || iRet > 1000);

  return iRet;
}

void vDN_Cerveja(Total *iBebidaCerveja) {
  EnumQuant iCont = CERVEJA;
  EnumVariedade_Cerveja iRet;
  EnumPrecoCerveja iPreco[32];
  int iContador = 0;
  int iCount_Cerveja = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int iTotAcumula[32];

  printf("\n DEPARTAMENTO - CERVEJA \n\n");

  printf(" PRODUTO 1: Skol 473ml Preco por unidade: %d Reais\n", SKOL_PRICE);
  printf(" PRODUTO 2: Original 350ml Preco por unidade: %d Reais\n", ORIGINAL_PRICE);
  printf(" PRODUTO 3: Brahma 350ml Preco por unidade: %d Reais \n", BRAHMA_PRICE);
  printf(" PRODUTO 4: Amstel 473ml Preco por unidade: %d Reais\n", AMSTEL_PRICE);
  printf(" PRODUTO 5: BudWeiser 350ml Preco por unidade: %d Reais\n", BUDWEISER_PRICE);
  printf(" PRODUTO 6: Bohemia 473ml Preco por unidade: %d Reais\n", BOHEMIA_PRICE);
  printf(" PRODUTO 7: Itaipava 473ml Preco por unidade: %d Reais\n", ITAIPAVA_PRICE);
  printf(" PRODUTO 8: Schin 350ml Preco por unidade: %d Reais\n\n", SCHIN_PRICE);

  iRet = iCodigo();
  iContador = iQuant(iCont);

  switch(iRet) {
    case SKOL:
      printf("\n CONFIRMANDO: %d unidades de Skol 350ml\n", iContador);
      iPreco[i] = SKOL_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
       iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] = iTotAcumula[i];
      }

      iCount_Cerveja++;
      giCerveja++;
      break;

    case ORIGINAL:
      printf("\n CONFIRMANDO: %d unidades de Original 350ml\n", iContador);
      iPreco[i] = ORIGINAL_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

    case BRAHMA:
      printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n", iContador);
      iPreco[i] = BRAHMA_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

    case AMSTEL:
      printf("\n CONFIRMANDO: %d unidades de Amstel 350ml\n", iContador);
      iPreco[i] = AMSTEL_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
       iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

      case BUDWEISER:
      printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n", iContador);
      iPreco[i] = BUDWEISER_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

      case BOHEMIA:
      printf("\n CONFIRMANDO: %d unidades de Bohemia 350ml\n", iContador);
      iPreco[i] = BOHEMIA_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

      case ITAIPAVA:
      printf("\n CONFIRMANDO: %d unidades de Itaipava 350ml\n", iContador);
      iPreco[i] = ITAIPAVA_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

      case SCHIN:
      printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n", iContador);
      iPreco[i] = SCHIN_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaCerveja->iCerveja.iValor_Cerveja[giCerveja] += iTotAcumula[i];
      }
      
      iCount_Cerveja++;
      giCerveja++;
      break;

   }
}
void vDN_Whisky(Total *iBebidaWhisky) {
  EnumQuant iCont = WHISKY;
  EnumVariedade_Whisky iRet;
  EnumPrecoWhisky iPreco[32];
  int iContador = 0;
  int iCount_Whisky = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int iTotAcumula[32];

  printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");

	printf(" PRODUTO 1: Red Label 750ml Preco por unidade: 65.00 Reais\n");
	printf(" PRODUTO 2: Red Label 1000ml Preco por unidade: 78.00 Reais\n");
	printf(" PRODUTO 3: Ballantines 750ml Preco por unidade: 55.00 Reais \n");
	printf(" PRODUTO 4: Ballantines 1000ml Preco por unidade: 63.00 Reais\n");
	printf(" PRODUTO 5: Jack Daniels Tenessee 1000ml Preco por unidade: 130.00 Reais\n");
	printf(" PRODUTO 6: Jack Daniels HONEY 1000ml Preco por unidade: 139.00 Reais\n");
	printf(" PRODUTO 7: Jack Daniels FIRE 1000ml Preco por unidade: 139.90 Reais\n");
	printf(" PRODUTO 8: Jack Daniels APPLE 1000ml Preco por unidade: 145.00 Reais\n\n");

  iRet = iCodigo();
  iContador = iQuant(iCont);

  switch(iRet) {
    case RED_LABEL:
      printf("\n CONFIRMANDO: %d unidades de Red Label 750ml\n", iContador);
      iPreco[i] = RED_LABEL_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
       iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] = iTotAcumula[i];
      }

      iCount_Whisky++;
      giWhisky++;
      break;

    case RED1L_LABEL:
      printf("\n CONFIRMANDO: %d unidades de Red Label 1000ml\n", iContador);
      iPreco[i] = RED1L_LABEL_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
       iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giWhisky++;
      break;

    case BALLANTINES:
      printf("\n CONFIRMANDO: %d unidades de Ballantines 750ml\n", iContador);
      iPreco[i] = BALLANTINES_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giWhisky++;
      break;

    case BALLANTINES_1L:
      printf("\n CONFIRMANDO: %d unidades de Ballantines 1000ml\n", iContador);
      iPreco[i] = BALLANTINES_1L_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giWhisky++;
      break;

      case JACK_TENESSE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels Tenessee 1000ml\n", iContador);
      iPreco[i] = JACK_TENESSE_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giWhisky++;
      break;

      case JACK_HONEY:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels HONEY 1000ml\n", iContador);
      iPreco[i] = JACK_HONEY_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giCerveja++;
      break;

      case JACK_FIRE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels FIRE 1000ml\n", iContador);
      iPreco[i] = JACK_FIRE_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giCerveja++;
      break;

      case JACK_APPLE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels APPLE 1000ml\n", iContador);
      iPreco[i] = JACK_APPLE_PRICE;

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaWhisky->iWhisky.iValor_Whisky[giWhisky] += iTotAcumula[i];
      }
      
      iCount_Whisky++;
      giWhisky++;
      break;

   }
}
void vDN_Gin(Total *iBebidaGin) {
  EnumQuant iCont = GIN;
  EnumVariedade_Gin iRet;
  EnumPrecoGin iPreco[32];
  int iContador = 0;
  int iCount_Gin = 0;
  int i = 0;
  int j = 0;
  int iTotAcumula[32];

  printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");

	printf(" PRODUTO 1: Tanqueray 750ml Preco por unidade: 105.00 Reais\n");
	printf(" PRODUTO 2: Tanqueray Sevilla 750ml Preco por unidade: 110.00 Reais\n");
	printf(" PRODUTO 3: Beefeater Dry 750ml Preco por unidade: 70.00 Reais\n");
	printf(" PRODUTO 4: Gordon'S Classico 750ml Preco por unidade: 67.00 Reais\n");
	printf(" PRODUTO 5: Gordon'S Pink 750ml Preco por unidade: 69.00 Reais\n\n");

  iRet = iCodigo();
  iContador = iQuant(iCont);

  switch(iRet) {
    case TANQUERAY:
      printf("\n CONFIRMANDO: %d unidades de Tanqueray 750ml\n", iContador);
      iPreco[i] = TANQUERAY_PRICE;

      for(i = 0; i <= iCount_Gin; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
       iBebidaGin->iGin.iValor_Gin[giGin] = iTotAcumula[i];
      }

      iCount_Gin++;
      giGin++;
      break;

    case TANQUERAY_SEVILLA:
      printf("\n CONFIRMANDO: %d unidades de Tanqueray Sevilla 750ml\n", iContador);
      iPreco[i] = TANQUERAY_SEVILLA_PRICE;

      for(i = 0; i <= iCount_Gin; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaGin->iGin.iValor_Gin[giGin] += iTotAcumula[i];
      }
      
      iCount_Gin++;
      giGin++;
      break;

    case BEEFEATER_DRY:
      printf("\n CONFIRMANDO: %d unidades de Beefeater Dry 750ml\n", iContador);
      iPreco[i] = BEEFEATER_DRY_PRICE;

      for(i = 0; i <= iCount_Gin; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaGin->iGin.iValor_Gin[giGin] += iTotAcumula[i];
      }
      
      iCount_Gin++;
      giGin++;
      break;

    case GORDON_CLASSIC:
      printf("\n CONFIRMANDO: %d unidades de Gordon'S Classico 750ml\n", iContador);
      iPreco[i] = GORDON_CLASSIC_PRICE;

      for(i = 0; i <= iCount_Gin; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaGin->iGin.iValor_Gin[giGin] += iTotAcumula[i];
      }
      
      iCount_Gin++;
      giGin++;
      break;

      case GORDON_PINK:
      printf("\n CONFIRMANDO: %d unidades de Gordon'S Pink 750ml\n", iContador);
      iPreco[i] = GORDON_PINK_PRICE;

      for(i = 0; i <= iCount_Gin; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
        iBebidaGin->iGin.iValor_Gin[giGin] += iTotAcumula[i];
      }
      
      iCount_Gin++;
      giGin++;
      break;

   }
}

int iDN_ConfirmaTransacao(void) {
  char szResposta[16];
  int iRet = 0;

  printf(" DESEJA FINALIZAR A VENDA: \n");
  printf(" CONFIRME: (S|N): ");
  scanf("%s",&szResposta);

  iRet = strcmp(ENTRADAVALIDADA, szResposta);

  if(iRet == 0)
    iRet = 1;
  else
    iRet = 0;

   return iRet;
}

int iDN_TransacaoCerveja(Total *iBebidaCerveja) {
	int iSoma = 0;
  int j = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n\n");

  for(j = 0; j<=8; j++) {
    if(iBebidaCerveja->iCerveja.iValor_Cerveja[j] > 1) {
      printf(" PRODUTO %d: %.2d Reais\n",j+1, iBebidaCerveja->iCerveja.iValor_Cerveja[j]);
    }
  }

  for(j = 0; j <=8; j++)
    iSoma += iBebidaCerveja->iCerveja.iValor_Cerveja[j];
  printf("\n Soma total: %.2d Reais\n",iSoma);

}

int iDN_TransacaoWhisky(Total *iBebidaWhisky) {
	int iSoma = 0;
  int j = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");

  for(j = 0; j<=8; j++) {
    if(iBebidaWhisky->iWhisky.iValor_Whisky[j] > 1) {
      printf(" PRODUTO %d: %.2d Reais\n",j+1, iBebidaWhisky->iWhisky.iValor_Whisky[j]);
    }
  }

  for(j = 0; j <=8; j++)
    iSoma += iBebidaWhisky->iWhisky.iValor_Whisky[j];
  printf("\n Soma total: %.2d Reais\n",iSoma);

}

int iDN_TransacaoGin(Total *iBebidaGin) {
	int iSoma = 0;
  int j = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");

  for(j = 0; j<=8; j++) {
    if(iBebidaGin->iGin.iValor_Gin[j] > 1) {
      printf(" PRODUTO %d: %.2d Reais\n",j+1, iBebidaGin->iGin.iValor_Gin[j]);
    }
  }

  for(j = 0; j <=8; j++)
    iSoma += iBebidaGin->iGin.iValor_Gin[j];
  printf("\n Soma total: %.2d Reais\n",iSoma);

}
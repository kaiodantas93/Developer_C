#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "control.h"

struct tm *atual;
DATA date;

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
  int iContador = 0;
  int iCount_Cerveja = 0;
  int iTotAcumula = 0;

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

      iTotAcumula =  SKOL_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja = iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Skol");

      iCount_Cerveja++;
      break;

    case ORIGINAL:
      printf("\n CONFIRMANDO: %d unidades de Original 350ml\n", iContador);

      iTotAcumula = ORIGINAL_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Original");
      
      iCount_Cerveja++;
      break;

    case BRAHMA:
      printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n", iContador);

      iTotAcumula = BRAHMA_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Brahma");
      
      iCount_Cerveja++;
      break;

    case AMSTEL:
      printf("\n CONFIRMANDO: %d unidades de Amstel 350ml\n", iContador);

      iTotAcumula = AMSTEL_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Amstel");
      
      
      iCount_Cerveja++;
      break;

      case BUDWEISER:
      printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n", iContador);

      iTotAcumula = BUDWEISER_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "BudWeiser");
      
      iCount_Cerveja++;
      break;

      case BOHEMIA:
      printf("\n CONFIRMANDO: %d unidades de Bohemia 350ml\n", iContador);

      iTotAcumula = BOHEMIA_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, " Bohemia");
      
      iCount_Cerveja++;
      break;

      case ITAIPAVA:
      printf("\n CONFIRMANDO: %d unidades de Itaipava 350ml\n", iContador);

      iTotAcumula = ITAIPAVA_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Itaipava");
            
      iCount_Cerveja++;
      break;

      case SCHIN:
      printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n", iContador);

      iTotAcumula = SCHIN_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaCerveja->iCerveja[iCount_Cerveja].iValor_Cerveja += iTotAcumula;
      iBebidaCerveja->iCerveja[iCount_Cerveja].iQuantidade = iContador;
      strcpy(iBebidaCerveja->iCerveja[iCount_Cerveja].szCerveja, "Schin");
            
      iCount_Cerveja++;
      break;

   }
}

void vDN_Whisky(Total *iBebidaWhisky) {
  EnumQuant iCont = WHISKY;
  EnumVariedade_Whisky iRet;
  int iContador = 0;
  int iCount_Whisky = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int iTotAcumula = 0;

  printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");

	printf(" PRODUTO 1: Red Label 750ml Preco por unidade: %d Reais\n", RED_LABEL_PRICE);
	printf(" PRODUTO 2: Red Label 1000ml Preco por unidade: %d Reais\n", RED1L_LABEL_PRICE);
	printf(" PRODUTO 3: Ballantines 750ml Preco por unidade: %d Reais \n", BALLANTINES_PRICE);
	printf(" PRODUTO 4: Ballantines 1000ml Preco por unidade: %d Reais\n", BALLANTINES_1L_PRICE);
	printf(" PRODUTO 5: Jack Daniels Tenessee 1000ml Preco por unidade: %d Reais\n", JACK_TENESSE_PRICE);
	printf(" PRODUTO 6: Jack Daniels HONEY 1000ml Preco por unidade: %d Reais\n", JACK_HONEY_PRICE);
	printf(" PRODUTO 7: Jack Daniels FIRE 1000ml Preco por unidade: %d Reais\n", JACK_FIRE_PRICE);
	printf(" PRODUTO 8: Jack Daniels APPLE 1000ml Preco por unidade: %d Reais\n\n", JACK_APPLE_PRICE);

  iRet = iCodigo();
  iContador = iQuant(iCont);

  switch(iRet) {
    case RED_LABEL:
      printf("\n CONFIRMANDO: %d unidades de Red Label 750ml\n", iContador);

      iTotAcumula = RED1L_LABEL_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky = iTotAcumula;
      iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
      strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Red Label");

      iCount_Whisky++;
      break;

    case RED1L_LABEL:
      printf("\n CONFIRMANDO: %d unidades de Red Label 1000ml\n", iContador);

      iTotAcumula = RED1L_LABEL_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
      iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
      strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Red Label 1L");
      
      iCount_Whisky++;
      break;

    case BALLANTINES:
      printf("\n CONFIRMANDO: %d unidades de Ballantines 750ml\n", iContador);

      iTotAcumula = BALLANTINES_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
      iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
      strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Ballantines");
      
      iCount_Whisky++;
      break;

    case BALLANTINES_1L:
      printf("\n CONFIRMANDO: %d unidades de Ballantines 1000ml\n", iContador);

        iTotAcumula = BALLANTINES_1L_PRICE * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula);
        iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
        iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
        strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Ballantines 1L");
      
      iCount_Whisky++;
      break;

      case JACK_TENESSE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels Tenessee 1000ml\n", iContador);

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula = JACK_TENESSE_PRICE * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula);
        iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
        iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
        strcpy(iBebidaWhisky->iWhisky[i].szWhisky, "Jack Daniels Tenessee");
      }
      
      iCount_Whisky++;
      break;

      case JACK_HONEY:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels HONEY 1000ml\n", iContador);

      iTotAcumula = JACK_HONEY_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
      iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
      strcpy(iBebidaWhisky->iWhisky[i].szWhisky, "Jack Daniels HONEY");

      iCount_Whisky++;
      break;

      case JACK_FIRE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels FIRE 1000ml\n", iContador);

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula = JACK_FIRE_PRICE * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula);
        iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
         iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
        strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Jack Daniels FIRE");
      }
      
      iCount_Whisky++;
      break;

      case JACK_APPLE:
      printf("\n CONFIRMANDO: %d unidades de Jack Daniels APPLE 1000ml\n", iContador);

      for(i = 0; i <= iCount_Whisky; i++) {
        iTotAcumula = JACK_APPLE_PRICE * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula);
        iBebidaWhisky->iWhisky[iCount_Whisky].iValor_Whisky += iTotAcumula;
         iBebidaWhisky->iWhisky[iCount_Whisky].iQuantidade = iContador;
        strcpy(iBebidaWhisky->iWhisky[iCount_Whisky].szWhisky, "Jack Daniels APPLE");
      }
      
      iCount_Whisky++;
      break;

   }
}

void vDN_Gin(Total *iBebidaGin) {
  EnumQuant iCont = GIN;
  EnumVariedade_Gin iRet;
  int iContador = 0;
  int iCount_Gin = 0;
  int i = 0;
  int j = 0;
  int iTotAcumula = 0;

  printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");

	printf(" PRODUTO 1: Tanqueray 750ml Preco por unidade: %d Reais\n", TANQUERAY_PRICE);
	printf(" PRODUTO 2: Tanqueray Sevilla 750ml Preco por unidade: %d Reais\n", TANQUERAY_SEVILLA_PRICE );
	printf(" PRODUTO 3: Beefeater Dry 750ml Preco por unidade: %d Reais\n", BEEFEATER_DRY_PRICE);
	printf(" PRODUTO 4: Gordon'S Classico 750ml Preco por unidade: %d Reais\n", GORDON_CLASSIC_PRICE);
	printf(" PRODUTO 5: Gordon'S Pink 750ml Preco por unidade: %d Reais\n\n", GORDON_PINK_PRICE);

  iRet = iCodigo();
  iContador = iQuant(iCont);

  switch(iRet) {
    case TANQUERAY:
      printf("\n CONFIRMANDO: %d unidades de Tanqueray 750ml\n", iContador);

      iTotAcumula = TANQUERAY_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaGin->iGin[iCount_Gin].iValor_Gin = iTotAcumula;
      iBebidaGin->iGin[iCount_Gin].iQuantidade = iContador;
      strcpy(iBebidaGin->iGin[iCount_Gin].szGin, "Tanqueray");
      
      iCount_Gin++;
      break;

    case TANQUERAY_SEVILLA:
      printf("\n CONFIRMANDO: %d unidades de Tanqueray Sevilla 750ml\n", iContador);

      iTotAcumula = TANQUERAY_SEVILLA_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaGin->iGin[iCount_Gin].iValor_Gin+= iTotAcumula;
      iBebidaGin->iGin[iCount_Gin].iQuantidade = iContador;
      strcpy(iBebidaGin->iGin[iCount_Gin].szGin, "Tanqueray Sevilla");
      
      iCount_Gin++;
      break;

    case BEEFEATER_DRY:
      printf("\n CONFIRMANDO: %d unidades de Beefeater Dry 750ml\n", iContador);

      iTotAcumula = BEEFEATER_DRY_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaGin->iGin[iCount_Gin].iValor_Gin += iTotAcumula;
      iBebidaGin->iGin[iCount_Gin].iQuantidade = iContador;
      strcpy(iBebidaGin->iGin[iCount_Gin].szGin, "Beefeater Dry");
      
      iCount_Gin++;
      break;

    case GORDON_CLASSIC:
      printf("\n CONFIRMANDO: %d unidades de Gordon'S Classico 750ml\n", iContador);

      iTotAcumula = GORDON_CLASSIC_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaGin->iGin[iCount_Gin].iValor_Gin += iTotAcumula;
      iBebidaGin->iGin[iCount_Gin].iQuantidade = iContador;
      strcpy(iBebidaGin->iGin[iCount_Gin].szGin, "Gordon'S Classico");
      
      iCount_Gin++;
      break;

      case GORDON_PINK:
      printf("\n CONFIRMANDO: %d unidades de Gordon'S Pink 750ml\n", iContador);

      iTotAcumula = GORDON_CLASSIC_PRICE * iContador;
      printf(" TOTAL: %d Reais\n\n",iTotAcumula);
      iBebidaGin->iGin[iCount_Gin].iValor_Gin += iTotAcumula;
      iBebidaGin->iGin[iCount_Gin].iQuantidade = iContador;
      strcpy(iBebidaGin->iGin[iCount_Gin].szGin, "Gordon'S Pink");
      
      iCount_Gin++;
      break;

   }
}

int iDN_ConfirmaTransacao(void) {
  char szResposta[16];
  int iRet = 0;

do {
    printf(" DESEJA FINALIZAR A VENDA: \n");
    printf(" CONFIRME: (S|N): ");
    scanf("%s",&szResposta);

    iRet = strcmp(ENTRADAVALIDADA, szResposta);

    if(iRet == 0)
      iRet = 1;
    else if(strcmp(ENTRADAPROIBIDA, szResposta) == 0)
      iRet = 0;
    else
      iRet = 2;

  } while (iRet == 2);

  return iRet;

}


int iDN_TransacaoCerveja(Total *iBebidaCerveja) {
	int iSoma = 0;
  int j = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n");
  
  for(j = 0; j<=8; j++) {
    if(iBebidaCerveja->iCerveja[j].iValor_Cerveja > 1) {
      printf(" PEDIDO %d: \n", j+1);
      printf(" PRODUTO: %d Unidades de %s \n", iBebidaCerveja->iCerveja[j].iQuantidade,
      iBebidaCerveja->iCerveja[j].szCerveja);
      printf(" VALOR: %.2d Reais\n", iBebidaCerveja->iCerveja[j].iValor_Cerveja);
    }
  }

  for(j = 0; j <=8; j++)
    iSoma += iBebidaCerveja->iCerveja[j].iValor_Cerveja;
  printf("\n SOMA FINAL DO PEDIDO: %.2d Reais\n",iSoma);

}

int iDN_TransacaoWhisky(Total *iBebidaWhisky) {
	int iSoma = 0;
  int k = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");

  for(k = 0; k<=8; k++) {
    if(iBebidaWhisky->iWhisky[k].iValor_Whisky > 1) {
      printf(" PEDIDO %d: \n", k+1);
      printf(" PRODUTO: %d Unidades de %s \n", iBebidaWhisky->iWhisky[k].iQuantidade,
      iBebidaWhisky->iWhisky[k].szWhisky);
      printf(" VALOR: %.2d Reais\n", iBebidaWhisky->iWhisky[k].iValor_Whisky);
    }
  }

  for(k = 0; k <=8; k++)
    iSoma += iBebidaWhisky->iWhisky[k].iValor_Whisky;
  printf("\n SOMA FINAL DO PEDIDO: %.2d Reais\n",iSoma);

}

int iDN_TransacaoGin(Total *iBebidaGin) {
	int iSoma = 0;
  int l = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");

  for(l = 0; l<=8; l++) {
    if(iBebidaGin->iGin[l].iValor_Gin > 1) {
      printf(" PEDIDO %d: \n", l+1);
      printf(" PRODUTO: %d Unidades de %s \n", iBebidaGin->iGin[l].iQuantidade,
      iBebidaGin->iGin[l].szGin);
      printf(" VALOR: %.2d Reais\n", iBebidaGin->iGin[l].iValor_Gin);
      
    }
  }

  for(l = 0; l <=8; l++)
    iSoma += iBebidaGin->iGin[l].iValor_Gin;
  printf("\n SOMA FINAL DO PEDIDO: %.2d Reais\n",iSoma);

}

int iDN_FinalTransacao(Total *total) {
	int iSoma = 0;
  int j = 0;

  for(j = 0; j <=8; j++) {
    if(total->iCerveja[j].iValor_Cerveja > 0 )
      iSoma += total->iCerveja[j].iValor_Cerveja;

    if(total->iWhisky[j].iValor_Whisky > 0)
      iSoma += total->iWhisky[j].iValor_Whisky;

    if(total->iGin[j].iValor_Gin > 0)
      iSoma += total->iGin[j].iValor_Gin; 
  }

  printf("\n SOMA FINAL DA VENDA: %.2d Reais\n",iSoma);

}
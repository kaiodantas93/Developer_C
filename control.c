#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "control.h"
#include "utilities.h"

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

  printf("%d/", date.iDay);
  printf("%.0d/", date.iMes);
  printf("%d\n", date.iYear);

  printf("Qual é o seu nome: ");
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

<<<<<<< HEAD
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

void vDN_Cerveja(void) {
  EnumQuant iCont = CERVEJA;
  EnumVariedade_Cerveja iRet;
  EnumPreco iPreco[32];
  Total myTotal;
  Total *c = &myTotal;
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
      }

      for(i = 0; i <= iCount_Cerveja; i++) {
        c->iCerveja[i] = iTotAcumula[i];
        iCount_Cerveja++;
      }
      break;

    case ORIGINAL:
      printf("\n CONFIRMANDO: %d unidades de Original 350ml\n", iContador);
      iPreco[i] = ORIGINAL_PRICE;

      for(i = 0; i <= iCount_Cerveja; i++) {
        iTotAcumula[i] = iPreco[i] * iContador;
        printf(" TOTAL: %d Reais\n\n",iTotAcumula[i]);
      }

      for(i = 0; i <= iCount_Cerveja; i++) {
        c->iCerveja[i] += iTotAcumula[i];
        iCount_Cerveja++;
        break;
      }
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

int iDN_TransacaoCerveja(Total *c) {
	int iSoma = 0;
  int j = 0;

	printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n\n");

  for(j = 1; j<=8; j++) {
    if(c->iCerveja[j] > 1) {
      printf(" PRODUTO %d: %.2lf Reais\n",j,c->iCerveja[j]);
    }
  }

  for(j = 1; j <=8; j++)
    iSoma += c->iCerveja[j];
  printf("\n Soma total: %.2lf Reais\n",iSoma);
}

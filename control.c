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
 printf("%d/", date.iMes);
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
  } while ((iRet) < 1 || (iRet) > 3);

}

int iValida(Cliente *k) {
 int iVerifica = 0;
 int iRet = 0;

   iVerifica = date.iYear - k->iAno;

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

void vDN_Cerveja(void) {

  printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n\n");
  printf(" PRODUTO 1: Skol 473ml Preco por unidade: 4.50 Reais\n");
  printf(" PRODUTO 2: Original 350ml Preco por unidade: 4 Reais\n");
  printf(" PRODUTO 3: Brahma 350ml Preco por unidade: 3 Reais \n");
  printf(" PRODUTO 4: Amstel 473ml Preco por unidade: 5.50 Reais\n");
  printf(" PRODUTO 5: BudWeiser 350ml Preco por unidade: 4 Reais\n");
  printf(" PRODUTO 6: Bohemia 473ml Preco por unidade: 4.50 Reais\n");
  printf(" PRODUTO 7: Itaipava 473ml Preco por unidade: 3 Reais\n");

  printf(" DESCRICAO DA COMPRA:\n");
  printf("\n");

  iDN_Codigo();
}

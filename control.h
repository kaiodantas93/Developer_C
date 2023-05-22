#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define IDADE 18
#define ENTRADAPROIBIDA "N"
#define ENTRADAVALIDADA "S"

typedef struct DATA {
int iDay;
int iMes;
int iYear;
}DATA;

typedef struct {
  char szName[512];
  int iDia;
  int iMes;
  int iAno;
  int iCalcuYear;
}Cliente;

typedef struct {
  int iCerveja[128];
  int iWhisky[64];
  int iGin[64];
}Total;

typedef enum {
  CERVEJA = 120,
  GIN = 60,
  WHISKY = 60
}EnumQuant;

typedef enum {
  SKOL = 1,
  ORIGINAL = 2,
  BRAHMA = 3,
  AMSTEL = 4,
  BUDWEISER = 5,
  BOHEMIA = 6,
  ITAIPAVA = 7,
  SCHIN = 8
}EnumVariedade_Cerveja;

typedef enum {
  SKOL_PRICE = 3,
  ORIGINAL_PRICE = 6,
  BRAHMA_PRICE = 5,
  AMSTEL_PRICE = 4,
  BUDWEISER_PRICE = 7,
  BOHEMIA_PRICE = 5,
  ITAIPAVA_PRICE = 3,
  SCHIN_PRICE = 3
}EnumPreco;

int iValida(Cliente *k);
void vVerifAge(Cliente *p);
int iDept(void);
int iQuant(int iCount);
int iCodigo(void);
void vDN_Cerveja(void);
int iDN_ConfirmaTransacao(void);
int iDN_TransacaoCerveja(Total *c);

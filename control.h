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
  int iValor_Cerveja[128];
  char szCerveja[128][128];
  int iQuantidade[128];
}iBebidaCerveja;

typedef struct {
  int iValor_Whisky[128];
  char szWhisky[128][128];
  int iQuantidade[128];
}iBebidaWhisky;

typedef struct {
  int iValor_Gin[128];
  char szGin[128][128];
  int iQuantidade[128];
}iBebidaGin;

typedef struct {
  iBebidaCerveja iCerveja;
  iBebidaWhisky iWhisky;
  iBebidaGin iGin;
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
}EnumPrecoCerveja;

typedef enum {
  RED_LABEL = 1,
  RED1L_LABEL = 2,
  BALLANTINES = 3,
  BALLANTINES_1L = 4,
  JACK_TENESSE = 5,
  JACK_HONEY = 6,
  JACK_FIRE = 7,
  JACK_APPLE = 8
}EnumVariedade_Whisky;

typedef enum {
  RED_LABEL_PRICE = 65,
  RED1L_LABEL_PRICE = 78,
  BALLANTINES_PRICE = 55,
  BALLANTINES_1L_PRICE = 63,
  JACK_TENESSE_PRICE = 130,
  JACK_HONEY_PRICE = 139,
  JACK_FIRE_PRICE = 139,
  JACK_APPLE_PRICE = 145
}EnumPrecoWhisky;

typedef enum {
 TANQUERAY = 1,
  TANQUERAY_SEVILLA = 2,
  BEEFEATER_DRY = 3,
  GORDON_CLASSIC = 4,
  GORDON_PINK = 5
}EnumVariedade_Gin;

typedef enum {
  TANQUERAY_PRICE = 65,
  TANQUERAY_SEVILLA_PRICE = 78,
  BEEFEATER_DRY_PRICE = 55,
  GORDON_CLASSIC_PRICE = 63,
  GORDON_PINK_PRICE = 130
}EnumPrecoGin;


int iValida(Cliente *k);
void vVerifAge(Cliente *p);
int iDept(void);
void vDN_Cerveja(Total *myTotal);
void vDN_Whisky(Total *myTotal);
void vDN_Gin(Total *myTotal);
int iQuant(int iCount);
int iCodigo(void);
int iDN_ConfirmaTransacao(void);
int iDN_TransacaoCerveja(Total *iBebidaCerveja);
int iDN_TransacaoWhisky(Total *iBebidaWhisky);
int iDN_TransacaoGin(Total *iBebidaGin);
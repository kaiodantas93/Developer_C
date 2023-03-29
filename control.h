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

typedef enum {
  CERVEJA = 120,
  GIN = 60,
  WHISKY = 60
}EnumQuant;

int iValida(Cliente *k);
void vVerifAge(Cliente *p);
int iDept(void);
int iQuant(int iCount);
int iCodigo(void);
void vDN_Cerveja(void);
int iDN_ConfirmaTransacao(void);

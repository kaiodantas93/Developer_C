#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define IDADE 18

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

int iValida(Cliente *k);
void vVerifAge(Cliente *p);
int iDept(void);

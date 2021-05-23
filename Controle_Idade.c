#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IDADE 18
#define ANOATUAL 2021

int DD(int* dia) {
    do {
        printf("Digite o dia do seu nascimento: ");
        scanf("%d", dia); 
    } while ((*dia) < 1 || (*dia) > 31);
}

int MES(int* mes) {
    do {
        printf("\nDigite o MES do seu nascimento: ");
        scanf("%d", mes);
    } while((*mes) < 1 || (*mes) > 12);
}

int ANO(int* ano) {
    do {
        printf("\nDia o ANO do seu nascimento: ");
        scanf("%d", ano);
    } while((*ano) < 1900 || (*ano) > ANOATUAL);
}

int CONFS(int* soma ,int* ano) {
    (*soma) = (ANOATUAL - (*ano));
        if((*soma) >= IDADE){
            printf("SEJA BEM VINDO\n\n");
            } else {
                printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",(*soma));
                abort();
                }       
    }

int PRODUTOS () {

     printf("DEPARTAMENTO - BEBIDA ALCOOLICA: \n\n");

     printf(" PRODUTO 1: Skol 473ml \n");
     printf(" PRODUTO 2: Original 473ml \n");
     printf(" PRODUTO 3: Brahma 473ml \n");
     printf(" PRODUTO 4: Amstel 473ml \n");
     printf(" PRODUTO 5: BudWeiser 473ml \n");
     printf(" PRODUTO 6: Bohemia 473ml \n");
     printf(" PRODUTO 7: Itaipava 473ml \n");
     printf(" PRODUTO 8: Schin 473ml \n");
}

int main() {

    int soma,Prod;
    int dia,mes,ano;
    char letra;

    do {
        DD(&dia); MES(&mes); ANO(&ano);
        printf("Sua data de nascimento informada esta correta? %d/%d/%d\n",dia,mes,ano);
        printf("CONFIRME: (S|N): ");
        if(getchar()=='N');
    } while(getchar()=='N');

    if(!(getchar()=='N')){
            CONFS(&soma, &ano);
            PRODUTOS(&Prod);
        }

    return 0;
}
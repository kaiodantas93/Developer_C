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
    //while(getchar()=='S');
        //if(getchar() == 'S'){
        if((*soma) >= IDADE){
            printf("SUA IDADE E: %d\n",(*soma));
            printf("SEJA BEM VINDO\n");
            } else {
                printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",(*soma));
                }
       /*} else {
            printf("TENTE NOVAMENTE\n");
        } */         
      
    } 
/*int CONFN(int* dia, int* mes, int* ano) {
            if(getchar()=='N');
            if(getchar() == 'N'){
                printf("SUA IDADE E: %d\n",(*soma));
            printf("SEJA BEM VINDO DO NAO\n");
            } else {
                printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d\n",(*soma));
                }
               }
         }*/

int main() {

    int soma;
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
        }

           
    /*do {
       
        scanf("%c",&letra);
    }
   
   
    //DD(&dia); MES(&mes); ANO(&ano);

    if();
    if(letra =='N') {
        DD(&dia); MES(&mes); ANO(&ano);
        printf("Sua data de nascimento informada esta correta? %d/%d/%d\n",dia,mes,ano);
       
    } */

   
    // {
       
    /*else if
        if(getchar()=='S') {
       
     } */



    /*if {
        printf("SEJA BEM VINDO DO NAO\n");
    } else {
        printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: \n");
    }*/

  
   
  
    return 0;
}
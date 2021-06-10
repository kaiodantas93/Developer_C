#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IDADE 18
#define ANOATUAL 2021

int DD(int* dia) {
    do {
        *dia = ' ';
        printf("Digite o dia do seu nascimento: ");
        scanf("%d", dia);
       if((getchar()=='N'));
    } while ((*dia) <1 || (*dia) > 31); 
}

int MES(int* mes) {
    do {
        *mes = ' ';
        printf("Digite o MES do seu nascimento: ");
        scanf("%d", mes);
        if((getchar()=='N'));
    } while((*mes) < 1 || (*mes) > 12);
}

int ANO(int* ano) {
    do {
        *ano = ' ';
        printf("Digite o ANO do seu nascimento: ");
        scanf("%d", ano);
        if((getchar()=='N'));
    } while((*ano) < 1900 || (*ano) > ANOATUAL);
}

int CONFS(int* somaidade ,int* ano) {
    (*somaidade) = (ANOATUAL - (*ano));
        if((*somaidade) >= IDADE){
            printf("\n***** SEJA BEM VINDO *****\n");
            } else {
                printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",(*somaidade));
                abort();
                }    
    }

int PRODUTOS (int cod, int quant,double preco[30],double total[30],int i) {

    printf("\nDEPARTAMENTO - BEBIDA ALCOOLICA: \n\n");

    printf(" PRODUTO 1: Skol 473ml Preco por unidade: 4.50 Reais\n");
    printf(" PRODUTO 2: Original 350ml Preco por unidade: 4 Reais\n");
    printf(" PRODUTO 3: Brahma 350ml Preco por unidade: 3 Reais \n");
    printf(" PRODUTO 4: Amstel 473ml Preco por unidade: 5.50 Reais\n");
    printf(" PRODUTO 5: BudWeiser 350ml Preco por unidade: 4 Reais\n");
    printf(" PRODUTO 6: Bohemia 473ml Preco por unidade: 4.50 Reais\n");
    printf(" PRODUTO 7: Itaipava 473ml Preco por unidade: 3 Reais\n");
    printf(" PRODUTO 8: Schin 350ml Preco por unidade: 2.5 Reais\n\n");

    printf("DESCRICAO DA COMPRA\n");

    do {
        printf("\n Digite o codigo do produto: ");
        scanf("%d", &cod);

        printf(" Digite a quantidade: ");
        scanf("%d", &quant);

    } while( cod < 1 || cod > 9);

    switch(cod) {

    case 1:
    printf("\n CONFIRMANDO: %d unidades de Skol 473ml\n",quant);
    preco[0] = 4.5;
    total[0] = preco[0] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[0]); 
    break;

    case 2:
    printf("\n CONFIRMANDO: %d unidades de Original 350ml\n",quant); 
    preco[1] = 4;
    total[1] = preco[1] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[1]);
    break;

    case 3:
    printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n",quant); 
    preco[2] = 3;
    total[2] = preco[2] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[2]);
    break;

    case 4:
    printf("\n CONFIRMANDO: %d unidades de Amstel 473ml\n",quant);
    preco[3] = 5.5;
    total[3] = preco[3] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[3]); 
    break;

    case 5:
    printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n",quant); 
    preco[4] = 4;
    total[4] = preco[4] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[4]);
    break;

    case 6:
    printf("\n CONFIRMANDO: %d unidades de Bohemia 473ml\n",quant); 
    preco[5] = 4.5;
    total[5] = preco[5] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[5]);
    break;

    case 7:
    printf("\n CONFIRMANDO: %d unidades de Itaipava 473ml\n",quant); 
    preco[6] = 3;
    total[6] = preco[6] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[6]);
    break;

    case 8:
    printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n",quant); 
    preco[7] = 2.5;
    total[7] = preco[7] * quant;
    printf(" TOTAL: %.2lf Reais\n\n",total[7]);
    break;
    }

}

double COMPRAS(double total[30],double somatotal,int i) {
    somatotal = 0;
    for(i = 0; i<=7; i++) {
        printf("total %d: %.2lf\n",i,total[i]);    
    }

    for(i = 0; i <=7; i++) 
        somatotal = somatotal + total[i];
    printf(" Total: %.2lf Reais\n",somatotal);
}

int main() {

    int dia,mes,ano;
    int quant,cod,somaidade,i;
    double somatotal, total[30], preco[30];
    char resp2[2] = "n";
    char resp1[2] = "N";
    char resp[2] = " ";
    char res[2] = "S";
    char res1[2] = "s";

    do {

        DD(&dia); printf("\n");
        MES(&mes); printf("\n");
        ANO(&ano); printf("\n");

        printf("Sua data de nascimento informada esta correta? %d/%d/%d\n",dia,mes,ano);
        do {
            printf("CONFIRME: (S|N): ");
            scanf("%s",&resp);

            if (strcmp(resp1,resp)) {
                continue;
            }

            while(strcmp(res1,resp)) {
                break;
            }

            if (strcmp(resp2,resp)) {
                break;
            }

            while(strcmp(res,resp)) {
                break;
            }

        } while(strcmp(res,resp));
       
    } while(strcmp(res,resp));

        CONFS(&somaidade, &ano);

    do {
        PRODUTOS(cod, quant, &preco[30], &total[30],i);
        printf(" Deseja finalizar a compra S/N: ");
        if((getchar()== 'n'));
    } while((getchar()=='n'));

    COMPRAS(&total[30],somatotal,i);
  
    return 0;
}

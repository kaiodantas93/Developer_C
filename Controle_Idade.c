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
            printf("\n***** SEJA BEM VINDO *****\n");
            } else {
                printf("VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",(*soma));
                abort();
                }      
    }


int PRODUTOS (int* cod, int* quant,double preco[10],double total[10]) {

        printf("\nDEPARTAMENTO - BEBIDA ALCOOLICA: \n\n");

        printf(" PRODUTO 1: Skol 473ml Preco por unidade: %.2lf\n",((preco[0]=4.5)));
        printf(" PRODUTO 2: Original 350ml Preco por unidade: %.2lf\n",((preco[1]=4)));
        printf(" PRODUTO 3: Brahma 350ml Preco por unidade: %.2lf\n",((preco[2]=3)));
        printf(" PRODUTO 4: Amstel 473ml Preco por unidade: %.2lf\n",((preco[3]=5.5)));
        printf(" PRODUTO 5: BudWeiser 350ml Preco por unidade: %.2lf\n",((preco[4]=4)));
        printf(" PRODUTO 6: Bohemia 473ml Preco por unidade: %.2lf\n",((preco[5]=4.5)));
        printf(" PRODUTO 7: Itaipava 473ml Preco por unidade: %.2lf\n",((preco[6]=3)));
        printf(" PRODUTO 8: Schin 350ml Prec o por unidade: %.2lf\n\n",((preco[7]=2.5)));

        printf("DESCRICAO DA COMPRA\n");

        do {
            printf("\n Digite o codigo do produto: ");
            scanf("%d", cod);
        } while((*cod) < 1 || (*cod) > 7);
       
        printf(" Digite a quantidade: ");
        scanf("%d", quant);

            switch((*cod)) {

        case 1:
        printf("\n CONFIRMANDO: %d unidades de Skol 473ml\n\n",(*quant));
        preco[0] = 4.5;
        total[0] = preco[0] * (*quant);
        break;

        case 2:
        printf("\n CONFIRMANDO: %d unidades de Original 350ml\n\n",(*quant));
        preco[1] = 4;
        total[1] = preco[1] * (*quant);
        break;

        case 3:
        printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n\n",(*quant));
        preco[2] = 3;
        total[2] = preco[2] * (*quant);
        break;

        case 4:
        printf("\n CONFIRMANDO: %d unidades de Amstel 473ml\n\n",(*quant));
        preco[3] = 5.5;
        total[3] = preco[3] * (*quant);
        break;

        case 5:
        printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n\n",(*quant));
        preco[4] = 4;
        total[4] = preco[4] * (*quant);
        break;

        case 6:
        printf("\n CONFIRMANDO: %d unidades de Bohemia 473ml\n\n",(*quant));
        preco[5] = 4.5;
        total[5] = preco[5] * (*quant);
        break;

        case 7:
        printf("\n CONFIRMANDO: %d unidades de Itaipava 473ml\n\n",(*quant));
        preco[6] = 3;
        total[6] = preco[6] * (*quant);
        break;

        case 8:
        printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n",(*quant));
        preco[7] = 2.5;
        total[7] = preco[7] * (*quant);
        break;
    }
}

double COMPRAS(double total[10],double valor[10]) {

    valor[0] = total[0];
    valor[1] = total[2];
    valor[2] = total[1];
    valor[3] = total[3];
    valor[4] = total[4];
    valor[5] = total[5];
    valor[6] = total[6];

    printf(" Total: %.2lf Reais\n",((valor[0])+(valor[1])+(valor[2])+(valor[3])+(valor[4])+(valor[5])+(valor[6])));
}

int main() {

    int soma;
    int dia,mes,ano;
    char letra;
    int quant,cod;
    double total[10];
    double valor[10];
    double preco[10];

    do {
        DD(&dia); MES(&mes); ANO(&ano);
        printf("Sua data de nascimento informada esta correta? %d/%d/%d\n",dia,mes,ano);
        printf("CONFIRME: (S|N): ");
        if(getchar()=='N');
    } while(getchar()=='N');

    if(!(getchar()=='N')){
            CONFS(&soma, &ano);
        }

    do {
        PRODUTOS(&cod, &quant, &preco[10], &total[10]);

        printf(" Deseja finalizar a compra S/N: ");

        if(getchar()== 'N');

    } while(getchar()=='N');

    COMPRAS(&total[10], &valor[10]);
   
    return 0;
}
    
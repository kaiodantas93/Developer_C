#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define IDADE 18
#define ANOATUAL 2021

int DD(int* dia, char* data) {  
    int atoi(const char *data);
    do {
        printf("Digite o dia do seu nascimento: ");
        scanf("%s", data);
        (*dia) =atoi(data);
        if((*dia) < 1 || (*dia) > 31) {
           memset(dia, 0, sizeof(dia));
           memset(data, 0, sizeof(data));
        } else {
            memset(data, 0, sizeof(data));
        }
        } while ((*dia) < 1 || (*dia) > 31);   
}
   
int MES(int* mes, char* maio) {  
    int atoi(const char *maio);
    do {
        printf("Digite o mes do seu nascimento: ");
        scanf("%s",maio);
        (*mes)=atoi(maio);
        if((*mes) < 1 || (*mes) > 12) {
            memset(mes, 0, sizeof(mes));
            memset(maio, 0, sizeof(maio));
            } else {
                memset(maio, 0, sizeof(maio));
            }
        } while ((*mes) < 1 || (*mes) > 12);   
}

int ANO(int* ano, char* adata) {
    int atoi(const char *adata);
    do {
        printf("Digite o ANO do seu nascimento: ");
        scanf("%s", adata);
        (*ano) =atoi(adata);
        } while ((*ano) < 1900 || (*ano) > ANOATUAL);
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

        while (cod < 1 || cod > 9) {

            printf("\n Digite o codigo do produto: ");
            scanf("%d", &cod);
        }

        printf(" Digite a quantidade: ");
        scanf("%d", &quant);

        switch(cod) {

            case 1:
            printf("\n CONFIRMANDO: %d unidades de Skol 473ml\n",quant);
            preco[0] = 4.5;
            double total0[10];
            double soma1 = 0;
            int contador1 = 0;

            for(i = 0; i <= contador1; i++) {
                total0[i] = preco[0] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total0[i]);
            }

            for(i = 0; i <= contador1; i++)
                total[0] = total[0] + total0[i];
            contador1++;
            break; 

            case 2:
            printf("\n CONFIRMANDO: %d unidades de Original 350ml\n",quant);
            preco[1] = 4;

            double total2[10];
            double soma2 = 0; 
            int contador2 = 0;

            for(i = 0; i <= contador2; i++) {
                total2[i] = preco[1] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total2[i]);
            }

            for(i = 0; i <= contador2; i++)
                total[1] = total[1] + total2[i];
            contador2++;
            break;

            case 3:
            printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n",quant);
            preco[2] = 3;

            double total3[10];
            double soma3 = 0; 
            int contador3 = 0;

            for(i = 0; i <= contador3; i++) {
                total3[i] = preco[2] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total3[i]);
            }

            for(i = 0; i <= contador3; i++)
                total[2] = total[2] + total3[i];
            contador3++;
            break;

            case 4:
            printf("\n CONFIRMANDO: %d unidades de Amstel 473ml\n",quant);
            preco[3] = 5.5;

            double total4[10];
            double soma4 = 0; 
            int contador4 = 0;

            for(i = 0; i <= contador4; i++) {
                total4[i] = preco[3] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total4[i]);
            }

            for(i = 0; i <= contador4; i++)
                total[3] = total[3] + total4[i];
            contador4++;
            break;

            case 5:
            printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n",quant);
            preco[4] = 4;

            double total5[10];
            double soma5 = 0; 
            int contador5 = 0;

            for(i = 0; i <= contador5; i++) {
                total5[i] = preco[4] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total5[i]);
            }

            for(i = 0; i <= contador5; i++)
                total[4] = total[4] + total5[i];
            contador5++;
            break;

            case 6:
            printf("\n CONFIRMANDO: %d unidades de Bohemia 473ml\n",quant);
            preco[5] = 4.5;

            double total6[10];
            double soma6 = 0; 
            int contador6 = 0;

            for(i = 0; i <= contador6; i++) {
                total6[i] = preco[5] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total6[i]);
            }

            for(i = 0; i <= contador6; i++)
                total[5] = total[5] + total6[i];
            contador6++;
            break;

            case 7:
            printf("\n CONFIRMANDO: %d unidades de Itaipava 473ml\n",quant);
            preco[6] = 3;

            double total7[10];
            double soma7 = 0; 
            int contador7 = 0;

            for(i = 0; i <= contador7; i++) {
                total7[i] = preco[6] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total7[i]);
            }

            for(i = 0; i <= contador7; i++)
                total[6] = total[6] + total7[i];
            contador7++;
            break;

            case 8:
            printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n",quant);
            preco[7] = 2.5;

            double total8[10];
            double soma8 = 0; 
            int contador8 = 0;

            for(i = 0; i <= contador8; i++) {
                total8[i] = preco[7] * quant;
                printf(" TOTAL: %.2lf Reais\n\n",total8[i]);
            }

            for(i = 0; i <= contador8; i++)
                total[7] = total[7] + total8[i];
            contador8++;
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
        printf(" Soma total: %.2lf Reais\n",somatotal);
    }

    int main() {
        int dia,mes,ano;
        char data;
        char maio;
        char adata;
        int quant,cod,somaidade,i;
        double somatotal, total[30], preco[30];
        char resp2[2] = "n";
        char resp1[2] = "N";
        char resp[2] = " ";
        char res[2] = "S";
        char res1[2] = "s";

        do {
            DD(&dia,&data); printf("\n");
            MES(&mes,&maio); printf("\n");
            ANO(&ano,&adata); printf("\n");

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

            } while(strcmp(res,resp));

        } while(strcmp(res,resp));

        CONFS(&somaidade, &ano);

        do {
            PRODUTOS(cod, quant, &preco[30], &total[30],i);
            do {
                printf(" Deseja finalizar a compra S/N: ");
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

                printf("**\n");
            } while(strcmp(res,resp));

        } while(strcmp(res,resp));

        COMPRAS(&total[30],somatotal,i);

        return 0;
    }
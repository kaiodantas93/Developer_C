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
        printf(" Digite o dia do seu nascimento: ");
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
        printf(" Digite o mes do seu nascimento: ");
        scanf("%s",maio);
        (*mes)=atoi(maio);
        if((*mes) < 1 || (*mes) > 12) {
            memset(maio, 0, sizeof(maio));
        }
    } while ((*mes) < 1 || (*mes) > 12);
}

int ANO(int* ano, char* adata) {
    int atoi(const char *adata);
    do {
        printf(" Digite o ANO do seu nascimento: ");
        scanf("%s", adata);
        (*ano) =atoi(adata);
    } while ((*ano) < 1900 || (*ano) > ANOATUAL);
}

int CONFS(int* somaidade ,int* ano) {
    (*somaidade) = (ANOATUAL - (*ano));
    if((*somaidade) >= IDADE){
        printf("\n ***** SEJA BEM VINDO *****\n\n");
    } else {
        printf(" VOCE NAO PODE ENTRAR, POIS SUA IDADE E: %d ANOS \n",(*somaidade));
        abort();
    } 
}

int CODIGO (int* cod, char* codigo) {
    do {
        int atoi(const char *codigo);
        printf(" Digite o codigo do produto: ");
        scanf("%s", codigo);
        fflush(stdin);
        (*cod) =atoi(codigo);
        } while ((*cod) < 1 || (*cod) > 8);        
    }

int QUANTIDADE (int* quant, char* quantid) {
    do {
        int atoi(const char *quantid);
        printf(" Digite a quantidade: ");
        scanf("%s", quantid);
        fflush(stdin);
        (*quant) =atoi(quantid);
        } while ((*quant) < 1 || (*quant) > 1000);
    }

int DEPARTAMENTO (int* dep, char* codep) {
        printf(" ESCOLHA O DEPARTAMENTO:\n\n");
        printf(" 1: BEBIDA ALCOOLICA - (CERVEJA)\n");
        printf(" 2: BEBIDA ALCOOLICA - (WHISKY)\n");
        printf(" 3: BEBIDA ALCOOLICA - (GIN)\n\n");

    do {
        int atoi(const char *codep);
        printf(" Digite o codigo do departamento: ");
        scanf("%s", codep);
        fflush(stdin);
        (*dep) =atoi(codep);
        } while ((*dep) < 1 || (*dep) > 3);        
}

int CERVEJA (int* cod, int* quant, int* dep, double preco[30], double total[30],int i) {
    switch(*cod) {
       case 1:
        printf("\n CONFIRMANDO: %d unidades de Skol 473ml\n",(*quant));
        preco[1] = 4.5;
        double total1[10];
        int contador1 = 0;

        for(i = 0; i <= contador1; i++) {
            total1[i] = preco[1] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total1[i]);
        }
        for(i = 0; i <= contador1; i++)
            total[1] = total[1] + total1[i];
        contador1++;
        break;

        case 2:
        printf("\n CONFIRMANDO: %d unidades de Original 350ml\n",(*quant));
        preco[2] = 4;
        double total2[10];
        int contador2 = 0;

        for(i = 0; i <= contador2; i++) {
            total2[i] = preco[2] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total2[i]);
        }

        for(i = 0; i <= contador2; i++)
            total[2] = total[2] + total2[i];
            contador2++;
            break;

        case 3:
        printf("\n CONFIRMANDO: %d unidades de Brahma 350ml\n",(*quant));
        preco[3] = 3;
        double total3[10];
        int contador3 = 0;

        for(i = 0; i <= contador3; i++) {
            total3[i] = preco[3] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total3[i]);
        }

        for(i = 0; i <= contador3; i++)
            total[3] = total[3] + total3[i];
            contador3++;
            break;

        case 4:
        printf("\n CONFIRMANDO: %d unidades de Amstel 473ml\n",(*quant));
        preco[4] = 5.5;
        double total4[10];
        int contador4 = 0;

        for(i = 0; i <= contador4; i++) {
            total4[i] = preco[4] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total4[i]);
        }

        for(i = 0; i <= contador4; i++)
            total[4] = total[4] + total4[i];
        contador4++;
        break;

        case 5:
        printf("\n CONFIRMANDO: %d unidades de BudWeiser 350ml\n",(*quant));
        preco[5] = 4;
        double total5[10];
        int contador5 = 0;

        for(i = 0; i <= contador5; i++) {
            total5[i] = preco[5] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total5[i]);
        }

        for(i = 0; i <= contador5; i++)
            total[5] = total[5] + total5[i];
        contador5++;
        break;

        case 6:
        printf("\n CONFIRMANDO: %d unidades de Bohemia 473ml\n",(*quant));
        preco[6] = 4.5;
        double total6[10];
        int contador6 = 0;

        for(i = 0; i <= contador6; i++) {
            total6[i] = preco[6] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total6[i]);
        }

        for(i = 0; i <= contador6; i++)
            total[6] = total[6] + total6[i];
        contador6++;
        break;

        case 7:
        printf("\n CONFIRMANDO: %d unidades de Itaipava 473ml\n",(*quant));
        preco[7] = 3;
        double total7[10];
        int contador7 = 0;

        for(i = 0; i <= contador7; i++) {
            total7[i] = preco[7] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total7[i]);
        }

        for(i = 0; i <= contador7; i++)
            total[7] = total[7] + total7[i];
        contador7++;
        break;

        case 8:
        printf("\n CONFIRMANDO: %d unidades de Schin 350ml\n",(*quant));
        preco[8] = 2.5;
        double total8[10];
        int contador8 = 0;

        for(i = 0; i <= contador8; i++) {
            total8[i] = preco[8] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",total8[i]);
        }

        for(i = 0; i <= contador8; i++)
            total[8] = total[8] + total8[i];
        contador8++;
        break;
    }
    (*dep) = 1;
}

int WHISKY (int* cod, int* quant, int* dep, double wpreco[30], double wtotal[30], int j) {
    switch(*cod) {
        case 1:
        printf("\n CONFIRMANDO %d unidades de Red Label 750ml\n",(*quant));
        wpreco[1] = 65;
        double wtotal1[10];
        int contador1 = 0;

        for(j = 0; j <= contador1; j++) {
            wtotal1[j] = wpreco[1] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",wtotal1[j]);
        }

        for(j = 0; j <=contador1; j++)
            wtotal[1] = wtotal[1] + wtotal1[j];
            contador1++;
            break;

        case 2:
        printf("\n CONFIRMANDO %d unidades de Red Label 1000ml\n",(*quant));
        wpreco[2] = 78;
        double wtotal2[10];
        int contador2 = 0;

        for(j = 0; j <= contador2; j++) {
            wtotal2[j] = wpreco[2] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",wtotal2[j]);
        }

        for(j = 0; j <=contador2; j++)
            wtotal[2] = wtotal[2] + wtotal2[j];
            contador2++;
            break;
    
        case 3:
        printf("\n CONFIRMANDO %d unidades de Ballantines 750ml\n",(*quant));
        wpreco[3] = 55;
        double wtotal3[10];
        int contador3 = 0;

        for(j = 0; j <= contador3; j++) {
            wtotal3[j] = wpreco[3] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",wtotal3[j]);
        }

        for(j = 0; j <=contador3; j++)
            wtotal[3] = wtotal[3] + wtotal3[j];
            contador3++;
            break;

        case 4:
        printf("\n CONFIRMANDO %d unidades de Ballantines 1000ml\n",(*quant));
        wpreco[4] = 63;
        double wtotal4[10];
        int contador4 = 0;

        for(j = 0; j <= contador4; j++) {
            wtotal4[j] = wpreco[4] * (*quant);
            printf(" TOTAL: %.2lf\n\n",wtotal4[j]);
        }

        for (j = 0; j<=contador4; j++) 
            wtotal[4] = wtotal[4] + wtotal4[j];
            contador4++;
            break;

        case 5:
        printf("\n CONFIRMANDO %d unidades de Jack Daniels Tenessee 1000ml\n",(*quant));
        wpreco[5] = 130;
        double wtotal5[10];
        int contador5 = 0;

        for (j = 0; j<=contador5; j++) {
            wtotal5[j] = wpreco[5] * (*quant);
            printf(" TOTAL: %.2lf\n\n",wtotal5[j]);
        }

        for (j = 0; j<=contador5; j++)
            wtotal[5] = wtotal[5] + wtotal5[j];
            contador5++;
            break;

        case 6:
        printf("\n CONFIRMANDO %d unidades de Jack Daniels HONEY 1000ml\n",(*quant));
        wpreco[6] = 139;
        double wtotal6[10];
        int contador6 = 0;

        for (j = 0; j<=contador6; j++) {
            wtotal6[j] = wpreco[6] * (*quant);
            printf(" TOTAL: %.2lf\n\n",wtotal6[j]);
        }

        for (j = 0; j<=contador6; j++)
            wtotal[6] = wtotal[6] + wtotal6[j];
            contador6++;
            break;

        case 7:
        printf("\n CONFIRMANDO %d unidades de Jack Daniels FIRE 1000ml\n",(*quant));
        wpreco[7] = 139;
        double wtotal7[10];
        int contador7 = 0;

        for (j = 0; j<=contador7; j++) {
            wtotal7[j] = wpreco[7] * (*quant);
            printf(" TOTAL: %.2lf\n\n",wtotal7[j]);
        }

        for (j = 0; j <=contador7; j++)
            wtotal[7] = wtotal[7] + wtotal7[j];
            contador7++;
            break;

        case 8:
        printf("\n CONFIRMANDO %d unidades de Jack Daniels APPLE 1000ml\n",(*quant));
        wpreco[8] = 145;
        double wtotal8[10];
        int contador8 = 0;

        for (j = 0; j<=contador8; j++) {
            wtotal8[j] = wpreco[8] * (*quant);
            printf(" TOTAL: %.2lf\n\n",wtotal8[j]);
        }

        for(j = 0; j<=contador8; j++)
            wtotal[8] = wtotal[8] + wtotal8[j];
            contador8++;
            break;
        }
        (*dep) = 2;
}

int GIN(int* cod, int* quant, int* dep, double gpreco[30], double gtotal[30], int k) {
    switch(*cod){
        case 1:
        printf("\n CONFIRMANDO %d unidades de Tanqueray 750ml\n",(*quant));
        gpreco[1] = 105;
        double gtotal1[10];
        int contador1 = 0;

        for(k = 0; k <=contador1; k++) {
            gtotal1[k] = gpreco[1] * (*quant);
            printf(" TOTAL: %.2lf Reais\n\n",gtotal1[k]);
        }

        for(k = 0; k <=contador1; k++)
            gtotal[1] = gtotal[1] + gtotal1[k];
            contador1++;
            break;

        case 2:
        printf("\n CONFIRMANDO %d unidades de Tanqueray Sevilla 750ml\n",(*quant));
        gpreco[2] = 110;
        double gtotal2[10];
        int contador2 = 0;

        for(k = 0; k <=contador2; k++) {
            gtotal2[k] = gpreco[2] * (*quant);
            printf(" Total: %.2lf Reais\n\n",gtotal2[k]);
        }

        for(k = 0; k <=contador2; k++)
            gtotal[2] = gtotal[2] + gtotal2[k];
            contador2++;
            break;

        case 3:
        printf("\n CONFIRMANDO %d unidades de Beefeater Dry 750ml\n",(*quant));
        gpreco[3] = 70;
        double gtotal3[10];
        int contador3 = 0;

        for(k = 0; k <=contador3; k++) {
            gtotal3[k] = gpreco[3] * (*quant);
            printf(" TOTAL: %.2lf\n\n",gtotal3[k]);
        }

        for(k = 0; k <=contador3; k++)
            gtotal[3] = gtotal[3] + gtotal3[k];
            contador3++;
            break;

        case 4:
        printf("\n CONFIRMANDO %d unidades de Gordon'S Classico 750ml\n",(*quant));
        gpreco[4] = 67;
        double gtotal4[10];
        int contador4 = 0;

        for(k = 0; k <=contador4; k++) {
            gtotal4[k] = gpreco[4] * (*quant);
            printf(" TOTAL: %.2lf\n\n",gtotal4[k]);
        }

        for(k = 0; k <=contador4; k++)
            gtotal[4] = gtotal[4] + gtotal4[k];
            contador4++;
            break;

        case 5:
        printf("\n CONFIRMANDO %d unidades de Gordon'S Pink 750ml\n",(*quant));
        gpreco[5] = 67;
        double gtotal5[10];
        int contador5 = 0;

        for(k = 0; k <=contador5; k++) {
            gtotal5[k] = gpreco[5] * (*quant);
            printf(" TOTAL: %.2lf\n\n",gtotal5[k]);
        }

        for(k = 0; k <=contador5; k++)
            gtotal[5] = gtotal[5] + gtotal5[k];
            contador5++;
            break;
        }
        (*dep) = 3;
}

double COMPCER(double total[30], double somatotal,int i) {
    somatotal = 0;

        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n\n");

        for(i = 1; i<=8; i++) {
            if(total[i] > 1) {
                printf(" PRODUTO %d: %.2lf Reais\n",i,total[i]);
                }
            }

    for(i = 1; i <=8; i++)
        somatotal = somatotal + total[i];
        printf("\n Soma total: %.2lf Reais\n",somatotal);
    }

double COMPWIS(double wtotal[30], double somawis, int j) {
somawis = 0;
   
        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");

        for(j = 1; j <=8; j++) {
            if(wtotal[j] > 1) {
                printf(" PRODUTO %d: %.2lf Reais\n",j,wtotal[j]);
                }
        }
    
        for(j = 1; j <=8; j++)
            somawis = somawis + wtotal[j];
        printf("\n Soma total: %.2lf Reais\n",somawis);
}

int COMGIN(double gtotal[30], double somagin, int k) {
    somagin = 0;
   
        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");

        for(k = 1; k <=8; k++) {
            if(gtotal[k] > 1) {
                printf(" PRODUTO %d: %.2lf Reais\n",k,gtotal[k]);
                }
        }
    
        for(k = 1; k <=8; k++)
            somagin = somagin + gtotal[k];
        printf("\n Soma total: %.2lf Reais\n",somagin);
}

int main() {

    int dia,mes,ano,cod,somaidade,i,j,k,quant,dep;
    char data,maio,adata,quantid,codigo,codep;
    double somawis,somatotal,somagin;

    double total[30] = {0};
    double preco[30] = {0};
    double wpreco[30] = {0};
    double wtotal[30] = {0};
    double gtotal[30] = {0};
    double gpreco[30] = {0};
    char resp2[2] = "n";
    char resp1[2] = "N";
    char resp[2] = " ";
    char res[2] = "S";
    char res1[2] = "s";

    do {
        DD(&dia,&data); printf("\n");
        MES(&mes,&maio); printf("\n");
        ANO(&ano,&adata); printf("\n");

        printf(" Sua data de nascimento informada esta correta? %d/%d/%d\n",dia,mes,ano);
        do {
            printf(" CONFIRME: (S|N): ");
            scanf("%s",&resp);
            fflush(stdin);

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

    DEPARTAMENTO(&dep, &codep);
    memset((&quant), 0,sizeof(quant));

    do {
        switch(dep) {
        case 1:
        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (CERVEJA) \n\n");
        printf(" PRODUTO 1: Skol 473ml Preco por unidade: 4.50 Reais\n");
        printf(" PRODUTO 2: Original 350ml Preco por unidade: 4 Reais\n");
        printf(" PRODUTO 3: Brahma 350ml Preco por unidade: 3 Reais \n");
        printf(" PRODUTO 4: Amstel 473ml Preco por unidade: 5.50 Reais\n");
        printf(" PRODUTO 5: BudWeiser 350ml Preco por unidade: 4 Reais\n");
        printf(" PRODUTO 6: Bohemia 473ml Preco por unidade: 4.50 Reais\n");
        printf(" PRODUTO 7: Itaipava 473ml Preco por unidade: 3 Reais\n");
        printf(" PRODUTO 8: Schin 350ml Preco por unidade: 2.5 Reais\n\n");

        printf(" DESCRICAO DA COMPRA:\n");
        printf("\n");

        CODIGO(&cod,&codigo);
       
        QUANTIDADE(&quant,&quantid);
     
        CERVEJA(&cod, &quant, &dep, &preco[30], &total[30],i);
        break;

        case 2:
        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (WHISKY) \n\n");
        printf(" PRODUTO 1: Red Label 750ml Preco por unidade: 65.00 Reais\n");
        printf(" PRODUTO 2: Red Label 1000ml Preco por unidade: 78.00 Reais\n");
        printf(" PRODUTO 3: Ballantines 750ml Preco por unidade: 55.00 Reais \n");
        printf(" PRODUTO 4: Ballantines 1000ml Preco por unidade: 63.00 Reais\n");
        printf(" PRODUTO 5: Jack Daniels Tenessee 1000ml Preco por unidade: 130.00 Reais\n");
        printf(" PRODUTO 6: Jack Daniels HONEY 1000ml Preco por unidade: 139.00 Reais\n");
        printf(" PRODUTO 7: Jack Daniels FIRE 1000ml Preco por unidade: 139.90 Reais\n");
        printf(" PRODUTO 8: Jack Daniels APPLE 1000ml Preco por unidade: 145.00 Reais\n\n");

        printf(" DESCRICAO DA COMPRA:\n");
        printf("\n");

        CODIGO(&cod,&codigo);
       
        QUANTIDADE(&quant,&quantid);

        WHISKY(&cod, &quant, &dep, &wpreco[30], &wtotal[30],j);
        break;

        case 3:
        printf("\n DEPARTAMENTO - BEBIDA ALCOOLICA: (GIN) \n\n");
        printf(" PRODUTO 1: Tanqueray 750ml Preco por unidade: 105.00 Reais\n");
        printf(" PRODUTO 2: Tanqueray Sevilla 750ml Preco por unidade: 110.00 Reais\n");
        printf(" PRODUTO 3: Beefeater Dry 750ml Preco por unidade: 70.00 Reais\n");
        printf(" PRODUTO 4: Gordon'S Classico 750ml Preco por unidade: 67.00 Reais\n");
        printf(" PRODUTO 5: Gordon'S Pink 750ml Preco por unidade: 69.00 Reais\n\n");

        printf(" DESCRICAO DA COMPRA:\n");
        printf("\n");

        CODIGO(&cod,&codigo);
       
        QUANTIDADE(&quant,&quantid);

        GIN(&cod, &quant, &dep, &gpreco[30], &gtotal[30],k);
        break;
}
    do {
          printf(" Deseja finalizar a compra S/N: ");
            scanf("%s",&resp);
            fflush(stdin);
            printf("\n");

            if(strcmp(resp1,resp)) {
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

    switch(dep) {
        case 1:
        COMPCER(&total[30], somatotal, i);
        break;

        case 2:
        COMPWIS(&wtotal[30], somawis, j);
        break;

        case 3:
        COMGIN(&gtotal[30], somagin, k);
   }

    return 0;
}


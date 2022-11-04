#include<stdio.h>
#include<stdlib.h>

int main(){

    int menu, close, endprog, senha, i, quant;

    struct referencia{

    char inf0[100], inf1[100], inf2[100], inf3[100], inf4[100], inf5[100], inf6[100], inf7[100];
}

CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];

            char usuario[100];

    system("cls");
    printf("LOGIN:");
    fflush(stdin);
    scanf("%[^\n]*s", usuario);
    printf("SENHA:");
    scanf("%d", &senha);



            switch(senha){
                case 123:

                    while(menu!=0){
            while(endprog!=1){
                system("color Ff");
                system("cls");

                    printf("-----------------------------------------------------------------------------------\n");
                    printf("\t\t  ***** SISTEMA DE CADASTRO DE PACIENTES ***** \n\n");
                    printf("-----------------------------------------------------------------------------------\n\n");
                    printf("\t\t\t    Seja bem vindo(a) %s\n", usuario);
                    printf("___________________________________________________________________________________\n");
                    printf("1 - CADASTRAR \n");
                    printf("2 - EXIBIR CADASTROS \n");
                    printf("0 - SAIR \n");
                    printf("-----------------------------------------------------------------------------------\n\n");
                    printf("\n QUAL OPCAO DESEJA ACESSAR? \n");
                    scanf("%d", &menu);

    switch(menu){
                case 1:
                    system("cls");
                    printf("\n\n QUANTOS CADASTROS DESEJA REALIZAR? \n");;
                    scanf("%d", &quant);

                for(i=1;i<=quant;i++){
                    system("cls");
                    printf("\n\n\t\t\t      INICIANDO CADASTRO %d\n", i);
                    printf("\t\t\t       ----------------------------\n\n");
                    printf("\n NOME DO PACIENTE:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf0);

                    printf("\n CPF:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf1);

                    printf("\n TELEFONE:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf2);

                    printf("\n ENDERECO:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf3);

                    printf("\n DATA/NASCIMENTO:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf4);

                    printf("\n EMAIL:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf5);

                    printf("\n DATA/DIAGNOSTICO:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf6);

                    printf("\n COMORBIDADES:");
                    fflush(stdin);
                    scanf("%[^\n]s", CA [i].inf7);


                    printf("\n\n\t\t");
                    system("pause");
                    system("cls");
                }
                break;


                case 2:
                    system("cls");

                    for(i=1;i<=quant;i++){
                        system("cls");
                        printf("\n\n\t\t\t\t      EXIBINDO CADASTRO %d\n", i);
                        printf("\t\t\t       --------------------------------\n\n");
                        printf(" NOME DO PACIENTE: %s\n", CA [i].inf0);
                        printf("\n CPF: %s\n", CA [i].inf1);
                        printf("\n TELEFONE: %s\n", CA [i].inf2);
                        printf("\n ENDERECO: %s\n", CA [i].inf3);
                        printf("\n DATA DE NASCIMENTO: %s\n", CA [i].inf4);
                        printf("\n EMAIL: %s\n", CA [i].inf5);
                        printf("\n DATA DO DIAGNOSTICO: %s\n", CA [i].inf6);
                        printf("\n COMORBIDADE: %s\n", CA [i].inf7);
                        printf("\n\n\t\t");
                        system("pause");

                }
                break;



                case 0:
                    system("cls");
                    printf("\n\n\t\t\t\t\t DESEJA ENCERRAR O PROGRAMA? \n\n");
                    printf("\t\t\t --------------------------------------------------------------\n\n");
                    printf(" 1 - SIM \n 2 - NAO");
                    printf("\n\n");
                    scanf("%d", &endprog);

                switch(close){
                case 1:
                    system("cls");
                    printf("\n\t\t SAINDO DO SISTEMA! \n\n\n\t\t");
                    system("pause");
                    return 0;
                    break;
                }
                }
                }
                break;
                    }
            }
system("pause");
return 0;
}




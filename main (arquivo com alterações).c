#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> // biblioteca para uso de acentua��o - idioma (Pt-Br)

#define TAM 600

struct dados_pessoas
{
    char inf0[100], inf1[100], inf2[100], inf3[100], inf4[100], inf5[100], inf6[100], inf7[100];
};

typedef struct dados_pessoas dados;

int main()
{
    setlocale(LC_ALL, "portuguese"); // permite uso de acentos (Pt-Br)

    dados lista[TAM];

    int menu=1, close=0, endprog=0, senha=0, i=0, quant=0, comorb=0;

    char usuario[100];

    system("cls");
    printf("LOGIN:");
    fflush(stdin);
    scanf("%[^\n]s", usuario);
    printf("SENHA:");
    scanf("%d", &senha);



    switch(senha)
    {
    case 123:

        while(menu!=0)
        {
            while(endprog!=1)
            {
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
                printf("\n QUAL OP��O DESEJA ACESSAR? \n");
                scanf("%d", &menu);

                switch(menu)
                {
                case 1:
                    system("cls");
                    printf("\n\n QUANTOS CADASTROS DESEJA REALIZAR? \n");
                    scanf("%d", &quant);

                    for(i=1; i<=quant; i++)
                    {
                        system("cls");
                        printf("\n\n\t\t\t      INICIANDO CADASTRO %d\n", i);
                        printf("\t\t\t       ----------------------------\n\n");
                        printf("\n NOME DO PACIENTE:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf0);

                        printf("\n CPF:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf1);

                        printf("\n TELEFONE:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf2);

                        printf("\n ENDERECO:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf3);

                        printf("\n DATA/NASCIMENTO:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf4);

                        printf("\n E-MAIL:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf5);

                        printf("\n DATA/DIAGN�STICO:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf6);

                        do
                        {
                            printf("\n O PACIENTE POSSUI ALGUMA COMORBIDADE? \n");
                            printf("\t\t\t       ----------------------------\n\n");
                            printf(" 1 - SIM \n 2 - NAO");
                            printf("\n\n");
                            scanf("%d", &comorb);
                            switch(comorb)
                            {
                            case 1:
                                printf("\n COMORBIDADES:");
                                fflush(stdin);
                                scanf("%[^\n]s", lista[i].inf7);
                                break;

                            case 2:
                                strcpy(lista[i].inf7,"N\\A");
                                break;

                            default:
                                system("cls");
                                break;
                            }

                        }
                        while (comorb!=1&&comorb!=2);

                        printf("\n\n\t\t");
                        system("pause");
                        system("cls");
                    }
                    break;


                case 2:
                    system("cls");

                    for(i=1; i<=quant; i++)
                    {
                        system("cls");
                        printf("\n\n\t\t\t\t      EXIBINDO CADASTRO %d\n", i);
                        printf("\t\t\t       --------------------------------\n\n");
                        printf(" NOME DO PACIENTE: %s\n", lista[i].inf0);
                        printf("\n CPF: %s\n", lista[i].inf1);
                        printf("\n TELEFONE: %s\n", lista[i].inf2);
                        printf("\n ENDERECO: %s\n", lista[i].inf3);
                        printf("\n DATA DE NASCIMENTO: %s\n", lista[i].inf4);
                        printf("\n EMAIL: %s\n", lista[i].inf5);
                        printf("\n DATA DO DIAGNOSTICO: %s\n", lista[i].inf6);
                        printf("\n COMORBIDADE: %s\n", lista[i].inf7);
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

                    switch(close)
                    {
                    case 1:
                        system("cls");
                        printf("\n\t\t SAINDO DO SISTEMA! \n\n\n\t\t");
                        system("pause");
                        return 0;
                        break;
                    }
                }
            }
        }
    }

    system("pause");
    return 0;
}




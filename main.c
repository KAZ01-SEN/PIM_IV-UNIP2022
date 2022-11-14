#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<locale.h> // biblioteca para uso de acentuação - idioma (Pt-Br)
#include <time.h> // Biblioteca para cálculos de tempo.
#include <conio.h>

#define TAM 600

struct dados_pessoas
{
    char inf0[100], inf1[100], inf2[100], inf3[100], inf4[100], inf5[100], inf6[100], inf7[100];
    int dataD,dataM,dataA,diagD,diagM,diagA;
};

typedef struct dados_pessoas dados;

bool checkBissexto(int ano) //Função para checar anos bissextos. Não precisa ser chamada fora da função checkDataErr.
{
    bool flag = false;
    if (ano % 100 == 0)
    {
        if (ano % 400 == 0)
        {
            flag = true;
        }
    }
    else if (ano % 4 == 0)
    {
        flag = true;
    }
    return (flag);
}

bool checkDataErr (int dia, int mes, int ano, int anoatual) //Função para checar datas inválidas. Chama a função checkBissexto recursivamente.
{
    bool flag = false;
    bool bs = checkBissexto(anoatual);
    if ( !(dia>=1&&dia<=31) || !(mes>=1&&mes<=12) || ano>anoatual || (dia>28 && mes==2 && bs==false) || (dia>29 && mes==2) ||
        (dia>30 &&(mes!=4||mes!=6||mes!=9||mes!=11)) )
    {
        flag = true;
    }
    return (flag);
}

int checkIdade (int dia, int mes, int ano, int diaatual, int mesatual, int anoatual) //Função para calcular idade.
{
    int idade;
    idade = anoatual - ano;
    if (mesatual > mes)
    {

    }
    else if (mesatual == mes)
    {
        if (diaatual < dia)
        {
            idade--;
        }
    }
    else
    {
        idade--;
    }
    return (idade);
}

int main()
{
    setlocale(LC_ALL, "portuguese"); // permite uso de acentos (Pt-Br)

    dados lista[TAM];

    int menu=1, close=0, endprog=0, senha=0, i=0, quant=0, comorb=0;
    bool err=false;
    time_t ts;
    struct tm *ct;

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
                printf("\n QUAL OPÇÃO DESEJA ACESSAR? \n");
                scanf("%d", &menu);

                switch(menu)
                {
                case 1:
                    system("cls");

                    FILE *pont_arq;
                    FILE *com_arq;

                    printf("\n\n QUANTOS CADASTROS DESEJA REALIZAR? \n");
                    scanf("%d", &quant);

                    for(i=1; i<=quant; i++)
                    {
                        err=false;
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

                        printf("\n CEP:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf4);

                        ts = time(NULL);
                        ct = localtime(&ts);

                        do{
                            printf("\n DATA DE NASCIMENTO (DD/MM/AAAA): ");
                            fflush(stdin);
                            scanf("%d/%d/%d", &lista[i].dataD,&lista[i].dataM,&lista[i].dataA);
                            err = checkDataErr(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_year+1900);
                            if ( err == true )
                            {
                                printf("\n DATA INVÁLIDA! INSIRA NOVAMENTE!");
                            }

                        }while(err==true);

                        printf("\n E-MAIL:");
                        fflush(stdin);
                        scanf("%[^\n]s", lista[i].inf5);

                        do{
                            printf("\n DATA DE DIAGNÓSTICO (DD/MM/AAAA): ");
                            fflush(stdin);
                            scanf("%d/%d/%d", &lista[i].diagD,&lista[i].diagM,&lista[i].diagA);
                            err = checkDataErr(lista[i].diagD,lista[i].diagM,lista[i].diagA,ct->tm_year+1900);
                            if ( err == true )
                            {
                                printf("\n DATA INVÁLIDA! INSIRA NOVAMENTE!");
                            }

                        }while(err==true);

                        if(pont_arq == NULL)
                        {
                            printf("ERRO NA ABERTURA DO ARQUIVO");
                            return 1;
                        }

                        pont_arq= fopen("arquivo.txt", "a");

                        fprintf(pont_arq, "\n\n------------------------------------------\n\n");
                        fprintf(pont_arq, "\n NOME DO PACIENTE: %s\n", lista[i].inf0);
                        fprintf(pont_arq, "\n CPF: %s\n", lista[i].inf1);
                        fprintf(pont_arq, "\n TELEFONE: %s\n", lista[i].inf2);
                        fprintf(pont_arq, "\n ENDERECO: %s\n", lista[i].inf3);
                        fprintf(pont_arq, "\n CEP: %s\n", lista[i].inf4);
                        fprintf(pont_arq, "\n DATA DE NASCIMENTO: %d/%d/%d\n", lista[i].dataD,lista[i].dataM,lista[i].dataA);
                        fprintf(pont_arq, "\n IDADE: %d\n", checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900));
                        fprintf(pont_arq, "\n EMAIL: %s\n", lista[i].inf5);
                        fprintf(pont_arq, "\n DATA DO DIAGNÓSTICO: %d/%d/%d\n", lista[i].diagD,lista[i].diagM,lista[i].diagA);




                        do
                        {

                            printf("\n O PACIENTE POSSUI ALGUMA COMORBIDADE? \n");
                            printf("\t\t\t       ----------------------------\n\n");
                            printf(" 1 - SIM \n 2 - NAO");
                            printf("\n\n");
                            scanf("%d", &comorb);
                            if (checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900) >= 65 && comorb == 1)
                            {

                                printf("\n COMORBIDADES:");
                                fflush(stdin);
                                scanf("%[^\n]s", lista[i].inf7);

                                fprintf(pont_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                fclose (pont_arq);

                                com_arq= fopen("comorbidade.txt", "a");

                                fprintf(com_arq, "\n NOME DO PACIENTE: %s\n", lista[i].inf0);
                                fprintf(com_arq, "\n CEP: %s\n", lista[i].inf4);
                                fprintf(com_arq, "\n IDADE: %d\n", checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900));
                                fprintf(com_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                fprintf(com_arq, "\n\n------------------------------------------\n\n");
                                fclose (com_arq);

                            }
                            else if (checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900) >= 65 && comorb == 2)
                            {

                                strcpy(lista[i].inf7,"Grupo de Risco");

                                fprintf(pont_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                fclose (pont_arq);

                                com_arq= fopen("comorbidade.txt", "a");

                                fprintf(com_arq, "\n NOME DO PACIENTE: %s\n", lista[i].inf0);
                                fprintf(com_arq, "\n CEP: %s\n", lista[i].inf4);
                                fprintf(com_arq, "\n IDADE: %d\n", checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900));
                                fprintf(com_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                fprintf(com_arq, "\n\n------------------------------------------\n\n");
                                fclose (com_arq);

                            }
                            else
                            {
                               switch(comorb)
                                {
                                case 1:
                                    printf("\n COMORBIDADES:");
                                    fflush(stdin);
                                    scanf("%[^\n]s", lista[i].inf7);

                                    fprintf(pont_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                    fprintf(pont_arq, "\n\n------------------------------------------\n\n");
                                    fclose (pont_arq);

                                    com_arq= fopen("comorbidade.txt", "a");

                                    fprintf(com_arq, "\n NOME DO PACIENTE: %s\n", lista[i].inf0);
                                    fprintf(com_arq, "\n CEP: %s\n", lista[i].inf4);
                                    fprintf(com_arq, "\n IDADE: %d\n", checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900));
                                    fprintf(com_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                    fprintf(com_arq, "\n\n------------------------------------------\n\n");
                                    fclose (com_arq);
                                    break;

                                case 2:

                                    strcpy(lista[i].inf7,"N\\A");
                                    fprintf(pont_arq, "\n COMORBIDADE: %s\n", lista[i].inf7);
                                    fprintf(pont_arq, "\n\n------------------------------------------\n\n");
                                    fclose (pont_arq);
                                    break;




                                default:
                                    system("cls");
                                    break;
                                }
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
                        printf("\n CEP: %s\n", lista[i].inf4);
                        printf("\n DATA DE NASCIMENTO: %d/%d/%d\n", lista[i].dataD,lista[i].dataM,lista[i].dataA);
                        printf("\n IDADE: %d\n", checkIdade(lista[i].dataD,lista[i].dataM,lista[i].dataA,ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900));
                        printf("\n EMAIL: %s\n", lista[i].inf5);
                        printf("\n DATA DO DIAGNÓSTICO: %d/%d/%d\n", lista[i].diagD,lista[i].diagM,lista[i].diagA);
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

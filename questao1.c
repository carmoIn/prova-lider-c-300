//
// Created by helci on 13/07/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "questao1.h"

#define FAIXAS_ETARIAS              7

int faixasEtarias[FAIXAS_ETARIAS][2] = {
        {0, 9},
        {10, 19},
        {20, 29},
        {30, 39},
        {40, 49},
        {50, 59},
        {60, 1000}
};

char faixasEtariasDescricao[FAIXAS_ETARIAS][30] = {
        "0 a 9 anos",
        "10 a 19 anos",
        "20 a 29 anos",
        "30 a 39 anos",
        "40 a 49 anos",
        "50 a 59 anos",
        "60 anos ou mais"
};

int vacinadosFaixaEtaria[FAIXAS_ETARIAS] = {0, 0};

int calculaFaixaEtaria(int idade)
{
    for (int i = 0; i < FAIXAS_ETARIAS; i++)
    {
        if (idade >= faixasEtarias[i][0] && idade <= faixasEtarias[i][1])
        {
            return i;
        }
    }
    return FAIXAS_ETARIAS - 1;
}

void lerVacinados()
{
    system("cls");
    int diaVacinacao, mesVacinacao, anoVacinacao;
    int diaNascimento, mesNascimento, anoNascimento;
    do {
        printf("\nInforme a data da vacinacao (dm/mm/yyyy):  ");
        scanf("%d/%d/%d", &diaVacinacao, &mesVacinacao, &anoVacinacao);
        fflush(stdin);

        if (diaVacinacao != 0 && mesVacinacao != 0 && anoVacinacao != 0) {
            printf("\nInforme a data de nascimento (dm/mm/yyyy):  ");
            scanf("%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);
            fflush(stdin);

            int idade = anoVacinacao - anoNascimento;
            if (mesVacinacao < mesNascimento ||
                (mesVacinacao == mesNascimento && diaVacinacao < diaNascimento)) {
                idade--;
            }

            int faixaEtaria = calculaFaixaEtaria(idade);

            vacinadosFaixaEtaria[faixaEtaria]++;

            printf("Dose para faixa etaria %s (idade %d) salva com sucesso!",
                   faixasEtariasDescricao[faixaEtaria],
                   idade);
        }

    } while(diaVacinacao != 0 && mesVacinacao != 0 && anoVacinacao != 0);
}

void relatorioVacinados()
{
    system("cls");
    for (int i = 0; i < FAIXAS_ETARIAS; i++)
    {
        if (vacinadosFaixaEtaria[i] == 0)
        {
            printf("%s: nenhuma dose aplicada\n", faixasEtariasDescricao[i]);
        }
        if (vacinadosFaixaEtaria[i] == 1)
        {
            printf("%s: 1 dose aplicada\n", faixasEtariasDescricao[i]);
        }
        if (vacinadosFaixaEtaria[i] > 1)
        {
            printf("%s: %d doses aplicadas\n", faixasEtariasDescricao[i], vacinadosFaixaEtaria[i]);
        }
    }
    getch();
    printf("\n");
}


void questao1()
{
    int opcao;
    do {
        system("cls");
        printf("1 - Lancar Dose\n");
        printf("2 - Relatorio de doses lancadas\n");
        printf("3 - Sair\n");
        printf("\n Digite uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: lerVacinados();
                break;
            case 2 : relatorioVacinados();
                break;
        }

    } while(opcao != 3);
}

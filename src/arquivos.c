#include "arquivos.h"

#include <stdio.h>
#include <string.h>

// Função CRIAR
int comando_criar(char nome[], char texto[]) {

    FILE *arquivo;

    // Verifica se o nome e o texto foram informados
    if (nome[0] == '\0' || texto[0] == '\0') {
        printf("Nome ou texto nao informado!\n");
        return 0;
    }

    // Abre o arquivo para escrita
    arquivo = fopen(nome, "w");

    // Verifica se conseguiu criar o arquivo
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo!\n");
        return 0;
    }

    // Grava o texto dentro do arquivo
    fprintf(arquivo, "%s", texto);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Arquivo criado com sucesso!\n");

    return 1;
}


// Função CAT
int comando_cat(char nome[]) {

    FILE *arquivo;
    char texto[1000];

    // Verifica se o nome foi informado
    if (nome[0] == '\0') {
        printf("Nome do arquivo nao informado!\n");
        return 0;
    }

    // Abre o arquivo para leitura
    arquivo = fopen(nome, "r");

    // Verifica se o arquivo existe
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado!\n");
        return 0;
    }

    // Lê o conteúdo do arquivo
    while (fgets(texto, sizeof(texto), arquivo) != NULL) {
        printf("%s", texto);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("\n");

    return 1;
}
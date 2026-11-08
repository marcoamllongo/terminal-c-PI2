#include <stdio.h>
#include <string.h>
#include "arquivos.h"

// Comando CRIAR
int criar_arquivo(char nome[], char texto[]) {

    // Verifica se o nome e o texto foram informados
    if (nome[0] == '\0' || texto[0] == '\0') {
        printf("Nome ou texto nao informado!\n");
        return 0;
    }

    // Verifica se o nome possui barras
    for (int i = 0; nome[i] != '\0'; i++) {

        if (nome[i] == '/' || nome[i] == '\\') {
            printf("Nome do arquivo invalido!\n");
            return 0;
        }
    }

    // Abre o arquivo para escrita
    FILE *arquivo = fopen(nome, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo!\n");
        return 0;
    }

    // Grava o texto no arquivo
    if (fputs(texto, arquivo) == EOF) {
        printf("Erro ao escrever no arquivo!\n");
        fclose(arquivo);
        return 0;
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Arquivo criado com sucesso!\n");

    return 1;
}


// Comando CAT
int cat_arquivo(char nome[]) {

    // Verifica se o nome foi informado
    if (nome[0] == '\0') {
        printf("Nome do arquivo nao informado!\n");
        return 0;
    }

    // Abre o arquivo para leitura
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado!\n");
        return 0;
    }

    // Mostra o conteudo do arquivo
    int caractere;

    while ((caractere = fgetc(arquivo)) != EOF) {
        printf("%c", caractere);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("\n");

    return 1;
}

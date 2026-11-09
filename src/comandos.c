#include "comandos.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    const char *nome;
    const char *descricao;
    const char *sintaxe;
    const char *exemplo;
} Comando;

static const Comando comandos[] = {
    {"ajuda", "Lista os comandos ou mostra a ajuda de um comando.",
     "ajuda [comando]", "ajuda cesar"},
    {"sair", "Encerra o programa.",
     "sair", "sair"},
    {"ec", "Exibe um texto na tela.",
     "ec <texto>", "ec ola mundo"},
    {"criar", "Cria um arquivo com o texto informado.",
     "criar <arquivo> <texto>", "criar msg.txt ola"},
    {"cat", "Mostra o conteudo de um arquivo.",
     "cat <arquivo>", "cat msg.txt"},
    {"cesar", "Cifra ou decifra texto ou arquivo com a cifra de Cesar.",
     "cesar cifrar -t <texto> <deslocamento>\n"
     "cesar cifrar -f <arquivo> <deslocamento>\n"
     "cesar decifrar -t <texto> <deslocamento>\n"
     "cesar decifrar -f <arquivo> <deslocamento>",
     "cesar cifrar -t ABC 3  -> DEF\n"
     "cesar decifrar -t DEF 3  -> ABC"}
    /* A2: registrar, login, logout, quem-sou e a segunda cifra */
};

static const size_t quantidade_comandos = sizeof(comandos) / sizeof(comandos[0]);

static int texto_vazio(const char *texto) {
    if (texto == NULL) return 1;
    while (*texto != '\0') {
        if (*texto != ' ' && *texto != '\t' && *texto != '\n' && *texto != '\r')
            return 0;
        texto++;
    }
    return 1;
}

int comando_ajuda(const char *args) {
    size_t i;
    size_t tamanho = 0;

    if (texto_vazio(args)) {
        puts("Comandos disponiveis:");
        for (i = 0; i < quantidade_comandos; i++)
            printf("  %-12s %s\n", comandos[i].nome, comandos[i].descricao);
        puts("Use 'ajuda <comando>' para ver a sintaxe e exemplos.");
        return 0;
    }

    while (*args == ' ' || *args == '\t')   /* pula espacos do inicio */
        args++;

    /* mede a primeira palavra (ignora o que vier depois dela) */
    while (args[tamanho] != '\0' && args[tamanho] != ' ' && args[tamanho] != '\t')
        tamanho++;

    for (i = 0; i < quantidade_comandos; i++) {
        if (strlen(comandos[i].nome) == tamanho &&
            strncmp(args, comandos[i].nome, tamanho) == 0) {
            printf("%s\nSintaxe:\n%s\nExemplo(s):\n%s\n",
                   comandos[i].descricao,
                   comandos[i].sintaxe,
                   comandos[i].exemplo);
            return 0;
        }
    }

    puts("Erro: comando desconhecido.");
    return 1;
}

int comando_ec(const char *args) {
    if (texto_vazio(args)) {
        puts("Erro: falta informar o texto.");
        return 1;
    }

    puts(args);
    return 0;
}
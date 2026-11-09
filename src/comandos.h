int comando_ajuda(const char *args);
int comando_ec(const char *args);

#ifndef COMANDOS_H
#define COMANDOS_H

/*
 * Mostra a lista de comandos quando args for NULL ou vazio.
 * Quando receber um nome, mostra a descricao, a sintaxe e exemplos daquele comando.
 * Retorna 0 em caso de sucesso e 1 se o comando for desconhecido.
 */
int comando_ajuda(const char *args);

/* Imprime o texto recebido. Retorna 0 em caso de sucesso e 1 se estiver vazio. */
int comando_ec(const char *args);

#endif
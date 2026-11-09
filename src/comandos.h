int comando_ajuda(const char *args);
int comando_ec(const char *args);

#ifndef COMANDOS_H
#define COMANDOS_H

/*
 * Mostra a lista de comandos quando nome_comando for NULL ou vazio.
 * Quando receber um nome, mostra a sintaxe e exemplos daquele comando.
 * Comando desconhecido gera uma mensagem informativa.
 */
void comando_ajuda(const char *nome_comando);

/* Imprime o texto recebido. Retorna 0 em caso de sucesso e 1 se estiver vazio. */
int comando_ec(const char *texto);

#endif
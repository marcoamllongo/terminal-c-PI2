# terminal-c-PI2
Terminal simplificado desenvolvido em C para o Projeto Integrador II da PUC-Campinas, com comandos personalizados e cifras clássicas.

# Modulo de ajuda e exibicao de texto

Os arquivos `comandos.c` e `comandos.h` implementam os comandos `ajuda` e `ec` para o terminal do Projeto Integrador II.

## Interface

- `int comando_ajuda(const char *args)`: com `NULL` ou texto vazio, lista os comandos disponiveis; com um nome (ex.: `cesar`), mostra descricao, sintaxe e exemplos. Considera apenas a primeira palavra de `args`. Retorna `0` em caso de sucesso e `1` se o comando nao existir (`Erro: comando desconhecido.`).
- `int comando_ec(const char *args)`: exibe o texto seguido de quebra de linha. Retorna `0` quando exibe e `1` quando o texto esta ausente (`Erro: falta informar o texto.`).

## Integracao no interpretador

Depois de separar a linha digitada em nome do comando e argumentos (`args` e o texto depois do nome, sem espacos no inicio):

```c
if (strcmp(nome, "ajuda") == 0) {
    comando_ajuda(args);   /* "" se nao houver argumento */
} else if (strcmp(nome, "ec") == 0) {
    comando_ec(args);      /* ex.: "ola mundo" */
}
```

Exemplos: `ajuda cesar` chama `comando_ajuda("cesar")`; `ec ola mundo` chama `comando_ec("ola mundo")`. O interpretador deve preservar todo o texto depois de `ec`.

## Compilacao

```sh
gcc -std=c11 -Wall -Wextra -pedantic main.c comandos.c arquivos.c cesar.c -o terminal
```

## Comandos documentados na ajuda (A1)

`ajuda`, `sair`, `ec`, `criar`, `cat` e `cesar`. Os comandos da A2 (usuarios e segunda cifra) serao acrescentados a tabela em `comandos.c` quando forem implementados.
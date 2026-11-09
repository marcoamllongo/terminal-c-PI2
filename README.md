# terminal-c-PI2
Terminal simplificado desenvolvido em C para o Projeto Integrador II da PUC-Campinas, com comandos personalizados e cifras clássicas.

Modulo de ajuda e exibicao de texto

Os arquivos `comandos.c` e `comandos.h` implementam os comandos `ajuda` e `ec` para integracao ao terminal do Projeto Integrador II.

## Interface

- `void comando_ajuda(const char *nome_comando)`: com `NULL` ou texto vazio, lista os comandos; com um nome, mostra sintaxe e exemplo; se o nome nao existir, informa `Comando desconhecido.`
- `int comando_ec(const char *texto)`: exibe o texto seguido de quebra de linha. Retorna `0` quando exibe e `1` quando o texto esta ausente.

## Integracao no interpretador

Depois de separar a linha digitada em comando e argumentos:

```c
#include "comandos.h"
#include <string.h>

if (strcmp(comando, "ajuda") == 0) {
    comando_ajuda(argumento_opcional); /* NULL se nao houver argumento */
} else if (strcmp(comando, "ec") == 0) {
    comando_ec(argumento_completo); /* ex.: "ola mundo" */
}
```

O interpretador deve juntar e preservar todo o texto depois de `ec`. Assim, `ec ola mundo` deve chamar `comando_ec("ola mundo")`. Para `ajuda cesar`, deve chamar `comando_ajuda("cesar")`.

## Compilacao

Compile `comandos.c` junto com o arquivo principal do terminal:

```sh
gcc -std=c11 -Wall -Wextra -pedantic main.c comandos.c -o terminal
```

A lista de comandos documentados segue o plano da atividade. Os comandos de outras partes do grupo precisam ser implementados pelos respectivos responsaveis.

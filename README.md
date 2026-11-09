# Terminal em C

Interpretador de comandos simplificado, desenvolvido em **linguagem C**, com foco em modularidade, manipulação de arquivos, criptografia clássica e organização de software.

O projeto busca reproduzir funcionalidades básicas de um terminal, permitindo que o usuário execute diferentes operações por meio de comandos de texto.

## Visão geral

O programa utiliza uma interface de linha de comando (CLI), na qual o usuário digita instruções que são interpretadas e encaminhadas para suas respectivas funções.

O terminal permanece em execução até receber o comando `sair`.

A arquitetura foi organizada em módulos independentes, permitindo desenvolver, testar e modificar funcionalidades sem concentrar toda a lógica em um único arquivo.

## Funcionalidades

O projeto contempla os seguintes comandos:

| Comando | Descrição |
|---|---|
| `ajuda` | Lista os comandos disponíveis |
| `ajuda <comando>` | Exibe instruções de utilização |
| `sair` | Encerra o terminal |
| `ec <texto>` | Exibe um texto na tela |
| `criar <arquivo> <texto>` | Cria ou sobrescreve um arquivo |
| `cat <arquivo>` | Exibe o conteúdo de um arquivo |
| `cesar cifrar` | Realiza a cifragem de textos ou arquivos |
| `cesar decifrar` | Realiza a decifragem de textos ou arquivos |

A cifra de César utiliza um deslocamento de 0 a 25 posições no alfabeto e permite trabalhar com textos (`-t`) ou arquivos (`-f`).

**Observação:** as funcionalidades estão em diferentes etapas de desenvolvimento e integração. A tabela representa o conjunto de comandos previsto para o terminal.

## Arquitetura

O projeto adota uma estrutura modular, com responsabilidades distribuídas entre os componentes.

```text
terminal-c-PI2/
├── src/
│   ├── main.c
│   ├── comandos.c
│   ├── comandos.h
│   ├── arquivos.c
│   ├── arquivos.h
│   ├── cesar.c
│   ├── cesar.h
│   ├── validacoes.c
│   └── validacoes.h
├── .gitignore
└── README.md
```

*A estrutura representa a organização prevista. Alguns arquivos de implementação ainda estão em desenvolvimento ou aguardando integração à branch principal.*

### Responsabilidades dos módulos

| Módulo | Responsabilidade |
|---|---|
| `main.c` | Leitura, interpretação e direcionamento dos comandos |
| `comandos.c` | Comandos de ajuda e exibição de texto |
| `arquivos.c` | Criação e leitura de arquivos |
| `cesar.c` | Implementação da cifra de César |
| `validacoes.c` | Validação de entradas e parâmetros |

Os arquivos `.h` definem as interfaces entre os módulos, enquanto os arquivos `.c` contêm suas implementações.

### Princípios de desenvolvimento

A arquitetura prioriza:

- **Alta coesão:** cada módulo possui responsabilidades bem definidas.
- **Baixo acoplamento:** comunicação por interfaces, reduzindo dependências desnecessárias.
- **Simplicidade:** soluções claras, sem abstrações excessivas.
- **Manutenibilidade:** facilidade de testar, corrigir e expandir funcionalidades.

## Compilação e execução

### Requisitos

- Compilador GCC ou equivalente.
- Terminal de comandos (PowerShell, Bash ou similar).

### Clonar o repositório

```bash
git clone https://github.com/marcoamllongo/terminal-c-PI2.git
cd terminal-c-PI2
```

### Compilar a versão básica

Enquanto os módulos não estiverem integrados à branch principal:

```bash
gcc src/main.c -o terminal
```

**Windows:**

```powershell
.\terminal.exe
```

**Linux:**

```bash
./terminal
```

Esse procedimento executa o núcleo básico presente na branch `main`. A compilação completa utilizará os demais arquivos `.c` após a integração.

## Estado do desenvolvimento

O projeto está em desenvolvimento ativo.

**Implementado ou publicado:**
- Estrutura inicial do repositório e organização dos módulos.
- Laço principal de execução do terminal.
- Interpretador de comandos publicado em branch de desenvolvimento.
- Implementações iniciais de ajuda, exibição de texto e manipulação de arquivos submetidas por Pull Requests.

**Em andamento:**
- Padronização das interfaces entre módulos.
- Integração das funções ao interpretador.
- Implementação e integração da cifra de César.
- Testes de funcionamento e tratamento de erros.

## Próximos passos

A evolução do projeto prevê:

- Consolidação e testes dos comandos existentes.
- Cadastro e autenticação de usuários.
- Gerenciamento de sessões (`login`, `logout` e `quem-sou`).
- Implementação de uma segunda cifra clássica.
- Ampliação das validações e do tratamento de erros.
- Refinamento da documentação e dos testes de integração.

## Desenvolvimento colaborativo

O desenvolvimento é realizado em equipe, com divisão de responsabilidades entre cinco colaboradores.

Utilizamos **Git e GitHub** para controle de versão. Novas funcionalidades são desenvolvidas em branches separadas e submetidas por Pull Requests antes da integração à `main`.

Essa abordagem permite acompanhar a evolução do código, revisar alterações e reduzir problemas de integração.

---

**Nota:** as cifras clássicas utilizadas neste projeto têm finalidade demonstrativa e não são adequadas para proteger informações sensíveis em aplicações reais.
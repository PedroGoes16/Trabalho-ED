# Trabalho ED - Sistema de Busca de Departamentos

Este projeto foi desenvolvido como atividade da disciplina de Estrutura de Dados.
O programa carrega informacoes de departamentos a partir de um arquivo `.txt` e permite consultar os dados por palavra-chave ou pelo nome do departamento.

## Objetivo

O objetivo do codigo e praticar o uso de estruturas de dados simples em C++, principalmente:

- `struct`
- `vector`
- vetores/arrays
- leitura de arquivos com `ifstream`
- menu interativo no terminal

## Estrutura de Dados Utilizada

A principal estrutura usada no projeto e a `struct Departamento`.

```cpp
struct Departamento {
    string codigo;
    string nome;
    string palavrasChave[5];
};
```

Ela representa um departamento da empresa e guarda tres tipos de informacao:

- `codigo`: identificador do departamento.
- `nome`: nome do departamento.
- `palavrasChave[5]`: lista com 5 palavras-chave relacionadas ao departamento.

Para armazenar todos os departamentos lidos do arquivo, foi utilizado um `vector`:

```cpp
vector<Departamento> departamentos;
```

O `vector` foi escolhido porque permite guardar varios departamentos em sequencia e acessar cada um deles usando um indice. Diferente de um vetor comum com tamanho fixo, o `vector` pode crescer conforme os dados sao carregados do arquivo.

## Como o Arquivo de Dados Deve Estar Organizado

O programa espera que o arquivo `.txt` tenha uma linha para cada departamento.

Cada linha deve seguir este formato:

```txt
codigo nome palavra1 palavra2 palavra3 palavra4 palavra5
```

Exemplo:

```txt
001 FINANCEIRO INVESTIMENTO RENDA GASTOS DESPESAS LUCRO
008 ADMINISTRATIVO MANUAL ORGANIZACAO ORGANOGRAMA SUPERVISAO GERENCIA
```

Importante: como o programa usa `cin` e `ifstream` com separacao por espacos, nomes compostos nao devem ter espaco. Por exemplo, use `RECURSOS_HUMANOS` em vez de `RECURSOS HUMANOS`.

## Funcionalidades

O programa possui um menu com as seguintes opcoes:

```txt
1 - Pesquisar por palavra-chave
2 - Pesquisar por departamento
3 - Exibir todos os departamentos
0 - Sair
```

### 1. Pesquisar por palavra-chave

O usuario digita uma palavra-chave, e o programa percorre todos os departamentos procurando essa palavra entre as 5 palavras-chave cadastradas.

Se encontrar, mostra o nome do departamento correspondente.

### 2. Pesquisar por departamento

O usuario digita o nome de um departamento, e o programa procura esse nome no `vector`.

Se encontrar, mostra:

- codigo identificador
- palavras-chave relacionadas ao departamento

### 3. Exibir todos os departamentos

Mostra todos os departamentos carregados do arquivo, incluindo codigo, nome e palavras-chave.

## Como Usar o Codigo

### 1. Compilar o programa

No terminal, dentro da pasta do projeto, execute:

```bash
g++ main.cpp -o main.exe
```

### 2. Executar o programa

Depois de compilar, execute:

```bash
./main.exe
```

No Windows PowerShell, tambem pode ser:

```powershell
.\main.exe
```

### 3. Informar o nome do arquivo

Ao iniciar, o programa vai pedir o nome do arquivo:

```txt
Digite o nome do arquivo:
```

Digite:

```txt
departamentos.txt
```

Depois disso, o menu sera exibido e o usuario podera escolher a opcao desejada.

## Observacao Sobre Acentos

O codigo configura o console do Windows para trabalhar com UTF-8:

```cpp
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
```

Isso ajuda a exibir caracteres especiais e acentos corretamente no terminal.

## Arquivos do Projeto

- `main.cpp`: codigo-fonte principal do programa.
- `departamentos.txt`: arquivo com os dados dos departamentos.
- `README.md`: explicacao do projeto.

## Autor

Pedro Goes

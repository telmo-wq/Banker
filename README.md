# 🏦Algoritmo de banqueiro (Banker) em C

Este repositório contém o código de uma implementação do algoritmo do banker, um algoritmo clássico para a prevenção de deadlocks em sincronização de processos, conforme proposto como projeto no livro Operating Systems Conceps, de Abraham Silberschatz, Peter Gavin e Greg Gagne

Conforme proposto no livro, o algoritmo aqui funciona a partir de um input fornecido via linha de comando e especificado em arquivos .txt. Na linha de comando, são especificados quantos recursos serão disponibilizados aos clientes e quantas instâncias cada um terá. A partir dele, o código lê os arquivos commands.txt e customer.txt - o primeiro contém as operações de RQ (alocação de recursos em um customer x), RL (liberação de recursos usados por customer x) e * (imprimir os status de cada customer), e o sgundo especifica a quantidade de recursos máxima que cada cliente pode pedir. Dentro desse repositório, os arquivos já veem preenchidos com valores de exemplos

Ao final, o programa registra todas as saídas em um result.txt gerado por ele mesmo

## 📖Conteúdo

Os arquivos contidos são:
- Banker.c: Arquivo com a função main principal

- Biblioteca.h: Arquivo header que define a biblioteca com as funções usadas

- Ler_comandos.c: Coração do algoritmo, contém a função que ler commands.txt e customer.txt linha por linha e escreve no result.txt as operações de RQ e RL

- Imprimir_status.c: Responsável pela operação * de exibir os status dos recursos max, allocation e need em tabela

- Contar_clientes.c: Pequena função auxiliar que retorna o número de clientes em customer.txt

- Is_safe.c: Função responsável pelo RQ, simula se a alocação de recursos é segura para os clientes

- Commands.txt: Contém os comandos requisitados para uso ou liberação de recursos

- Customer.txt: Define os números máximos de cada instância de recurso para cada cliente

- Result.txt: Arquivo gerado no final com a saída de cada operação em commands.txt

- Makefile: Arquivo que automatiza a compilação com make


## ✍️Como reproduzir

Clonando o repositório e acessando o diretório, compile:

```
cd Banker
make clean
make
```

Para executar, digite

```
./banker 10 5 7
```

Onde 10, 5 e 7 são valores das instâncias (decididos pelo usuário)

Este código foi escrito por Telmo Melo (telmo-wq) em um sistema Fedora Linux



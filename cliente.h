#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Local para armazenar os dados fornecidos pelo usuario
*/
typedef struct Cliente {
  char nome[50];
  char endereco[100];
  int ID;

}Cliente;

// Função para ler e armazenar os dados fornecidos em um arquivo de texto.
Cliente *lerClientes(char *nomeArquivo, int *numClientes);

/*
Função onde serão feitas escolhas pelo usuario 
como cadastro e ordenação dos clientes
*/
void Menu(Cliente *cliente, int *opc);

/*
Função onde serão recebidos os dados principais do usuario
para cadastro do cliente na ordenação
*/
void Dados_Cliente(Cliente *cliente, int numClientes);

/*
Função principal para ordenação dos clientes presentes no arquivo .txt
*/
void ShellSort(Cliente *arr, int cont);

/*

*/
void Ordena_Cliente(FILE *arquivo, int numClientes);

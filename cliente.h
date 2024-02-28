#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Local para armazenar os dados fornecidos pelo usuario
*/
struct Cliente cliente;

/*
Função onde serão feitas escolhas pelo usuario 
como cadastro e ordenação dos clientes
*/
void Menu(Cliente *cliente, int *opc);

/*
Função onde serão recebidos os dados principais do usuario
para cadastro do cliente na ordenação
*/
void Dados_Cliente(Clinete *cliente, int *numClientes);

/*
Função principal para ordenação dos clientes presentes no arquivo .txt
*/
void ShellSort(FILE *arquivo, int cont);


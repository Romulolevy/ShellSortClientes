#include "cliente.h"
#include <stdlib.h>

typedef struct cliente {
  char nome[50];
  char endereco[100];
  int ID;

}Cliente;

int VerificaDados(const char *str) {
  while (*str){
    if (!((*str >= 'a' && *str <='z') || (*str >= 'A' && <= 'Z') || *str == '')) {
      return 1;
    }
    str++;
  }
  return 0;
}

void Imprimir_Clientes(Cliente *cliente, int numClientes){
  for(int i = 0; i < numClientes; i++){
    printf("ID: %d, Nome: %s, Endereco: %s\n", cliente->ID, cliente->nome, cliente->endereco); 
  }
}

void Menu (Cliente *cliente, int *opc) {
system("clear");
printf("----------- Seja bem Vindo -----------");
printf("Oque deseja fazer: (1)- Cadastrar Cliente: \n (2)- Mostrar Ordenacao \n (3)- Sair \n");
scanf("%d", opc);
}

// Função para inserir dados dos clientes 
void Dados_Cliente (Cliente *cliente, int numClientes){
  int validarDados;

int novoID;
printf("Insforme um ID para o cliente: \n");
scanf("%d", &novoID);
// Tratativa para verificar existencia de um ID parecido
for (int i = 0; i < numClientes; i++) {
  if (cliente[i].ID == novoID){
    printf("ID ja existente, Insira um novo ID: \n");
    scanf("%D", novoID);
    i = -1;
  }
}
cliente[numClientes].ID = novoID;

  do {
    validarDados = 1;
    printf("Informe nome Cliente: \n");
    scanf(" %[^\n]", cliente[numClientes].nome);
// Tratativa para nao inserir numeros no nome do cliente
    if(verificar_Dados(cliente[numClientes].nome)){
      printf("Usuario nao pode conter numeros! \n");
      validarDados = 0;
    }

  } while (!validarDados);

printf("Insira o Endereco: \n");
scanf(" %[^\n]", cliente[numClientes].endereco);

FILE *arquivo;
arquivo = fopen("clientes.txt", "a+");
fprintf(arquivo, "ID: %d\t Nome: %s\t Endereco: %s\n", cliente[numClientes].ID cliente[numClientes].nome cliente[numClientes].endereco);
fclose(arquivo);
}

// Funcao principal para ordenar os clientes dentro do arquivo
void ShellSort(FILE *arquivo, int cont) {

  // Loop para dividir o array em subconjuntos de tamanho decrescente
  for (int intervalo = cont / 2; intervalo > 0; intervalo /= 2) {

    // Loop para ordenar cada subconjunto usando o método de inserção
    for (int i = intervalo; i < cont; i += 1) {

    
      Cliente *lerClientes(char *nomeArquivo, int *numClientes) {
  FILE *arquivo = fopen(nomeArquivo, "a+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
    exit(1);
  }

  int contador = 0;
  char linha[150];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    contador++;
  }
  rewind(arquivo);
  contador /= 2;

  Cliente *clientes = (Cliente *)calloc(contador,sizeof(Cliente));
  if (clientes == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }

  for (int i = 0; i < contador; i++) {
    if (fscanf(arquivo, "%d %49[^\n] %99[^\n]", &clientes[i].ID,clientes[i].nome, clientes[i].endereco) != 3) {
    }
  }

  fclose(arquivo);
  *numClientes = contador;
  return clientes;
}

    }
  }
}

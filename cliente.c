#include "cliente.h"
#include <stdlib.h>
#include <string.h>

int VerificaDados(const char *str) {
  while (*str){
    if (!((*str >= 'a' && *str <='z') || (*str >= 'A' && *str <= 'Z') || *str == ' ')) {
      return 1;
    }
    str++;
  }
  return 0;
}

Cliente *lerClientes(char *nomeArquivo, int *numClientes) {
  FILE *arquivo = fopen(nomeArquivo, "r");
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
    if (fscanf(arquivo, "%d %49[^\n] %99[^\n]", &clientes[i].ID, clientes[i].nome, clientes[i].endereco) != 3) {
    }
  }

  fclose(arquivo);
  *numClientes = contador;
  return clientes;
}

void Imprimir_Clientes(Cliente *cliente, int numClientes){
  for(int i = 0; i < numClientes; i++){
    printf("ID: %d, Nome: %s, Endereco: %s\n", cliente->ID, cliente->nome, cliente->endereco); 
  }
}

void Menu(Cliente *cliente, int *opc) {
system("cls");
printf("----------- Seja bem Vindo -----------\n");
printf("Oque deseja fazer:\n (1)- Cadastrar Cliente: \n (2)- Mostrar Ordenacao \n (3)- Sair \n");
scanf("%d", opc);
}

// Função para inserir dados dos clientes 
void Dados_Cliente(Cliente *cliente, int numClientes){
  int validarDados;

int novoID;
printf("Insforme um ID para o cliente: \n");
scanf("%d", &novoID);
// Tratativa para verificar existencia de um ID parecido
for (int i = 0; i < numClientes; i++) {
  if(isalpha(cliente[i].ID)){
    printf("ID inserido nao e um numero valido: \n");
    scanf("%d", novoID);
    i = -1;
  }
  if (cliente[i].ID == novoID){
    printf("ID ja existente, Insira um novo ID: \n");
    scanf("%d", novoID);
    i = -1;
  }
}
cliente[numClientes].ID = novoID;

  do {
    validarDados = 1;
    printf("Informe nome Cliente: \n");
    scanf(" %[^\n]", cliente[numClientes].nome);
// Tratativa para nao inserir numeros no nome do cliente
    if(VerificaDados(cliente[numClientes].nome)){
      printf("Usuario nao pode conter numeros! \n");
      validarDados = 0;
    }

  } while (!validarDados);

printf("Insira o Endereco: \n");
scanf(" %[^\n]", cliente[numClientes].endereco);

FILE *arquivo;
arquivo = fopen("clientes.txt", "a+");
fprintf(arquivo, "ID: %d\t Nome: %s\t Endereco: %s\n", cliente[numClientes].ID, cliente[numClientes].nome, cliente[numClientes].endereco);
fclose(arquivo);
}

void ShellSort(Cliente *arr, int cont) {
  printf(arr);
  for (int intervalo = cont / 2; intervalo > 0; intervalo /= 2) {
    for (int i = intervalo; i < cont; i += 1) {
      Cliente temp = arr[i];
      int j;
      for (j = i; j >= intervalo && arr[j - intervalo].ID > temp.ID; j -= intervalo) {
        arr[j] = arr[j - intervalo];
      }
      arr[j] = temp;
    }
  }
}

void Ordena_Cliente(FILE *arquivo, int numClientes){
Cliente *cliente = (Cliente *)malloc((numClientes + 1) * sizeof(Cliente));
if (cliente == NULL){
  printf("Erro ao alocar memoria. \n");
  exit(EXIT_FAILURE);
}

int j = 0;
while(fscanf(arquivo, " %[^\n]; %[^\n]; %d\n", cliente[j].nome, cliente[j].endereco, &cliente[j].ID) == 3){
  j++;
}

Cliente lerClientes("clientes.txt", numClientes);
cliente[j] = *Dados_Cliente(Ler, numClientes);
j++;
ShellSort(cliente, j);

arquivo = fopen("clientes.txt", "w");

if (arquivo == NULL){
 printf("Erro ao abrir o arquivo para escrita.\n");
  exit(EXIT_FAILURE);
}
for (int i = 0; i < j; i++) {
  fprintf(arquivo, "%s;%s;%d\n", cliente[i].nome, cliente[i].endereco, cliente[i].ID);
  }

  fclose(arquivo);


}

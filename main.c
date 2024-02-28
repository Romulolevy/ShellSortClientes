#include "cliente.h"

// Comandos para execução
/*

gcc -c main.c
gcc -c cliente.c
gcc -o executavel.exe cliente.o main.o
./executavel.exe

*/

int main(){
FILE *arquivo = fopen("clientes.txt", "at");
if(arquivo == NULL){
    printf("Erro na execucao clientes.txt\n");
    return 1;
}

fclose(arquivo);

int numClientes;
struct Cliente *cliente = lerClientes("clientes.txt", &numClientes);

int opc, continua = 1;
while(continua){

    Menu(cliente, &opc);

    switch(opc){
case 1:
printf("Informe os Dados do novo Cliente: \n");
Dados_Cliente(cliente, numClientes);
numClientes++;
break;

case 2:
ShellSort(cliente, numClientes);
Imprimir_Clientes(cliente, numClientes);

break;

case 3:
    printf("Encerrando programa ... \n");
    return 0;
default:
    printf("Opção invalida! \n");
    }

}

free(cliente);

    return 0;
}

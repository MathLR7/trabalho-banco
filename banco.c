/*Bom dia, boa tarde, boa noite, professor! Facilitarei sua correcao, o meu trabalho esta incompleto nos
seguintes pontos:
-nao linkados a nenhum arquivo de texto, entao quando fecha o programa, encerra os clientes e operacoes
-faltam as funcoes que: apresentam as operacoes feitas, salva o conteudo nos txts, verifica o extrato, e 
exclui os clientes
-outros detalhes menores pedidos que nao conseguirei listar aqui
Sinto muito por nao ter feito de modo completo, pois seria um trabalho bem legal de se fazer, de qualquer
modo, boa correcao e bom descanso nas ferias*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nome[50];
        int codigo;
        double saldo;
} Cliente;

typedef struct{
    int codCliente_origem;
    int codCliente_destino;
    int tipoOp;
    double valor;
} Operacoes;

Cliente** listaClientes;
int contaClientes=0;


/*void lertxt(){
    FILE *arq;
    arq = fopen("clientes.txt","rt");
    if(arq=NULL){
        printf("Nao ha arquivo de clientes, um novo será criado\n");
        system("pause");
        return;
    }


}*/

void cadastraCliente(){

    char nome[50];
	double saldo;
	printf("Digite o nome do novo cliente: ");
	fgets(nome, 49, stdin);
	strtok(nome, "\n");

	printf("Digite o saldo do novo cliente: ");
	scanf("%lf",&saldo);

	listaClientes = realloc(listaClientes, (contaClientes+1)*sizeof(Cliente*));
	listaClientes[contaClientes] = malloc(sizeof(Cliente));
	strcpy(listaClientes[contaClientes]->nome,nome);
	listaClientes[contaClientes]->saldo = saldo;
    listaClientes[contaClientes]->codigo = contaClientes+1;
	contaClientes++;
	system("pause");

}

void depositaFundos(int codcli){
    double quantia;
    printf("Insira o valor a ser depositado:");
    fflush(stdin);
	scanf("%lf", &quantia);
	fflush(stdin);
    if(quantia>0){
        listaClientes[codcli-1]->saldo += quantia;
        printf("Valor depositado com sucesso!\n");
        system("pause");
    }
    else{
        printf("Valor nao depositavel, operacao cancelada\n");
        system("pause");
    }
}

void sacarFundos(int codcli){
    double quantia;
    printf("Insira o valor a ser sacado:");
    fflush(stdin);
	scanf("%lf", &quantia);
	fflush(stdin);
    if(quantia>0 && listaClientes[codcli-1]->saldo>=quantia){
        listaClientes[codcli-1]->saldo -= quantia;
        printf("Valor sacado com sucesso!\n");
        system("pause");
    }
    else{
        printf("Valor nao sacavel, operacao cancelada\n");
        system("pause");
    }
}

void mostraSaldo(int codcli){
    printf("Esta conta apresenta saldo de R$%.2lf\n",listaClientes[codcli-1]->saldo);
    system("pause");
}

void transfereFundos(int codcli){
    printf("Digite o numero da conta para qual deseja fazer a transferencia:");
    int contadestino;
    fflush(stdin);
	scanf("%d", &contadestino);
	fflush(stdin);

    double quantia;
    printf("Insira o valor a ser transferido:");
    fflush(stdin);
	scanf("%lf", &quantia);
	fflush(stdin);

    if(quantia>0 && listaClientes[codcli-1]->saldo>=quantia){
        listaClientes[codcli-1]->saldo -= quantia;
        listaClientes[contadestino-1]->saldo += quantia;
        printf("Valor transferido com sucesso!\n");
        system("pause");
    }
    else{
        printf("Valor nao transferivel, operacao cancelada\n");
        system("pause");
    }
}

void menuCliente(){
    
    int option = 0;
    int exit= 0;
    int codcli;
    printf("\nInforme o codigo do cliente: ");
    fflush(stdin);
	scanf("%d", &codcli);
	fflush(stdin);
    if(codcli<=0||codcli>contaClientes+1){
        printf("Cliente inexistente, voce sera retornado para o menu inicial\n");
        system("pause");
        return;
    }
    


    do{

        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1. Depositar fundos\n");
        printf("2. Transferir fundos\n");
        printf("3. Sacar fundos\n");
        printf("4. Mostrar saldo\n");
        printf("5. Mostrar extrato **operacao indisponivel no momento, favor dirigir-se ao caixa ao lado**\n");
        printf("6. Excluir cliente **operacao indisponivel no momento, favor dirigir-se ao caixa ao lado**\n");
        printf("7. Voltar ao menu anterior\n");


        fflush(stdin);
		scanf("%d", &option);
		fflush(stdin);

        switch (option){
            case 1:
                depositaFundos(codcli);
            break;
        
            case 2:
                transfereFundos(codcli);
            break;

            case 3:
                sacarFundos(codcli);
            break;
            
            case 4:
                mostraSaldo(codcli);
            break;

            case 5:
                //mostraExtrato();
                printf("\nOperacao indisponivel no momento, dirija-se ao caixa ao lado\n");
                system("pause");
            break;

            case 6:
                //excluiCliente(codcli);
                printf("\nOperacao indisponivel no momento, dirija-se ao caixa ao lado\n");
                system("pause");
            break;

            case 7:
                exit=1;
            break;

            default:
                printf("\nDigite um numero valido!\n");
                system("pause");
            break;
        } 
    }while(exit==0);
}

void menuGeral(){

    int option = 0;
    int exit= 0;


    do{

        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1. Cadastra Cliente\n");
        printf("2. Seleciona Cliente\n");
        printf("3. Historico de todas operacoes  **indisponivel ERROR 501**\n");
        printf("4. Salvar Dados **indisponivel ERROR 501**\n");
        printf("9. Sair\n");

        fflush(stdin);
		scanf("%d", &option);
		fflush(stdin);

        switch (option){
            case 1:
                cadastraCliente();
            break;
        
            case 2:
                menuCliente();
            break;

            case 3:
                //mostraTodasOperacoes();
                printf("https://github.com/MathLR7/P3/blob/main/ERROR\n");
                system("pause");
            break;
            
            case 4:
                //salvarData();
                printf("https://github.com/MathLR7/P3/blob/main/ERROR\n");
                system("pause");
            break;

            case 9:
                exit=1;
            break;

            default:
                printf("\nDigite um numero valido!\n\n");
            break;
        } 
    }while(exit==0);
}

int main(){
    //lertxt();
    system("cls");
    printf("Bem vindo ao banco que nem existe e ja eh melhor que a Caixa\n\n");
    system("pause");
    menuGeral();

    return 0;
}
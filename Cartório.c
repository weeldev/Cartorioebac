#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aplica��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	FILE *file; //Cria o arquivo
	
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, "\nCPF: "); //Texto para cadastro do CPF
	fprintf(file,cpf); //Salve o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar as informa��es
	fprintf(file, "\nNOME: "); //Salvar o arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
			
	system("pause");
}
	
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[250];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, usu�rio n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}	
}		

	
int main()
	{
	int opcao=0; //Difinindo as vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{	
		system("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Final do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Responsavel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;
		} //fimda sele��o
		}
	}

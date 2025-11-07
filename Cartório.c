#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de aplicação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	FILE *file; //Cria o arquivo
	
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file, "\nCPF: "); //Texto para cadastro do CPF
	fprintf(file,cpf); //Salve o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar as informações
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
		printf("Não foi possivel abrir o arquivo, usuário não localizado!\n");
	}
	
	printf("\nEssas são as informações do usuário: \n");
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}	
}		

	
int main()
	{
	int opcao=0; //Difinindo as variáveis 
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(x=1;x=1;)
		{	
			system("cls"); //Responsável por limpar a tela
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //Final do menu
		
			scanf("%d", &opcao); //Armazenando a escolha do usuário
			
			system("cls"); //Responsavel por limpar a tela
			
			switch(opcao)
			{
				case 1:
				registro(); //Chamada de funções
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; // Quebra o codigo e faz sair do sistema
				break;
				
				default:
				printf("Essa opção não está disponivel\n");
				system("pause");
				break;
			} //fim da seleção
		}
	}
	
	else 
		printf("Senha incorreta!");
}


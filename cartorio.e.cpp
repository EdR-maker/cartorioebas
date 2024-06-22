#include <stdio.h> //blibioteca de comunica��o com o �suario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletanto informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file,",");// colocando virgula para separar
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coleta dados
	scanf("%s",nome);//salva dados
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,nome);//coleta o nome
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}
	

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
		
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do us�ario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if (file==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}	
}


 
int main()
{
	
	int opcao=0;
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
	system("cls");
	
	
	setlocale(LC_ALL,"PORTUGUESE");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("op��o: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3: 
		deleta();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
		
	}
	
	
	
	}
}

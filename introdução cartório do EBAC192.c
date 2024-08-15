#include <stdio.h>
// #include <stdio.h> � uma bibioteca de comunica��o com o usu�rio.

#include <stdlib.h> // usado para reservar um espa�o na mem�ria ou seja � igual VAR em logica e algoritmo.
#include <locale.h> // � uma BB de aloca��o de textos por regi�o ou seja ela leva em considera��o a linguagem nativa do pa�s, com essa bibioteca a pontua��o do portugu�s, etc, entram em vigor.
// \T � um comando para gerar um espa�o no texto que ira aparecer para o usu�rio.
// /n � um comando usado para pular uma linha, e pode ser usado tanto no come�o quanto no final do ( ).
#include <string.h> // BB respons�vel pelas strings

int registro()
{
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salvo valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
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
	
	printf("Digite o cpf a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Arquivo n�o encontrado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("");
		printf("");
	}
	
	
	system("pause");
}

int deletar()
{

	char cpf[40];
	
	printf("Digite o cpf a ser deletado");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario apagado com sucesso!. \n");
		system("pause");
	}
}


int main()
	{
	
	int opcao =0;
	int laco=1;
	
	
	
	for(laco=1;laco=1;)
	
		{
		
	
	
	
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("*** Cart�rio da EBAC ***\n\n");
	printf("*** Sejam bem vindos ***\n");
	printf("### EScolha a op��o desejada no menu\n\n");
	printf("\t1 Registrar nomes\n\n ");
	printf("\t2 Consultar nomes\n\n ");
	printf("\t3 Deletar nomes\n\n ");
	printf("");
	printf("Escolha digitando 1, 2, ou 3\n");
	
	
	scanf("%d" , &opcao);
	
	
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
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema");
		return 0;
		break; 
		
	
		
		
		
		default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
}
	
}
}

	
	
	



#include <stdio.h>
// #include <stdio.h> é uma bibioteca de comunicação com o usuário.

#include <stdlib.h> // usado para reservar um espaço na memória ou seja é igual VAR em logica e algoritmo.
#include <locale.h> // é uma BB de alocação de textos por região ou seja ela leva em consideração a linguagem nativa do país, com essa bibioteca a pontuação do português, etc, entram em vigor.
// \T é um comando para gerar um espaço no texto que ira aparecer para o usuário.
// /n é um comando usado para pular uma linha, e pode ser usado tanto no começo quanto no final do ( ).
#include <string.h> // BB responsável pelas strings

int registro()
{
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores da string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salvo valor da variável
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
		printf("Arquivo não encontrado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	printf("*** Cartório da EBAC ***\n\n");
	printf("*** Sejam bem vindos ***\n");
	printf("### EScolha a opção desejada no menu\n\n");
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			
}
	
}
}

	
	
	



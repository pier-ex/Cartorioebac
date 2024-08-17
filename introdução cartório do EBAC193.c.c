#include <stdio.h>
// #include <stdio.h> é uma bibioteca de comunicação com o usuário.

#include <stdlib.h> // usado para reservar um espaço na memória ou seja é igual VAR em logica e algoritmo.
#include <locale.h> // é uma BB de alocação de textos por região ou seja ela leva em consideração a linguagem nativa do país, com essa bibioteca a pontuação do português, etc, entram em vigor.
// \T é um comando para gerar um espaço no texto que ira aparecer para o usuário.
// /n é um comando usado para pular uma linha, e pode ser usado tanto no começo quanto no final do ( ).
#include <string.h> // BB responsável pelas strings

int registro()
{
	// Inicio da criação de variavéis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int continuar = 1;
	
	// final da criação de variáveis/string
	
	while (continuar) //loop para continuar os registros.
	{
	

	
	printf("Digite o cpf a ser cadastrado: "); // coletando informaçções do usuario.
	scanf("%s", cpf); //%s refere-se a string/ quando precisa-se salvar uma string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores da string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa "escrever"
	fprintf(file,cpf); //salvo valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre e altera o arquivo
	fprintf(file,","); // adiciona uma virgula para melhor organizar as informações quando forem consultadas
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado"); // chama a mnesagem para cadastrar o nome
	scanf("%s",nome); // salva a informação "nome"
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // chama a mensagem para cadastrar o sobrenome
	scanf("%s", sobrenome); //salva a informação sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // chama a mensagem para adicionar o cargo
	scanf("%s", cargo); //salva a informação "cargo"
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause"); //pausa o sistema, sendo necessário uma ação para seguir
	
	
	int escolha;
	
	printf("Deseja registrar outro usuario?\n1-Sim\n2-Voltar ao menu\n");
	scanf("%d", &escolha);
	
	if (escolha == 2){
		continuar = 0; // sair do loop, voltando ao menu principal
		
	
	}
	
	system("cls");	
	
	}
}
	
	
	

	
	

int consulta() //função responsável por consultar os usuários cadastrados
{
	
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma
	
	//criação de variáveis
	char cpf[40]; 
	char conteudo[200];
	
	// fim da seção de variavéis.
	
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
		
		setlocale(LC_ALL, "Portuguese");
	
	//definindo variáveis
	
	int opcao =0; //armazena a opção do usuário
	int laco=1; //controla o loop
	char senhadigitada[]="a";
	int comparacao;

	
	
	printf("*** Cartório da EBAC ***\n\n");
	printf("Vamos criar um login\n\n");
	
	
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0 )
	{
	
	
		system("cls");
		for(laco=1;laco=1;) // loop infinito para o menu principal
	
			{
		
	
			setlocale(LC_ALL, "Portuguese");
	
			printf("*** Cartório da EBAC ***\n\n");
			printf("*** Sejam bem vindos ***\n");
			printf("### EScolha a opção desejada no menu\n\n");
			printf("\t1 Registrar nomes\n\n ");
			printf("\t2 Consultar nomes\n\n ");
			printf("\t3 Deletar nomes\n\n ");
			printf("\t4 Sair do sistema\n\n");
			printf("");
			printf("Escolha digitando 1, 2, 3 ou 4\n");
	
	
			scanf("%d" , &opcao); //armazenando a escolha do usuário
	
	
			system("cls"); //limpa a tela
	
			switch(opcao) //inicio da seleção com base na escolha do usuário
			{
				case 1:
				registro(); //chamado da função de registrar usuários
				break;
		
				case 2:
				consulta();	//chamado da função de registrar usuários
				break;
			
				case 3:
				deletar(); //chamado da função de registrar usuários
				break;
		
				case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break; 
		
				//chama a mensagem caso o usuário não tenha escolhido nenhuma das opçãoes listadas acima
		
	
		
		
		
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			
			}
	
		}
			
	}
	
	 else
		printf("Senha incorreta!");
		
	
		
	
	
}
	

	



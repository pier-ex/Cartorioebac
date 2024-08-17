#include <stdio.h>
// #include <stdio.h> � uma bibioteca de comunica��o com o usu�rio.

#include <stdlib.h> // usado para reservar um espa�o na mem�ria ou seja � igual VAR em logica e algoritmo.
#include <locale.h> // � uma BB de aloca��o de textos por regi�o ou seja ela leva em considera��o a linguagem nativa do pa�s, com essa bibioteca a pontua��o do portugu�s, etc, entram em vigor.
// \T � um comando para gerar um espa�o no texto que ira aparecer para o usu�rio.
// /n � um comando usado para pular uma linha, e pode ser usado tanto no come�o quanto no final do ( ).
#include <string.h> // BB respons�vel pelas strings

int registro()
{
	// Inicio da cria��o de variav�is/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int continuar = 1;
	
	// final da cria��o de vari�veis/string
	
	while (continuar) //loop para continuar os registros.
	{
	

	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa���es do usuario.
	scanf("%s", cpf); //%s refere-se a string/ quando precisa-se salvar uma string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w" significa "escrever"
	fprintf(file,cpf); //salvo valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre e altera o arquivo
	fprintf(file,","); // adiciona uma virgula para melhor organizar as informa��es quando forem consultadas
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado"); // chama a mnesagem para cadastrar o nome
	scanf("%s",nome); // salva a informa��o "nome"
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // chama a mensagem para cadastrar o sobrenome
	scanf("%s", sobrenome); //salva a informa��o sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // chama a mensagem para adicionar o cargo
	scanf("%s", cargo); //salva a informa��o "cargo"
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause"); //pausa o sistema, sendo necess�rio uma a��o para seguir
	
	
	int escolha;
	
	printf("Deseja registrar outro usuario?\n1-Sim\n2-Voltar ao menu\n");
	scanf("%d", &escolha);
	
	if (escolha == 2){
		continuar = 0; // sair do loop, voltando ao menu principal
		
	
	}
	
	system("cls");	
	
	}
}
	
	
	

	
	

int consulta() //fun��o respons�vel por consultar os usu�rios cadastrados
{
	
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma
	
	//cria��o de vari�veis
	char cpf[40]; 
	char conteudo[200];
	
	// fim da se��o de variav�is.
	
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
		
		setlocale(LC_ALL, "Portuguese");
	
	//definindo vari�veis
	
	int opcao =0; //armazena a op��o do usu�rio
	int laco=1; //controla o loop
	char senhadigitada[]="a";
	int comparacao;

	
	
	printf("*** Cart�rio da EBAC ***\n\n");
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
	
			printf("*** Cart�rio da EBAC ***\n\n");
			printf("*** Sejam bem vindos ***\n");
			printf("### EScolha a op��o desejada no menu\n\n");
			printf("\t1 Registrar nomes\n\n ");
			printf("\t2 Consultar nomes\n\n ");
			printf("\t3 Deletar nomes\n\n ");
			printf("\t4 Sair do sistema\n\n");
			printf("");
			printf("Escolha digitando 1, 2, 3 ou 4\n");
	
	
			scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
	
			system("cls"); //limpa a tela
	
			switch(opcao) //inicio da sele��o com base na escolha do usu�rio
			{
				case 1:
				registro(); //chamado da fun��o de registrar usu�rios
				break;
		
				case 2:
				consulta();	//chamado da fun��o de registrar usu�rios
				break;
			
				case 3:
				deletar(); //chamado da fun��o de registrar usu�rios
				break;
		
				case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break; 
		
				//chama a mensagem caso o usu�rio n�o tenha escolhido nenhuma das op��oes listadas acima
		
	
		
		
		
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			
			}
	
		}
			
	}
	
	 else
		printf("Senha incorreta!");
		
	
		
	
	
}
	

	



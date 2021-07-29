//Declaração de bibliotecas 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//Declaração de struct

struct cadastro{
	char cpf[12];
	char nome[31];
	int data[3];
};typedef struct cadastro cad;

struct pedidos{
	char cpf[12];
	int pedido;
	char modelo[30];
	float valor;
	int data[3];
};typedef struct pedidos ped;

//Declaração de funções
void entrada(char usuario[], char senha[]);
void verific(char bancoveri[]);
void verificacao( char bancoveri[]);
void cadastro(char x[]);
void pedidos(char x[]);
int sequencia();
void consultar();

//Declaração de ponteiro 
FILE *pontarq;
FILE *pontarq1;
FILE *pontarq2;
FILE *pontarq3;

//Declaração de struct
cad cliente;

//Função principal
main()
{
	//Declaração de variaveis
	char usuario[31], senha[10], usu[31], pas[31], banco[31];
	char resp;
	int opcao;
	char cpf[12], cpf1[12];	
	
	printf("Bem vindo ao Sistema de informacao\n");
	
	if((pontarq=fopen("usuarios.txt", "r"))==NULL)
	{
		pontarq=fopen("usuarios.txt", "w");
		
		printf("Cadastro e senha do usuario.... \n");
		
		//Entrada de dados
		entrada(usuario, senha);
		
		fprintf(pontarq, "%s %s ", usuario, senha);
		printf("Cadastro de Usuario concluido com sucesso.");
		
		//Fechar pasta 
		fclose(pontarq);
		
		//Fechar arquivo
		exit(0);
	}
	
	else{	
			
				printf("Entre com o usuario e senha:  \n");
				entrada(usuario, senha);
				system("cls");
				
				while((fscanf(pontarq, "%s %s", usu, pas))!= EOF)
				{
					
					if(strcmp(usuario, usu)==0 and strcmp(senha, pas)==0 )
					{
						
						do{
					
							printf("----MENU PRINCIPAL----\n");
							printf("1 - Cadastro de cliente.\n");
							printf("2 - Listar clientes.\n");
							printf("3 - Cadastrar pedidos.\n");
							printf("4 - Listar pedido.\n");
							printf("5 - Consultar pedido.\n");
							printf("6 - Sair.\n");
							
							printf("Digite a opcao de sua escolha: ");
							scanf("%i", &opcao);
							
							system("cls");
							
							switch(opcao){
								
								case 1:{
									
									printf("CADASTRO DE CLIENTES\n");
							
									strcpy(banco, "cadastro.txt");
									
									do{
										if((pontarq1=fopen("cadastro.txt", "rb"))==NULL)
										{
											printf("Digite o cpf: ");
											fflush(stdin);
											gets(cpf);
											cadastro(cpf);
											system("pause");
											system("cls");	
											fclose(pontarq1);
										}
										
										else
										{
											verific(banco);
											system("pause");
											system("cls");															
										}
											
										
									}while(toupper(resp)=='S');
									
								
									break;
								}
								
								case 2:{
									
									//declaração de struct
									cad cliente;
									
									printf("LISTA DE CLIENTES: ");
									
									if((pontarq2=fopen("cadastro.txt", "r"))== NULL)
										{
											printf("Erro na abertura do arquivo.....\n");
											system("pause");
											exit(0);
										}
										
									else
									{
										while((fread(&cliente, sizeof(cliente), 1, pontarq2))==1)
										{
											printf("\nCpf: %s\nNome: %s\n", cliente.cpf,cliente.nome);
											printf("Data de nascimento: %i/%i/%i \n", cliente.data[0], cliente.data[1], cliente.data[2]);
											printf("\n");
										}
									
										system("pause");
										system("cls");
										fclose(pontarq2);
									}
									break;
								}
								
								case 3: {
									printf("CADASTRO DE PEDIDOS\n");
							
									strcpy(banco, "cadastro.txt");
									
									do{
										if((pontarq1=fopen("cadastro.txt", "rb"))==NULL)
										{
											printf("Digite o cpf: ");
											fflush(stdin);
											gets(cpf1);
											system("cls");
											pedidos(cpf1);	
										}
										
										else
										{
											verificacao(banco);
											system("pause");
											system("cls");			
										}
											
										fclose(pontarq1);
									}while(toupper(resp)=='S');
			
									break;
								}
								
								case 4: {
									//declaração de struct
									ped client;
									
									printf("LISTA DE PEDIDOS ");
									
									if((pontarq2=fopen("pedidos.txt", "r"))== NULL)
										{
											printf("Erro na abertura do arquivo.....\n");
											system("pause");
											exit(0);
										}
										
									else
									{
										while((fread(&client, sizeof(client), 1, pontarq2))==1)
										{
											printf("\nCpf: %s\nNumero do pedido: %i", client.cpf,client.pedido);
											printf("\nValor do carro: %f\nModelo do carro: %s", client.valor,client.modelo);
											printf("\nData de compra: %i/%i/%i \n", client.data[0], client.data[1], client.data[2]);
											printf("\n");
										}
									
										system("pause");
										system("cls");
										fclose(pontarq2);
									}
									break;
								}
								
								case 5:{
									consultar();
									break;
								}
								
								//sair do menu
								case 6 :{
									exit(0);
									break;
								}
							}
						}while(true);
					}
					
					printf("Usuario ou senha incorretos... \n");
					printf("Tente novamente....\n");
					system("pause");
					system("cls");
					fclose(pontarq);
				}
	
	}
}

//Função de cadastro
void entrada(char usuario[], char senha[])
{
	printf("Entre com o Usuario: ");
	fflush(stdin);
	gets(usuario);
	
	printf("Entre com a senha: ");
	fflush(stdin);
	gets(senha);
}

//função de verificação
void verific( char bancoveri[])
{
	//Declaração de variaveis locais 
	int flag=0;
	char cpfvali[12];
	cad cliente;
	
	//entrada do cpf
	printf("Entre com o cpf do cliente: ");
	fflush(stdin);
	gets(cpfvali);
	
	pontarq2 = fopen(bancoveri, "rb");
	
	while((fread(&cliente, sizeof(cliente),1,pontarq2))== 1)
	{	
		if(strcmp(cpfvali,cliente.cpf) == 0)
		{
			flag = 1;
		}
	}		
		
	fclose(pontarq2);
	
	if(flag == 0)
	cadastro(cpfvali);
	
	else
	{
		printf("CPF existente ,adicione outro cpf\n");
		system("pause");
		system("cls");	
	}	
}

//função de verificação
void verificacao( char bancoveri[])
{
	//Declaração de variaveis locais 
	char cpf[12];
	int flag = 0;
	cad cliente;
	
	//entrada do cpf
	printf("Entre com o cpf do cliente: ");
	fflush(stdin);
	gets(cpf);
	
	pontarq2 = fopen(bancoveri, "rb");
	
	while((fread(&cliente, sizeof(cad),1,pontarq2))== 1)
	{		
			if(strcmp(cpf,cliente.cpf)==0)
			{
				pedidos(cpf);
				flag = 1;
			}		
	}
	fclose(pontarq2);
	
	if(flag = 0)
	printf("Cpf nao encontrado.....");
}

void cadastro(char x[])
{
	cad cliente;
	
	//abertura de arquivo para escrita modo binário
	pontarq3=fopen("cadastro.txt", "ab");
	
	strcpy(cliente.cpf,x);
	
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	gets(cliente.nome);
	
	printf("Digite o dia do seu nascimento: ");
	scanf("%i", &cliente.data[0]);
	
	printf("Digite o mes do seu nascimento: ");
	scanf("%i", &cliente.data[1]);
	
	printf("Digite o ano do seu nascimento: ");
	scanf("%i", &cliente.data[2]);
	
	//escrita no arquivo como registro
	fwrite(&cliente, sizeof(cliente), 1, pontarq3);
	
	//fechar o arquivo
	fclose(pontarq3);
}

void pedidos(char x[])
{
	//Declarações
	ped client;
	int sequencia();
	int numero;
	
	//abertura de arquivo para escrita modo binário
	
	pontarq3=fopen("pedidos.txt", "ab");
	
	client.pedido = sequencia();
	
	strcpy(client.cpf,x);
	
	printf("Digite o modelo do carro: ");
	fflush(stdin);
	gets(client.modelo);
	
	printf("Digite o dia de compra ");
	scanf("%i", &client.data[0]);
	
	printf("Digite o mes de compra: ");
	scanf("%i", &client.data[1]);
	
	printf("Digite o ano de compra: ");
	scanf("%i", &client.data[2]);
	
	printf("Digite o valor do carro: ");
	scanf("%f",&client.valor);
	
	//escrita no arquivo como registro
	fwrite(&client, sizeof(client), 1, pontarq3);
	
	//fechar o arquivo
	fclose(pontarq3);
}

//função sequencia()
int sequencia()
{
	//declaração de variável
	int numero;
	
	//abertura do arquivo texto para leitura
	if((pontarq2=fopen("sequencia.txt","r"))==NULL)
	{
		//primeira vez - inicializar a sequência
		numero = 1;
		
		//abertura do arquivo texto para gravação
		pontarq2=fopen("sequencia.txt", "w");
		
		//gravar a sequência no disco
		fprintf(pontarq2, "%i ", numero);
		
		//fechar o arquivo
		fclose(pontarq2);
	}
	else
	{
		//recuperar o valor corrente da sequência
		while((fscanf(pontarq2, "%i", &numero))!=EOF)
			numero++;
		//fechar o arquivo 
		fclose(pontarq2);
		
		//incrementar a sequência no arquivo
		//abertura do arquivo texto para gravação
		pontarq2=fopen("sequencia.txt", "w");
		
		//gravar a sequência no disco
		fprintf(pontarq2, "%i ", numero);
		
		//fechar o arquivo
		fclose(pontarq2);
			
	}
	return numero;
}

void consultar()
{
	//declaração das variáveis
	ped client;
	long int offset;
	int flag = 0, codfunc;
	
	//abrir o arquivo para leitura modo binário
	if((pontarq2=fopen("pedidos.txt","r"))==NULL)
	{
		printf("\nNao ha registros cadastrados...\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("Informe o numero do pedido: ");
		scanf("%i", &codfunc);
		
		//calcular o deslocamento
		offset = (codfunc-1) * sizeof(client);
		
		//deslocar o ponteiro do arquivo
		if((fseek(pontarq2,offset,0))!=0)
		{
			printf("\nerro em movimentar o ponteiro...\n");
			system("pause");
		}
		
		else
		{
			//ler o valor da posição corrente
			while((fread(&client, sizeof(client), 1, pontarq2))==1)
			{
				if(client.pedido == codfunc)
				{
					printf("\nCpf: %s\nNumero do pedido: %i", client.cpf,client.pedido);
					printf("\nValor do carro: %f\nModelo do carro: %s", client.valor,client.modelo);
					printf("\nData de compra: %i/%i/%i \n", client.data[0], client.data[1], client.data[2]);
					printf("\n");
					system("pause");
					system("cls");
					flag = 1;
				}
			}
			
			if(flag == 0)
			printf("\nCodigo nao foi encontrado...\n");
			system("pause");
			system("cls");
		}
		fclose(pontarq);		
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct cliente{
    char nome[100];
    char endereco[100];
	char telefone[100];
    int cpf;
};


void GetCliente(struct cliente *cls){
	printf("| Digite o Nome do cliente: ");
	scanf("%s",&cls->nome);
	fflush(stdin);
	printf("| Digite o Endereco do cliente: ");
    scanf("%s",&cls->endereco);
    fflush(stdin);
    printf("| Digite o Telefone do cliente: ");
    scanf("%s",&cls->telefone);
    printf("| Digite o CPF do cliente: ");
    scanf("%d",&cls->cpf);
    
}

typedef struct veiculo{
    char modelo[100];
    char cor[100];
    char placa[10];
    float chassi;
    float ano;
    float passageiros;
};

void GetVeiculo(struct veiculo *cls){
	printf("| Digite o modelo do veiculo: ");
	scanf("%s",&cls->modelo);
	fflush(stdin);
	printf("| Digite o cor do veiculo: ");
    scanf("%s",&cls->cor);
    fflush(stdin);
    printf("| Digite a placa do veiculo: ");
    scanf("%s",&cls->placa);
    fflush(stdin);
    printf("| Digite o chassi do veiculo: ");
    scanf("%f",&cls->chassi);
    printf("| Digite o ano do veiculo: ");
    scanf("%f",&cls->ano);
    printf("| Digite o numero de passageiros do veiculo: ");
    scanf("%f",&cls->passageiros);
    
}

typedef struct funcionario{
    char nome[100];
    char endereco[100];
    char telefone[100];
    float cpf;
	char cargo[100];
    float registro;
};

void GetFuncionario(struct funcionario *cls){
	printf("| Digite o Nome do funcionario: ");
	scanf("%s",&cls->nome);
	printf("| Digite o Endereco do funcionario: ");
    scanf("%s",&cls->endereco);
    printf("| Digite o Telefone do funcionario: ");
    scanf("%s",&cls->telefone);
    printf("| Digite o CPF do funcionario: ");
    scanf("%f",&cls->cpf);
    printf("| Digite o cargo do funcionario: ");
    scanf("%s",&cls->cargo);
    printf("| Digite o numero de registro do funcionario: ");
    scanf("%f",&cls->registro);
	
}
typedef struct locacao{
    float dias;
    float valor;
    float cod;
    float cpf;
    float chassi;
};

void GetLocacao(struct locacao *cls){
	printf("| Digite o codigo de locacao: ");
	scanf("%f",&cls->cod);
	printf("| Digite os dias de aluguel: ");
	scanf("%f",&cls->dias);
	printf("| Digite o valor: ");
	scanf("%f",&cls->valor);
	printf("| Digite o cpf do cliente: ");
	scanf("%f",&cls->cpf);
	printf("| Digite o chassi do veiculo: ");
	scanf("%f",&cls->chassi);
    
} 

typedef struct historico{
    float dias;
    float valor;
    float cod;
    float cpf;
    float chassi;
};

void GetHistorico(struct historico *cls){
	printf("| Digite o codigo de locacao: ");
	scanf("%f",&cls->cod);
	printf("| Digite os dias de aluguel: ");
	scanf("%f",&cls->dias);
	printf("| Digite o valor: ");
	scanf("%f",&cls->valor);
	printf("| Digite o cpf do cliente: ");
	scanf("%f",&cls->cpf);
	printf("| Digite o chassi do veiculo: ");
	scanf("%f",&cls->chassi);
    
} 

typedef struct login{
	char login[10];
	char senha[10];

};

void Aplogin(struct login *cls){
	printf(" | Digite o login: ");
	scanf("%s",&cls->login);
	printf(" | Digite a senha: ");
	scanf("%s",&cls->senha);
}

void ValidarLogin(){
	
	char  loginn[5];
	char senhaa[5];
	int car = 1;
struct login loo;

do {

		printf("|-------------------------------|\n");
        printf("|			 LOCAFACIL  		|\n");
        printf("|			 VEICULOS   		|\n");
        printf("|-------------------------------|\n");
        printf("|             LOGIN             |\n");
        printf("|-------------------------------|\n");
        printf("|             NOME:             |\n");
        scanf("%s",&loginn);
        printf("|-------------------------------|\n");
        printf("|             SENHA:            |\n");
        printf("|-------------------------------|\n");
		scanf("%s",&senhaa);
		system("cls");
		
	FILE * loginnn;
 	loginnn = fopen("login.txt","r+");
 
	 
					while((fscanf(loginnn,"%s %s \n",loo.login,loo.senha)!= EOF) && car != 3){
                        if((strcmp(loo.login,loginn) == 0) && (strcmp(loo.senha,senhaa) == 0)){
                                   printf("logaDo!\n");
                                   car = 3;
                            }
						}
											
					}while(car != 3);
	}


int main(){

int opcao;
struct cliente cl;
struct veiculo vl;
struct funcionario fun;
struct locacao loc;
struct login lo;




ValidarLogin();

	do{
		
		
        printf("|-------------------------------|\n");
        printf("|			 LOCAFACIL  		|\n");
        printf("|			 VEICULOS   		|\n");
        printf("|-------------------------------|\n");
        printf("|  1  |        CLIENTES         |\n");
        printf("|-------------------------------|\n");
        printf("|  2  |        VEICULOS         |\n");
        printf("|-------------------------------|\n");
        printf("|  3  |        LOCACAO          |\n");
        printf("|-------------------------------|\n");
        printf("|  4  |          SAIR           |\n");
        printf("|-------------------------------|\n");
        printf("|  5  |      FUNCIONARIOS       |\n");
        printf("|-------------------------------|\n");
        printf("| Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao){
            case 1:{
                int opcli;
                printf("|-------------------------------|\n");
				printf("|             CLIENTES          |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
				printf("|  3  |        EXCLUIR          |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |        VOLTAR           |\n");
				printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&opcli);
				system("cls");
				switch(opcli){
                    case 1:{
                        int buscaCli;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o CPF do cliente: ");
                        scanf ("%d",&buscaCli);
						//system("CLS");
						FILE *cliente;    //PONTEIRO PARA ARQUIVO
						cliente = fopen("cliente.txt", "r");
						while(fscanf(cliente,"%s %s %s %d", cl.nome,cl.endereco,cl.telefone,&cl.cpf)!= EOF){
                            if(buscaCli == cl.cpf){
                                    printf("Nome: %s\nEndereco: %s\nTelefone: %s\nCPF: %d\n",cl.nome,cl.endereco,cl.telefone,cl.cpf);
                            }
						}
						fclose(cliente);
						system("pause");
						system("cls");
                    }
                    break;
					case 2:{
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *cliente;    //PONTEIRO PARA ARQUIVO
                        cliente = fopen("cliente.txt", "a");
                        if(cliente ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            
                        }
                        
                        GetCliente(&cl);
                        fflush(stdin);
                        fprintf(cliente,"%s %s %s %d\n",cl.nome,cl.endereco,cl.telefone,cl.cpf);
                        fclose(cliente);
                        printf("Cliente Cadastrado com Sucesso\n");
                        system("pause");
                        system("cls");
                        break;
                    }
					case 3:{    //  CASO ESCOLHA 3 ABRE EXCLUIR
                        int excluirCPF;
                        printf("|-------------------------------|\n");
                        printf("|            EXCLUIR            |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o CPF do cliente para excluir: ");
                        scanf ("%d",&excluirCPF);// LER O QUE SERA EXCLUIDO DO ARQUIVO
                        FILE *cli, *cliente; //  ARQUIVO TEMPORARIO
						if((cliente = fopen("cliente.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"							
						if((cli = fopen("cli.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO						
						while(fscanf(cliente,"%s %s %s %d\n", cl.nome,cl.endereco,cl.telefone,&cl.cpf) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                                                    
								if (excluirCPF != cl.cpf){// SELECIONE TODOS EXETO CPF
                                	fprintf(cli,"%s %s %s %d\n", cl.nome,cl.endereco,cl.telefone,cl.cpf); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }
                        }
                        printf("Excluido com Sucesso\n");
                        fclose(cliente);
                        fclose(cli);
                        remove("cliente.txt");
                        rename("cli.txt", "cliente.txt");
                        system("pause");
						system("cls");
						break;
                    }
               		case 4:{
						system("cls");
					break;
					}
				}
			}
			break;
			case 2:{
                int opVei;
                printf("|-------------------------------|\n");
				printf("|             VEICULOS          |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
				printf("|  3  |        EXCLUIR          |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |        VOLTAR           |\n");
				printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&opVei);
				system("cls");
				switch(opVei){
                    case 1:{
                        int buscaVei;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o chassi do veiculo: ");
                        scanf ("%d",&buscaVei);
						//system("CLS");
						FILE *veiculo;    //PONTEIRO PARA ARQUIVO
						veiculo = fopen("veiculo.txt", "r");
						while(fscanf(veiculo,"%s %s %s %f %f %f", vl.modelo,vl.cor,vl.placa,&vl.chassi,&vl.ano, &vl.passageiros)!= EOF){
                            if(buscaVei == vl.chassi){
                                    printf("Modelo: %s\nCor: %s\nPlaca: %s\nChassi: %.0f\nAno: %.0f\nPasageiros: %.0f\n",vl.modelo,vl.cor,vl.placa,vl.chassi, vl.ano, vl.passageiros);
                            }
						}
						fclose(veiculo);
						system("pause");
						system("cls");
                    }
                    break;
					case 2:{
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *veiculo;    //PONTEIRO PARA ARQUIVO
                        veiculo = fopen("veiculo.txt", "a");
                        if(veiculo ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            
                        }
                        
                        GetVeiculo(&vl);
                        fprintf(veiculo,"%s %s %s %.0f %.0f %.0f\n",vl.modelo,vl.cor,vl.placa,vl.chassi, vl.ano, vl.passageiros);
                        fclose(veiculo);
                        printf("Veiculo Cadastrado com Sucesso\n");
                        system("pause");
                        system("cls");
                        break;
                    }
//                    break;
					case 3:{    //  CASO ESCOLHA 3 ABRE EXCLUIR
                        int excluirChassi;
                        printf("|-------------------------------|\n");
                        printf("|            EXCLUIR            |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o chassi do veiculo para excluir: ");
                        scanf ("%d",&excluirChassi);// LER O QUE SERA EXCLUIDO DO ARQUIVO
                        FILE *tveic, *veiculo; //  ARQUIVO TEMPORARIO
						if((veiculo = fopen("veiculo.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"
						if((tveic = fopen("tveic.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        while(fscanf(veiculo,"%s %s %s %f %f %f", vl.modelo,vl.cor,vl.placa,&vl.chassi,&vl.ano, &vl.passageiros) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO
                            if (excluirChassi != vl.chassi){// COMPARAR SE CLIENTE A SER EXCLUIDO FOR DIFERENTE  DA LINHA ATUAL
                                fprintf(tveic,"%s %s %s %.0f %.0f %.0f\n",vl.modelo,vl.cor,vl.placa,vl.chassi, vl.ano, vl.passageiros); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }
                        }
                        printf("Excluido com Sucesso\n");
                        fclose(veiculo);
                        fclose(tveic);
                        remove("veiculo.txt");
                        rename("tveic.txt", "veiculo.txt");
                        system("pause");
						system("cls");
						break;
                    }
                    case 4:{
						system("cls");
					break;
					}
				}
			}
			break;
			case 5:{
                int opfun;
                printf("|-------------------------------|\n");
				printf("|           FUNCIONARIOS        |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
				printf("|  3  |        EXCLUIR          |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |        VOLTAR           |\n");
				printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&opfun);
				system("cls");
				switch(opfun){
                    case 1:{
                        int buscaFun;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o numero de registro do funcionario: ");
                        scanf ("%d",&buscaFun);
						//system("CLS");
						FILE *funcionario;    //PONTEIRO PARA ARQUIVO
						funcionario = fopen("funcionario.txt", "r");
						while(fscanf(funcionario,"%s %s %s %f %s %f\n", fun.nome,fun.endereco,fun.telefone,&fun.cpf,fun.cargo,&fun.registro)!= EOF){
                            if(buscaFun == fun.registro){
                                    printf("Nome: %s\nEndereco: %s\nTelefone: %s\nCPF: %.0f\nCargo: %s\nRegistro: %.0f\n",fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro);
                            }
						}
						fclose(funcionario);
						system("pause");
						system("cls");
                    }
                    break;
					case 2:{
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *funcionario;   //PONTEIRO PARA ARQUIVO
						FILE *login; //login
                        funcionario = fopen("funcionario.txt", "a+");
                        login = fopen("login.txt","a");
                        if(funcionario ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            
                        }
                        if(login ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            
                        }
                        
                        
                       	GetFuncionario(&fun);
                        Aplogin(&lo);
                        fprintf(funcionario,"%s %s %s %.0f %s %.0f\n", fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro);
                        fprintf(login,"%s  %s \n",lo.login,lo.senha);
                        fclose(funcionario);
                        fclose(login);
                        printf("Funcionario Cadastrado com Sucesso\n");
                        system("pause");
                        system("cls");
                        break;
                    }
					case 3:{    //  CASO ESCOLHA 3 ABRE EXCLUIR
                        int excluirREG;
                        printf("|-------------------------------|\n");
                        printf("|            EXCLUIR            |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o registro do funcionario para excluir: ");
                        scanf ("%d",&excluirREG);// LER O QUE SERA EXCLUIDO DO ARQUIVO
                        FILE *tfun, *funcionario; //  ARQUIVO TEMPORARIO
						if((funcionario = fopen("funcionario.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"							
						if((tfun = fopen("tfun.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        while(fscanf(funcionario,"%s %s %s %f %s %f", fun.nome,fun.endereco,fun.telefone,&fun.cpf,fun.cargo,&fun.registro) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                            
								if (excluirREG != fun.registro){// SELECIONE TODOS EXETO CPF
                                	fprintf(tfun,"%s %s %s %.0f %s %.0f\n", fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }
                        }
                        printf("Excluido com Sucesso\n");
                        fclose(funcionario);
                        fclose(tfun);
                        remove("funcionario.txt");
                        rename("tfun.txt", "funcionario.txt");
                        system("pause");
						system("cls");
						break;
                    }
                    case 4:{
						system("cls");
					break;
					}
				}
			}
			break;
			case 3:{
				int oploc;
				printf("|-------------------------------|\n");
				printf("|              LOCACAO          |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
				printf("|  3  |       DEVOLUCAO         |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |        EXCLUIR          |\n");
				printf("|-------------------------------|\n");
				printf("|  5  |       HISTORICO         |\n");
				printf("|-------------------------------|\n");
				printf("|  6  |         VOLTAR          |\n");
				printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&oploc);
				system("cls");
				switch(oploc){
                    case 1:{
                        float buscaLoc;
                        char lixo[10];
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o numero de registro da locacao: ");
                        scanf("%f",&buscaLoc);
						//system("CLS");
						FILE *locacao;    //PONTEIRO PARA ARQUIVO
						locacao = fopen("locacao.txt", "r");
							while(fscanf(locacao,"%s %f %s %f %s %f %s %f %s %f\n", &lixo, &loc.cod, &lixo, &loc.dias, &lixo, &loc.valor, &lixo, &loc.cpf, &lixo, &loc.chassi)!= EOF){
                            if(buscaLoc == loc.cod){
                                    printf("Locacao: %.0f\nDiarias: %.0f\nValor: %.0f\nCPF Cliente: %.0f\nChassi do Veiculo: %.0f\n", loc.cod,loc.dias,loc.valor,loc.cpf,loc.chassi);
                            }
                   		}
						fclose(locacao);
						system("pause");
						system("cls");  
                    }
                    break;
					case 2:{
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");                                                                                          
                        FILE *locacao, *cliente, *funcionario, *veiculo;
                        locacao = fopen("locacao.txt", "a");
                        cliente = fopen("cliente.txt", "a");
                        funcionario = fopen("funcionario.txt", "a");
                        veiculo = fopen("veiculo.txt", "a");
                        if(locacao ==  NULL){
                            printf("Erro na abertura do arquivo LOCACAO!");
                        }
                        if(cliente == NULL){
                        	printf("Erro na abertura do arquivo CLIENTE!");
                        	system("pause");
                            
						}
						if(funcionario == NULL){
                        	printf("Erro na abertura do arquivo FUNCIONARIO!");
                        	system("pause");
                            
						}
						if(veiculo == NULL){
                        	printf("Erro na abertura do arquivo VEICULO!");
                        	system("pause");
                    
						}
                        GetLocacao(&loc);
                        fprintf(locacao, "codigoLoc: %.0f dias: %.0f valor: %.0f clienteCPF: %.0f veiculo: %.0f\n", loc.cod,loc.dias,loc.valor*loc.dias,loc.cpf, loc.chassi);
                        fclose(cliente);
                        fclose(veiculo);
                        fclose(funcionario);
						fclose(locacao);
                        printf("Locacao Cadastrado com Sucesso\n");
                        system("pause");
                        system("cls");
                        break;  
                    }
					case 3:{    //  CASO ESCOLHA 3 ABRE DEVOLUCAO
                        float bloc;
                        char lixo[10];
                        printf("|-------------------------------|\n");
                        printf("|           DEVOLUCAO           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o registro de locacao para devolucao: ");
                        scanf ("%f",&bloc);// LER O QUE SERA EXCLUIDO DO ARQUIVO
                        FILE *dloc, *tloc, *locacao, *historico; //  ARQUIVO TEMPORARIO
                        
                        if((locacao = fopen("locacao.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"							
						if((historico = fopen("historico.txt","a")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
						if((tloc = fopen("tloc.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        while(fscanf(locacao,"%s %f %s %f %s %f %s %f %s %f\n", &lixo, &loc.cod, &lixo, &loc.dias, &lixo, &loc.valor, &lixo, &loc.cpf, &lixo, &loc.chassi) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                            
								if (bloc == loc.cod){// SELECIONE TODOS EXETO CPF
                                	fprintf(historico,"codigoLoc: %.0f dias: %.0f valor: %.0f clienteCPF: %.0f veiculo: %.0f\n", loc.cod,loc.dias,loc.valor*loc.dias,loc.cpf, loc.chassi); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            	}
                            	if (bloc != loc.cod){// SELECIONE TODOS EXETO CPF
                                	fprintf(tloc,"codigoLoc: %.0f dias: %.0f valor: %.0f clienteCPF: %.0f veiculo: %.0f\n", loc.cod,loc.dias,loc.valor*loc.dias,loc.cpf, loc.chassi); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }                            	
                        }                        
                        printf("Excluido com Sucesso\nSalvo no Historico\n");
                        fclose(locacao);
                        fclose(historico);
                        fclose(tloc);
                        remove("locacao.txt");
                        rename("tloc.txt", "locacao.txt");   
                        system("pause");
						system("cls");
						break;
                    }
					case 4:{    //  CASO ESCOLHA 3 ABRE EXCLUIR
                        float excluirloc;
                        char lixo[10];
                        printf("|-------------------------------|\n");
                        printf("|            EXCLUIR            |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o registro de locacao para excluir: ");
                        scanf ("%f",&excluirloc);// LER O QUE SERA EXCLUIDO DO ARQUIVO
                        FILE *tloc, *locacao; //  ARQUIVO TEMPORARIO
						if((locacao = fopen("locacao.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"							
						if((tloc = fopen("tloc.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        while(fscanf(locacao,"%s %f %s %f %s %f %s %f %s %f\n", &lixo, &loc.cod, &lixo, &loc.dias, &lixo, &loc.valor, &lixo, &loc.cpf, &lixo, &loc.chassi) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                            
								if (excluirloc != loc.cod){// SELECIONE TODOS EXETO CPF
                                	fprintf(tloc,"codigoLoc: %.0f dias: %.0f valor: %.0f clienteCPF: %.0f veiculo: %.0f\n", loc.cod,loc.dias,loc.valor*loc.dias,loc.cpf, loc.chassi); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }
                        }
                        printf("Excluido com Sucesso\n");
                        fclose(locacao);
                        fclose(tloc);
                        remove("locacao.txt");
                        rename("tloc.txt", "locacao.txt");   
                        system("pause");
						system("cls");
						break;
                    }
					case 5:{    //  CASO ESCOLHA 3 ABRE HISTORICO
                        printf("|-------------------------------|\n");
                        printf("|            HISTORICO          |\n");
                        printf("|               DE              |\n");
                        printf("|             LOCACAO           |\n");
                        printf("|-------------------------------|\n");                        
                        FILE *historico;    //PONTEIRO PARA ARQUIVO
						historico = fopen("historico.txt", "rt");
						
						char Linha[100];
  						char *result;
  						int i;
						if (historico == NULL)  // Se houve erro na abertura
  						{
     						printf("Problemas na abertura do arquivo\n");
     						return;
  						}
  						i = 1;
  						while (!feof(historico)) {// Lê uma linha (inclusive com o '\n')
      						result = fgets(Linha, 100, historico);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      							if (result)  // Se foi possível ler
	  								printf("=>  %s\n",Linha);
      							i++;
  						}
  						fclose(historico);
						system("pause");
						system("cls");
						break;
                    }
                    case 6:{
						system("cls");
					break;
					}
				}
				
				
				break;
			}
			
		}
	}while(opcao!=4);
}

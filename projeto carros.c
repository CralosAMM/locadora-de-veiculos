#include <stdio.h>
#include <stdlib.h>


typedef struct cliente{
    char nome[100];
    char endereco[100];
    float telefone;
    float cpf;
};

void GetCliente(struct cliente *cls){
	printf("| Digite o Nome do cliente: ");
	scanf("%s",&cls->nome);
	printf("| Digite o Endereco do cliente: ");
    scanf("%s",&cls->endereco);
    printf("| Digite o Telefone do cliente: ");
    scanf("%f",&cls->telefone);
    printf("| Digite o CPF do cliente: ");
    scanf("%f",&cls->cpf);
    return 0;
}

typedef struct veiculo{
    char modelo[100];
    char cor[100];
    char placa[6];
    float chassi;
    float ano;
    float passageiros;
};

void GetVeiculo(struct veiculo *cls){
	printf("| Digite o modelo do veiculo: ");
	scanf("%s",&cls->modelo);
	printf("| Digite o cor do veiculo: ");
    scanf("%s",&cls->cor);
    printf("| Digite a placa do veiculo: ");
    scanf("%s",&cls->placa);
    printf("| Digite o chassi do veiculo: ");
    scanf("%f",&cls->chassi);
    printf("| Digite o ano do veiculo: ");
    scanf("%f",&cls->ano);
    printf("| Digite o numero de passageiros do veiculo: ");
    scanf("%f",&cls->passageiros);
    return 0;
}

typedef struct funcionario{
    char nome[100];
    char endereco[100];
    float telefone;
    float cpf;
	char cargo;
    float registro;
};

void GetFuncionario(struct funcionario *cls){
	printf("| Digite o Nome do funcionario: ");
	scanf("%s",&cls->nome);
	printf("| Digite o Endereco do funcionario: ");
    scanf("%s",&cls->endereco);
    printf("| Digite o Telefone do funcionario: ");
    scanf("%f",&cls->telefone);
    printf("| Digite o CPF do funcionario: ");
    scanf("%f",&cls->cpf);
    printf("| Digite o cargo do funcionario: ");
    scanf("%s",&cls->cargo);
    printf("| Digite o numero de registro do funcionario: ");
    scanf("%f",&cls->registro);
	return 0;
}
int main(){
	
int opcao;
struct cliente cl;
struct veiculo vl;
struct funcionario fun;

	do{
		
		
        printf("|-------------------------------|\n");
        printf("|			LOCADORA CARROS		|\n");
        printf("|-------------------------------|\n");
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
        printf("|  6  |     EXTRATO DO DIA      |\n");
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
						while(fscanf(cliente,"%s %s %f %f", cl.nome,cl.endereco,&cl.telefone,&cl.cpf)!= EOF){
                            if(buscaCli == cl.cpf){
                                    printf("Nome: %s\nEndereco: %s\nTelefone: %.0f\nCPF: %.0f\n",cl.nome,cl.endereco,cl.telefone,cl.cpf);
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
                            return ;
                        }
                        
                        GetCliente(&cl);
                        fprintf(cliente,"%s %s %.0f %.0f\n",cl.nome,cl.endereco,cl.telefone,cl.cpf);
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
                        FILE *tcli, *cliente; //  ARQUIVO TEMPORARIO
						if((cliente = fopen("cliente.txt", "r+")) == NULL);// ABRIR ARQUIVO CLIENTE EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "R+"							
						while(fscanf(cliente,"%s %s %f %f", cl.nome,cl.endereco,&cl.telefone,&cl.cpf) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                            
						if((tcli = fopen("tcli.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        
								if (excluirCPF != cl.cpf){// SELECIONE TODOS EXETO CPF
                                	fprintf(tcli,"%s %s %.0f %.0f\n", cl.nome,cl.endereco,cl.telefone,cl.cpf); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
                            }
                        }
                        printf("Excluido com Sucesso\n");
                        fclose(cliente);
                        fclose(tcli);
                        remove("cliente.txt");
                        rename("tcli.txt", "cliente.txt");
                        system("pause");
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
				printf("| Escolha uma opcao: ");
				scanf("%d",&opVei);
				system("cls");
				switch(opVei){
                    case 1:{
                        int buscaVei;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite a placa do veiculo: ");
                        scanf ("%d",&buscaVei);
						//system("CLS");
						FILE *veiculo;    //PONTEIRO PARA ARQUIVO
						arq_veiculo = fopen("veiculo.txt", "r");
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
                        FILE *arq_veiculo;    //PONTEIRO PARA ARQUIVO
                        arq_veiculo = fopen("veiculo.txt", "a");
                        if(veiculo ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            return ;
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
						if((tveic = fopen("temp.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
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
				printf("| Escolha uma opcao: ");
				scanf("%d",&opfun);
				system("cls");
				switch(opfun){
                    case 1:{
                        int buscaFun;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o CPF do cliente: ");
                        scanf ("%d",&buscaFun);
						//system("CLS");
						FILE *funcionario;    //PONTEIRO PARA ARQUIVO
						funcionario = fopen("funcionario.txt", "r");
						while(fscanf("%s %s %.0f %.0f %s %.0f\n", fun.nome,fun.endereco,&fun.telefone,&fun.cpf,fun.cargo,&fun.registro)!= EOF){
                            if(buscaFun == fun.cpf){
                                    printf("Nome: %s\nEndereco: %s\nTelefone: %.0f\nCPF: %.0f\nCargo: %s\nRegistro: %.0f",fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro);
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
                        FILE *funcionario;    //PONTEIRO PARA ARQUIVO
                        funcionario = fopen("funcionario.txt", "a");
                        if(funcionario ==  NULL){
                            printf("Erro na abertura do arquivo!");
                            system("pause");
                            return ;
                        }
                        
                        GetFuncionario(&fun);
                        fprintf(funcionario,"%s %s %.0f %.0f %s %.0f\n", fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro);
                        fclose(funcionario);
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
						while(fscanf(funcionario,"%s %s %f %f %s %f", fun.nome,fun.endereco,&fun.telefone,&fun.cpf,fun.cargo,&fun.registro) != EOF){//LACO PARA LER TODAS AS LINHAS DO ARQUIVO                            
						if((tfun = fopen("tfun.txt","w+")) == NULL);// ABRIR ARQUIVO TEMPORARIO EM MODO ATUALIZACAO PARA LEITURA E/OU GRAVACAO "W+" SE ARQUIVO JA EXISTE, SERA APAGADO E CRIADDO UM NOVO
                        
								if (excluirREG != cl.cpf){// SELECIONE TODOS EXETO CPF
                                	fprintf(tfun,"%s %s %.0f %.0f %s %.0f\n", fun.nome,fun.endereco,fun.telefone,fun.cpf,fun.cargo,fun.registro); // SE SIM PRINTA CLIENTE ATUAL NO ARQUIVO TEMPORARIO
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
				}
			}
			break;
			
		}
	}while(opcao!=4);
}










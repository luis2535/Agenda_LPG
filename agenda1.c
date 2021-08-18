#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char rua[50];
    char numero[10];
    char complemento[30];
    char bairro[30];
    char cep[30];
    char cidade[30];
    char estado[30];
    char pais[30];
}Endereco;
typedef struct{
    char DDD[30];
    char num[30];
}Telefone;
typedef struct{
    int dia, mes, ano;
}Data;
typedef struct{
    char nome[50];
    char email[50];
    Endereco endereco;
    Telefone telefone;
    Data dt_aniversario;
}Agenda;
void le_pessoa (Agenda *a);
void mostra_pessoa(Agenda a);
void mostra_dados(Agenda a);
void mostra_aniversariante_do_mes(Agenda a, int b, int c);
void mostra_aniversariante_do_dia(Agenda a, int b, int c, int d);

int main(){
    int continuar = 1;
    int registros = 0;
    int i;
    char espaco[10], nome[50];
    Agenda *agenda;
    printf("\nAgenda iniciada\n");
    while(continuar == 1 ){
    printf("\nInforme o servico desejado:\n");
    printf("1 - Buscar dados de uma pessoa.\n");
    printf("2 - Aniversariantes do mes.\n");
    printf("3 - Aniversariantes do dia.\n");
    printf("4 - Adicionar registros na agenda.\n");
    printf("5 - Remover registros da agenda.\n");
    printf("6 - Exibir registros.\n");
    printf("7 - Encerrar o programa.\n");
    printf("\n");

    int opcao;
    scanf("%d",&opcao);
    switch(opcao){
        case 1 :
        printf("\nVoce escolheu a opcao Buscar dados de uma pessoa!\n");  
        if(registros == 0){
            printf("\nNao ha nenhum registro na agenda.\n");
        }else{
            printf("Informe o nome da pessoa a ser procurada:\n");
            int comparar, quantidade=0;
            gets(espaco);
            gets(nome);
            for(i=0;i<registros;i++){
                comparar = strcmp(nome, agenda[i].nome);
                if (comparar == 0){
                    quantidade++;
                    printf("\n");
                    printf("#%d\n",quantidade);
                 mostra_dados(agenda[i]);
             }
         }
         if(quantidade == 0){
             printf("\nNome nao encontrado na busca.\n");
         }
        }
        break;
        case 2 :
        printf("\nVoce escolheu a opcao Aniversariantes do mes!\n");
        if(registros == 0){
            printf("\nNao ha nenhum registro na agenda.\n");
        }else{
        printf("Informe o numero do mes que deseja pesquisar:\n");
        int mes;
        int cont=0;
        scanf("%d",&mes);
        for(i=0;i<registros;i++){
            mostra_aniversariante_do_mes(agenda[i], mes, cont);
            if (mes == agenda[i].dt_aniversario.mes){
                cont++;
            }
        }
            if(cont == 0){
                printf("\nNenhum aniversariante encontrado na busca.\n");
            }
        }
        break;
        case 3 :
        printf("\nVoce escolheu a opcao Aniversariantes do dia!\n");
        if(registros == 0){
            printf("\nNao ha nenhum registro na agenda.\n");
        }else{
            printf("Informe o dia e o mes do aniversario a pesquisar:\n");
            int dia, mes1;
            int aux=0;
            printf("Dia: ");
            scanf("%d",&dia);
            printf("Mes: ");
            scanf("%d",&mes1);
            for(i=0;i<registros;i++){
                mostra_aniversariante_do_dia(agenda[i],mes1,dia,aux);
                if(dia == agenda[i].dt_aniversario.dia && mes1 == agenda[i].dt_aniversario.mes){
                    aux++;                   
                }    
                }
            if(aux == 0){
                printf("\nNenhum aniversariante encontrado na busca.\n");
            }
        }
        break;
        case 4 :
        printf("\nVoce escolheu a opcao Adicionar registros na agenda!\n");
        printf("Quantos registros deseja adicionar?\n");
        int n;
        scanf("%d",&n);
        gets(espaco);
        if(registros==0){
            agenda = malloc(sizeof(Agenda)*n);
            registros = n;
            for(i=0;i<n;i++){
                le_pessoa(&agenda[i]);
                printf("\n");
            }
        }else{
            agenda = realloc(agenda , sizeof(Agenda)*(registros + n));
            for(i=registros;i<(registros+n);i++){
                le_pessoa(&agenda[i]);
                printf("\n");
            }
            registros = registros + n;
        }
        break;
        case 5 :
        printf("\nVoce escolheu a opcao Remover registros da agenda!\n");
        if(registros == 0){
            printf("\nNao ha nenhum registro na agenda.\n");
        }else{
            printf("Escolha o numero do registro que deseja excluir:\n");
            for(i=0;i<registros;i++){
                printf("#%d - %s\n",i+1, agenda[i].nome);
            }
            int excluir;
            scanf("%d",&excluir);
            if((excluir-1)!=registros){
                for(i=(excluir-1);i<registros;i++){
                agenda[i]=agenda[i+1];
            }
            }
            registros--;
            agenda = realloc(agenda, sizeof(Agenda)*registros);
            printf("Registro removido com sucesso!\n");
        }        
        break;
        case 6 :
        printf("\nVoce escolheu a opcao Exibir registros da agenda!\n");
        if(registros == 0){
            printf("\nNao ha nenhum registro na agenda.\n");
        }else{
            for(i=0;i<registros;i++){
                printf("#%d\n",i+1);
                mostra_pessoa(agenda[i]);
            }
        }    
        break;
        case 7 :
        printf("\nPrograma finalizado!\n");
        continuar = -1;
        break;
    }
    }
    free(agenda);   
    return 0;
}
void le_pessoa (Agenda *a){
    char vazio[10];
    printf("Digite o nome: ");
    gets(a->nome);
    printf("Digite o email: ");
    gets(a->email);
    printf("Digite a rua: ");
    gets(a->endereco.rua);
    printf("Digite o numero: ");
    gets(a->endereco.numero);
    printf("Digite o complemento: ");
    gets(a->endereco.complemento);
    printf("Digite o bairro: ");
    gets(a->endereco.bairro);
    printf("Digite o CEP: ");
    gets(a->endereco.cep);
    printf("Digite a cidade: ");
    gets(a->endereco.cidade);
    printf("Digite o estado: ");
    gets(a->endereco.estado);
    printf("Digite o pais: ");
    gets(a->endereco.pais);
    printf("Digite o DDD: ");
    gets(a->telefone.DDD);
    printf("Digite o numero do telefone: ");
    gets(a->telefone.num);
    printf("Digite a data do nascimento\n");
    printf("Digite o dia: ");
    scanf("%d",&a->dt_aniversario.dia);
    printf("Digite o mes: ");
    scanf("%d",&a->dt_aniversario.mes);
    printf("Digite o ano: ");
    scanf("%d",&a->dt_aniversario.ano);
    gets(vazio);
}
void mostra_pessoa(Agenda a){
    printf("Nome: %s\n",a.nome);
    printf("Email: %s\n",a.email);
    printf("Rua: %s\n",a.endereco.rua);
    printf("Numero: %s\n",a.endereco.numero);
    printf("Complemento: %s\n",a.endereco.complemento);
    printf("Bairro: %s\n",a.endereco.bairro);
    printf("CEP: %s\n",a.endereco.cep);
    printf("Cidade: %s\n",a.endereco.cidade);
    printf("Estado: %s\n",a.endereco.estado);
    printf("Pais: %s\n",a.endereco.pais);
    printf("DDD: %s\n",a.telefone.DDD);
    printf("Numero telefone: %s\n",a.telefone.num);
    printf("Dia do aniversario: %d\n",a.dt_aniversario.dia);
    printf("Mes do aniversario: %d\n",a.dt_aniversario.mes);
    printf("Ano do aniversario: %d\n",a.dt_aniversario.ano);
    printf("\n");
}
void mostra_dados(Agenda a){
    printf("Nome: %s\n",a.nome);
    printf("Email: %s\n",a.email);
    printf("Telefone: (%s) %s\n",a.telefone.DDD, a.telefone.num);
    printf("\n");
}
void mostra_aniversariante_do_mes(Agenda a, int b, int c){
    if(b == a.dt_aniversario.mes){
    printf("\n");
    printf("#%d\n",c+1);
    printf("Nome: %s\n",a.nome);
    printf("Aniversario: %d/%d/%d\n",a.dt_aniversario.dia, a.dt_aniversario.mes, a.dt_aniversario.ano);
    printf("\n");
    }
}
void mostra_aniversariante_do_dia(Agenda a, int b, int c, int d){
    if(b == a.dt_aniversario.mes && c == a.dt_aniversario.dia){
    printf("\n");
    printf("#%d\n",d+1);
    printf("Nome: %s\n",a.nome);
    printf("Aniversario: %d/%d/%d\n",a.dt_aniversario.dia, a.dt_aniversario.mes, a.dt_aniversario.ano);
    printf("\n");
    }
}
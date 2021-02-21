/* Alunos:
Gabriel Alves Hussein 17/0103200
Victor Amaral 17/0164411
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Suspeitos{
    int valido;
    char nome[50];
}SUSPEITOS;

void mostraSuspeito(SUSPEITOS *suspeitos){
    for(int i = 0;i < 100; i++){
        if(suspeitos[i].valido != 0){
            printf("%d - %s\n",i+1,suspeitos[i].nome);
        }
    }
}

void adicionaSuspeito(int *nSuspeitos,SUSPEITOS *suspeitos){
    char nome[50];

    int i = 0;
    if(*nSuspeitos < 100){
        while(suspeitos[i].valido != 0){
            i++;
        }
        printf("Informe o nome do suspeito a ser cadastrado:\n");
        scanf("%s", nome);
        strcpy(suspeitos[i].nome, nome);
        suspeitos[i].valido = 1;
        *nSuspeitos = *nSuspeitos + 1;

    }
    else{
        printf("Numero maximo de suspeitos cadastrados.\n");
    }
}

void removeSuspeito(int *nSuspeitos,SUSPEITOS *suspeitos,int relacoes[100][100]){
    int suspeito;

    mostraSuspeito(suspeitos);
    printf("Informe o numero do suspeito a ser removido:\n");
    scanf("%d",&suspeito);
    if(suspeitos[suspeito-1].valido = 1){
      suspeitos[suspeito-1].valido = 0;
      for(int i = 0;i < 100;i++){
        relacoes[suspeito-1][i] = 0;
        relacoes[i][suspeito-1] = 0;
      }
      *nSuspeitos = *nSuspeitos - 1;
    }
    else{
        printf("Numero informado nao corresponde ao de um suspeito cadastrado.\n");
    }
}

void mostraMenu(int nSuspeitos){
  //system("clear");
  printf("\n");
  printf(" ====================================================\n");
  printf("|                 Rede de Suspeitos                  |\n");
  printf("|             >>>>>>>>> Menu <<<<<<<<<               |\n");
  printf("| 1 - Gerar lista de contatos para um suspeito       |\n");
  printf("| 2 - Mostrar todas os suspeitos                     |\n");
  printf("| 3 - Adicionar mais algum suspeito(%d restantes)    |\n",100 - nSuspeitos);
  printf("| 4 - Remover algum suspeito(%d cadastradas)         |\n", nSuspeitos);
  printf("| 5 - Adicionar  relação                             |\n");
  printf("| 6 - Remover    relação                             |\n");
  printf("| 7 - Visualizar todas as relações                   |\n");
  printf("| 0 - Sair                                           |\n");
  printf(" ====================================================\n");
  printf("Sua opcao: ");
}

void adicionaRelacao(SUSPEITOS *suspeitos,int relacoes[100][100]){
    int pessoa1,pessoa2;
    mostraSuspeito(suspeitos);
    printf("Digite o numero dos suspeitos que mantem contato:");
    scanf("%d",&pessoa1);
    scanf("%d",&pessoa2);
    if(suspeitos[pessoa1-1].valido == 1 && suspeitos[pessoa2-1].valido == 1){
      if(relacoes[pessoa1-1][pessoa2-1] == 0){
         relacoes[pessoa1-1][pessoa2-1] = 1;
         relacoes[pessoa2-1][pessoa1-1] = 1;
      }
      else{
          printf("Esses suspeitos ja possuem relacionamento, aperte enter para voltar ao menu.");
          getc(stdin);
      }
    }
    else{
      printf("Algum dos numeros informados nao corresponde a nenhum suspeito cadastrado, aperte enter para voltar ao menu.");
      getc(stdin);
    }
}

void removeRelacao(SUSPEITOS *suspeitos,int relacoes[100][100]){
    int pessoa1,pessoa2;
    mostraSuspeito(suspeitos);
    printf("Digite o numero dos suspeitos que deixaram de ter contato:");
    scanf("%d",&pessoa1);
    scanf("%d",&pessoa2);
    if(suspeitos[pessoa1-1].valido == 1 && suspeitos[pessoa2-1].valido == 1){
      if(relacoes[pessoa1][pessoa2] == 1){
         relacoes[pessoa1][pessoa2] = 0;
         relacoes[pessoa2][pessoa1] = 0;
      }
      else{
          printf("Esses suspeitos ja nao mantem uma relacao registrada, aperte enter para voltar ao menu.");
          getc(stdin);
      }
    }
    else{
      printf("Algum dos numeros informados nao corresponde a nenhum suspeito cadastrado, aperte enter para voltar ao menu.");
      getc(stdin);
    }
}

void listaSuspeitos(int pessoa,SUSPEITOS *suspeitos,int relacoes[100][100]){
    for(int i = 0;i < 100; i++){
        if(relacoes[pessoa-1][i] != 0){
            printf("%d - %s\n",i+1,suspeitos[i].nome);
        }
    }
}

void geraLista(SUSPEITOS * suspeitos, int relacoes[100][100], int nSuspeitos);

int max = 99;

int main(){
    SUSPEITOS suspeitos[100];
    int relacoes[100][100] = {0};
    int nSuspeitos = 0;
    int opcao = 0;


    for(int i = 0;i < 100; i++)
        suspeitos[i].valido = 0;

    geraLista(suspeitos, relacoes, nSuspeitos);

    do{
        mostraMenu(nSuspeitos);
        scanf("%d",&opcao);
        system("clear");
        switch(opcao){
        case 1:
            
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
            break;
        case 2:
            printf("Lista de suspeitos cadastrados:\n");
            mostraSuspeito(suspeitos);
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
            break;
        case 3:
            adicionaSuspeito(&nSuspeitos,suspeitos);
            break;
        case 4:
            removeSuspeito(&nSuspeitos,suspeitos,relacoes);
            break;
        case 5:
            adicionaRelacao(suspeitos,relacoes);
            break;
        case 6:
            break;
            removeRelacao(suspeitos,relacoes);
        case 7:
            for(int i = 0;i < 100; i++){
               if(suspeitos[i].valido != 0){
                  printf("Contatos de %s:\n",suspeitos[i].nome);
                  listaSuspeitos(i+1, suspeitos, relacoes);
                  printf("\n");
               }
            }
            printf("Aperte enter para voltar ao menu.");
            getc(stdin);
        }

  }while(opcao != 0);
    

    return 0;
}

void geraLista(SUSPEITOS *suspeitos, int relacoes[100][100], int nSuspeitos){
    strcpy(suspeitos[0].nome, "Jorge");
    suspeitos[0].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[1].nome, "Neymar");
    suspeitos[1].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[2].nome, "Ricardo");
    suspeitos[2].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[3].nome, "Juninho");
    suspeitos[3].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[4].nome, "Pedro");
    suspeitos[4].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[5].nome, "Jonas");
    suspeitos[5].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[6].nome, "Amanda");
    suspeitos[6].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[7].nome, "Julia");
    suspeitos[7].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[8].nome, "Maria");
    suspeitos[8].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[9].nome, "Cleyton");
    suspeitos[9].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[10].nome, "Tulio");
    suspeitos[10].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[11].nome, "Emanuel");
    suspeitos[11].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[12].nome, "Jessica");
    suspeitos[12].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[13].nome, "Luisa");
    suspeitos[13].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[14].nome, "Ana");
    suspeitos[14].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[15].nome, "Jose");
    suspeitos[15].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[16].nome, "Kauan");
    suspeitos[16].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[17].nome, "Peter");
    suspeitos[17].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[18].nome, "Maikon");
    suspeitos[18].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[19].nome, "Victor");
    suspeitos[19].valido = 1;
    nSuspeitos++;
    strcpy(suspeitos[20].nome, "Hussein");
    suspeitos[20].valido = 1;
    nSuspeitos++;

    relacoes[0][1] = 1;
    relacoes[1][0] = 1;
    relacoes[1][2] = 1;
    relacoes[2][1] = 1;
    relacoes[3][2] = 1;
    relacoes[2][3] = 1;
    relacoes[19][2] = 1;
    relacoes[2][19] = 1;
    relacoes[19][3] = 1;
    relacoes[3][19] = 1;
    relacoes[14][3] = 1;
    relacoes[3][14] = 1;
    relacoes[14][19] = 1;
    relacoes[19][14] = 1;
    relacoes[1][17] = 1;
    relacoes[17][1] = 1;
    relacoes[17][13] = 1;
    relacoes[13][17] = 1;
    relacoes[4][7] = 1;
    relacoes[7][4] = 1;
    relacoes[18][4] = 1;
    relacoes[4][18] = 1;
    relacoes[4][15] = 1;
    relacoes[15][4] = 1;
    relacoes[15][16] = 1;
    relacoes[16][15] = 1;
    relacoes[10][16] = 1;
    relacoes[16][10] = 1;
    relacoes[0][18] = 1;
    relacoes[18][0] = 1;
    relacoes[1][3] = 1;
    relacoes[3][1] = 1;
    relacoes[1][4] = 1;
    relacoes[4][1] = 1;
    relacoes[1][5] = 1;
    relacoes[5][1] = 1;
    relacoes[6][8] = 1;
    relacoes[8][6] = 1;
    relacoes[9][11] = 1;
    relacoes[11][9] = 1;
    relacoes[12][6] = 1;
    relacoes[6][12] = 1;
    relacoes[8][1] = 1;
    relacoes[8][1] = 1;
}
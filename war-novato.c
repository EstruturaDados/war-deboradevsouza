#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca que tem funções para manipular strings em C

#define MAX_TERRITORIOS 5
#define TAM_STRING 100

struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função principal
int main() {
    struct Territorio biblioteca[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    do {
        printf("=================================\n");
        printf("    JOGO WAR - NÍVEL INICIANTE\n");
        printf("=================================\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("---------------------------------\n");
        printf("Escolha uma opção: \n");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
            printf("--- Cadastro de um novo território --- \n\n");

            if (totalTerritorios < MAX_TERRITORIOS) {
                printf("Digite o nome do território: ");
                fgets(biblioteca[totalTerritorios].nome, TAM_STRING, stdin);

                printf("Digite o nome da cor do território: ");
                fgets(biblioteca[totalTerritorios].cor, TAM_STRING, stdin);

                biblioteca[totalTerritorios].nome[strcspn(biblioteca[totalTerritorios].nome, "\n")] = '\0';
                biblioteca[totalTerritorios].cor[strcspn(biblioteca[totalTerritorios].cor, "\n")] = '\0';

                printf("Digite o número de tropas:");
                scanf("%d", &biblioteca[totalTerritorios].tropas);

                limparBufferEntrada();

                totalTerritorios++;

                printf("\nTerritório cadastrado com sucesso!\n");

            } else {
                printf("Você já cadastrou todos os territórios possíveis \n");
            }

            printf("\nPressione Enter para continuar...");
            getchar(); 
            break;

            case 2: 
                printf("--- Lista de territórios cadastrados ---");

                if (totalTerritorios == 0)
                {
                    printf("Nenhum território cadastrado ainda. \n");
                } else {
                    for (int i = 0; i < totalTerritorios; i++)
                    {
                        printf("----------------------------\n");
                        printf("Território: %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[1].nome);
                        printf("Cor: %s\n", biblioteca[1].cor);
                        printf("Tropas: %d\n", biblioteca[1].tropas);
                    }
                    printf("-------------------------------\n");
                    
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

                case 0: 
                    printf("\nSaindo do sistema. \n");
                    break;
                
        
        default: 
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar.");
                getchar();
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
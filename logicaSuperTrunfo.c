#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[50];
    char cidade[50];
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para mostrar os dados da carta
void mostrarCarta(Carta c) {
    printf("\n Carta - %s (%s)\n", c.cidade, c.estado);
    printf("Codigo: %d\n", c.codigo);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
}

int main() {
    Carta c1, c2;
    int opcao;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf("%s", c1.estado);
    printf("Cidade: ");
    scanf("%s", c1.cidade);
    printf("Codigo: ");
    scanf("%d", &c1.codigo);
    printf("Populacao: ");
    scanf("%d", &c1.populacao);
    printf("Area (em km2): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c1.pontos_turisticos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf("%s", c2.estado);
    printf("Cidade: ");
    scanf("%s", c2.cidade);
    printf("Codigo: ");
    scanf("%d", &c2.codigo);
    printf("Populacao: ");
    scanf("%d", &c2.populacao);
    printf("Area (em km2): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &c2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // Iniciar a comparação
    printf("\n=== Selecione o atributo para comparaçao ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (Populacao / Area)\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    // Exibindo as cartas
    mostrarCarta(c1);
    mostrarCarta(c2);

    printf("\n=== Resultado da Comparaçao ===\n");

    // Exibição de resultados
    switch(opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf(" Vencedora: %s\n", c1.cidade);
            else if (c2.populacao > c1.populacao)
                printf(" Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            if (c1.area > c2.area)
                printf(" Vencedora: %s\n", c1.cidade);
            else if (c2.area > c1.area)
                printf(" Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            if (c1.pib > c2.pib)
                printf(" Vencedora: %s\n", c1.cidade);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf(" Vencedora: %s\n", c1.cidade);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf(" Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 5: {
            float densidade1 = (float)c1.populacao / c1.area;
            float densidade2 = (float)c2.populacao / c2.area;
            if (densidade1 < densidade2)
                printf(" Vencedora (menor densidade): %s\n", c1.cidade);
            else if (densidade2 < densidade1)
                printf(" Vencedora (menor densidade): %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        }
        default:
            printf(" Opção inválida.\n");
    }

    return 0;
}

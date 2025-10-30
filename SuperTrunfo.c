#include <stdio.h>

typedef struct {
    char estado[4];
    char codigo[9];
    char nome[64];
    unsigned long int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
    float super_poder;
} Carta;

//populacao + area + pib + pontos + pib_per_capita + (1/densidade)
void calcular(Carta *c) {
    if (c->area > 0)
        c->densidade = (double)c->populacao / c->area;
    else
        c->densidade = 0;

    if (c->populacao > 0)
        c->pib_per_capita = c->pib / (double)c->populacao;
    else
        c->pib_per_capita = 0;

    double inv_dens = (c->densidade > 0) ? 1.0 / c->densidade : 0.0;
    double soma = (double)c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + inv_dens;
    c->super_poder = (float)soma;
}

int maior(double a, double b) {
    if (a > b) return 1;
    if (b > a) return 0;
    return -1;
}

int menor(double a, double b) {
    if (a < b) return 1;
    if (b < a) return 0;
    return -1;
}

void resultado(char *nome, int r) {
    if (r == 1)
        printf("%s: Carta 1 venceu (1)\n", nome);
    else if (r == 0)
        printf("%s: Carta 2 venceu (0)\n", nome);
    else
        printf("%s: Empate (0)\n", nome);
}

int main() {
    Carta c1, c2;

    printf("=== Carta 1 ===\n");
    printf("Estado: ");
    scanf("%s", c1.estado);
    printf("Codigo: ");
    scanf("%s", c1.codigo);
    printf("Nome: ");
    getchar();
    fgets(c1.nome, 64, stdin);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%lf", &c1.area);
    printf("PIB: ");
    scanf("%lf", &c1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c1.pontos_turisticos);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: ");
    scanf("%s", c2.estado);
    printf("Codigo: ");
    scanf("%s", c2.codigo);
    printf("Nome: ");
    getchar();
    fgets(c2.nome, 64, stdin);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%lf", &c2.area);
    printf("PIB: ");
    scanf("%lf", &c2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c2.pontos_turisticos);

    //calcula métricas das duas cartas 
    calcular(&c1);
    calcular(&c2);
    
    //compara atributo por atributo (densidade: menor vence)
    printf("\nComparacao de Cartas:\n");
    resultado("Populacao", maior((double)c1.populacao, (double)c2.populacao));
    resultado("Area", maior(c1.area, c2.area));
    resultado("PIB", maior(c1.pib, c2.pib));
    resultado("Pontos Turisticos", maior((double)c1.pontos_turisticos, (double)c2.pontos_turisticos));
    resultado("Densidade Populacional", menor(c1.densidade, c2.densidade));
    resultado("PIB per Capita", maior(c1.pib_per_capita, c2.pib_per_capita));
    resultado("Super Poder", maior(c1.super_poder, c2.super_poder));

    return 0;
}

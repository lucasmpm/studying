#include <stdio.h>
#include <string.h>

int main() {
    // ---------- Variáveis da Carta 1 ----------
    char estado1;
    char codigo1[4];
    char cidade1[100];
    unsigned long populacao1; 
    float area1;
    float pib1;
    int pontos1;

    // Cálculos carta 1
    float densidade1;
    float pib_percapita1;
    float superpoder1;

    // ---------- Variáveis da Carta 2 ----------
    char estado2;
    char codigo2[4];
    char cidade2[100];
    unsigned long populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Cálculos carta 2
    float densidade2;
    float pib_percapita2;
    float superpoder2;

    // ---------- Entrada Carta 1 ----------
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta: ");
    scanf("%3s", codigo1);

    getchar();

    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km2): ");
    scanf("%f", &area1);

    printf("PIB (bilhões): ");
    scanf("%f", &pib1);

    printf("Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // ---------- Entrada Carta 2 ----------
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta: ");
    scanf("%3s", codigo2);

    getchar();

    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km2): ");
    scanf("%f", &area2);

    printf("PIB (bilhões): ");
    scanf("%f", &pib2);

    printf("Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // ---------- Cálculos ----------
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pib_percapita1 = (pib1 * 1e9f) / (float)populacao1;
    pib_percapita2 = (pib2 * 1e9f) / (float)populacao2;

    // inverso da densidade (assumindo densidade != 0)
    float inv_dens1 = 1.0f / densidade1;
    float inv_dens2 = 1.0f / densidade2;

    // Super Poder (tudo virando float)
    superpoder1 = (float)populacao1 + area1 + (pib1 * 1e9f) + (float)pontos1 + pib_percapita1 + inv_dens1;
    superpoder2 = (float)populacao2 + area2 + (pib2 * 1e9f) + (float)pontos2 + pib_percapita2 + inv_dens2;

    // ---------- Comparações ----------
    // Só usando comparação direta que retorna 0 ou 1
    int cmp_pop   = (populacao1 > populacao2);
    int cmp_area  = (area1 > area2);
    int cmp_pib   = (pib1 > pib2);
    int cmp_pts   = (pontos1 > pontos2);

    // densidade: menor vence → invertendo comparação
    int cmp_dens  = (densidade1 < densidade2);

    int cmp_pc    = (pib_percapita1 > pib_percapita2);
    int cmp_super = (superpoder1 > superpoder2);

    // ---------- Saída ----------
    printf("\n\n===== RESULTADO DAS COMPARAÇÕES =====\n\n");

    printf("População: Carta %d venceu (%d)\n", cmp_pop ? 1 : 2, cmp_pop);
    printf("Área: Carta %d venceu (%d)\n", cmp_area ? 1 : 2, cmp_area);
    printf("PIB: Carta %d venceu (%d)\n", cmp_pib ? 1 : 2, cmp_pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", cmp_pts ? 1 : 2, cmp_pts);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", cmp_dens ? 1 : 2, cmp_dens);
    printf("PIB per Capita: Carta %d venceu (%d)\n", cmp_pc ? 1 : 2, cmp_pc);
    printf("Super Poder: Carta %d venceu (%d)\n", cmp_super ? 1 : 2, cmp_super);

    return 0;
}

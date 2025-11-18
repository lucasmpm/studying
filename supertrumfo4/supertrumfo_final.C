#include <stdio.h>
#include <string.h>

int main() {
    // ---------- Variáveis da Carta 1 ----------
    char estado1;
    char codigo1[4];       // ex: "A01" + '\0'
    char cidade1[100];
    unsigned long populacao1; // agora é unsigned long para números maiores
    float area1;           // km^2
    float pib1;            // em bilhões de reais (entrada)
    int pontos1;

    // Calculados para Carta 1
    float densidade1;      // hab / km^2
    float pib_percapita1;  // reais por habitante
    float superpoder1;     // soma de atributos (float)

    // ---------- Variáveis da Carta 2 ----------
    char estado2;
    char codigo2[4];
    char cidade2[100];
    unsigned long populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Calculados para Carta 2
    float densidade2;
    float pib_percapita2;
    float superpoder2;

    // ---------- ENTRADA DA CARTA 1 ----------
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    // limpar buffer antes do fgets
    getchar();

    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // retirar o '\n' do final

    printf("População: ");
    scanf("%lu", &populacao1); // %lu para unsigned long

    printf("Área (em km^2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // ---------- ENTRADA DA CARTA 2 ----------
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    getchar();

    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km^2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // ---------- CÁLCULOS ----------
    // segurança: evitar divisão por zero
    if (area1 <= 0.0f) {
        // se a área for zero ou negativa, evita divisão por zero
        densidade1 = 0.0f;
    } else {
        // casting da população para float antes de dividir
        densidade1 = (float)populacao1 / area1;
    }

    if (populacao1 == 0UL) {
        // se populacao = 0, evita dividir por zero
        pib_percapita1 = 0.0f;
    } else {
        // PIB está em bilhões -> converto para reais: *1e9
        pib_percapita1 = (pib1 * 1e9f) / (float)populacao1;
    }

    if (area2 <= 0.0f) {
        densidade2 = 0.0f;
    } else {
        densidade2 = (float)populacao2 / area2;
    }

    if (populacao2 == 0UL) {
        pib_percapita2 = 0.0f;
    } else {
        pib_percapita2 = (pib2 * 1e9f) / (float)populacao2;
    }

    // ---------- CÁLCULO DO SUPER PODER ----------
    // Repare que aqui eu somo valores de tipos diferentes.
    // Eu converto tudo para float para fazer a soma.
    // - populacao: cast para float (pode perder precisão se for muito grande)
    // - area: já float
    // - pib: eu considero o PIB em REAIS (pib * 1e9f)
    // - pontos: cast para float
    // - pib_percapita: já em float
    // - inverso da densidade: 1 / densidade (quanto menor densidade, maior é o inverso)
    //   se densidade for zero, evito dividir por zero e uso 0.0f no inverso.
    float inv_dens1 = (densidade1 > 0.0f) ? (1.0f / densidade1) : 0.0f;
    float inv_dens2 = (densidade2 > 0.0f) ? (1.0f / densidade2) : 0.0f;

    superpoder1 = (float)populacao1        // população como float
                  + area1                  // área
                  + (pib1 * 1e9f)          // PIB convertido para reais
                  + (float)pontos1         // pontos turísticos
                  + pib_percapita1         // PIB per capita (reais)
                  + inv_dens1;             // inverso da densidade

    superpoder2 = (float)populacao2
                  + area2
                  + (pib2 * 1e9f)
                  + (float)pontos2
                  + pib_percapita2
                  + inv_dens2;

    // ---------- SAÍDA FORMATADA ----------
    printf("\n\n===== CARTA 1 =====\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_percapita1);
    printf("Super Poder: %.2f\n", superpoder1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_percapita2);
    printf("Super Poder: %.2f\n", superpoder2);

    // ---------- COMPARAÇÕES ----------
    // 1 significa Carta 1 venceu, 0 significa Carta 2 venceu
    // População: maior vence
    int cmp_populacao = (populacao1 > populacao2) ? 1 : 0;

    // Área: maior vence
    int cmp_area = (area1 > area2) ? 1 : 0;

    // PIB: maior vence (uso o PIB em bilhões comparando pib1 e pib2)
    int cmp_pib = (pib1 > pib2) ? 1 : 0;

    // Pontos Turísticos: maior vence
    int cmp_pontos = (pontos1 > pontos2) ? 1 : 0;

    // Densidade Populacional: menor vence -> se densidade1 < densidade2, Carta1 vence
    int cmp_densidade = (densidade1 < densidade2) ? 1 : 0;

    // PIB per Capita: maior vence
    int cmp_pib_percapita = (pib_percapita1 > pib_percapita2) ? 1 : 0;

    // Super Poder: maior vence
    int cmp_superpoder = (superpoder1 > superpoder2) ? 1 : 0;

    // ---------- IMPRIMIR RESULTADOS DAS COMPARAÇÕES ----------
    printf("\n\nComparação de Cartas:\n\n");

    printf("População: Carta %s ( %d )\n", cmp_populacao ? "1 venceu" : "2 venceu", cmp_populacao);
    printf("Área: Carta %s ( %d )\n", cmp_area ? "1 venceu" : "2 venceu", cmp_area);
    printf("PIB: Carta %s ( %d )\n", cmp_pib ? "1 venceu" : "2 venceu", cmp_pib);
    printf("Pontos Turísticos: Carta %s ( %d )\n", cmp_pontos ? "1 venceu" : "2 venceu", cmp_pontos);
    printf("Densidade Populacional: Carta %s ( %d )\n", cmp_densidade ? "1 venceu" : "2 venceu", cmp_densidade);
    printf("PIB per Capita: Carta %s ( %d )\n", cmp_pib_percapita ? "1 venceu" : "2 venceu", cmp_pib_percapita);
    printf("Super Poder: Carta %s ( %d )\n", cmp_superpoder ? "1 venceu" : "2 venceu", cmp_superpoder);

    return 0;
}

#include <stdio.h>


#define qtd_bebidas  15
#define qtd_doces   24
#define qtd_salgados 14


char nomes_bebidas[qtd_bebidas][75] = {
    "Café",
    "Cappuccino",
    "Café latte",
    "Macchiato",
    "Americano",
    "Caramel Macchiato",
    "Iced latte",
    "Chocolate quente cremoso",
    "Chá de hibisco com frutas vermelhas",
    "Suco de laranja natural",
    "Suco natural de frutas vermelhas",
    "Suco natural de abacaxi com hortelã",
    "Água com gás",
    "Suco natural de pêssego",
    "Água sem gás"
};

float precos_bebidas[qtd_bebidas] = {
    7.50, 13.00, 11.00, 9.00, 8.00,
    16.50, 15.00, 14.00, 10.50, 11.00,
    15.50, 12.00, 14.00, 12.00, 5.50
};

int estoque_bebidas[qtd_bebidas] = {
    20, 20, 20, 20, 20,
    15, 15, 15, 15, 15,
    15, 15, 20, 15, 30
};


char nomes_doces[qtd_doces][75] = {
    "Pastel doce",
    "Donut de chocolate",
    "Sonho recheado",
    "Bolo gelado",
    "Bolo com cobertura de chocolate",
    "Bolo de baunilha com cobertura de leite ninho",
    "Pudim",
    "Cookie de baunilha com gotas de chocolate",
    "Brownie de chocolate",
    "Torta de limão siciliano",
    "Cheesecake de frutas vermelhas",
    "Banoffee pie",
    "Torta holandesa",
    "Mil-folhas tradicional",
    "Cinnamon Roll",
    "Palha italiana de brigadeiro",
    "Bolo de laranja com calda",
    "Muffin de mirtilo",
    "Macarons",
    "Bolo de cenoura com cobertura de brigadeiro",
    "Brigadeiro tradicional",
    "Brownie vegano e sem glúten",
    "Bolo de banana integral",
    "Torta de maçã"
};

float precos_doces[qtd_doces] = {
    10.00, 11.50, 10.00, 12.00, 11.00,
    14.00, 11.00, 14.00, 11.00, 9.50,
    11.50, 14.00, 11.50, 16.00, 15.50,
    15.00, 3.50, 9.00, 9.00, 13.50,
    8.00, 12.50, 6.00, 14.00
};

int estoque_doces[qtd_doces] = {
    15, 15, 15, 10, 10,
    10, 10, 15, 15, 10,
    10, 10, 10, 10, 10,
    10, 10, 15, 15, 10,
    30, 10, 10, 10
};


char nomes_salgados[qtd_salgados][75] = {
    "Pão de queijo mineiro",
    "Croissant recheado",
    "Coxinha de frango",
    "Avocado Toast",
    "Quiche de alho-poró",
    "Folhado com requeijão",
    "Folhado de ricota e espinafre",
    "Empada de palmito",
    "Empada de frango",
    "Pastel de carne",
    "Pastel de queijo e presunto",
    "Esfirra de carne",
    "Esfirra de queijo",
    "Esfirra de calabresa"
};

float precos_salgados[qtd_salgados] = {
    6.50, 16.00, 10.00, 24.00, 14.50,
    12.00, 12.00, 9.00, 9.00, 11.00,
    11.00, 9.50, 9.50, 9.50
};

int estoque_salgados[qtd_salgados] = {
    30, 15, 20, 10, 10,
    15, 15, 20, 20, 20,
    20, 20, 20, 20
};


int carrinho_bebidas[qtd_bebidas] = {0};
int carrinho_doces[qtd_doces] = {0};
int carrinho_salgados[qtd_salgados] = {0};


void escolher_bebidas() {
    printf("\n===== BEBIDAS =====\n");
    for (int i = 0; i < qtd_bebidas; i++) {
        printf("%d - %s | R$ %.2f | estoque: %d\n",
               i, nomes_bebidas[i], precos_bebidas[i], estoque_bebidas[i]);
    }
}

void escolher_doces() {
    printf("\n===== DOCES =====\n");
    for (int i = 0; i < qtd_doces; i++) {
        printf("%d - %s | R$ %.2f | estoque: %d\n",
               i, nomes_doces[i], precos_doces[i], estoque_doces[i]);
    }
}

void escolher_salgados() {
    printf("\n===== SALGADOS =====\n");
    for (int i = 0; i < qtd_salgados; i++) {
        printf("%d - %s | R$ %.2f | estoque: %d\n",
               i, nomes_salgados[i], precos_salgados[i], estoque_salgados[i]);
    }
}



void escolher_bebida() {
    int codigo, quantidade;
    escolher_bebidas();
    printf("\nDigite o código da bebida: ");
    scanf("%d", &codigo);

    if (codigo < 0 || codigo >= qtd_bebidas) {
        printf("Código inválido!\n");
        return;
    }

    printf("Quantos?: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    if (quantidade > estoque_bebidas[codigo]) {
        printf("Estoque insuficiente! Só temos %d.\n", estoque_bebidas[codigo]);
        return;
    }

    carrinho_bebidas[codigo] = carrinho_bebidas[codigo] + quantidade;
    estoque_bebidas[codigo] = estoque_bebidas[codigo] - quantidade;

    printf("Adicionado: %d x %s\n", quantidade, nomes_bebidas[codigo]);
}

void escolher_doce() {
    int codigo, quantidade;
    escolher_doces();
    printf("\nDigite o código do doce: ");
    scanf("%d", &codigo);

    if (codigo < 0 || codigo >= qtd_doces) {
        printf("Código inválido!\n");
        return;
    }

    printf("Quantos?: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    if (quantidade > estoque_doces[codigo]) {
        printf("Estoque insuficiente! Só temos %d.\n", estoque_doces[codigo]);
        return;
    }

    carrinho_doces[codigo] = carrinho_doces[codigo] + quantidade;
    estoque_doces[codigo] = estoque_doces[codigo] - quantidade;

    printf("Adicionado: %d x %s\n", quantidade, nomes_doces[codigo]);
}

void escolher_salgado() {
    int codigo, quantidade;
    escolher_salgados();
    printf("\nDigite o código do salgado: ");
    scanf("%d", &codigo);

    if (codigo < 0 || codigo >= qtd_salgados) {
        printf("Código inválido!\n");
        return;
    }

    printf("Quantos?: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    if (quantidade > estoque_salgados[codigo]) {
        printf("Estoque insuficiente! Só temos %d.\n", estoque_salgados[codigo]);
        return;
    }

    carrinho_salgados[codigo] = carrinho_salgados[codigo] + quantidade;
    estoque_salgados[codigo] = estoque_salgados[codigo] - quantidade;

    printf("Adicionado: %d x %s\n", quantidade, nomes_salgados[codigo]);
}



void mostra_compra() {
    float total = 0;
    float subtotal;
    int encontrou = 0;

    printf("\n===== SUA COMPRA =====\n");

    for (int i = 0; i < qtd_bebidas; i++) {
        if (carrinho_bebidas[i] > 0) {
            encontrou = 1;
            subtotal = carrinho_bebidas[i] * precos_bebidas[i];
            printf("[Bebida] %s | %d x R$ %.2f = R$ %.2f\n",
                   nomes_bebidas[i], carrinho_bebidas[i],
                   precos_bebidas[i], subtotal);
            total = total + subtotal;
        }
    }

    for (int i = 0; i < qtd_doces; i++) {
        if (carrinho_doces[i] > 0) {
            encontrou = 1;
            subtotal = carrinho_doces[i] * precos_doces[i];
            printf("[Doce] %s | %d x R$ %.2f = R$ %.2f\n",
                   nomes_doces[i], carrinho_doces[i],
                   precos_doces[i], subtotal);
            total = total + subtotal;
        }
    }

    for (int i = 0; i <qtd_salgados; i++) {
        if (carrinho_salgados[i] > 0) {
            encontrou = 1;
            subtotal = carrinho_salgados[i] * precos_salgados[i];
            printf("[Salgado] %s | %d x R$ %.2f = R$ %.2f\n",
                   nomes_salgados[i], carrinho_salgados[i],
                   precos_salgados[i], subtotal);
            total = total + subtotal;
        }
    }

    printf("--------------------------\n");
    printf("TOTAL: R$ %.2f\n", total);
}

int main() {

    printf("  ______ ___   _      _     ____   ____ ___  _____ _____ \n");
    printf("  |  ___/ _ \\ | |    | |   / ___| / ___/ _ \\|  ___|  ___|\n");
    printf("  | |_ / /_\\ \\| |    | |   \\___ \\| |  | | | | |_  | |_   \n");
    printf("  |  _||  _  || |___ | |___ ___) | |__| |_| |  _| |  _|  \n");
    printf("  |_|  |_| |_|\\_____/\\_____/____/ \\____\\___/|_|   |_|    \n");
    printf("\n");
    printf("       - QUE TAL COMEÇAR O DIA COM UM CAFÉ? -\n");

    int opcao;

    do {

        printf("\n========== MENU ==========\n");
        printf("1 - Escolher Bebida\n");
        printf("2 - Escolher Doce\n");
        printf("3 - Escolher Salgado\n");
        printf("4 - Ver compra\n");
        printf("0 - Finalizar\n");
        printf("==========================\n");

        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        switch (opcao) {

            case 1:
                escolher_bebida();
                break;

            case 2:
                escolher_doce();
                break;

            case 3:
                escolher_salgado();
                break;

            case 4:
                mostra_compra();
                break;

            case 0:
                printf("\nFinalizando compra...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    printf("\n========== RESUMO DA COMPRA ==========\n");

    mostra_compra();

    printf("\nOBRIGADA PELA COMPRA! VOLTE SEMPRE.\n");

    return 0;
}

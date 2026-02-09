#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 20
#define MAX_MOV 50

typedef struct {
    int cod;
    char nome[30];
    int qtd;
    float valor;
} Produto;

typedef struct {
    int codProd;
    int tipo;
    int qtd;
} Mov;

Produto prod[MAX_PRODUTOS];
Mov movimentos[MAX_MOV];

int totProd = 0;
int totMov = 0;

void cadProd() {
    printf("\nCadastrando produto...\n");

    printf("Codigo: ");
    scanf("%d", &prod[totProd].cod);

    printf("Nome: ");
    getchar();
    fgets(prod[totProd].nome, 30, stdin);
    prod[totProd].nome[strcspn(prod[totProd].nome, "\n")] = 0;

    printf("Quantidade inicial: ");
    scanf("%d", &prod[totProd].qtd);

    printf("Valor do produto: ");
    scanf("%f", &prod[totProd].valor);

    totProd++;
    printf("Produto cadastrado!\n");
}

int achaProd(int cod) {
    int i;
    for (i = 0; i < totProd; i++) {
        if (prod[i].cod == cod) {
            return i;
        }
    }
    return -1;
}

void mover(int tipo) {
    int cod, q;

    if (tipo == 1) {
        printf("\nEntrada de estoque\n");
    } else {
        printf("\nSaida de estoque\n");
    }

    printf("Codigo do produto: ");
    scanf("%d", &cod);

    int pos = achaProd(cod);
    if (pos == -1) {
        printf("Nao achei esse produto.\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &q);

    if (tipo == 2) { 
        if (q > prod[pos].qtd) {
            printf("Nao tem tudo isso no estoque!\n");
            return;
        }
        prod[pos].qtd -= q;
    } else {
        prod[pos].qtd += q;
    }

    movimentos[totMov].codProd = cod;
    movimentos[totMov].tipo = tipo;
    movimentos[totMov].qtd = q;
    totMov++;

    printf("Movimentacao feita!\n");
}

void consulta() {
    int cod;
    printf("\nCodigo do produto: ");
    scanf("%d", &cod);

    int pos = achaProd(cod);
    if (pos == -1) {
        printf("Nao achei esse produto.\n");
        return;
    }

    printf("\nProduto: %s\n", prod[pos].nome);
    printf("Estoque: %d\n", prod[pos].qtd);
    printf("Valor: R$ %.2f\n", prod[pos].valor);

    if (prod[pos].qtd == 0) {
        printf("Esgotado\n");
    } else {
        printf("Disponivel\n");
    }
}

void relatorio() {
    int i;

    printf("\nRelatorio:\n");

    if (totMov == 0) {
        printf("Nao tem movimentacoes.\n");
        return;
    }

    for (i = 0; i < totMov; i++) {
        int pos = achaProd(movimentos[i].codProd);

        printf("\nProduto: %s\n", prod[pos].nome);
        printf("Tipo: %s\n", movimentos[i].tipo == 1 ? "Entrada" : "Saida");
        printf("Quantidade: %d\n", movimentos[i].qtd);
    }
}

int main() {
    int op;

    do {
        printf("\nMENU:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Entrada\n");
        printf("3 - Saida\n");
        printf("4 - Consultar\n");
        printf("5 - Relatorio\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) cadProd();
        if (op == 2) mover(1);
        if (op == 3) mover(2);
        if (op == 4) consulta();
        if (op == 5) relatorio();

    } while (op != 0);

    return 0;
}
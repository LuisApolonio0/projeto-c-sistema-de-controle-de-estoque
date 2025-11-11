#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[20];
    float preco;
    int quantidade;
} ProdutoEstoque;

int main()
{
    ProdutoEstoque produto;

    printf("========Cadastro de remedios========\n\n");
    printf("Digite o nome do produto:\n");
    fgets(produto.nome, 20, stdin);
    printf("Digite as informaçoes do produto na exata ordem: Codigo, valor(ex.:12.99), quantidade):\n");
    scanf("%d,%f,%d", &produto.codigo, &produto.preco, &produto.quantidade);

    printf("Código: %d, Valor: %.2f, Quantidade: %d, Nome: %s.\n", produto.codigo, produto.preco, produto.quantidade, produto.nome);

    return 0;
}

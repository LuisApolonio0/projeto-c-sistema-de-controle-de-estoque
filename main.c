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
    char linha[50];
    char opcao;

    do{
    printf("========Cadastro de remedios========\n\n");

    printf("Digite o nome do produto:\n");
    fgets(produto.nome, 20, stdin);

    printf("Digite as informacoes do produto na exata ordem: Codigo, valor(ex.:12.99), quantidade):\n");
    fgets(linha, 50, stdin);
    sscanf(linha, "%d, %f, %d", &produto.codigo, &produto.preco, &produto.quantidade);

    printf("Codigo: %d, Valor: %.2f, Quantidade: %d, Nome: %s.\n", produto.codigo, produto.preco, produto.quantidade, produto.nome);

    printf("Deseja continuar?(Use S para Sim ou N para Não)\n");
    scanf("%c", &opcao);
    getchar();

    }while(opcao == 's' || opcao == 'S');

    return 0;
}
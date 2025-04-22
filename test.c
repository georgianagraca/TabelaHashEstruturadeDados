#include <stdio.h>
#include <string.h>
#include "hash_table.h"

int main() {
    HashTable* tabela = criar_tabela();

    inserir(tabela, "nome", "Ana");
    inserir(tabela, "curso", "Computação");
    inserir(tabela, "cidade", "Recife");

    printf("Teste 1: %s\n", strcmp(buscar(tabela, "nome"), "Ana") == 0 ? "OK" : "ERRO");
    printf("Teste 2: %s\n", strcmp(buscar(tabela, "curso"), "Computação") == 0 ? "OK" : "ERRO");
    printf("Teste 3: %s\n", buscar(tabela, "estado") == NULL ? "OK" : "ERRO");

    inserir(tabela, "nome", "Bruno");
    printf("Teste 4 (atualizar): %s\n", strcmp(buscar(tabela, "nome"), "Bruno") == 0 ? "OK" : "ERRO");

    remover(tabela, "nome");
    printf("Teste 5 (remover): %s\n", buscar(tabela, "nome") == NULL ? "OK" : "ERRO");

    liberar_tabela(tabela);
    return 0;
}

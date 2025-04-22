#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

unsigned int hash(const char* chave) {
    unsigned int soma = 0;
    while (*chave)
        soma += *chave++;
    return soma % TABLE_SIZE;
}

HashTable* criar_tabela() {
    HashTable* tabela = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
        tabela->buckets[i] = NULL;
    return tabela;
}

void inserir(HashTable* tabela, const char* chave, const char* valor) {
    unsigned int idx = hash(chave);
    Node* atual = tabela->buckets[idx];

    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            free(atual->valor);
            atual->valor = strdup(valor);
            return;
        }
        atual = atual->proximo;
    }

    Node* novo = malloc(sizeof(Node));
    novo->chave = strdup(chave);
    novo->valor = strdup(valor);
    novo->proximo = tabela->buckets[idx];
    tabela->buckets[idx] = novo;
}

char* buscar(HashTable* tabela, const char* chave) {
    unsigned int idx = hash(chave);
    Node* atual = tabela->buckets[idx];
    while (atual) {
        if (strcmp(atual->chave, chave) == 0)
            return atual->valor;
        atual = atual->proximo;
    }
    return NULL;
}

void remover(HashTable* tabela, const char* chave) {
    unsigned int idx = hash(chave);
    Node* atual = tabela->buckets[idx];
    Node* anterior = NULL;

    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior)
                anterior->proximo = atual->proximo;
            else
                tabela->buckets[idx] = atual->proximo;

            free(atual->chave);
            free(atual->valor);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void liberar_tabela(HashTable* tabela) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* atual = tabela->buckets[i];
        while (atual) {
            Node* temp = atual;
            atual = atual->proximo;
            free(temp->chave);
            free(temp->valor);
            free(temp);
        }
    }
    free(tabela);
}

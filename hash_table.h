#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

typedef struct Node {
    char* chave;
    char* valor;
    struct Node* proximo;
} Node;

typedef struct {
    Node* buckets[TABLE_SIZE];
} HashTable;

HashTable* criar_tabela();
void inserir(HashTable* tabela, const char* chave, const char* valor);
char* buscar(HashTable* tabela, const char* chave);
void remover(HashTable* tabela, const char* chave);
void liberar_tabela(HashTable* tabela);

#endif

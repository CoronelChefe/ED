#include <stdio.h>
#include <string.h>

#define NIL 0
#define DELETED 1
#define FILLED 2

typedef struct HashEnt {
  int flag;
  int hash;
  char s[20];
} HashEnt;

typedef struct HashTabel {
  int size;
  HashEnt entradas[101];
} HashTabel;

int hash_funcao(char *s) {
  long sum = 0;
  long i = 1;
  while(*s != '\0') {
    sum += (*s) * i;
    ++i;
    ++s;
  }
  return (19 * sum) % 101;
}

int hash_tabel_find(HashTabel *h, char *string) {
  int hash = hash_funcao(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entradas[loc].flag == NIL) return 0;
    if(h->entradas[loc].flag == DELETED) continue;
    if(h->entradas[loc].hash == hash && (strcmp(h->entradas[loc].s, string) == 0)) {
      return 1;
    }
  }
  return 0;
}

void hash_tabel_insere(HashTabel *h, char *string) {
  int hash = hash_funcao(string);
  int j;

  if (hash_tabel_find(h, string) == 1) return;

  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entradas[loc].flag == NIL || h->entradas[loc].flag == DELETED) {
      (h->size)++;
      h->entradas[loc].flag = FILLED;
      h->entradas[loc].hash = hash;
      strcpy(h->entradas[loc].s, string);
      break;
    }
  }
  return;
} 

void hash_tabel_delet(HashTabel *h, char *string) {
  int hash = hash_funcao(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entradas[loc].flag == NIL) return;
    if(h->entradas[loc].flag == DELETED) continue;
    if(h->entradas[loc].hash == hash && (strcmp(h->entradas[loc].s, string) == 0)) {
      h->entradas[loc].flag = DELETED;
      (h->size)--;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    HashTabel hash_tabel;

    int i, j;
    for(i = 0; i < 101; ++i) {
      hash_tabel.entradas[i].flag = NIL;
    }
    hash_tabel.size = 0;

    int n;
    scanf("%d", &n);

    char string[50];
    for(i = 0; i < n; ++i) {
      scanf("%s", string);
      if(string[0] == 'A') {
        //Insere
        hash_tabel_insere(&hash_tabel, string + 4);
      } else {
        //Apaga
        hash_tabel_delet(&hash_tabel, string + 4);
      }
    }

    printf("%d\n", hash_tabel.size);
    for(i = 0; i < 101; ++i) {
      if(hash_tabel.entradas[i].flag == FILLED) {
        printf("%d:%s\n", i, hash_tabel.entradas[i].s);
      }
    }
  }
  return 0;
}

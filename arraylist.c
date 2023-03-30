#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList
{
  void **data; //un arreglo dinámico para almacenar *punteros* a los datos.
  int capacity; //el tamaño actual del arreglo
  int size; //la cantidad de datos válidos almacenados en la lista
} ArrayList;

ArrayList *createList(void)
{
  ArrayList *lista;
  lista = (ArrayList*) malloc(sizeof(ArrayList*));
  lista->capacity = 2;
  lista->size = 0;
  lista->data = (void**) malloc(sizeof(void*));
  return lista;
}

void append(ArrayList * l, void * data)
{
  if(l->capacity <= l->size)
  {
    l->capacity *= 2;
    l->data = (void**)realloc(l->data, l->size * sizeof(void*));
    l->data[l->size] = data;
  }
  else
  {
    l->data[l->size] = data;
    l->size++;
  }
}

void push(ArrayList * l, void * data, int i)
{
  if(l->size < i) return;
  if(l->capacity <= l->size)
  {
    l->capacity *= 2;
    l->data = (void**)realloc(l->data, l->size * sizeof(void*));
  }
}

void* pop(ArrayList * l, int i)
{
  return NULL;
}

void* get(ArrayList * l, int i)
{
  return NULL;
}

int get_size(ArrayList * l)
{
  return l->size;
}

//remove elements
void clean(ArrayList * l)
{
    
}

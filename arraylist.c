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
  if(l->capacity == l->size)
  {
    l->capacity *= 2;
    l->data = (void**)realloc(l->data, l->size * sizeof(void*));
  }
  if(l->size > i)
  {
    int k;
    for(k = l->size; i < k; k--)
    {
      l->data[k] = l->data[k-1];
    }
  }
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i)
{
  if(i < 0)
  {
    i = l->size + i;
  }
  if(i < 0 || i >= l->size)
  {
    return NULL;
  }
  void *data = l->data[i];
  for(int k = i; k < l->size -1; k++)
  {
    l->data[k] = l->data[k+1];
  }
  l->size--;
  return data;
}

void* get(ArrayList * l, int i)
{
  if(i < 0)
  {
    i += l->size;
  }
  if(i < 0 || i >= l->size)
  {
    return NULL;
  }  
  return l->data[i];
}

int get_size(ArrayList * l)
{
  return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  l->capacity = 2;
  l->size = 0;
  l->data = (void**) realloc(l->data, l->capacity * sizeof(void*));
}

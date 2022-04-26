/*
** EPITECH PROJECT, 2021
** my
** File description:
** hashtable.c
*/

#include <stdlib.h>
#include "./include/hashtable.h"

htable_t *new_htable(unsigned (*hash)(void *), size_t size,
int (*key_cmp)(void *, void *))
{
    htable_t *new = malloc(sizeof(htable_t));

    if (!new)
        return NULL;
    new->buckets = malloc(sizeof(hashbucket_t *) * size);
    if (!new->buckets) {
        free(new);
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        new->buckets[i] = NULL;
    }
    new->hash = hash;
    new->size = size;
    new->nb_elem = 0;
    new->key_cmp = key_cmp;
    return new;
}

void hbucket_put_to_end(hashbucket_t *new, hashbucket_t *tmp,
htable_t *self)
{
    do {
        if (self->key_cmp(tmp->key, new->key) == 0) {
            free(tmp->data);
            tmp->data = new->data;
            free(new->key);
            free(new->data);
            free(new);
            return;
        }
        tmp = tmp->next;
    }
    while (tmp->next == NULL);
    tmp->next = new;
}

void htable_add(htable_t *self, void *data, void *key) {
    hashbucket_t *new = malloc(sizeof(hashbucket_t));
    hashbucket_t *tmp;
    int index = self->hash(key) % self->size;
    int out = 0;

    if (!new)
        return;
    new->data = data;
    new->key =  key;
    new->next = NULL;
    tmp =  self->buckets[index];
    if (!tmp) {
        self->buckets[index] = new;
    } else {
        hbucket_put_to_end(new, tmp, self);
        tmp->next = new;
    }
    self->nb_elem++;
}

void *htable_get(htable_t *self, void *key)
{
    int index = self->hash(key) % self->size;
    hashbucket_t *tmp = self->buckets[index];

    if (tmp == NULL)
        return NULL;
    while (self->key_cmp(tmp->key, key) != 0) {
        tmp = tmp->next;
        if (tmp == NULL)
            return NULL;
    }
    return tmp->data;
}

/*
** EPITECH PROJECT, 2021
** my
** File description:
** hasttable.h
*/

#ifndef A399835D_5B67_44B3_8686_532C421DDBCA
    #define A399835D_5B67_44B3_8686_532C421DDBCA
    #include <unistd.h>

typedef struct hash_bucket_s hashbucket_t;
struct hash_bucket_s {
    void *data;
    void *key;
    hashbucket_t *next;
};

typedef struct htable_s htable_t;
struct htable_s {
    size_t size;
    size_t nb_elem;
    hashbucket_t **buckets;
    unsigned (*hash)(void *data);
    int (*key_cmp)(void *, void *);
};

htable_t *new_htable(unsigned (*hash)(void *), size_t size,
int (*key_cmp)(void *, void *));
void htable_add(htable_t *self, void *data, void *key);
void *htable_get(htable_t *self, void *key);
void htable_destroy(htable_t *self);
htable_t *new_htable_str(size_t size);

    #define _NEW_HTABLE_STR(size) new_htable_str(size)
    #define _HTABLE_STR_ADD(s, data, key) (htable_add(s, data, my_strdup(key)))

#endif

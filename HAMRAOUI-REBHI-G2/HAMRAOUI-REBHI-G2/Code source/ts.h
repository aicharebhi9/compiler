
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef MINI_R_COMPILER_TS_H
#define MINI_R_COMPILER_TS_H
#define TS_ITERATOR(ts) {ts, 0, ts->table[0]}

typedef struct {
    char EntityName[20];
    char EntityCode[20];
    char EntityType[20];
	char Entityvalue[20];
	char Entityvaleur[20];
} ts_value_t;

//symbolstable element structure
typedef struct ts_elem_t {
    struct ts_elem_t *next; // Next element in case of a collision
    void *data;    // Pointer to the stored element
    char key[];    // Key of the stored element
} ts_elem_t;

//symbolstabe structure
typedef struct {
    unsigned int capacity;    // symbolstable capacity (in terms of hashed keys)
    unsigned int e_num;    // Number of element currently stored in the symbolstable
    ts_elem_t **table;    // The table containaing elements
} ts_t;

//Structure used for iterations
typedef struct {
    ts_t *ht;    // The symbolstable on which we iterate
    unsigned int index;    // Current index in the table
    ts_elem_t *elem;    // Curent element in the list
} ts_elem_it;


char err_ptr;
void *HT_ERROR = &err_ptr; // Data pointing to HT_ERROR are returned in case of error

/* 	Internal funcion to calculate hash for keys.
	It's based on the DJB algorithm from Daniel J. Bernstein.
	The key must be ended by '\0' character.*/
static unsigned int ts_calc_hash(char *key) {
    unsigned int hash = 5381;
    int c;
    while ((c = *key++) != 0)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

/* 	Create a symbolstable with capacity 'capacity'
	and return a pointer to it*/
ts_t *ts_create(ts_t *symbols_t ,unsigned int capacity) {
    if (symbols_t != NULL)
        return symbols_t;
    symbols_t = (ts_t *) malloc(sizeof(ts_t));
    if (!symbols_t)
        return NULL;
    if ((symbols_t->table = (ts_elem_t **) malloc(capacity * sizeof(ts_elem_t *))) == NULL) {
        free(symbols_t->table);
        return NULL;
    }
    symbols_t->capacity = capacity;
    symbols_t->e_num = 0;
    unsigned int i;
    for (i = 0; i < capacity; i++)
        symbols_t->table[i] = NULL;
    return symbols_t;
}

/* 	Store data in the symbolstable. If data with the same key are already stored,
	they are overwritten, and return by the function. Else it return NULL.
	Return HT_ERROR if there are memory alloc error*/
void *ts_put(ts_t *symbolst, char *key, void *data) {
    if (data == NULL)
        return NULL;
    unsigned int h = ts_calc_hash(key) % symbolst->capacity;
    ts_elem_t *e = symbolst->table[h];
   
    while (e != NULL) {
        if (!strcmp(e->key, key)) {
            void *ret = e->data;
            e->data = data;
            return ret;
        }
        e = e->next;
    }
    
    // Getting here means the key doesn't already exist
    if ((e = malloc(sizeof(ts_elem_t) + strlen(key) + 1)) == NULL)
        return HT_ERROR;
    strcpy(e->key, key);
    e->data = data;

    // Add the element at the beginning of the linked list
    e->next = symbolst->table[h];
    symbolst->table[h] = e;
    symbolst->e_num++;
    return NULL;
}

/* Retrieve data from the symbolstable */
void *ts_get(ts_t *symbolst, char *key) {
    unsigned int h = ts_calc_hash(key) % symbolst->capacity;
    ts_elem_t *e = symbolst->table[h];
    while (e != NULL) {
        if (!strcmp(e->key, key))
            return e->data;
        e = e->next;
    }
    return NULL;
}

/* Retrieve data from the symbolstable */
void *ts_update_value(ts_t *symbolst, char *key, char *type) {
    if (type == NULL)
        return NULL;
    unsigned int h = ts_calc_hash(key) % symbolst->capacity;
    ts_elem_t *e = symbolst->table[h];
    while (e != NULL) {
        if (!strcmp(e->key, key)){
            ts_value_t* ret = (ts_value_t*) e->data;
            strcpy(ret->EntityType,type);
            return ret;
        }
        e = e->next;
    }
    return NULL;
}

/* 	Remove data from the symbolstable. Return the data removed from the table
	so that we can free memory if needed */
void *ts_remove(ts_t *symbolst, char *key) {
    unsigned int h = ts_calc_hash(key) % symbolst->capacity;
    ts_elem_t *e = symbolst->table[h];
    ts_elem_t *prev = NULL;
    while (e != NULL) {
        if (!strcmp(e->key, key)) {
            void *ret = e->data;
            if (prev != NULL)
                prev->next = e->next;
            else
                symbolst->table[h] = e->next;
            free(e);
            e = NULL;
            symbolst->e_num--;
            return ret;
        }
        prev = e;
        e = e->next;
    }
    return NULL;
}

/* 	Remove data from the symbolstable. Return the data removed from the table
	so that we can free memory if needed */

/* List keys. k should have length equals or greater than the number of keys */
void ts_list_keys(ts_t *symbolst, char **k, size_t len) {
    if (len < symbolst->e_num)
        return;
    int ki = 0; //Index to the current string in **k
    int i = symbolst->capacity;
    while (--i >= 0) {
        ts_elem_t *e = symbolst->table[i];
        while (e) {
            k[ki++] = e->key;
            e = e->next;
        }
    }
}

/* 	List values. v should have length equals or greater
	than the number of stored elements */
void ts_list_values(ts_t *symbolst, void **v, size_t len) {
    if (len < symbolst->e_num)
        return;
    int vi = 0; //Index to the current string in **v
    int i = symbolst->capacity;
    while (--i >= 0) {
        ts_elem_t *e = symbolst->table[i];
        while (e) {
            v[vi++] = e->data;
            e = e->next;
        }
    }
}

/* Iterate through table's elements. */
ts_elem_t *ts_iterate(ts_elem_it *iterator) {
    while (iterator->elem == NULL) {
        if (iterator->index < iterator->ht->capacity - 1) {
            iterator->index++;
            iterator->elem = iterator->ht->table[iterator->index];
        } else
            return NULL;
    }
    ts_elem_t *e = iterator->elem;
    if (e)
        iterator->elem = e->next;
    return e;
}

/* Iterate through keys. */
char *ts_iterate_keys(ts_elem_it *iterator) {
    ts_elem_t *e = ts_iterate(iterator);
    return (e == NULL ? NULL : e->key);
}

/* Iterate through values. */
void *ts_iterate_values(ts_elem_it *iterator) {
    ts_elem_t *e = ts_iterate(iterator);
    return (e == NULL ? NULL : e->data);
}

/* 	Removes all elements stored in the symbolstable.
	if free_data, all stored datas are also freed.*/
void ts_clear(ts_t *symbolst, int free_dynamic_data) {
    ts_elem_it it = TS_ITERATOR(symbolst);
    char *k = ts_iterate_keys(&it);
    while (k != NULL) {
        if (free_dynamic_data == 1) {
            void *ret = ts_remove(symbolst, k);
            if (ret != NULL) {
                free(ret);
            }
        } else {
            ts_remove(symbolst, k);
        }
        k = ts_iterate_keys(&it);
    }
}

/* 	Destroy the hash table, and free memory.
	Data still stored are freed*/
void ts_destroy(ts_t *symbolst, int free_dynamic_data) {
    ts_clear(symbolst, free_dynamic_data); // Delete and free all.
    free(symbolst->table);
    free(symbolst);
}

// checks for idf double declaration
int ts_double_declare(ts_t *symbolst, char *key){
    void * el = ts_get(symbolst,key);
    if (el != NULL) {
        ts_value_t* data = (ts_value_t*) el;
        if (strcmp(data->EntityType, "") == 0){
            return 0;
        } else return 1;
    } else {
        return 0;
    }
}



#endif //MINI_R_COMPILER_TS_H
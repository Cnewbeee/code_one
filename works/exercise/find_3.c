#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 3001
#define MULT 37
#define MAX_WORD_LENGTH 21

typedef struct hash_entry {
    char *word;
    struct hash_entry *next;
} hash_entry;

unsigned int hash(char *str) {
    unsigned int h = 0;
    char *p;
    for (p = str; *p != '\0'; p++) {
        h = MULT * h + *p;
    }
    return h % NHASH;
}

int sequential_search(char *word, char **word_table, int size) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (strcmp(word, word_table[i]) == 0) {  
            return 1;
        }
        if (strcmp(word, word_table[i]) < 0) {
            break;
        }
    }
    return 0;
}

int binary_search(char *word, char **word_table, int start, int end) {
    int comparisons = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        comparisons++;
        int result = strcmp(word, word_table[mid]);
        if (result == 0) {
            return 1;
        } else if (result < 0) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

int index_search(char *word, char **word_table, int *index_table, int *count_table) {
    int comparisons = 0;
    int index = word[0] - 'a';
    int start = index_table[index];
    int count = count_table[index];
    int end = start + count - 1;
    comparisons += binary_search(word, word_table, start, end);
    return comparisons;
}

int hash_search(char *word, hash_entry **hash_table) {
    int comparisons = 0;
    unsigned int hash_value = hash(word);
    hash_entry *entry = hash_table[hash_value];
    while (entry != NULL) {
        comparisons++;
        if (strcmp(word, entry->word) == 0) {
            return 1;
        }
        if (strcmp(word, entry->word) < 0) {
            break;
        }
        entry = entry->next;
    }
    return 0;
}

int main() {
    char **word_table = (char**)malloc(3500 * sizeof(char *));
    int *index_table = (int*)malloc(26 * sizeof(int));
    int *count_table = (int*)malloc(26 * sizeof(int));
    hash_entry **hash_table = (hash_entry**)malloc(NHASH * sizeof(hash_entry *));
    for (int i = 0; i < NHASH; i++) {
        hash_table[i] = NULL;
    }

    FILE *file = fopen("dictionary3000.txt", "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    int total_words = 0;
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, file) != NULL) {  
        buffer[strcspn(buffer, "\n")] = 0;
        word_table[total_words] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(word_table[total_words], buffer);
        int index = buffer[0] - 'a';
        if (total_words == 0 || strcmp(word_table[total_words - 1], buffer) != 0) {
            index_table[index] = total_words;
            count_table[index] = 1;
        } else {
            count_table[index]++;
        }
        total_words++;
        unsigned int hash_value = hash(buffer);
        hash_entry *entry = (hash_entry*)malloc(sizeof(hash_entry));
        entry->word = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(entry->word, buffer);
        entry->next = hash_table[hash_value];
        hash_table[hash_value] = entry;
    }
    fclose(file);

    char word[MAX_WORD_LENGTH];
    int search_method;
    scanf("%s %d", word, &search_method);

    int result = 0;
    int comparisons = 0;

    switch (search_method) {
        case 1:
            comparisons = sequential_search(word, word_table, total_words);
            result = comparisons > 0;
            break;
        case 2:
            comparisons = binary_search(word, word_table, 0, total_words - 1);
            result = comparisons > 0;
            break;
        case 3:
            comparisons = index_search(word, word_table, index_table, count_table);
            result = comparisons > 0;
            break;
        case 4:
            comparisons = hash_search(word, hash_table);
            result = comparisons > 0;
            break;
        default:
            return EXIT_FAILURE;
    }

    printf("%d %d\n", result, comparisons);

    for (int i = 0; i < total_words; i++) {
        free(word_table[i]);
    }
    for (int i = 0; i < NHASH; i++) {
        hash_entry *entry = hash_table[i];
        while (entry != NULL) {
            hash_entry *next = entry->next;
            free(entry->word);
            free(entry);
            entry = next;
        }
    }
    free(word_table);
    free(index_table);
    free(count_table);
    free(hash_table);

    return 0;
}

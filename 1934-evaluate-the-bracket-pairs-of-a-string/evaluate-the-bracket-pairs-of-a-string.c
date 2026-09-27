#define TABLE_SIZE 200003

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

unsigned long hash(char *str) {
    unsigned long h = 5381;
    while (*str) {
        h = ((h << 5) + h) + *str;
        str++;
    }
    return h % TABLE_SIZE;
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    Node **table = calloc(TABLE_SIZE, sizeof(Node*));

    for (int i = 0; i < knowledgeSize; i++) {
        unsigned long h = hash(knowledge[i][0]);

        Node *node = malloc(sizeof(Node));
        node->key = knowledge[i][0];
        node->value = knowledge[i][1];
        node->next = table[h];
        table[h] = node;
    }

    int n = strlen(s);
    char *result = malloc(2 * n + 1);
    int ri = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '(') {
            result[ri++] = s[i];
            continue;
        }

        int j = i + 1;
        while (s[j] != ')')
            j++;

        char key[101];
        int len = j - i - 1;

        memcpy(key, s + i + 1, len);
        key[len] = '\0';

        unsigned long h = hash(key);
        Node *node = table[h];

        while (node != NULL && strcmp(node->key, key) != 0)
            node = node->next;

        if (node == NULL) {
            result[ri++] = '?';
        } else {
            int vlen = strlen(node->value);
            memcpy(result + ri, node->value, vlen);
            ri += vlen;
        }

        i = j;
    }

    result[ri] = '\0';

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *node = table[i];

        while (node != NULL) {
            Node *next = node->next;
            free(node);
            node = next;
        }
    }

    free(table);

    return result;
}
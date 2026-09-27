typedef struct {
    char **a;
    int n;
    int cap;
} Set;

void init(Set *s) {
    s->n = 0;
    s->cap = 16;
    s->a = malloc(s->cap * sizeof(char *));
}

int exists(Set *s, char *str) {
    for (int i = 0; i < s->n; i++) {
        if (strcmp(s->a[i], str) == 0)
            return 1;
    }
    return 0;
}

void add(Set *s, char *str) {
    if (exists(s, str)) {
        free(str);
        return;
    }

    if (s->n == s->cap) {
        s->cap *= 2;
        s->a = realloc(s->a, s->cap * sizeof(char *));
    }

    s->a[s->n++] = str;
}

Set concat(Set *x, Set *y) {
    Set res;
    init(&res);

    for (int i = 0; i < x->n; i++) {
        for (int j = 0; j < y->n; j++) {
            int l1 = strlen(x->a[i]);
            int l2 = strlen(y->a[j]);

            char *str = malloc(l1 + l2 + 1);

            memcpy(str, x->a[i], l1);
            memcpy(str + l1, y->a[j], l2);
            str[l1 + l2] = '\0';

            add(&res, str);
        }
    }

    return res;
}

void unite(Set *x, Set *y) {
    for (int i = 0; i < y->n; i++)
        add(x, y->a[i]);

    free(y->a);
}

Set parseExpression(char *s, int *pos);

Set parseTerm(char *s, int *pos) {
    Set res;
    init(&res);

    int first = 1;

    while (s[*pos] != '\0' &&
           s[*pos] != '}' &&
           s[*pos] != ',') {

        Set cur;

        if (s[*pos] == '{') {
            (*pos)++;
            cur = parseExpression(s, pos);
            (*pos)++;
        } else {
            init(&cur);

            char *str = malloc(2);
            str[0] = s[*pos];
            str[1] = '\0';

            add(&cur, str);
            (*pos)++;
        }

        if (first) {
            free(res.a);
            res = cur;
            first = 0;
        } else {
            Set temp = concat(&res, &cur);

            for (int i = 0; i < res.n; i++)
                free(res.a[i]);

            for (int i = 0; i < cur.n; i++)
                free(cur.a[i]);

            free(res.a);
            free(cur.a);

            res = temp;
        }
    }

    return res;
}

Set parseExpression(char *s, int *pos) {
    Set res;
    init(&res);

    while (1) {
        Set term = parseTerm(s, pos);

        unite(&res, &term);

        if (s[*pos] == ',') {
            (*pos)++;
        } else {
            break;
        }
    }

    return res;
}

int cmp(const void *a, const void *b) {
    char *x = *(char **)a;
    char *y = *(char **)b;
    return strcmp(x, y);
}

char** braceExpansionII(char* expression, int* returnSize) {
    int pos = 0;

    Set res = parseExpression(expression, &pos);

    qsort(res.a, res.n, sizeof(char *), cmp);

    *returnSize = res.n;

    return res.a;
}
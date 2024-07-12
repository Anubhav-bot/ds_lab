// TO IMPLEMENT UNION, INTERSECTION, AND DIFFERENCE OPERATION OF SETS.

#include <stdio.h>
#include <stdlib.h>

#define SEPARATE_LENGTH 0
#define INTEGRATED_LENGTH 1

int *getUnion(int *a, int len_a, int *b, int len_b) {
    int len = len_a + len_b;
    int* uni = (int*)malloc(sizeof(int) * (len+1));
    int i, j, k;
    for(i = 0; i < len_a; i++)
    {
        for(j = 0; j < i; j++) {
            if(a[i] == uni[j]) break;
        }
        if(i == j) uni[i+1] = a[i]; //leave uni[0] empty to store length later    
    }
    i++;

    for(k = 0; k < len_b; k++)
    {
        for(j = 0; j < i+k; j++) {
            if(b[k] == uni[j]) break;
        }
        if(i+k == j) uni[i++] = b[k];
    }
    uni[0] = i; // store length of uni in uni[0]
    return uni;
}

int *getIntersection(int *a, int len_a, int *b, int len_b) {
    int len = (len_a > len_b)? len_a : len_b;
    int* inter = (int*)malloc(sizeof(int) * (len+1));
    int i, j;
    int index = 1;

    for(i = 0; i < len_a; i++)
    {
        for(j = 0; j < len_b; j++)
        {
            if(a[i] == b[j]) {
                inter[index++] = a[i];
                break;
            }
        }
    }
    inter[0] = index;
    return inter;
}

int *getDifference(int *u, int len_u, int *s, int len_s) {
    int len = len_u - len_s;
    int* d = (int*)malloc(sizeof(int) * (len+1));
    int i, j;
    int index = 1;

    for(i = 0; i < len_u; i++) {
        for(j = 0; j < len_s; j++) {
            if(u[i] == s[j]) break;
        }
        if(j == len_s) d[index++] = u[i];
    }
    d[0] = index;
    return d;
}

void display(int *s, int s_len, int type) {
    printf("{ ");
    for(int i = type; i < s_len; i++)
    {
       printf("%d%s", s[i], (i+1 < s_len)? ", ":"");
    }
    printf(" }\n");
}

int main() {
    int u[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[5] = {2, 3, 4, 6, 8};
    int b[3] = {3, 6, 9};

    int len_u = sizeof(u) / sizeof(u[0]);
    int len_a = sizeof(a) / sizeof(a[0]);
    int len_b = sizeof(b) / sizeof(b[0]);

    printf("U: ");
    display(u, len_u, SEPARATE_LENGTH);

    printf("A: ");
    display(a, len_a, SEPARATE_LENGTH);

    printf("B: ");
    display(b, len_b, SEPARATE_LENGTH);

    int* uni = getUnion(a, len_a, b, len_b);
    printf("\nUnion: [len = %d]\n", uni[0]-1);
    display(uni, uni[0], INTEGRATED_LENGTH);
    free(uni);

    int* inter = getIntersection(a, len_a, b, len_b);
    printf("\nIntersection: [len = %d]\n", inter[0]-1);
    display(inter, inter[0], INTEGRATED_LENGTH);
    free(inter);

    int* diffA = getDifference(u, len_u, a, len_a);
    printf("\nDifference of A: [len = %d]\n", diffA[0]-1);
    display(diffA, diffA[0], INTEGRATED_LENGTH);
    free(diffA);

    int* diffB = getDifference(u, len_u, b, len_a);
    printf("\nDifference of B: [len = %d]\n", diffB[0]-1);
    display(diffB, diffB[0], INTEGRATED_LENGTH);
    free(diffB);

    return 0;
}

/* lab3exe_E.c
 * ENSF 337, Lab 3 Exercise E
 * Completed by: Jaxon Braun
 * Submission Date: October 13, 2021
 */

#include <stdio.h>
#include <string.h>

int substring(const char *s1, const char *s2);
/* REQUIRES
 * s1 and s2 are valid C-string terminated with '\0';
 * PROMISES
 * returns one if s2 is a substring of s1). Otherwise returns zero.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 *   n_source >= 0.
 *   Elements source[0], source[1], ..., source[n_source - 1] exist.
 *   Elements negatives_only[0], negatives_only[1], ..., negatives_only[n_source - 1] exist.
 * PROMISES
 *   number_of_negatives == number of negative values in source[0], ..., source[n_source - 1].
 *   negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain those negative values, in
 *   the same order as in the source array.                           */

int main(void)
{
    char s[] = "Knock knowk!Who’s there?";
    int a[] = { 2, -15, 69, -46, 0 };
    int size_a;
    int i;
    int negative[5];
    int n_negative;
    
    size_a = sizeof(a) / sizeof(a[0]);
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    select_negatives(a, size_a, negative, &n_negative);
    printf("\nnegative elements from array a are as follows:");
    for (i = 0; i < n_negative; i++)
        printf("  %d", negative[i]);
    printf("\n");
    
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Who"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "knowk"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "knock"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, ""));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "ck! Who's"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "ck!Who's"));
    return 0;
}

int substring(const char *s1, const char* s2)
{
    int s1_length = 0;
    int s2_length = 0;
    while (*(s1+s1_length) != '\0'){
        s1_length += 1; 
    }
    while (*(s2+s2_length) != '\0'){
        s2_length += 1; 
    }
    for (int i = 0; i < s1_length; i++){
        int j;
        int counter = 0;
        for (int j; j < s2_length; j++){
            if (j == counter){
                return 1;
            }
            if (*(s1+i) == *(s2+i+j)){
                counter++;
            }
        }
    }
    return 0;
}


void select_negatives(const int *source, int n_source, int* negatives_only, int* number_of_negatives)
{
    int i;
    *number_of_negatives = 0;
    for (int i = 0; i < n_source; i++){
        if (source[i] < 0){
            negatives_only[*number_of_negatives] = source[i];
            *number_of_negatives += 1;
        }
    }
    return;
}


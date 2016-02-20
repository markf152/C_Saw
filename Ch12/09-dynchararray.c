/* 09-dynchararray.c -- creates dynamic array of pointers to char to store */
/* a user-specified number of words using the precise amount of memory */
/* needed for each word */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int num_words;
    char ** word_list; 
    char words_input[200];
    char ch;
    char word[50];
    int i;
    int j = 0;
    int k = 0;

    puts("\n");

    printf("How many words do you wish to enter? ");
    scanf("%d", &num_words);
    printf("\n");
//    printf("num_words = %d\n", num_words);
    word_list = (char **) malloc(num_words * sizeof(char *));
//  printf("num_words * sizeof(char *) = %d\n", (int)(num_words * sizeof(char *)));
    printf("Enter %d words now:\n", num_words);
    while ((ch = getchar()) != '\n')
        continue;
    fgets(words_input, 50, stdin);
    printf("\n");
    words_input[strlen(words_input) - 1] = 0;
//    printf("words_input = %s\n", words_input);

    for (i = 0; i < num_words; i++) {
        while (words_input[j] != ' ' && words_input[j] != '\0') {
            word[k] = words_input[j];
            k++;
            j++;
        }
//        putchar('\n');
        word[k] = '\0';
//        printf("length of %s is %d\n", word, (int)strlen(word));
//        printf("%d\n", i);
//        printf("word_list[%d] = %p\n", i, word_list[i]);
//        printf("strlen(word) = %d\n", (int)strlen(word));
//        printf("(strlen(word) + 1) * sizeof(char) = %d\n", 
//                   (int)((strlen(word) + 1) * sizeof(char)));
        word_list[i] = (char *) malloc((strlen(word)) * sizeof(char));
//        printf("word_list[%d] = %p\n", i, word_list[i]);
        strncpy(word_list[i], word, (int)strlen(word));
        j++;
        k = 0;
//        printf("------ %s end for\n", word);
//        printf("words_input[j] = %c\n", words_input[j]);
    }

    printf("Here are your words: \n");
    for (i = 0; i < num_words; i++) { 
        puts(word_list[i]);
        free(word_list[i]);
    }
    
    free(word_list);

    puts("\n");

    return 0;
}


#include <stdio.h>
#include <ctype.h>

int main(int argc , char *argv[])
{
//case 1: we get a file
    FILE *file;
    if (argc > 1){
        file = fopen(argv[1], "r");

        if (file == NULL) {
        perror("Error opening file");
        return 1;
        }
    }
    else{
        file = stdin;
    }

    int line_ct = 0;
    int word_ct = 0;
    int char_ct = 0;
    char c;
    int new_word = 1;
    
    while (fscanf(file , "%c" , &c) != EOF){
 
        char_ct++;
        if (new_word && !isspace(c)){
            new_word = 0;
            word_ct++;
        }
        else if (!new_word && isspace(c)){
            new_word = 1;
        }
        if (c == '\n'){
            line_ct++;       
        }
    }

    if (argc > 1){
        fclose(file);
        printf("%d    %d    %d  %s\n" , line_ct , word_ct , char_ct, argv[1]);
    }
    else{
        printf("%d    %d    %d  \n" , line_ct , word_ct , char_ct);
    }

    return 0;
}
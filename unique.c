#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char *line1 = NULL;
    size_t size1 = 0;
    char *line2 = NULL;

    if (getline(&line1 , &size1 , file) <= 0){
        free(line1);
        return 0;
    }
    printf("%s" , line1);
    line2 = line1;
    size1 = 0;
    line1 = NULL;
    int unique = 0;

    while(getline(&line1 , &size1 , file) > 0){
        unique = 0;
        int line_char_ct = 0;

        while (line1[line_char_ct] != '\0' && line2[line_char_ct] != '\0'){
            if (line1[line_char_ct] != line2[line_char_ct]){
                if ((line1[line_char_ct] == '\0' && line2[line_char_ct] == '\n' )||
                    (line1[line_char_ct] == '\n' && line2[line_char_ct] == '\0')){
                        //addnewline = 1;
                        break;
                    }
                unique = 1;
                break;
            }
            line_char_ct++;
            }

        
        if (unique){
            printf("%s" , line1);
        }

        free(line2);
        line2 = line1;
        line1 = NULL;
        size1 = 0;
    }
    free(line1); // Free the memory one last time in case getline fails
    free(line2);
    if (unique){
        printf("\n");
    }
    if (file != stdin) {
        fclose(file); // Close the file if it's not stdin
    }


}
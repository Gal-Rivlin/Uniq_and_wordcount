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
    int running = 1;

    int line_ct = 0;
    int word_ct = 0;
    int char_ct = 0;

    while (running){
//the first part of the while loop will be to extract a line 
//the line will be either from a file, or from a scanf
        char currentline[100];
        currentline[0] = '\0';

        if (argc == 1){
            fgets(currentline, sizeof(currentline), stdin);
        }
        else{
            fgets(currentline, sizeof(currentline), file);
        }

//the second part will be to check if we are done: we do this by checking if the first char is \0
        if (currentline[0] == '\0'){
            running = 0;
        }

//now the third part will be to read the line and add to our counters

        if (running){

            int line_char_ct = 0;
            int new_word = 1;
            while (currentline[line_char_ct] != '\0'){
                char_ct++;
                if (new_word && !isspace(currentline[line_char_ct])){
                    new_word = 0;
                    word_ct++;
                }
                else if (!new_word && isspace(currentline[line_char_ct])){
                    new_word = 1;
                }
                if (currentline[line_char_ct] == '\n'){
                    line_ct++;       
                }
                line_char_ct++;
                

            }



        }


    }

    printf("%d    %d    %d  %s\n" , line_ct , word_ct , char_ct, argv[1]);

    return 0;
}
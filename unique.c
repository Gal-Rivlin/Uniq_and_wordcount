#include <stdio.h>
#include <ctype.h>

int main(int argc , char *argv[])
{
//case 1: we get a file
    FILE *file;
    if (argc > 1){
        file = fopen(argv[1], "r");

        if (file == NULL) {
        printf("Error opening file");
        return 1;
        }
    }
    int switcher = 1;
    char currentline1[100];
    char currentline2[100];
    int addnewline = 0;

    while (1){
        addnewline = 0;
//the first part of the while loop will be to extract a line 
//the line will be either from a file, or from a scanf
//we are alteranating between which lines we are coppying too, so that we compare between them
        if (argc == 1){
            if (switcher == 1){
                if(fgets(currentline1, sizeof(currentline1), stdin) == NULL){
                    break;
                }
                switcher = 2;
            }
            else{
                if(fgets(currentline2, sizeof(currentline2), stdin) == NULL){
                    break;
                }
                switcher = 1;
            }    
        }
        else{
            if (switcher == 1){
                if(fgets(currentline1, sizeof(currentline1), file) == NULL){
                    break;
                }
                switcher = 2;
            }
            else{
                if(fgets(currentline2, sizeof(currentline2), file) == NULL){
                    break;
                }
                switcher = 1;
            }
        }

//now the third part will be to read and check if there's a difference
        int unique = 0;
        int line_char_ct = 0;
        while (currentline1[line_char_ct] != '\0' || currentline2[line_char_ct] != '\0'){
            if (currentline1[line_char_ct] != currentline2[line_char_ct]){
                if ((currentline1[line_char_ct] == '\0' && currentline2[line_char_ct] == '\n' )||
                    (currentline1[line_char_ct] == '\n' && currentline2[line_char_ct] == '\0')){
                        addnewline = 1;
                        break;
                    }
                unique = 1;
                break;
            }
            line_char_ct++;

        }

    
// fourth part we are checking if it's unique, and if it is we print it out
//remember we switched the sign of "switcher", so it's actually opposite signs now
        if (unique){
            if (switcher == 2){
                printf("%s" , currentline1);
            }
            if (switcher == 1){
                printf("%s" , currentline2);
            }
            addnewline = 1;
        }   
    }
    if (addnewline){
        printf("\n");
    }
    return 0;
}
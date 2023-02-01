/*
Functionless practice of string manipulation for APSC 143 at Queen's University

Program first takes in user input (max length 50).
Next, it removes all lower case letters and spaces from the input.
Next, it repeats the string "LEXICON" until it is the same length as the input, if it goes over the length of the input, it cuts off the extra characters.
Next, it encrypts the input by reflecting the difference between the input and the repeated LEXICON across the LEXICON.
Finally, it prints the encrypted message.

Pasting in the encrypted output will decrypt the message. 
*/

#include <stdio.h>
#include <string.h>               

int main()
{
    char codeArray[3][50];          //array of 3 strings
    char LEXICON[] = "LEXICON";     //repeacted encryption tool
    int numSpecial;                 //in the case of special characters
    
    //user input
    char codePhrase[50];            
    printf("Enter secret message: ");
    fgets(codePhrase, 50, stdin);     //fgets functionality allows spaces
    
    
    //loop to omit lower case variables and spaces
    for(int i=0, j; i<=(strlen(codePhrase)-1); i++) {
    
    //while loop for all characters that ARE NOT 
    /*                                      A TO Z                          \0 VARIABLE                                 ! OR '                  */
        while(!(codePhrase[i] >= 'A' && codePhrase[i] <= 'Z') && !(codePhrase[i] == '\0') && !(codePhrase[i] == '!') && !(codePhrase[i] == '\'')){
            for(j=i; codePhrase[j] !='\0'; j++)
                codePhrase[j]=codePhrase[j+1];          //characters that arent A-Z, !, ', or \0 are skipped
        codePhrase[j] = '\0';
        }
        
        if(codePhrase[strlen(codePhrase)-1] == '\n')
            (codePhrase[strlen(codePhrase)-1]  == '\0');   //if the last character is a new line, replace it with a null
    }


    //repeats the string "LEXICON" to match the number of characters in the code phrase
    char RESULT[50];
    strcpy(RESULT, LEXICON);
        while(strlen(RESULT) <= (strlen(codePhrase)))
            strcat(RESULT, LEXICON);

    //if the result is longer than the input, subtract the extra characters.
    int extraChar = strlen(RESULT) - strlen(codePhrase); 
        if(strlen(RESULT) >= strlen(codePhrase))                    
            RESULT[strlen(RESULT) - extraChar]='\0';  //subtract the overlap and set the last character to NULL


    //initialize array of strings
    strcpy(codeArray[0], codePhrase);       //row 1 is the input
    strcpy(codeArray[1], RESULT);           //row 2 is the RESULT (repeat of LEXICON)
    codeArray[2];                           //row 3 is the encryption
  
    //encrypt codePhrase
    for(int j=0; j<=strlen(codePhrase)-1; j++){
        
        //count the number of special variables to create a pause in the LEXICON when they occur
        if(!(codePhrase[j] >= 'A' && codePhrase[j] <= 'Z') && !(codePhrase[j] == '\0'))
            numSpecial ++;              
        
        switch(codePhrase[j]){           //encrypt if it's a letter from A to Z
            
            //dont encrypt special characters
            case'!': 
                codeArray[2][j] = codeArray[0][j];
                break;

            case'\'':
                codeArray[2][j] = codeArray[0][j];
                break;
            
            default:{
                //reflect the difference between letters across the LEXICON for the encription
                int letterDiff = codeArray[0][j] - codeArray[1][j-numSpecial];       
                codeArray[2][j] = codeArray[1][j-numSpecial] - letterDiff;            
                                                                                     
                //if the reflected value is greater than Z, loop around to the beginning of the alphabet (ie: XYZ->ABC)
                if(codeArray[2][j] > 90)                                  
                    codeArray[2][j] = codeArray[2][j] - 26;   //move back 26 letters
            
                //if the reflected value is less than A, loop around to the end of the alphabet (ie: CBA->ZYX)
                else if(codeArray[2][j] < 65)                             
                    codeArray[2][j] = codeArray[2][j] + 26;   //move forward 26 letters
                break;
            }
        }//end switchcase
    }//end for loop
    
    printf("\n*BEGIN_MESSAGE*\n\n%s\n\n*END_MESSAGE*\n", codeArray[2]);     //encryption
}//end main

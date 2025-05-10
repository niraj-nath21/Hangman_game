/*
   Name of the Project: Hangman game (Word guessing game)
   Written By: Niraj Nath
   Roll number: KCE080BCT016
*/

// Declaration of header files and defining constant
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define maxtries 7

// User defined funtions
void displayhangman(int n);
int input(char word[26], char guess,char guessedword[26]);
void displayword(char word[26],char guessedword[26]);

// Main function
int main() {
    char word[26];
    char guessedword[26]={0};
    int len, tries = 0;
    int correct=0;
    char guess;
    printf("Enter the word to guess (in lowercase):\n");
    scanf("%s", word);
    getchar();
    system("cls");
    len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
    while (tries<maxtries) {
        displayhangman(tries);
        displayword(word,guessedword);
        printf("\nEnter your guess\n");
        scanf("%c",&guess);
        getchar();
        if(input(word,guess,guessedword)){
            correct =1;
            for(int i=0;i<len;i++){
                if(!guessedword[word[i]-'a']){
                    correct =0;
                    break;
                }
            }
            if(correct){
                printf("Congratulations you've guessed the word \n%s",word);
                break;
            }
        }else{
            tries++;
        }
    }
    return 0;
}
// Function to display the guessed letters
void displayword(char word[26],char guessedword[26]){
    int len;
    len=strlen(word);
    for(int i=0;i<len;i++){
        if(guessedword[word[i]-'a']){
            printf("%c",word[i]);
        }else{
            printf("-");
        }
    }
}
// Function to check the guessed letter is correct or not
int input(char word[26], char guess,char guessedword[26]) {
    int correct=0;
    int len=strlen(word);
    for(int i=0;i<len;i++){
        if(guess==word[i]){
            guessedword[word[i]-'a']=1;
            correct=1;
        }
    }
    return correct;
}
// Fuction to display the hangman
void displayhangman(int n) {
    system("cls");
    switch (n) {
        case 0: 
            printf("_________\n");
            printf("|      |\n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
           
            break;
        case 1: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
           
            break;
        case 2: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|      |\n");
            printf("|       \n");
            printf("|       \n");
           
            break;
        case 3: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|     /|\n");
            printf("|       \n");
            printf("|       \n");
           
            break;
        case 4: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|     /|\\\n");
            printf("|       \n");
            printf("|       \n");
           
            break;
        case 5: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|     /|\\\n");
            printf("|      | \n");
            printf("|       \n");
           
            break;
        case 6: 
            printf("_________\n");
            printf("|      |\n");
            printf("|      O\n");
            printf("|     /|\\\n");
            printf("|      | \n");
            printf("|     / \\\n");
           
            break;
    }
}

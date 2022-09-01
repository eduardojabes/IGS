#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum { false, true } bool;
#define CHUNK 1024
 
int romanToDecimal(char);
 
int romanToDecimal(char c){
     int value=0;
     switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}

bool validateOperation(char rn1, char rn2){
    bool value = false;
    switch (rn1){
        case 'I': value = (rn2 == 'V') | (rn2 == 'X'); break;
        case 'X': value = (rn2 == 'L') | (rn2 == 'C'); break;
        case 'C': value = (rn2 == 'D') | (rn2 == 'M'); break;
    }
}

int main(){
 
    char rom_Number[CHUNK];
    int position=0;
    long int dec_Number =0;
 
    printf("Enter any roman number (Valid digits are I, V, X, L, C, D, M):  \n");
    scanf("%s",rom_Number);
 
    while(rom_Number[position]){
        // Wrong input
        if(romanToDecimal(rom_Number[position]) < 0){
            printf("Invalid roman digit : %c\n",rom_Number[position]);
            return 0;
        }
        // Verify if Roman Number is in correct order
        if((strlen(rom_Number) - position ) > 2){
            if(romanToDecimal(rom_Number[position]) < romanToDecimal(rom_Number[position + 2])){
                printf("Invalid roman number - incorrect order\n");
                return 0;
            }
        }
        // Verify the Roman logic incremental number
        if(romanToDecimal(rom_Number[position]) >= romanToDecimal(rom_Number[position+1]))
            dec_Number = dec_Number + romanToDecimal(rom_Number[position]);
        else{
            if (validateOperation(rom_Number[position],rom_Number[position+1]) == false)
            {
                printf("Invalid roman number - incorrect order - '%c' can't subtract '%c'\n",rom_Number[position],rom_Number[position+1]);
                system("pause");
                return 0;
            }
            dec_Number = dec_Number + (romanToDecimal(rom_Number[position+1]) - romanToDecimal(rom_Number[position]));         
            position++;
        }
        position++;
    }
 
    printf("Its decimal value is : %ld\n",dec_Number);
    system("pause");
    return 0;
}
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

uint32_t getRed(uint32_t color){
  uint32_t mask = 0xFF0000;
  uint32_t red_bits = mask & color;
  red_bits = red_bits >> 16;
  return red_bits;
}


uint32_t getRedTotalVariation(uint32_t initial_color, uint32_t final_color){
    int inicial = getRed(initial_color);
    int final = getRed(final_color);
    return (final - inicial);
}

void applyRedVariation(uint32_t initial_color, int total_variation, int steps){
    int current_step = 1;
    uint32_t actual_color = initial_color;
      
    while (current_step <= steps){
        int variation = total_variation * current_step / steps;
        uint32_t bit_variation = variation << 16;
        
        actual_color = initial_color + bit_variation;
        printf("Actual color is : 0x%x\n",actual_color);
        current_step++;
    }
}

int main(){
uint32_t cor_inicial = 0x00001A;
uint32_t cor_final = 0xFF001A;
int steps = 10;
int total_variation = getRedTotalVariation(cor_inicial, cor_final);
applyRedVariation(cor_inicial, total_variation, steps);

system("pause");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void setSeed(){
    uint64_t t = time(NULL);
    uint32_t t1 = (uint32_t)t;
    srand(t1);
}

int main(){
    setSeed();
    uint32_t countOfChars;
    
    printf("enter count of chars: ");

    if(scanf("%u", &countOfChars) != 1) {
        printf("enter correct amount");
        return 1;
    }

    char* pass = malloc((countOfChars + 1)*sizeof(char));
    if (pass == NULL){
        printf("not enough memory");
        return 1;
    }
    
    char alphabet[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
    uint32_t sizealph = sizeof(alphabet) - 1;

    for(int32_t i = 0; i < countOfChars; i++){
        pass[i] = alphabet[rand() % sizealph];
    }
    pass[countOfChars] = '\0';

    printf("%s", pass);

    free(pass);

    return 0;
}
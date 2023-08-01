// От стандартния вход се въвежда цяло положително число (което има най-много 500 цифри). Напишете функция, която кодира низа и връща нов символен низ, за който е заделена динамична памет. Кодирането се случва по следния начин:
// Ако една цифра е на четна позиция, тя се замества със съответстващата главна латинска буква. Например:
// 0 се замества с A 
// 1 се замества с B
// 2 се замества с C и т.н.
// Ако една цифра е на нечетна позиция, тя се замества със символ, както е зададено в долната таблица:
// Цифра
// Символ

// Погрижете се за освобождаването на динамично заделената памет.
// Примерен вход:
// 10296126782646987676234
// Примерен изход:
// B!C,G#C\H.C\E\J.H\H\C~E


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* coding(const char *input, char arr1[], char arr2[]) {
    size_t size = strlen(input);
    char *ptr = (char*)malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; i++) {
        char digit = input[i];

        if (i == 0 || i % 2 == 0) {
            int num = digit - '0';
            ptr[i] = arr1[num];
        } else {
            int num = digit - '0';
            ptr[i] = arr2[num];
        }
    }
    ptr[size] = '\0'; 
    return ptr;
}

int main() {
    char input[502]; //za zatvarqshtiqt simvol i za buffer
    scanf("%501s", input);

    //smenil sum ediniqt simvol zashtoto mi zatvarq masiva

    char arr1[] = "ABCDEFGHI"; 
    char arr2[] = "!#/~=`\\>.,";

    char *ptr = coding(input, arr1, arr2);

    printf("%s\n", ptr);

    free(ptr);
    return 0;
}

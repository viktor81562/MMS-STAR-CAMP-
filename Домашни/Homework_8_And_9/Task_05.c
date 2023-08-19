#include <stdio.h>
#include <stdint.h>

typedef struct MyTime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} MyTime;

int isLeapYear(MyTime t) {
    if ((t.year % 4 == 0 && t.year % 100 != 0) || (t.year % 400 == 0)) {
        return 1; // Високосна година
    } else {
        return 0; // Не е високосна година
    }
}

int totalDaysInYear(MyTime t) {
    return isLeapYear(t) ? 366 : 365;
}

void printMonth(MyTime t) {
    const char* month_names[] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    if (t.month >= 1 && t.month <= 12) {
        printf("%s\n", month_names[t.month - 1]);
    } else {
        printf("Invalid month\n");
    }
}

int secondsPassed(MyTime t) {
    MyTime epoch = {1970, 1, 1, 0, 0, 0};

    uint32_t epoch_seconds = ((uint32_t)t.year - epoch.year) * 31536000 + 
                             (totalDaysInYear(t) - 1) * 86400 + 
                             t.hour * 3600 + t.minute * 60 + t.second;

    return epoch_seconds;
}

int main() {
    printf("Size of MyTime: %zu bytes\n", sizeof(MyTime));

    MyTime t1 = {2023, 7, 30, 12, 30, 45};
    MyTime t2 = {2020, 2, 29, 0, 0, 0};
    MyTime t3 = {2000, 12, 31, 23, 59, 59};



    return 0;
}

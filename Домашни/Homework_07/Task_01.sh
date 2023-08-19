#!/bin/bash

# Компилиране на програмата
gcc -o your_program your_program.c -lm

# Обхождане на файловете в директорията tests
for test_file in tests/*.in; do
    # Извличане на номера на теста от името на файла (например: 1.in -> 1)
    test_number=$(basename "$test_file" | cut -d. -f1)

    # Изпълнение на програмата с текущия тест и запис на изхода във временен файл
    ./your_program < "$test_file" > "tests/$test_number.tmp_out"

    # Сравнение на очаквания изход със стойността от временния изходен файл
    if diff -w "tests/$test_number.tmp_out" "tests/$test_number.out" &>/dev/null; then
        echo "Test $test_number: Passed"
    else
        echo "Test $test_number: Failed"
    fi

    # Изтриване на временния изходен файл
    rm "tests/$test_number.tmp_out"
done

# Изтриване на компилираната програма
rm your_program




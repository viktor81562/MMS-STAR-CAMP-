#include<stdio.h>
 
#define N 10
 
double arr[N];
// start_index - елемента, който е влязъл най-отдавна в опашката
// end_index - индекса, на който да запазим нов елемент в опашката (end_index - 1 е най-скорошният елемент на опашката)
size_t start_index = 0, end_index = 0;
//     read_pointer write_pointer
// enqueue - добавяме нов елемент при end_index
// dequeue - премахваме елемент от start_index
void print_buffer() {
    for(size_t i = 0; i < N; i++) {
        if(start_index%N <= i && i < end_index%N) {
            printf("%3.2lf ", arr[i]);
        } else {
            printf(" --- ");
        }
    }
    printf("\n");
    for(size_t i = 0; i < N; i++) {
        if(i == start_index) {
            printf("  S  ");
        } else if(i == end_index) {
            printf("  E  ");
        } else {
            printf("     ");
        }
    }
    printf("\n\n");
}
 
void enqueue(double data) {
    arr[end_index%N] = data;
    end_index++;
}
double dequeue() {
    size_t old_start = start_index;
    start_index++;
 return arr[start_index%N];
}
 
int main() {
    enqueue(1);
    print_buffer();
    enqueue(2);
    print_buffer();
    enqueue(3);
    print_buffer();
    enqueue(4);
    print_buffer();
    return 0;
}
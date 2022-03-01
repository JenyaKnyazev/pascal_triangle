#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int find_element(int row, int col) {
    int left, up;
    left = up = 0;
    if (row == 0)
        return 1;
    if (row > 0 && row > col)
        up = find_element(row - 1, col);
    if (col > 0)
        left = find_element(row - 1, col - 1);
    return left + up;
}
int count_digits(int n) {
    if (n > 0)
        return 1 + count_digits(n / 10);
    return 0;
}
void print_space(int n) {
    while (n > 0) {
        putchar(' ');
        n--;
    }
}
void print_arr(int* arr, int start, int end, int space) {
    int i;
    for (i = start; i <= end/2; i++) {
        printf("%d", arr[i]);
        print_space(space - count_digits(arr[i])+1);
    }
    if (end % 2 == 1) {
        if ((space - count_digits(arr[i]) + 1) / 2 == 0)
            putchar(' ');
        print_space((space - count_digits(arr[i]) + 1)/2);
        printf("%d", arr[i]);
        print_space((space - count_digits(arr[i]) + 1)/2);
        i++;
    }
    for (; i <= end; i++) {
        print_space(space - count_digits(arr[i]) + 1);
        printf("%d", arr[i]);
    }
    putchar('\n');
}
void print_pascal_triangle(int rows) {
    int* run = (int*)calloc(rows + 2, sizeof(int));
    int* prev_line = (int*)calloc(rows + 2, sizeof(int));
    int* temp;
    int i,r,spaces;
    spaces = count_digits(find_element(rows - 1, rows / 2));
    prev_line[1] = 1;
    for (i = 1; i <= rows; i++) {
        for (r = 1; r <= i; r++)
            run[r] = prev_line[r] + prev_line[r - 1];
        print_space((rows - i)*spaces);
        print_arr(run, 1, i, spaces);
        temp = prev_line;
        prev_line = run;
        run = temp;
    }
    free(run);
    free(prev_line);
}
void run() {
    int n;
    do {
        printf("negative or zero exit,Enter pascal trinagle rows : ");
        scanf("%d", &n);
        print_pascal_triangle(n);
    } while (n > 0);
}
void main(){
    run();
    system("pause");
}

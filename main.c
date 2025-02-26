#include <stdio.h>
//10����->2����
void bit_change(int n, int binary[10]) {
    int i = 9;

    // �迭 �ʱ�ȭ
    for (int j = 0; j < 10; j++) {
        binary[j] = 0;
    }

    // 10������ 2������ ��ȯ
    while (n > 0 && i >= 0) {
        binary[i] = n % 2;
        n = n / 2;
        i--;
    }
}
//AND����
void compare_AND(int binary1[10], int binary2[10], int binary_out[10]) {
    for (int a = 0; a < 10; a++) {
        if (binary1[a]==1 && binary2[a]==1) {
            binary_out[a] = 1;
        }
        else {
            binary_out[a] = 0;
        }
    }
    printf("\n");
}
//OR����
void compare_OR(int binary1[10], int binary2[10], int binary_out[10]) {
    for (int a = 0; a < 10; a++) {
        if (binary1[a] == 1 || binary2[a] == 1) {
            binary_out[a] = 1;
        }
        else {
            binary_out[a] = 0;
        }
    }
    printf("\n");
}
//����Լ�
void print_binary(int binary[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%d", binary[i]);
        if ((i-1) % 4 == 0)printf(" ");
    }
    
}
//binary->decimal
int change_decimal(int binary[10]) {
    int decimal = 0;
    for (int i = 0; i < 10; i++) {
        decimal = decimal * 2 + binary[i];
    }
    return decimal;
}

//�����Լ�
int main(void) {
    int input1, input2;
    int change_bit1[10], change_bit2[10], result_AND[10], result_OR[10];

    // ����� �Է� �ޱ�
    printf("�Է�:\n>> ");
    scanf_s("%d %d", &input1, &input2);

    // 10������ 2������ ��ȯ
    bit_change(input1, change_bit1);
    bit_change(input2, change_bit2);

    // AND, OR ���� ����
    compare_AND(change_bit1, change_bit2, result_AND);
    compare_OR(change_bit1, change_bit2, result_OR);

    // 2������ 10������ ��ȯ
    int and_decimal = change_decimal(result_AND);
    int or_decimal = change_decimal(result_OR);

    // ���1
    printf("���:\n");
    printf(">> %d (10) = ", input1);
    print_binary(change_bit1);
    printf(" (2)\n");
    printf(">> %d (10) = ", input2);
    print_binary(change_bit2);
    printf(" (2)\n");
    //���2
    printf(">> ");
    print_binary(change_bit1);
    printf(" (2) AND ");
    print_binary(change_bit2);
    printf(" (2) = ");
    print_binary(result_AND);
    printf(" (2) = %d (10)\n", and_decimal);
    printf(">> ");
    print_binary(change_bit1);
    printf(" (2) OR  ");
    print_binary(change_bit2);
    printf(" (2) = ");
    print_binary(result_OR);
    printf(" (2) = %d (10)\n", or_decimal);

    return 0;
}

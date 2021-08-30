#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int a[SIZE][SIZE] = {
        {0,5,9,0,0,0,0,0},
        {0,0,0,6,0,0,13,0},
        {0,0,0,0,3,4,0,0},
        {0,0,0,0,0,0,11,0},
        {0,0,0,0,0,13,0,0},
        {0,0,0,8,0,0,0,0},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0}
    }; // ������� ������
int d[SIZE]; // ����������� ����������
int v[SIZE]; // ���������� �������

int begin_index = 0;
void inic() {
    // ����� ������� ������
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //������������� ������ � ����������
    for (int i = 0; i < SIZE; i++) {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
}

void Dejk() {
    int temp = 0, minindex = 0, min = 0;
    // ��� ���������
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++) { // ���� ������� ��� �� ������ � ��� ������ min
            if ((v[i] == 1) && (d[i] < min)) { // ��������������� ��������
                min = d[i];
                minindex = i;
            }
        }
        // ��������� ��������� ����������� ���
        // � �������� ���� �������
        // � ���������� � ������� ����������� ����� �������
        if (minindex != 10000) {
            for (int i = 0; i < SIZE; i++) {
                if (a[minindex][i] > 0) {
                    temp = min + a[minindex][i];
                    if (temp < d[i]) d[i] = temp;
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);

    // ����� ���������� ���������� �� ������
    //printf("\n���������� ���������� �� ������: \n");
    //for (int i = 0; i < SIZE; i++)
        //printf("%5d ", d[i]);
}

void put(int ver_end) {
    // �������������� ����
    int ver[SIZE]; // ������ ���������� ������
    int temp = 0;

    int end = ver_end; // ������ �������� �������
    ver[0] = end + 1; // ��������� ������� - �������� �������
    int k = 1; // ������ ���������� �������
    int weight = d[end]; // ��� �������� �������
    while (end != begin_index) { // ���� �� ����� �� ��������� �������
        for (int i = 0; i < SIZE; i++) // ������������� ��� �������
            if (a[i][end] != 0) {   // ���� ����� 
                int temp = weight - a[i][end]; // ���������� ��� ���� �� ���������� �������
                if (temp == d[i]) { // ���� ��� ������ � ������������ ������ �� ���� ������� � ��� �������
                    weight = temp; // ��������� ����� ���
                    end = i;       // ��������� ���������� �������
                    ver[k] = i + 1; // � ���������� �� � ������
                    k++;
                }
            }
    }
    // ����� ���� (��������� ������� ��������� � ����� ������� �� k ���������)
   /* printf("\n����� ����������� ����\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", ver[i]);*/
    printf("\nX%d\t%3d ", ver_end, ver[k - 2] - 1); //����� ������� �������

}
int main() {
       
    system("chcp 1251");
    system("cls");
    int ver_end = 0;
    inic();
    Dejk();
    while (1) {
        printf("\n\n���� ��������� ���������, ������� 0\n");
        printf("�������: ");
        scanf("%d", &ver_end);
        if (ver_end == 0) break;
        put(ver_end);
    }
    

    getchar(); getchar();
    return 0;
}
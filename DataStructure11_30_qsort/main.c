#include <stdio.h> 
#define SIZE 1000  //������ ������ ���� 
#define MAX 20 //������ ���� ���� 

int a[MAX];


//ī��Ʈ ���� 
int compare_count, move_count;
int c_total, m_total;
int once;//ó�� �ѹ��� ����Ŭ������ ��µǰ� 

//���� �Լ� 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//���� ������ �����ֱ����� ��ü ����Ʈ 
void print_all(int list[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d->", list[i]);

    }
    printf("\n");
}



void quickSort(int list[], int start, int end) {

    
    if (start >= end) return;
    //��Ƽ�� ������
    int key = start, i = start + 1, j = end, temp;
    while (i <= j) {
        while (i <= end && list[i] <= list[key]) i++,compare_count++;
        while (j > start && list[j] >= list[key]) j--, compare_count++;

        if (i > j) { swap(&list[key], &list[j]); move_count++; }
        else swap(&list[i], &list[j]);
    }
    if(once==0)print_all(list);

    //���� 
    quickSort(list,start, j - 1);
    quickSort(list ,j + 1, end);
}



void quickSortCycle() {

    compare_count = 0;
    move_count = 0;



    int i;

    int n = MAX;
    int list[MAX];

    if (once == 0)printf("�ʱⰪ\n");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        if (once == 0)printf("%d->", list[i]);

    }
    if (once == 0) {
        printf("\n");
        printf("\n");
    }
    quickSort(list, 0, n - 1);
    if (once == 0) {
        printf("compare count : %d\n", compare_count);
        printf("move count : %d\n", move_count);
    }
    //printf("rand %d", rand() % 100);
    c_total += compare_count;
    m_total += move_count;

}


void main() {
    srand(time(NULL));
    quickSortCycle();

    once = 1;//�ڿ� ����Ŭ������ ��� x
    for (int i = 0; i < 19; i++) {
        quickSortCycle();
    }


    printf(" compare count avg:%f\n ", (float)c_total / (float)20);
    printf("move count avg:%f\n ", (float)m_total / (float)20);


}
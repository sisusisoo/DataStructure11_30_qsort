#include <stdio.h> 
#define SIZE 1000  //정리가 가능한 갯수 
#define MAX 20 //정렬할 숫자 갯수 

int a[MAX];


//카운트 변수 
int compare_count, move_count;
int c_total, m_total;
int once;//처음 한번의 싸이클에서만 출력되게 

//스왑 함수 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//정렬 과정을 보여주기위한 전체 프린트 
void print_all(int list[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d->", list[i]);

    }
    printf("\n");
}



void quickSort(int list[], int start, int end) {

    
    if (start >= end) return;
    //파티션 나누기
    int key = start, i = start + 1, j = end, temp;
    while (i <= j) {
        while (i <= end && list[i] <= list[key]) i++,compare_count++;
        while (j > start && list[j] >= list[key]) j--, compare_count++;

        if (i > j) { swap(&list[key], &list[j]); move_count++; }
        else swap(&list[i], &list[j]);
    }
    if(once==0)print_all(list);

    //정렬 
    quickSort(list,start, j - 1);
    quickSort(list ,j + 1, end);
}



void quickSortCycle() {

    compare_count = 0;
    move_count = 0;



    int i;

    int n = MAX;
    int list[MAX];

    if (once == 0)printf("초기값\n");
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

    once = 1;//뒤에 싸이클에서는 출력 x
    for (int i = 0; i < 19; i++) {
        quickSortCycle();
    }


    printf(" compare count avg:%f\n ", (float)c_total / (float)20);
    printf("move count avg:%f\n ", (float)m_total / (float)20);


}
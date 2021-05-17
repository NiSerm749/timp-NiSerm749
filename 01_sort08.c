#include <stdio.h>
#include <stdlib.h>

// сортировка Шелла
void shellSort(int *arr, int size, FILE* fp) {
    int tmp, s, i, j, z; // переменная для обмена элементов

    for (s = size / 2; s > 0; s /= 2) { // цикл по блокам
        for (i = 0; i < size; i++) {
            for(j = i + s; j < size; j += s) {
                if(arr[i] > arr[j]){
                    tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;

                    for (z = 0; z < size; z++) {
                        if (z != 0)
                            fprintf(fp, " ");
                        fprintf(fp, "%d", arr[z]);
                    }
                    fprintf(fp, "\n");

                }

            }
        }
    }
}

// сортировка "расческой"
void combSort(int *arr, int size, FILE* fp) {
    double factor = 1.2473309; // фактор уменьшения
    int step = size - 1; // шаг сортировки
    int tmp, i, j; // переменная для обмена элементов

    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1) {
        for (i = 0; i + step < size; i++) {
            if (arr[i] > arr[i + step]) {
                tmp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = tmp;

                for (j = 0; j < size; j++) {
                    if (j != 0)
                        fprintf(fp, " ");
                    fprintf(fp, "%d", arr[j]);
                }
                fprintf(fp, "\n");
            }
        }
        step /= factor; // уменьшим шаг сортировки
    }
}

int main() {
    int size, i;
    scanf("%d", &size);
    int *a1 = (int*)malloc(sizeof(int) * size);
    int *a2 = (int*)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) {
        scanf("%d", &a1[i]);
        a2[i] = a1[i];
    }

    char qf [] = "shellSort.log";
    FILE *fp = fopen(qf, "w+");
    for (i = 0; i < size; i++) {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", a1[i]);
    }
    fprintf(fp, "\n");

    shellSort(a1, size, fp);
    fclose(fp);

    for(int i = 0; i < size; i++) {
        printf("%d", a1[i]);
        if(i<size-1)
            printf(" ");
    }

    char hf [] = "combSort.log";
    fp = fopen(hf, "w+");
    for (i = 0; i < size; i++) {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", a2[i]);
    }
    fprintf(fp, "\n");

    combSort(a2, size, fp);
    fclose(fp);
    free(a1);
    free(a2);
    printf("\n");
    return 0;
}
#include <stdio.h>

int HEAP[100];
int SIZE = 0;

int push(int number) {
    /**
     * @return location of the inserted
     */
    int now = SIZE + 1;
    HEAP[SIZE ++] = number;
    while (now > 1) {
        int next = now / 2;
        if (HEAP[next - 1] < HEAP[now - 1]) {
            int tmp = HEAP[next - 1];
            HEAP[next - 1] = HEAP[now - 1];
            HEAP[now - 1] = tmp;
            now /= 2;
        } else {
            break;
        }
    }
    return now - 1;
}

void modify() {
    int p = SIZE - 1;
    while (p > 0) {
        int tmp = HEAP[p];
        HEAP[p] = HEAP[0];
        HEAP[0] = tmp;
        p --;

        int now = 1;
        while (now * 2 <= p) {
            int next = 2 * now;
            if (HEAP[next] > HEAP[next - 1]) { // 这里注意选择更大的子节点
                next ++;
            }
            if (HEAP[next - 1] > HEAP[now - 1]) {
                tmp = HEAP[next - 1];
                HEAP[next - 1] = HEAP[now - 1];
                HEAP[now - 1] = tmp;
                now = next;
            } else {
                break;
            }
        }
    }
}

void heap_sort(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        push(array[i]);
    }
    modify();
    for (i = 0; i < size; i++) {
        array[i] = HEAP[i];
    }
}

int main() {
    // test
    int i, n, arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heap_sort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

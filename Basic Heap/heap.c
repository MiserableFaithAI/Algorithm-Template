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
        if (HEAP[next - 1] > HEAP[now - 1]) {
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

int pop() {
    int result = HEAP[0];
    HEAP[0] = HEAP[-- SIZE];
    int now = 1;
    while (now * 2 <= SIZE) {
        int next = 2 * now;
        if (HEAP[next] < HEAP[next - 1]) { // 这里注意选择更小的子节点
            next ++;
        }
        if (HEAP[next - 1] < HEAP[now - 1]) {
            int tmp = HEAP[next - 1];
            HEAP[next - 1] = HEAP[now - 1];
            HEAP[now - 1] = tmp;
            now = next;
        } else {
            break;
        }
    }
    return result;
}

int top() {
    return HEAP[0];
}
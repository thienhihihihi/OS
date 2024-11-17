#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q == NULL || proc == NULL) return;

    // Kiểm tra hàng đợi đã đầy hay chưa
    if (q->size == MAX_QUEUE_SIZE) {
        fprintf(stderr, "Queue is full, cannot enqueue process.\n");
        return;
    }

    // Thêm tiến trình vào cuối hàng đợi
    q->proc[q->size] = proc;

    // Tăng kích thước hàng đợi
    q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
         if (q==NULL || empty(q)) return NULL;
         
         int highest_prio_idx = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->proc[i]->prio > q->proc[highest_prio_idx]->prio) {
            highest_prio_idx = i;
        }
    }
          struct pcb_t * selected_proc = q->proc[highest_prio_idx];
          
    for (int i = highest_prio_idx; i < q->size - 1; i++) {
        q->proc[i] = q->proc[i + 1];
    }

    // Giảm kích thước hàng đợi
    q->size--;

    return selected_proc;
}


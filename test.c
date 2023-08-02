//wakeup
pthread_mutex_lock(&current_mutex);
process->state = PROCESS_READY;
pthread_mutex_unlock(&current_mutex);
enqueue(rq, process);

//deque
if (is_empty(queue)) {
        return NULL;
    }
    pthread_mutex_lock(&queue_mutex);
    pcb_t* rmValue = queue->head;
    if (rmValue->next == NULL)  {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = rmValue->next;
    }
    pthread_mutex_unlock(&queue_mutex);
    return rmValue;

//schedule
pcb_t* runProc = dequeue(rq);
    if (runProc == NULL) {
        context_switch(cpu_id, NULL, rrtimeslice);
        return;
    }
    pthread_mutex_lock(&current_mutex);
    runProc->state = PROCESS_RUNNING;
    current[cpu_id] = runProc;
    pthread_mutex_unlock(&current_mutex);
    context_switch(cpu_id, runProc, rrtimeslice);

//enqueue
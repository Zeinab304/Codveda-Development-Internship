#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define TOTAL_ITEMS 15

int buffer[BUFFER_SIZE];
int product = 0;
int consumption = 0;
int count = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cv_empty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for (int item = 1; item <= TOTAL_ITEMS; item++) {
        pthread_mutex_lock(&mtx);

        while (count == BUFFER_SIZE) {
            printf("\n[PRODUCER] Buffer is FULL! Waiting for consumer....\n\n");
            pthread_cond_wait(&cv_full, &mtx);
        }

        buffer[consumption] = item;
        consumption = (consumption + 1) % BUFFER_SIZE;
        count++;

        printf("[PRODUCER] Produced item: %d | Buffer Size: %d\n", item, count);

        pthread_cond_signal(&cv_empty);
        pthread_mutex_unlock(&mtx);

        usleep(500000);
    }
    printf("\n[PRODUCER] Finished producing all %d items. Thread exiting...\n\n", TOTAL_ITEMS);
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= TOTAL_ITEMS; i++) {
        pthread_mutex_lock(&mtx);

        while (count == 0) {
            printf("\n[CONSUMER] Buffer is EMPTY! Waiting for producer...\n\n");
            pthread_cond_wait(&cv_empty, &mtx);
        }

        int item = buffer[product];
        product = (product + 1) % BUFFER_SIZE;
        count--;

        printf("[CONSUMER] Consumed item: %d | Buffer Size: %d\n", item, count);

        pthread_cond_signal(&cv_full);
        pthread_mutex_unlock(&mtx);

        usleep(800000);
    }
    printf("\n[CONSUMER] Finished consuming all %d items. Thread exiting...\n", TOTAL_ITEMS);
    return NULL;
}

int main() {
    printf("--- Starting Bounded Producer-Consumer Simulation ---\n\n");

    pthread_t prodThread, consThread;

    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);

    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cv_full);
    pthread_cond_destroy(&cv_empty);

    printf("\n--- All threads finished. Program terminating successfully! ---\n");
    return 0;
}

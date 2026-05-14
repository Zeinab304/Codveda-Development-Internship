#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

queue<int> buffer;
const int BUFFER_SIZE = 5;

mutex mtx;
condition_variable cv_full;
condition_variable cv_empty;

const int TOTAL_ITEMS = 15;

// Producer Function
void producer() {

    for (int item = 1; item <= TOTAL_ITEMS; item++) {
        unique_lock<mutex> lock(mtx);

        while (buffer.size() == BUFFER_SIZE) {
            cout << "\n[PRODUCER] Buffer is FULL! Waiting for consumer....\n\n";
            cv_full.wait(lock);
        }

        buffer.push(item);
        cout << "[PRODUCER] Produced item: " << item << " | Buffer Size: " << buffer.size() << endl;

        cv_empty.notify_one();
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\n[PRODUCER] Finished producing all " << TOTAL_ITEMS << " items. Thread exiting...\n\n";
}


// Consumer Function
void consumer() {

    for (int i = 1; i <= TOTAL_ITEMS; i++) {
        unique_lock<mutex> lock(mtx);

        while (buffer.empty()) {
            cout << "\n[CONSUMER] Buffer is EMPTY! Waiting for producer...\n\n";
            cv_empty.wait(lock);
        }

        int item = buffer.front();
        buffer.pop();
        cout << "[CONSUMER] Consumed item: " << item << " | Buffer Size: " << buffer.size() << endl;

        cv_full.notify_one();
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(800));
    }
    cout << "\n[CONSUMER] Finished consuming all " << TOTAL_ITEMS << " items. Thread exiting...\n";
}

int main() {
    cout << "--- Starting Bounded Producer-Consumer Simulation ---\n\n";

    thread prodThread(producer);
    thread consThread(consumer);

    prodThread.join();
    consThread.join();

    cout << "\n--- All threads finished. Program terminating successfully! ---\n";
    return 0;
}
class MyCircularDeque {
private:
    vector<int> deque; 
    int front, rear;   
    int size, capacity;

public:
    MyCircularDeque(int k) {
        deque = vector<int>(k);  
        capacity = k;          
        size = 0;               
        front = 0;             
        rear = k - 1;            
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;                     
        size++;                                   
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        deque[rear] = value;          
        size++;                       
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;                        
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity; 
        size--;                                   
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;  
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) return -1; 
        return deque[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

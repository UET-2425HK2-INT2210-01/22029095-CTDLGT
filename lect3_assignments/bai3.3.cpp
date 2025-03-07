//Queue su dung mang:

Algorithm Enqueue(Q, x):
    if Q.rear = Q.size - 1 then:
        return "Queue is full"
    Q.rear ? Q.rear + 1
    Q.array[Q.rear] ? x

Algorithm Dequeue(Q):
    if Q.front > Q.rear then:
        return "Queue is empty"
    Q.front ? Q.front + 1

Algorithm Front(Q):
    if Q.front > Q.rear then:
        return "Queue is empty"
    return Q.array[Q.front]

//Ðo phuc tap:
Enqueue(x): O(1)
Dequeue(): O(1)
Front(): O(1)

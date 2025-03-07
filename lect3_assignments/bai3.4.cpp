//Queue su dung danh sach lien ket:

Algorithm Enqueue(Q, x):
    newNode ? CreateNode(x)
    if Q.rear = NULL then:
        Q.front ? newNode
        Q.rear ? newNode
    else:
        Q.rear.next ? newNode
        Q.rear ? newNode

Algorithm Dequeue(Q):
    if Q.front = NULL then:
        return "Queue is empty"
    temp ? Q.front
    Q.front ? Q.front.next
    Delete(temp)

Algorithm Front(Q):
    if Q.front = NULL then:
        return "Queue is empty"
    return Q.front.value

//do phuc tap:
Enqueue(x): O(1)
Dequeue(): O(1)
Front(): O(1)

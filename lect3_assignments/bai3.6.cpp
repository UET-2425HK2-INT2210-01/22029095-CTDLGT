//stack su dung danh sach lien ket
Algorithm Push(S, x):
    newNode ? CreateNode(x)
    newNode.next ? S.top
    S.top ? newNode

Algorithm Pop(S):
    if S.top = NULL then:
        return "Stack is empty"
    temp ? S.top
    S.top ? S.top.next
    Delete(temp)

Algorithm Top(S):
    if S.top = NULL then:
        return "Stack is empty"
    return S.top.value

//do phuc tap
Push(x): O(1)
Pop(): O(1)
Top(): O(1)

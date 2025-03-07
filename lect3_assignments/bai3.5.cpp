//stack su dung mang:

Algorithm Push(S, x):
    if S.top = S.size - 1 then:
        return "Stack is full"
    S.top ? S.top + 1
    S.array[S.top] ? x

Algorithm Pop(S):
    if S.top = -1 then:
        return "Stack is empty"
    S.top ? S.top - 1

Algorithm Top(S):
    if S.top = -1 then:
        return "Stack is empty"
    return S.array[S.top]

//Ðo phuc tap:
Push(x): O(1)
Pop(): O(1)
Top(): O(1)

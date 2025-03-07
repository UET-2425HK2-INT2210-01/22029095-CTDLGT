
//thuat toan 1: dung Lap:

Algorithm Power_Iterative(n):
    result ? 1
    for i from 1 to n do:
        result ? result * 2
    return result


//thuat toan 2: de quy:

Algorithm Power_Recursive(n):
    if n = 0 then:
        return 1
    else:
        return 2 * Power_Recursive(n - 1)



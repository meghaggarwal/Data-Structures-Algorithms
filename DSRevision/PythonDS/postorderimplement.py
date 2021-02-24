import time


# given a full , complete, perfect  binary tree of height h, which has been filled with numbers from 1 to (2^h-1) in postorder
#  
#    1

#    3
#  1  2

#       7
#   3      6
# 1   2  4   5

# given the height h and a node n
# give the parent of n or -1 if it doesn't exist

def solution(h, q):
    # Your code here
    class Powers:
        def __init__(self, size):

            # create a array containing values
            # 1,3,7,15, 31, ...
            self._buffer = [1] * size
            curr = 1
            for idx in range(size):
                curr *= 2
                self._buffer[idx] = curr - 1

        def get_idx(self, idx):
            return self._buffer[idx]

        def find(self, value):
            start = 0
            end = len(self._buffer) - 1
            while start <= end:
                mid = (start + end)//2
                if mid >= (len(self._buffer) - 1):
                    raise ValueError()

                if self._buffer[mid] == value:
                    return self._buffer[mid], self._buffer[mid + 1], True

                if value > self._buffer[mid]:
                    start =  mid + 1
                else:
                    end = mid - 1

            if mid == end:
                return self._buffer[mid], self._buffer[mid + 1], False
            else:
                return self._buffer[mid - 1], self._buffer[mid], False

    # additional +1 for Binary Search
    p = Powers(h + 1)
    max_value = p.get_idx(-2)
    print(max_value)
    # direction
    # 'L'
    # 'R'

    def find(value, direction, powers):
        if value >= max_value:
            return -1

        L,U, matched = p.find(value)
        #print(value)
        if matched:
            #print("\n\n")
            if direction == 'L':
                return L + 1
            else:
                return 1

        direction = 'L'
        if value >= (U + L) // 2:
            direction = 'R'
        return find(value - L, direction, powers)

    result = []
    for value in q:
        t = find(value, 'L', p)
        if t != -1:
            t += value
        result.append(t)
    return result

now = time.time()
print(solution(6, [1,7,32,100,4, 22, 29, 25, 28]))
print(time.time() - now)
print("\n")


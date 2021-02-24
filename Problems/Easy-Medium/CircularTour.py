# Given info for n petrol pumps, calculate whether there exist a circular tour starting from any petrol pump.

# Approach 1 - Window sliding method
# If at a certain petrol pump available gas is less than zero, move the start pointer
# End pointer will always move untill end is not equal to start
# TC - O(n) SC - O(1) 

def circularPetrolPump(x, y, n):

    start = 0
    end = 1
    totalGas = x[start] - y[start]
    while(start!=end):
        if totalGas < 0:
            totalGas -= x[start] - y[start]
            start = (start + 1) % n
            if start == 0:
                    return -1
            
        totalGas += x[end] - y[end]
        end  = (end + 1) % n

    return start

x = [4,6,1,4] #Petrol
y = [6,5,3,5] #Distance
n = 4

print(circularPetrolPump(x,y,n))

# Approach 2 : availableGas + deficient Gas > 0 
# if availableGas < 0, move start pointer
# No end pointer is required, since we keep track of deficient gas 
# Loop till n

# TC _ O(n), SC _ O(1)

def circularTour(x, y, n):
    start = 0
    availableGas = 0
    deficientGas = 0
    for i in range(n):
        availableGas += x[i] - y[i]

        if availableGas < 0:
            availableGas = 0
            deficientGas += availableGas
            start = (start + 1) % n
    if availableGas + deficientGas >=0:
        return start
    else:
        return -1
x = [10,7,4,4]
y = [6,5,3,5]
n = 4
print(circularTour(x,y,n))


# Approach 3 Brute force
# TC - O(n)  SC - O(1)

def circularTourCheck(x,y,n):
    for i in range(n):
        gasAvailable = 0
        start = i
        end = (start + 1)%n 
        flag = True
        while(end != start):
            gasAvailable += x[i] - y[i]
            end = (end + 1) % n
            if gasAvailable < 0:
                flag = False
                break
        if flag:
            return i
        else:
            continue 
    return -1
x = [4,2,11,4]
y = [6,5,3,5]
n = 4
print(circularTourCheck(x,y,n))





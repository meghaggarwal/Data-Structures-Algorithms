def tour(lis, n):
    start = 0
    end = 0
    tp = 0
    count = 0
    tp = tp + lis[start][0] - lis[start][1]

    
    while(start <= n):
        
        if tp < 0:
            tp -= lis[start][0] - lis[start][1]
            if start == end:
                end = (end + 1 )% n
                tp =  lis[end ][0] - lis[end][1]
            start = (start + 1) % n
       
            if start == 0:
                return -1
            
        else:
            end = (end + 1) % n
            tp += lis[end][0] - lis[end][1]
            
            
        if start == end:
            return start


            
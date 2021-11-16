def CodeWrite (num): 
    num = 1
    while (num < 100):
        flag = 0 
        i=2
        while(i <= num/2): 
            if(num % i == 0):
              flag = 1 
              break
            i=i+1 
            if flag == 0:
             print(num) 
            num = num + 1
# Question One (1) Remove Duplicates from Sorted Array.

import random

def remove_duplicates(arr):
    index = 1
    print(f'Initial length is {len(arr)}')  
    for i in range(len(arr)):               #inplace operation to avoid introducing another array
        if arr[i] != arr[i-1]:
            arr[index] = arr[i]
            index +=1
    
    print(f'new length is : {index}')   
    return index
def main():
    n =int(input("How many numbers do you want?"))
    arr = [random.randint(1,10)for i in range(n)]
    arr.sort()
    remove_duplicates(arr)

if __name__ == "__main__":
    main()




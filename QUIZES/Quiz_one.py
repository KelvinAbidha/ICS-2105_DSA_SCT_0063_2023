'''
 Question One (1) Remove Duplicates from Sorted Array.
 Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
'''
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




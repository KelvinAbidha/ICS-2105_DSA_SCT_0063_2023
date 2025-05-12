'''
Task One 
Define two functions: summation and maximum both of which take an integer array of length
0<= n<= ∞. The summation function gets the sum of the integers while the maximum function
obtains the largest integer in the array
Within the main function; declare an array of length n, obtain the n from the user, then allow the
user to enter these n integers storing them in the array. Call the two functions in turns and display
their outputs.
'''

def sum(arr):
    sum = 0
    for i in arr:
        sum += i
    
    return sum
    
def max(arr):
    max = arr[0]
    for num in arr[1:]:
        if num > max :
            max = num
        return max
        
def main():
    n = int(input("How many numbers will you need?"))
    arr = []
    for i in range(n):
        element = int(input("Enter number"))
        arr.append(element)

    print(f'Sum is = {sum(arr)}')
    print(f'Max is = {max(arr)}')
    
if __name__ == "__main__":
    main()
        

    
    

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
        

    
    
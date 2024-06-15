def Binary_Search(arr,low,high,num):
    if high >= low:
        mid = (high + low) // 2

        if num == arr[mid]:
            return mid
        elif num < arr[mid]:
            return Binary_Search(arr,low,mid-1,num)
        else:
            return Binary_Search(arr,mid+1,high,num)
    else:
        return -1

arr = [1,2,3,4,5,6,7,8,9]
low = 0
high = len(arr)-1
num = int(input())
result = Binary_Search(arr,low,high,num)

if result == -1:
    print("None")
else:
    print(result)

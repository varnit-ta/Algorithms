def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

array = [23, 4 , 6, 33, 78, 0 , 23]
bubble_sort(array)
print(array)
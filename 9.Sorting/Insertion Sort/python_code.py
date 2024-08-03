def insertion_sort(arr):
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j = j - 1

        arr[j+1] = key

data = [9, 5, 1, 4, 3]
insertion_sort(data)
print('Sorted Array in Ascending Order:')
print(data)
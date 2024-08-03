def binary_search(array, x, low, high):
    while low <= high:
        mid = low + (high - low)//2

        if array[mid] == x:
            return True

        if array[mid] > x:
            return binary_search(array, x, low, mid - 1)
        if array[mid] < x:
            return binary_search(array, x, mid + 1, high)

    return False

arr = [0, 3, 5, 6, 93, 100, 304, 406, 987]

print(binary_search(arr, 5, 0, len(arr)-1))
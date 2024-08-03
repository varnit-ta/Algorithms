def merge_sort(arr):
    n = len(arr)

    if n < 2:
        return
    
    mid = n//2

    left = arr[:mid]
    right = arr[mid:]

    merge_sort(left)
    merge_sort(right)

    i, j, k = 0, 0, 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

if __name__ == "__main__":
    array = [6, 5, 12, 10, 9, 1]
    print(array)
    merge_sort(array)
    print(array)
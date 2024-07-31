array = [10 ,4, 2, 12, 134, 5, 33, 3]

def heapify(arr, size, i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < size and arr[left] > arr[largest]:
        largest = left
    if right < size and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[largest], arr[i] = arr[i], arr[largest]
        heapify(arr, size, largest)

def build_heap(arr, size):
    for i in range(size//2 - 1, -1, -1):
        heapify(arr, size, i)

def heap_sort(arr, size):
    build_heap(arr, size)

    print("")
    print("="*20)
    print("Original Heap : ", arr)

    for i in range(size-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    print("Sorted Heap : ", arr)
    print("="*20)
    print("")

def insert(arr, size, num):
    print("")
    print("="*20)
    print("Previous Heap : ", arr)

    arr.append(num)
    build_heap(arr, len(arr))

    print("After Heap : ", arr)
    print("="*20)
    print("")

def remove(arr, size, num):

    print("")
    print("="*20)
    print("Previous Heap : ", arr)

    i = 0
    for i in range(size):
        if num == arr[i]:
            break

    arr[i], arr[size - 1] = arr[size - 1], arr[i]
    arr.remove(num)

    build_heap(arr, len(arr))

    print("After Heap : ", arr)
    print("="*20)
    print("")

def main():
    while 1:
        print("1. Heap Sort")
        print("2. Insert")
        print("3. Delete")
        print("4. Exit")
        choice = int(input("Enter your choice : "))

        if choice == 1:
            heap_sort(array[:], len(array))
        elif choice == 2:
            num = int(input("Enter value to insert in heap : "))
            insert(array, len(array), num)
        elif choice == 3:
            num = int(input("Enter value to delete from heap : "))
            remove(array, len(array), num)
        elif choice == 4:
            break
        else:
            print("Invalid Input")

main()
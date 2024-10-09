def insertion_sort(array: list[int]) -> list[int]:
    for i in range(len(array)):
        for j in range(i, 0, -1):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
            else:
                break
    return array


def binare_search(array: list[int], find_number: int) -> int:
    left, right = 0, len(array) - 1
    while left <= right:
        middle = (right + left) // 2
        if array[middle] > find_number:
            right = middle - 1
        elif array[middle] < find_number:
            left = middle + 1
        else:
            return middle + 1
    return -1


def recurse(array: list[int], left: int, right: int, find_number: int) -> int:
    if left > right:
        return -1
    middle = (right + left) // 2
    if array[middle] > find_number:
        return recurse(array, left, middle - 1, find_number)
    elif array[middle] < find_number:
        return recurse(array, middle + 1, right, find_number)
    return middle + 1


def main():
    array = [2, 1, 7, 8, 9, 6, 5, 120]
    array = insertion_sort(array)
    print(*array, sep=' ')
    find_number = int(input("Введите искомое число: "))
    print("Индекс (от 1 до n):", binare_search(array, find_number))
    print("Индекс (от 1 до n):", recurse(array, 0, len(array) - 1, find_number))


if __name__ == "__main__":
    main()

#include <stdio.h>

// Function to print the elements of an array(TRAVERSAL Operation)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// INSERTION OPERATION IN AN ARRAY
void insertElement(int arr[], int *size, int index, int value) {
    if (index < 0 || index > *size) {
        printf("Invalid index for insertion.\n");
    } else {
        // Shift elements to the right to make space for the new element
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        (*size)++;
    }
}

// DELETION OPERATION IN AN ARRAY
void deleteElement(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion.\n");
    } else {
        // Shift elements to the left to close the gap left by the deleted element
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
}

int main() {
    int arr[10] = {11,12,13,14,15};
    int size = 5;

    printf("Original array: ");
    printArray(arr, size);

    // Insert an element at index 2
    insertElement(arr, &size, 2, 77);
    printf("Array after insertion: ");
    printArray(arr, size);

    // Delete the element at index 3
    deleteElement(arr, &size, 4);
    printf("Array after deletion: ");
    printArray(arr, size);

    return 0;
}

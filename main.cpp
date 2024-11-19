#include <iostream>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {

    std::cout << "\nElements are\n"<< std::endl;
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Append(struct Array* arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
    else {
        std::cerr << "Array Overflow" << std::endl;
    }
}
void Insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for(int i= arr->length; i>index; i-- ) {
            arr -> A[i] = arr -> A[i-1];
        }
        arr -> A[index] = x;
        arr -> length++;
    }
    else{
        std::cerr << "\nArray Overflow\n" << std::endl;
    }
}
/
int BinarySearch(struct Array arr, int key) {
    int mid;
    int l=0;
    int h=arr.length-1;
    while (l<=h) {
        mid = (l+h)/2;
        if (key == arr.A[mid]) {
            return mid;
        }
        else if (key < arr.A[mid]) {
            h=mid-1;
        }
        else
            l = mid+1;
    }
    return -1;
}
int RbinarySearch(int a[], int l, int h, int key) {
    int mid;
    if(l <=h) {
        mid = (l+h)/2;
        if (key == a[mid]) {
            return mid;
        }
        else if (key < a[mid]) {
            return RbinarySearch(a,l,mid-1,key);
        }
        else {
            return RbinarySearch(a,mid+1,h,key);
        }
    }
}

int Sum(struct Array arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum;
}

int Delete(struct Array* arr, int index) {
    int x= 0;
    if(index >= 0 && index < arr-> length ) {
        x = arr->A[index];
        for(int i =index; i<arr->length-1; i++) {
            arr->A[i] = arr -> A[i+1];
        }
        arr->length--;
    }
    else {
        std::cerr << "Invalid Index" << std::endl;
    }
    return x;
}

int LinearSearch(struct Array* arr, int key) {
    for(int i = 0; i< arr->length; i++) {
        if(key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }

    }
}
void DisplayArray(struct Array arr) {

    std::cout <<"Array elements: "<< std::endl;
    for(int i=0; i < arr.length;i++) {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    struct Array arr;
    int choice,x,index;
    std::cout << "Enter Array Size: ";
    std::cin >> arr.size;
    arr.A = new int[arr.size];
    do {
        std::cout <<"Menu\n";
        std::cout<<"1. Insert\n"; // ok
        std::cout<<"2. Delete\n"; // ok
        std::cout<<"3. Linear Search\n"; // ok
        std::cout<<"4. Sum\n"; // ok
        std::cout<<"5. Binary Search\n";
        std::cout<<"6. Append\n";
        std::cout<<"7. Display\n";
        std::cout<<"8. Exit\n"; // Option sayisini degistirdim bunu ayarla

        std::cout<<"Enter Choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Enter index and element: ";
                std::cin >> index >> x ;
                Insert(&arr,index,x);
                std::cout<<"\nArray Inserted:\n"<<std::endl;
                break;
            case 2:
                std::cout <<"Enter the index:";
                std::cin >> index;
                x = Delete(&arr,index);
                if ( index <0 || index > arr.length ) {
                    std::cerr << "Invalid Index" << std::endl;
                }
                else
                    std::cout <<"\nArray Deleted:\n"<<std::endl;
                break;
            case 3:
                std::cout <<"Enter the element for linear searching";
                std::cin >> x;
                index = LinearSearch(&arr,x);
                std::cout<<"\nArray Searched:\n"<<std::endl;
                if(index < 0 || index > arr.size) {
                    std::cout<<"Element not found\n";
                }
                else {
                    std::cout<<"Element found at index: "<<index<<std::endl;
                }
                break;
            case 4:
                std::cout << "sum " << Sum(arr) << std::endl;
                break;
            case 5:
                std::cout << "\nEnter the element for Binary Search";
                std::cin >> x;
                index = BinarySearch(arr,x); // Binary Search Complexity O(LogN)
                std::cout<<"\nArray Searched:\n"<<std::endl;
                if(index < 0 || index > arr.size) {
                    std::cout<<"\nElement not found\n";
                }
                else {
                    std::cout<<"\nElement found at index: "<<index<<std::endl;
                }
                break;
            case 6:
                std::cout << "\nEnter the element for append to array: "; // Append method is used
                std::cin >> x;
                Append(&arr,x);
                if (arr.length == arr.size) {
                    std::cout << "Append failed: Array is full.\n";
                }
                else {
                    std::cout<<"\nArray Appended:\n"<<std::endl;
                }

                break;
            case 7:
                DisplayArray(arr);
                break;
            case 8:
                std::cout << "Exit\n";
                break;

            default:
                std::cout << "Invalid Choice\n";
        }
    } while (choice<8);
    return 0;

}











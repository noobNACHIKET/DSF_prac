#include <iostream> 
using namespace std; 

void heapify(int arr[], int n, int i) { 
    // Find largest among root, left child and right child 
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) 
        largest = left; 

    if (right < n && arr[right] > arr[largest]) 
        largest = right; 

    // Swap and continue heapifying if root is not largest 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    } 
} 

void build_heap(int arr[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 

void heapSort(int arr[], int n) { 
    for(int i = n - 1; i >= 0; i--)  { 
    swap(arr[0], arr[i]);  
    heapify(arr, i, 0); 
 } 
} 


int extract_topper(int arr[], int& n) {
    // Return -1 if heap is empty
    if (n == 0) {
        return -1;
    }
    // Store the topmost element
    int topper = arr[0];
    // Swap the topmost element with the last element
    swap(arr[0], arr[n-1]);
    // Reduce the heap size
    n--;
    // Heapify the new root element
    heapify(arr, n, 0);
    // Return the topper element
    return topper;
}

void display(int arr[], int n) { 
    for (int i = 0; i < n; ++i) { 
        cout << arr[i] << " "; 
    } 
    cout << "\n"; 
}

int main() { 
    int n; 
    cout << "Enter the number of Students : "; 
    cin >> n; 
    int arr[n]; 
    for (int i=0; i<n; i++) { 
        cout << "Enter rank of student " << i+1 << " : "; 
        cin >> arr[i]; 
    } 
    // Build the max-heap based on ranks
    build_heap(arr, n); 
    // Extract the topmost element i.e. the next topper student for internship
    int topper = extract_topper(arr, n);
    if (topper != -1) {
        cout << "\nNext topper student for internship : " << topper << "\n";
    } else {
        cout << "\nNo student is eligible for internship.\n";
    }
    // Sort the array in ascending order of grades using heap sort
    heapSort(arr, n); 
    cout << "\nStudent ranks in ascending order : "; 
    display(arr, n); 
    return 0; 
}

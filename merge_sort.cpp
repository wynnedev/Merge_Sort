#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#define TOTAL_ELEMENTS 100
#define NUMBER_RANGE 1000

//TODO Implement using iterators instead of values
void Merge(std::vector<int>& data, unsigned start, unsigned mid, unsigned end) {

   // printf("Merging Start %d Mid %d End %d\n", start, mid, end);
    //initialize left-hand elements
    unsigned elements_left = mid - start + 1;
    std::vector<int> temp_left;
    for (unsigned i = 0; i < elements_left; i++) {
        temp_left.push_back(data[start + i]);
    }

    //initialize right-hand elements
    unsigned elements_right = end - mid;
    std::vector<int> temp_right;
    for (unsigned i = 0; i < elements_right; i++) {
        temp_right.push_back(data[mid + 1 + i]);
    }

    unsigned i = 0;
    unsigned j = 0;
    int pos = start;

    while (i < temp_left.size() && j < temp_right.size()) {
        //Insert smaller element
        if (temp_left[i] <= temp_right[j]) {
            data[pos] = temp_left[i++];
        }

        else {
            data[pos] = temp_right[j++];
        }

        //increment position
        ++pos;
    }

    //clean up remaining element
    while (i < temp_left.size()) {
        data[pos++] = temp_left[i++];
    }

    while (i < temp_right.size()) {
        data[pos++] = temp_right[i++];
    }
}

void MergeSort(std::vector<int>& data, unsigned l, unsigned r) {
    //printf("Sorting l %d r %d\n",l, r);

    if (l < r) {
        // Calculate middle of vector
        int mid = (l + r) / 2;


        //Sort Sub Vectors
        MergeSort(data, l, mid);
        MergeSort(data, (mid + 1), r);

        // Merge the two sub-lists
        Merge(data, l, mid, r);
    }
}

int main() {
    std::vector<int> data;

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        data.push_back(rand() % NUMBER_RANGE);
    }

    for (int& n : data) {
        printf("%d ", n);
    }
    printf("\n\n");

    MergeSort(data, 0, data.size() - 1);
    
    for (int& n : data) {
        printf("%d ", n);
    }
}

void memsort(vector<int>& arr,int first, int mid, int last, vector<int> temp)
{
    int i = first;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= last) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= last) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int i = 0; i < k; i++) {
        arr[first + i] = temp[i];
    }
}

void arrsort(vector<int>& arr,int first, int end, vector<int> temp)
{
    if (first < end) {
        int mid = (first + end) / 2;
        arrsort(arr, first, mid, temp);
        arrsort(arr, mid + 1, end, temp);
        memsort(arr, first, mid, end, temp);
    }
}
void sort012(int arr[], int n)
{
    int count[3] = {0,0,0};
    for(int i = 0; i<n; i++) {
        count[arr[i]]++;
    }
    int k = 0;
    for(int i = 0; i<count[0]; i++) {
        arr[k++] = 0;
    }
    for(int i = 0; i<count[1]; i++) {
        arr[k++] = 1;
    }
    for(int i = 0; i<count[2]; i++) {
        arr[k++] = 2;
    }
}
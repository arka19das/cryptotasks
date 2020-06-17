#include <bits/stdc++.h>
//#include <benchmark/benchmark.h>

#define ll long long

using namespace std;

static void intAddition(benchmark::State& state) {
    srand(time(0));
    int a = rand();
    srand(time(0));
    int b = rand();
    for (auto _ : state) {
        a + b;
    }
}

BENCHMARK(intAddition);

void merge (vector <int> &a, int l, int m, int r) {
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int v1[n1], v2[n2];
    for (i = 0; i < n1; i++) v1[i] = a[l+i];
    for (i = 0; i < n2; i++) v2[i] = a[m+1+i];

    i = 0; j = 0; k = 0;
    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            a[k] = v1[i];
            i++;
        }
        else {
            a[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = v1[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = v2[j];
        j++;
        k++;
    }
}

void mergeSort(vector <int> &a, int n) 
{ 
   int curr_size;  
   int left_start; 
  
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) 
   { 
       for (left_start=0; left_start<n-1; left_start += 2*curr_size) 
       { 
           int mid = min(left_start + curr_size - 1, n-1); 
  
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  
           merge(a, left_start, mid, right_end); 
       } 
   } 
} 

static void mergeSort(benchmark::State& state) {
    
    int size = 101001;
    int s = 0, e = size-1;
    vector <int> a(n);
    for (auto _ : state) {
        for (ll i = 0; i < size; i++) {
        a[i]=(rand());
    }
        mergeSort(a, size);
    }
}

BENCHMARK(mergeSort);

void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

ll partition (vector <int> &a, ll low, ll high) {
    int pivot = a[high];
    ll i = low-1;
    for (ll j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap (&a[i+1], &a[high]);
    return (i+1);
}

void quickSort(vector <int> &a, ll l, ll h) {
    int stack[h - l + 1];
    int sz = h-l+1; 
  
    int top = -1; 
     
    stack[++top] = l; 
    stack[++top] = h; 
  
    while (top >= 0) { 
         
        h = stack[top--]; 
        l = stack[top--];
         
        int p = partition(a, l, h); 
 
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
   
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    }
}

static void qSort(benchmark::State& state) {
    
    ll size = 10100;
    ll s = 0, e = size-1;
    vector <int> arr(size);
    for (auto _ : state) {
        for (ll i = 0; i < size; i++) {
        a[i]=(rand());
    }

        quickSort(arr, s, e);
    }
}

BENCHMARK(qSort);

static void normalSort(benchmark::State& state) {
    
    ll n = 101001;
    ll s = 0, e = n-1;
    vector <int> arr(n);
    for (auto _ : state) {
        for (ll i = 0; i < size; i++) {
        a[i]=(rand());
    }
        sort(arr.begin(), arr.end());
    }
}

BENCHMARK(normalSort);

BENCHMARK_MAIN();
#include <stdio.h>

int findMax(int *v, int n) {
  int max = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  return max;
}

void countingSort(int *v, int n, int exp) {
  const int range = 10;
  int output[n];
  int count[range];

  for (int i = 0; i < range; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count[(v[i] / exp) % 10]++;
  }

  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(v[i] / exp) % 10] - 1] = v[i];
    count[(v[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    v[i] = output[i];
  }
}

void radixSort(int *v, int n) {
  int max = findMax(v, n);

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(v, n, exp);
  }
}

void printvay(int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int tam = 8;
  int v[8] = {170, 45, 75, 90, 802, 24, 2, 66};

  printf("vay original: ");
  printvay(v, tam);

  radixSort(v, tam);

  printf("vay ordenado: ");
  printvay(v, tam);

  return 0;
}

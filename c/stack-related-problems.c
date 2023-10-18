// 1. Maximum area of histogram
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

ll getMaxArea(ll arr[], int n) {
  ll area = 0;
  for (int i = 0; i < n; i++) {
    ll minSoFar = INT_MAX;
    for (int j = i; j < n; j++) {
      minSoFar = min(minSoFar, arr[j]);
      area = max(area, minSoFar * (j - i + 1));
    }
  }
  return area;
}

int *nearestMinRight(ll arr[], int n) {
  int *right = malloc(sizeof(int) * n);
  for (int i = n - 1; i >= 0; i--) {
    right[i] = n;
    while (!stack_empty() && arr[i] <= arr[stack_top()]) {
      right[i] = stack_top();
      stack_pop();
    }
    stack_push(i);
  }
  return right;
}

int *nearestMinLeft(ll arr[], int n) {
  int *left = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    left[i] = -1;
    while (!stack_empty() && arr[i] <= arr[stack_top()]) {
      left[i] = stack_top();
      stack_pop();
    }
    stack_push(i);
  }
  return left;
}

int main() {
  ll arr[] = {6, 2, 5, 4, 5, 1, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  int *right = nearestMinRight(arr, n);
  int *left = nearestMinLeft(arr, n);

  ll *width = malloc(sizeof(ll) * n);
  for (int i = 0; i < n; i++) {
    width[i] = (right[i] - left[i] - 1) * arr[i];
  }

  printf("%lld\n", *max_element(width, width + n));

  free(right);
  free(left);
  free(width);

  return 0;
}

// 2. Maximum area of binary matrix
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int nearestMinRight(int arr[], int n) {
  int *stack = malloc(sizeof(int) * n);
  int top = -1;
  int v[n];
  for (int i = n - 1; i >= 0; i--) {
    while (top >= 0 && arr[i] <= arr[stack[top]]) {
      top--;
    }
    if (top >= 0) {
      v[i] = stack[top];
    } else {
      v[i] = n;
    }
    top++;
    stack[top] = i;
  }
  free(stack);
  return v[i];
}

int nearestMinLeft(int arr[], int n) {
  int *stack = malloc(sizeof(int) * n);
  int top = -1;
  int v[n];
  for (int i = 0; i < n; i++) {
    while (top >= 0 && arr[i] <= arr[stack[top]]) {
      top--;
    }
    if (top >= 0) {
      v[i] = stack[top];
    } else {
      v[i] = -1;
    }
    top++;
    stack[top] = i;
  }
  free(stack);
  return v[i];
}

int MAH(int arr[], int n) {
  int area = 0;
  int right[n];
  int left[n];
  for (int i = 0; i < n; i++) {
    right[i] = nearestMinRight(arr, n);
    left[i] = nearestMinLeft(arr, n);
  }

  for (int i = 0; i < n; i++) {
    int curr_area = (right[i] - left[i] - 1) * arr[i];
    area = max(area, curr_area);
  }
  return area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
  int arr[m];
  memset(arr, 0, sizeof(arr));

  int max_area = 0;

  for (int i = 0; i < n; i++) {
    // create 1D array
    for (int j = 0; j < m; j++) {
      if (M[i][j] == 0) {
        arr[j] = 0;
      } else {
        arr[j] += 1;
      }
    }

    int curr_area = MAH(arr, m);
    max_area = max(max_area, curr_area);
  }

  return max_area;
}

int main() {
  int n = 4, m = 4;
  int M[n][m] = {{0, 1, 1, 0},
                  {1, 1, 1, 1},
                  {1, 1, 1, 1},
                  {1, 1, 0, 0}};

  int max_area = maxArea(M, n, m);
  printf("%d\n", max_area);

  return 0;
}

// 3. Next Greater to right
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
  int *arr;
  int top;
} stack;

void init_stack(stack *s, int size) {
  s->arr = malloc(sizeof(int) * size);
  s->top = -1;
}

void push(stack *s, int val) {
  s->top++;
  s->arr[s->top] = val;
}

int pop(stack *s) {
  int val = s->arr[s->top];
  s->top--;
  return val;
}

int is_empty(stack *s) {
  return s->top == -1;
}

void nge(int *nums, int n) {
  stack s;
  init_stack(&s, n);
  int ans[n];

  for (int i = n - 1; i >= 0; i--) {
    while (!is_empty(&s) && nums[i] > nums[s.arr[s.top]]) {
      pop(&s);
    }
    if (!is_empty(&s)) {
      ans[i] = s.arr[s.top] - i;
    } else {
      ans[i] = 0;
    }
    push(&s, i);
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  int nums[] = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
  int n = sizeof(nums) / sizeof(nums[0]);

  nge(nums, n);

  return 0;
}

// 4. Rainwater Trapping
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

ll trappingWater(int arr[], int n) {
  ll rain = 0;
  int *left = malloc(sizeof(int) * n);
  int *right = malloc(sizeof(int) * n);

  left[0] = arr[0];
  for (int i = 1; i < n; i++) {
    left[i] = max(arr[i], left[i - 1]);
  }

  right[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(arr[i], right[i + 1]);
  }

  for (int i = 0; i < n; i++) {
    rain += min(left[i], right[i]) - arr[i];
  }

  free(left);
  free(right);

  return rain;
}

int main() {
  int N = 4;
  int arr[] = {7, 4, 0, 9};

  ll rain = trappingWater(arr, N);

  printf("%lld\n", rain);

  return 0;
}


// 5. Stock Span Problem
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
  int *arr;
  int top;
} stack;

void init_stack(stack *s, int size) {
  s->arr = malloc(sizeof(int) * size);
  s->top = -1;
}

void push(stack *s, int val) {
  s->top++;
  s->arr[s->top] = val;
}

int pop(stack *s) {
  int val = s->arr[s->top];
  s->top--;
  return val;
}

int is_empty(stack *s) {
  return s->top == -1;
}

// O(N^2) + O(N)
int *solve(int *arr, int n) {
  int *result = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    int j = i - 1;
    for (; j >= 0; --j) {
      if (arr[j] > arr[i]) {
        result[i] = i - j;
        break;
      }
    }
    if (j < 0) {
      result[i] = i + 1;
    }
  }
  return result;
}

// O(N) + O(2*N)
int *optmised(int *arr, int n) {
  int *result = malloc(sizeof(int) * n);

  stack s;
  init_stack(&s, n);

  for (int i = 0; i < n; i++) {
    while (!is_empty(&s) && arr[s.arr[s.top]] <= arr[i]) {
      pop(&s);
    }
    if (is_empty(&s)) {
      result[i] = i + 1;
    } else {
      result[i] = i - s.arr[s.top];
    }
    push(&s, i);
  }

  free(&s);

  return result;
}

int main() {
  int arr[] = {10, 4, 5, 90, 120, 80};
  int n = sizeof(arr) / sizeof(arr[0]);

  int *result = optmised(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);

  return 0;
}

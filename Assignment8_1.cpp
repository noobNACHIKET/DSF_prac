#include <bits/stdc++.h>

#include <stdio.h>

#define SIZE 10
#define FALSE 0
#define TRUE 1
#define h(x) x % SIZE
using namespace std;
// Without replacement 
void insert(int data[], int flag[], int chain[], int x) {
  int i = 0, j, start;
  start = h(x);
  while (flag[start] && i < SIZE) {
    if (data[start] % SIZE == x % SIZE) break;
    i++;
    start = (start + 1) % SIZE;
  }
  if (i == SIZE) {
    cout << "\nThe Hash Table is FULL";
    return;
  }
  while (chain[start] != -1)
    start = chain[start];
  j = start;
  while (flag[j] && i < SIZE) {
    j = (j + 1) % SIZE;
    i = i + 1;
  }
  if (i == SIZE) {
    cout << "\nThe Hash Table is FULL";
    return;
  }
  data[j] = x;
  flag[j] = TRUE;
  if (j != start)
    chain[start] = j;
}
int search(int data[], int flag[], int chain[], int x) {
  int i = 0, j;
  j = h(x);
  while (i < SIZE && flag[j] && data[j] % SIZE != x % SIZE) {
    i++;
    j = (j + 1) % SIZE;
  }
  if (flag[j] != 1 || i == SIZE)
    return (-1);
  while (j != -1) {
    if (data[j] == x)
      return (j);
    j = chain[j];
  }
  return (-1);
}
int main() {
  int i, j, x, op, loc, data[SIZE], flag[SIZE], chain[SIZE];
  for (i = 0; i < SIZE; i++) {
    flag[i] = FALSE;
    chain[i] = -1;
  }
  memset(data, -1, sizeof(data));
  do {
    cout << "\n1)Insert\n2)Search\n3)Display\n4)Quit\n";
    cout << "Enter your choice : ";
    cin >> op;
    switch (op) {
    case 1:
      cout << "\nEnter a number to be inserted : ";
      cin >> x;
      insert(data, flag, chain, x);
      break;
    case 2:
      cout << "\nEnter a number to be searched : ";
      cin >> x;
      loc = search(data, flag, chain, x);
      if (loc == -1) {
        cout << "\nElement not found ";
      } else {
        cout << "\nElement found at location = " << loc;
      }
      break;
    case 3:
      cout << "\nData\tIndex\tChain" << endl;
      for (int i = 0; i < SIZE; i++) {
        cout << data[i] << "\t " << i << "\t" << chain[i] << endl;
      }
      break;
    }
  } while (op != 4);
  return 0;
}
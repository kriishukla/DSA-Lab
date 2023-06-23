#include "../include/common.h"
#include "pa1.h"
#include <stdio.h>
#include <stdlib.h>


// don't remove these globals
static struct record *record_arr = NULL;
static size_t max_capacity = 0;
static size_t num_records = 0;

// don't modify this function
struct record *get_record_arr()
{
  return record_arr;
}

// don't modify this function
// compare two uids
// return -1 if uid1 < uid2
// return 0 if uid1 == uid2
// return 1 if uid1 > uid2
static int cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < MAX_LEN; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}

// don't modify this function min_idx
// compare two records when uid is key
// return -1 if record1 < record2
// return 0 if record1 == record2
// return 1 if record1 > record2
static int cmp_record(struct record *r1, struct record *r2)
{
  return cmp_uid(r1->uid, r2->uid);
}

//don't modify this function
static void *allocate_memory(size_t size)
{
  return __mymalloc(size);
}


static void free_memory(void *ptr)
{
  __myfree(ptr);
}

//---------------- Add your code below this line ----------------- //

#define NOT_IMPLEMENTED { printf("%s still needs to be implemented!\n", func); abort(); }

// return the total number of records in the
// record_arr
size_t get_num_records()
{
  return (size_t)num_records;

};

// Insert record krish at the end of the record array.
// If the record array is full, allocate a new buffer
// of double size, copy data from old buffer to the new
// buffer, delete the old buffer, and make record_arr
// point to the new buffer.
// Insert record krish at the end of the record array.
// If the record array is full, allocate a new buffer
// of double size, copy data from old buffer to the new
// buffer, delete the old buffer, and make record_arr
// point to the new buffer.
void insert_record(struct record krish)
{
  if (max_capacity == 0){
max_capacity = 1;num_records = 0;
record_arr = (struct record*) allocate_memory(max_capacity * sizeof(struct record));}
  if (max_capacity == num_records){
max_capacity *= 2;
struct record *krish = (struct record *) allocate_memory(max_capacity *   sizeof(struct record));
int i = 0;
while (i < num_records){      
krish[i] = record_arr[i];
i++;}
free_memory(record_arr);
record_arr = krish;}
record_arr[num_records] = krish;
num_records++;}


// return the record corresponding to the uid
// use the linear search algorithm
// you can also use cmp_uid routine defined earlier
// if none of the records contain the input uid
// return a dummy record with status == -1
struct record search_record_linear(char uid[MAX_LEN]) {
  struct record krish;
  int flag = 1;
  for (int i = 0; i < num_records; i++) {
    if (cmp_uid(uid, record_arr[i].uid) == 0) {
      krish = record_arr[i];
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    krish.status = -1;
  }
  return krish;
}
//binary
struct record search_record_binary(char uid[MAX_LEN]) {
struct record krish;int l = 0;int high = num_records - 1;int mid;int flag = 1;
while (l <= high) {
mid = (l + high) / 2;
if (cmp_uid(uid, record_arr[mid].uid) == 0) {
krish = record_arr[mid];
flag = 0;
break;} 
else if (cmp_uid(uid, record_arr[mid].uid) == 1) {
l = mid + 1;
} else {
high = mid - 1;}}
if (flag == 1) {
    krish.status = -1;
  }
  return krish;
}


// delete record correspondig to the uid
// if the corresponding record doesn't exist
// return a dummy record with status == -1
// Otherwise, return a copy of the record to the caller

// resize the record array in the following manner
// let's say, x is the size of the array
// and after deletion only x/4 
// space in the array is occupied, in this
// case, allocate an array of size x/2,
// copy records from old array to the new
// array, and delete the old array,
// make record_arr point to the new array
struct record delete_record(char uid[MAX_LEN]) {
  int index = -1;
  int flag = 1;
  int i = 0;
while (i < num_records) {
if (cmp_uid(record_arr[i].uid, uid) == 0) {
index = i;flag = 0;
break;}
i++;}

if (flag == 1) {
struct record dummy;
dummy.status = -1;
return dummy;}
struct record deleted_record = record_arr[index];
i = index;
while (i < num_records - 1) {
record_arr[i] = record_arr[i + 1];
i++;}
num_records--;
if (num_records * 4 <= max_capacity) {
size_t new_capacity = max_capacity / 2;
struct record *new_arr = allocate_memory(new_capacity * sizeof(struct record));
i = 0;
while (i < num_records) {
new_arr[i] = record_arr[i];
i++;}
free_memory(record_arr);
record_arr = new_arr;
max_capacity = new_capacity;}
return deleted_record;}

// delete all records in the record_arr
// free_memory record_arr
void delete_all_records(){
free_memory(record_arr);
num_records = 0;
max_capacity = 0;}

static int newcmp(struct record r1, struct record r2){
return cmp_uid(r1.uid, r2.uid);}

// sort the record array using quick sort
// use cmp_record implementaion to compare two records
#define EXCHANGE(arr, i, j) { \
  struct record tmp = arr[i]; \
  arr[i] = arr[j]; \
  arr[j] = tmp; \
}

int partition(struct record arr[], int lo, int hi){
struct record pivot = arr[lo];int left = lo;int right = hi;
while (left < right){
for (; left <= right && newcmp(arr[left], pivot) <= 0; left++);
for (; right >= left && newcmp(arr[right], pivot) > 0; right--);
if (left < right){EXCHANGE(arr, left, right);}}
EXCHANGE(arr, lo, right);
return right;}
void quicksort(struct record arr[], int lo, int hi){
while (lo < hi){
int p = partition(arr, lo, hi);
quicksort(arr, lo, p - 1);
lo = p + 1;}}
void sort_records_quick(){
quicksort(record_arr, 0, num_records - 1);}


// sort the record_arr using merge sort
// use cmp_record implementaion to compare two records
void merge(struct record arr[], int left, int middle, int right) {
int i, j, k;int n1 = middle - left + 1;int n2 = right - middle;
struct record *left_array = allocate_memory(n1 * sizeof(struct record));
struct record *right_array = allocate_memory(n2 * sizeof(struct record));
    for (i = 0; i < n1; i++)
        left_array[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_array[j] = arr[middle + 1 + j];
    i = 0; j = 0; k = left; 
for (k = left; i < n1 && j < n2; k++) {
if (cmp_record(&left_array[i], &right_array[j]) == -1 || cmp_record(&left_array[i], &right_array[j]) == 0) {
arr[k] = left_array[i];
i++;}
else {arr[k] = right_array[j];
j++;}}
while (i < n1) {arr[k] = left_array[i];
i++; k++;}
while (j < n2) {arr[k] = right_array[j];
j++; k++;}
free_memory(left_array);
free_memory(right_array);}

void mergeSort(struct record arr[], int left, int right) {
if (left < right) {int middle = left + (right - left) / 2;
mergeSort(arr, left, middle);
mergeSort(arr, middle + 1, right);
merge(arr, left, middle, right);}}

void sort_records_merge() {mergeSort(record_arr, 0, num_records - 1);}

// sort the record_arr using selection sort
// use cmp_record implementaion to compare two records
void swap(struct record *arr,  int i, int j){struct record tmp = arr[i];arr[i] = arr[j];arr[j] = tmp;}

void sort_records_selection(){
int i, index;
for (i = 0; i < num_records; i++){
index = i;
for (int j = i + 1; j < num_records; j++){
if (newcmp(record_arr[j], record_arr[index]) == -1){index = j;}}
if (index != i){
swap(record_arr, i, index);}}}

// return the number of records corresponding to the input name
// use linear search to obtain the results

static int cmp_name(struct record *r1, struct record *r2)
{
  return strcmp(r1->name, r2->name);
}
static int stlrcmp(struct record *r1, struct record *r2)
{
  return strcmp(r1->name, r2->name);
}

size_t get_num_records_with_name_linear(char name[MAX_LEN])
{int flag = 1;int count = 0;
for (int i = 0; i < num_records; i++)
{if (strcmp(record_arr[i].name, name) == 0){
flag = 0;count++;}}
if (flag == 0){
return (size_t)count;}
else{
return 0;}}

// implement quick sort algorithm to sort the
// record_arr using name as key
void exch(struct record arr[], int i, int j) {
struct record temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

int part(struct record *arr, int lo, int hi) {
char *pivot = arr[lo].name;
int left = lo;
int right = hi;

for (; left < right; ) {
for (; left <= right && strcmp(arr[left].name, pivot) <= 0; ) {
left++;
}
for (; right >= left && strcmp(arr[right].name, pivot) > 0; ) {
right--;
}
if (left < right) {
exch(arr, left, right);
}
}
exch(arr, lo, right);
return right;
}

void qui(struct record *arr, int lo, int hi) {
if (lo >= hi) {
return;
}
int p = part(arr, lo, hi);
qui(arr, lo, p - 1);
qui(arr, p + 1, hi);}
void rearrange_data(){
  qui(record_arr, 0, num_records - 1);}

// return the number of records corresponding to the input name
// use binary search to obtain the results
// you can assume that the caller has sorted
// data using name as key before making these queries
// return the number of records corresponding to the input name
// use binary search to obtain the results
// assume that the caller has sorted data using name as key before making these queries
size_t get_num_records_with_name_binary(char name[MAX_LEN]){
  int mid; int count = 0;int left = 0;int right = num_records - 1;
int compare_records(int index, char str[]) {
if (strcmp(record_arr[index].name, str) == 0) {return 0;}
else if (strcmp(record_arr[index].name, str) < 0) {return -1;} 
else {return 1;}}

for (; left <= right;) {
mid = (left + right) / 2;
if (compare_records(mid, name) == 0) {
count++;
  for (int i = mid - 1; i >= 0 && compare_records(i, name) == 0; i--) {
count++;      }
for (int i = mid + 1; i < num_records && compare_records(i, name) == 0; i++) {
 count++;}
return count;}
else if (compare_records(mid, name) < 0) {left = mid + 1;} 
else {right = mid - 1;}}
return count;}

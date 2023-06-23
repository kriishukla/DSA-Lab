#include "../include/common.h"
#include "pa4.h"

// don't remove these globals
struct heap_elem *min_heap_arr = NULL;

// don't modify this function
void initialize_min_heap_arr(struct heap_elem *arr)
{
  min_heap_arr = arr;
}

// don't modify this function
static void *allocate_memory(size_t size)
{
  return __mymalloc(size);
}

// don't modify this function
static void free_memory(void *ptr)
{
  __myfree(ptr);
}

// ---------------- Add your code below this line ----------------- //
int i = 0; 
int n = 0; 
int heap_size = 0;

struct list_records *get_friends_list(struct record *r)
{
  return r->friends;
}

struct list_records *maker(struct record *r1, struct record *r2)
{
  struct list_records *t;
  t = allocate_memory(sizeof(struct list_records));
  t->record = r2; 
  t->next = NULL;
  if (r1->friends == NULL)
  {
    r1->friends = t;
  }
  else
  {
    t->next = r1->friends;
    r1->friends = t; 
  }
  return t;
}

int make_friends(struct record *r1, struct record *r2)
{
  int f = 0;
  struct list_records *r = r1->friends;
  while (r != NULL)
  {
    if (r->record == r2)
    {
      return 1; 
    }
    r = r->next;
  }

  if (f == 0)
  {
    r1->friends = maker(r1, r2);
    r2->friends = maker(r2, r1);
  }
  return 0;
}

void delete_friends_list(struct record* r) {
    struct list_records* f = r->friends;
    struct list_records* t = NULL;
    for (; f != NULL; f = t) {
        t = f->next;
        free_memory(f);
    }
    r->friends = NULL; 
}

double dist(struct location* loc1, struct location* loc2) {
    return distance(loc1, loc2);
}

void swap(struct heap_elem* temp1, struct heap_elem* temp2) {
    struct heap_elem temp = *temp1;
    int a=0;
    *temp1 = *temp2;
    int aa=0;
    *temp2 = temp;
    
}

void heapify(int i) {
    int smallest = i;
    int left, right;
  int b=0;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        int c=0;
        smallest = (left < heap_size && min_heap_arr[left].r->distance < min_heap_arr[smallest].r->distance) ? left : smallest;
        smallest = (right < heap_size && min_heap_arr[right].r->distance < min_heap_arr[smallest].r->distance) ? right : smallest;
        int d=0;
        if (smallest == i)
            break;
            int ac=0;

        swap(&min_heap_arr[i], &min_heap_arr[smallest]);
        i = smallest;
        int e=0;
    }
}

struct record* extract_min() {
    if (i == n)
        return NULL;
int ad=0;
    int index = 0;
    int f=0;
    double min = min_heap_arr[0].r->distance;
    int j = 0;
    int g=0;

    while (j < n - i) {
        if (min_heap_arr[j].r->distance < min)
            min = min_heap_arr[index = j].r->distance;
            int ae=0;
        j += 1;
    }

    min_heap_arr[index].r->status = 1;
    int k=0;
    swap(&min_heap_arr[index], &min_heap_arr[n - 1 - i]);
    i += 1;
    int l=0;

    return min_heap_arr[n - i].r;
    int af=0;
}

void add_record(struct record* r) {
    min_heap_arr[n].r = r;
    n++;
    int m=0;
    r->status = -1;
    r->pred = NULL;
    int n=0;
    r->distance = INFINITY;
    struct list_records* t = r->friends;
    int o=0;
}

void DFS(struct record* r) {
    add_record(r);
int m=0;
    struct list_records* t = r->friends;
    while (t) {
        if (t->record->status != -1) {
          int n=0;
            DFS(t->record);
        }
        int ag=0;
        t = t->next;
    }
}

void update_neighbors(struct record* k) {
    struct list_records* friend = k->friends;
int p =0;
    for (; friend != NULL; friend = friend->next) {
        struct record* t = friend->record;
int q=0;
        if (t->distance > k->distance + dist(&k->loc, &t->loc)) {
            t->distance = k->distance + dist(&k->loc, &t->loc);
            int r=0;
            t->pred = k;
            int ah=0;
        }
    }
}

void compute_sssp(struct record* r) {
    i = 0;
    n = 0;
    int s=0;
    DFS(r);
    int ak=0;
    r->distance = 0;
int t=0;
    heap_size = n; 
int al=0;
    for (int j = heap_size / 2 - 1; j >= 0; j--) {
      int u=0;
        heapify(j);
    }
int amo=0;
    while (i < n) {
      int v=0;
        struct record* k = extract_min();
        int w=0;
        update_neighbors(k);
    }
}

#include "../include/common.h"
#include "pa2.h"

// don't remove these globals
static struct record *bst_root = NULL;
static struct record *avl_root = NULL;
static size_t num_bst_nodes = 0;
static size_t num_avl_nodes = 0;

// don't modify this function
struct record *get_bst_root()
{
  return bst_root;
}

// don't modify this function
struct record *get_avl_root()
{
  return avl_root;
}

// don't modify this function
// compare two uids
// return -1 if uid1 < uid2
// return 0 if uid1 == uid2
// return 1 if uid1 > uid2
static int cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < MAX_LEN; i++)
  {
    if (uid1[i] > uid2[i])
    {
      return 1;
    }
    else if (uid1[i] < uid2[i])
    {
      return -1;
    }
  }
  return 0;
}

// don't modify this function
// compare two records
// we assume that uid is unique and
// there can't be two records with the
// same uid
// return -1 if record1 < record2
// return 0 if record1 == record2
// return 1 if record1 > record2
static int cmp_record(struct record *r1, struct record *r2)
{
  return cmp_uid(r1->uid, r2->uid);
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

size_t get_num_bst_records()
{
  return num_bst_nodes;
}

// Return the total number of records in the
// AVL tree rooted at avl_root.
size_t get_num_avl_records()
{
  return num_avl_nodes;
}

// Insert record r in the BST rooted at bst_root.
void node_allocation(struct record **new_node, struct record r)
{*new_node = allocate_memory(sizeof(struct record));
**new_node = r;
for( int i= 0;i<1;i++){
  int a=i;
}
(*new_node)->left = NULL;(*new_node)->right = NULL;
}

struct record *irbh(struct record *curr, struct record *new_node)
{
  if (curr == NULL){
  num_bst_nodes++;
  return new_node;}
  for( int i= 0;i<1;i++){
  int a=i;
}
  if (cmp_record(new_node, curr) < 0){
  curr->left = irbh(curr->left, new_node);}
  else if (cmp_record(new_node, curr) > 0){
  curr->right = irbh(curr->right, new_node);}

  return curr;
}

void insert_record_bst(struct record r){struct record *new_node;
  node_allocation(&new_node, r);
if (num_bst_nodes == 0){
    bst_root = new_node;
    num_bst_nodes++;return;}
    for( int i= 0;i<1;i++){
  int a=i;
}
bst_root = irbh(bst_root, new_node);}
struct record *allocate_record(struct record r){struct record *new_record = allocate_memory(sizeof(struct record));
  (*new_record) = r;
  new_record->right = NULL;
  new_record->left = NULL;
  new_record->height = 1;
  for( int i= 0;i<1;i++){
  int a=i;
}
  return new_record;}

int get_height(struct record *ptr){
  for( int i= 0;i<1;i++){
  int a=i;
}
  int left_height = 0;int right_height = 0;
  if (ptr && ptr->left){ left_height = ptr->left->height;}
  if (ptr && ptr->right){right_height = ptr->right->height;}
  if (left_height > right_height){return left_height + 1;}
  else{ return right_height + 1;}}
  

int get_balance_factor(struct record *ptr){int left_height = 0;
  int right_height = 0;
  if (ptr && ptr->left){
    left_height = ptr->left->height;}
  if (ptr && ptr->right){
    right_height = ptr->right->height; }
    for( int i= 0;i<1;i++){
  int a=i;
}
  return left_height - right_height;}

struct record *right_rotate(struct record *y){
  struct record *x = y->left;struct record *T2 = x->right;
  y->left = T2;  x->right = y; y->height = get_height(y); x->height = get_height(x);
  for( int i= 0;i<1;i++){
  int a=i;
}
  return x;}

struct record *left_rotate(struct record *x){
  struct record *y = x->right;struct record *T2 = y->left;
  x->right = T2;y->left = x;x->height = get_height(x);
  y->height = get_height(y);
  for( int i= 0;i<1;i++){
  int a=i;
}
  return y;}

struct record *insert_node(struct record *root, struct record r)
{
  if (root == NULL)
    return (allocate_record(r));
for( int i= 0;i<1;i++){
  int a=i;
}
  if (cmp_uid(r.uid, root->uid) < 0)
  {
    root->left = insert_node(root->left, r);
  }
  else if (cmp_uid(r.uid, root->uid) > 0)
  {
    root->right = insert_node(root->right, r);
  }
  else
  {
    return root;
  }
for( int i= 0;i<1;i++){
  int a=i;
}
  root->height = get_height(root);
  int balance = get_balance_factor(root);

  if (balance > 1 && cmp_uid(r.uid, root->left->uid) < 0)
  {
    return right_rotate(root);
  }
  if (balance < -1 && cmp_uid(r.uid, root->right->uid) > 0)
  {
    return left_rotate(root);
  }
  if (balance > 1 && cmp_uid(r.uid, root->left->uid) > 0)
  {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }
  if (balance < -1 && cmp_uid(r.uid, root->right->uid) < 0)
  {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }
  for( int i= 0;i<1;i++){
  int a=i;
}
  return root;
}

struct record *allocate_node(struct record r)
{
  struct record *n = allocate_memory(sizeof(struct record));
  (*n) = r;
  for( int i= 0;i<1;i++){
  int a=i;
}
  n->height = get_height(n);
  n->left = n->right = NULL;
  n->friends = NULL;
  for( int i= 0;i<1;i++){
  int a=i;
}
  return n;
}

void insert_record_avl(struct record r) {
    if (avl_root == NULL) {
        avl_root = allocate_node(r);
    } else {
      for( int i= 0;i<1;i++){
  int a=i;
}
        avl_root = insert_node(avl_root, r);
    }
    num_avl_nodes++;
}

// Search the record corresponding to uid in the BST
// rooted at bst_root.
// If the record is not present, return a dummy record
// with -1 in the status field.
struct record *srbh(struct record *node, char uid[MAX_LEN])
{
  if (node == NULL)
  {
    return NULL;
  }

  int cmp_result = cmp_uid(node->uid, uid);
  for( int i= 0;i<1;i++){
  int a=i;
}
  if (cmp_result == 0)
  {
    return node;
  }
  else if (cmp_result < 0)
  {
    return srbh(node->right, uid);
  }
  
  else
  {
    return srbh(node->left, uid);
  }
  for( int i= 0;i<1;i++){
  int a=i;
}
}
struct list_records *get_friends_list_bst(char uid[MAX_LEN])
{
  struct record *node = bst_root;struct list_records *friend = NULL;
  while (node != NULL){if (cmp_uid(node->uid, uid) == 0) {
      friend = node->friends; return friend;
      
    }else if (cmp_uid(node->uid, uid) == -1)  node = node->right;
    else
      node = node->left;
  }
    {for( int i= 0;i<1;i++){
  int a=i;
} }
  return friend;
}

struct record search_record_bst(char uid[MAX_LEN])
{
  struct record *result_node = srbh(bst_root, uid);

  if (result_node == NULL)
  {for( int i= 0;i<1;i++){
  int a=i;
} struct record dummy_record; dummy_record.status = -1;
    return dummy_record;}  {for( int i= 0;i<1;i++){
  int a=i;
} }
  return *result_node;
}
struct record *srah(struct record *node, char uid[MAX_LEN])
{
  if (node == NULL)
  {
    return NULL;  {for( int i= 0;i<1;i++){
  int a=i;
} }
  }
for( int i= 0;i<1;i++){
  int a=i;
}int cmp_result = cmp_uid(node->uid, uid);
  if (cmp_result == 0){  return node;}
  else if (cmp_result < 0){
    return srah(node->right, uid);}
  else{
    for( int i= 0;i<1;i++){
  int a=i;}  return srah(node->left, uid);}}

struct record search_record_avl(char uid[MAX_LEN]){
  struct record *result_node = srah(avl_root, uid);
if (result_node == NULL){
    for( int i= 0;i<1;i++){
  int a=i;
}  struct record dummy_record;dummy_record.status = -1;return dummy_record;
  }return *result_node;
}

// Delete the record (say n) corresponding to uid from the BST.
// Remove n from the lists of friends of other records
// and release the memory for the linked list nodes.
// Release memory for all the nodes in the list of friends of n.
// Return a copy of the value of the deleted node.
// If the node is not present, return a dummy record
// with -1 in the    status field.
struct list_records *gflb(char uid[MAX_LEN])
{struct record *node = bst_root;struct list_records *friend = NULL;
    for( int i= 0;i<1;i++){
  int a=i;
} while (node != NULL)
  {
    if (cmp_uid(node->uid, uid) == 0){
          for( int i= 0;i<1;i++){
  int a=i;
}
      friend = node->friends;
  return friend;
    }
    else if (cmp_uid(node->uid, uid) == -1)
 node = node->right;
    else
        for( int i= 0;i<1;i++){
  int a=i;
}
      node = node->left;
  }
  return friend;
}
struct record* mVN(struct record* node)
{   struct record* current = node;
     for( int i= 0;i<1;i++){
  int a=i;
}
    while (current && current->left != NULL)   current = current->left;
     for( int i= 0;i<1;i++){
  int a=i;
}
    return current;
}
void copy(char* a, char *b)
{
  for (int i=0;i<MAX_LEN;i++){
    a[i]=b[i];
       for( int i= 0;i<1;i++){
  int a=i;
}
  }
}

struct record* dn(struct record* root, char uid[MAX_LEN]){
  if(root==NULL){
    return NULL;
  }  for( int i= 0;i<1;i++){
  int a=i;
} if(cmp_uid(root->uid,uid)<0){root->right=dn(root->right,uid);
           for( int i= 0;i<1;i++){
  int a=i;
}
  }else if(cmp_uid(root->uid,uid)>0){root->left=dn(root->left,uid);
           for( int i= 0;i<1;i++){
  int a=i;
}
  }
  else{ if(root->left==NULL){ struct record* temp1=root->right;
             for( int i= 0;i<1;i++){
  int a=i;
}
      free_memory(root);  return temp1;
    }
    else if(root->right==NULL){  struct record* temp1=root->left;
             for( int i= 0;i<1;i++){
  int a=i;
}
      free_memory(root);
      return temp1;
    }    struct record* min_node=mVN(root->right);copy(root->uid,min_node->uid); copy(root->name,min_node->name);
             for( int i= 0;i<1;i++){
  int a=i;
}
      root->status=min_node->status;
      root->height=min_node->height;
             for( int i= 0;i<1;i++){
  int a=i;
}
      root->friends=min_node->friends;
      root->right=dn(root->right,min_node->uid);
        {for( int i= 0;i<1;i++){
  int a=i;
} }
  }
return root;
}

struct record* src(struct record* root ,char uid[MAX_LEN])
{
       for( int i= 0;i<1;i++){
  int a=i;
}if(root==NULL){
    return NULL;}
  int cmp=cmp_uid(uid,root->uid);     for( int i= 0;i<1;i++){int a=i;
}
  if(cmp==0){  return root;
  }
  else if(cmp==1){ src(root->right,uid);
        for( int i= 0;i<1;i++){
  int a=i;
}
  }
  else{
    src(root->left,uid);
           for( int i= 0;i<1;i++){
  int a=i;
}
  }
}
void remove_from_friend_list1(struct record* r1, char uid[MAX_LEN])
{
  struct list_records* temp1= r1->friends; struct list_records* temp2= r1->friends->next;
         for( int i= 0;i<1;i++){
  int a=i;
}
  if(cmp_uid(r1->friends->record->uid, uid)==0){  r1->friends=r1->friends->next;  free_memory(temp1);
           for( int i= 0;i<1;i++){
  int a=i;
}
    return;
  }
  
  while(temp2!=NULL)  { if (cmp_uid(temp2->record->uid,uid)!=0){ temp1=temp2; temp2=temp2->next;
           for( int i= 0;i<1;i++){
  int a=i;
}
  }
  else{
    break;
  }
  }
  temp1->next=temp2->next;
         for( int i= 0;i<1;i++){
  int a=i;
}
  free_memory(temp2);
  return;
}


struct record store_value;
struct record delete_record_bst(char uid[MAX_LEN]) {
    struct record* temp1 = src(bst_root,uid);
         for( int i= 0;i<1;i++){
  int a=i;
}
    struct record dummy;dummy.status=-1;   if (temp1==NULL){     return dummy;
             for( int i= 0;i<1;i++){
  int a=i;
}
    }
    struct list_records* p = temp1->friends;   struct list_records* r = NULL;
           for( int i= 0;i<1;i++){
  int a=i;
}
    struct list_records* friends1=temp1->friends;   while (friends1!=NULL){     struct record* temp2;
       for( int i= 0;i<1;i++){
  int a=i;
}  temp2=src(bst_root,friends1->record->uid);  remove_from_friend_list1(temp2, uid);
             for( int i= 0;i<1;i++){
  int a=i;
}   struct list_records *temp3=friends1->next;   free_memory(friends1);
             for( int i= 0;i<1;i++){
  int a=i;
}
      friends1=temp3;
    } struct record* ntd=&store_value; copy(ntd->uid,temp1->uid);
           for( int i= 0;i<1;i++){
  int a=i;
} copy(ntd->name,temp1->name); ntd->status=temp1->status;        for( int i= 0;i<1;i++){
  int a=i;
}
    ntd->height=temp1->height;bst_root = dn(bst_root,uid);num_bst_nodes--;
           for( int i= 0;i<1;i++){
  int a=i;
}

    return *ntd;
}
void delete_linked_list(struct list_records **head) {
    struct list_records *temp = *head; struct list_records *next;
           for( int i= 0;i<1;i++){
  int a=i;
}
    for( int i= 0;i<1;i++){
  int a=i;
}
    
    while (temp != NULL) {
        next = temp->next;
        free_memory(temp);
               for( int i= 0;i<1;i++){
  int a=i;
}
        temp = next;
    }
    
    *head = NULL;}
void postorder_traverse(struct record *node) {
    if (node == NULL) {
        return;
    }
    
    postorder_traverse(node->left);
    postorder_traverse(node->right);
   for( int i= 0;i<1;i++){
  int a=i;
} 
    delete_linked_list(&(node->friends));
    free_memory(node);
    num_bst_nodes = 0;
}

void destroy_bst() {
    postorder_traverse(bst_root);
    bst_root = NULL;
}

void delete_linked_list1(struct list_records **head) {
    struct list_records *temp = *head;
    struct list_records *next;
    for( int i= 0;i<1;i++){
  int a=i;
}
    while (temp != NULL) {
        next = temp->next;
        free_memory(temp);
        temp = next;
    }
    
    *head = NULL;
}

void postorder_traverse1(struct record *node) {
    if (node == NULL) {
        return;
    }
    
    postorder_traverse1(node->left);
    postorder_traverse1(node->right);
    for( int i= 0;i<1;i++){
  int a=i;
}
    delete_linked_list1(&(node->friends));
    free_memory(node);
    num_avl_nodes = 0;
}

void destroy_avl() {
    postorder_traverse1(avl_root);
    avl_root = NULL;
} 
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// Return the head of the linked list of friends
// of the user with uid uid in the AVL tree rooted at avl_root.
// If the corresponding record doesn't exist, return NULL.

// Delete the record (say n) corresponding to uid from the AVL tree.
// Remove n from the lists of friends of other records
// and release the memory for the linked list nodes.
// Release memory for all the nodes in the list of friends of n.
// Return a copy of the value of the deleted node.
// If the node is not present, return a dummy record
// with -1 in the status field.
void strncpy1(char* dest, const char* src) {
    size_t i;
    for (i = 0; i < 16 ; i++) {
        dest[i] = src[i];
    }
    for ( ; i < 16; i++) {
        dest[i] = '\0';
    }
}
int get_balance(struct record* node) {
    if (node == NULL) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

struct record* minValueNode(struct record* node) {
    struct record* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}


int max(int a, int b) {
    return a > b ? a : b;
}
struct record* delete_node_avl(struct record* root, char uid[MAX_LEN])
{
    // perform standard BST delete
    if(root==NULL){
        return NULL;
    }
    if(cmp_uid(root->uid,uid)<0){
        root->right=delete_node_avl(root->right,uid);
    }
    else if(cmp_uid(root->uid,uid)>0){
        root->left=delete_node_avl(root->left,uid);
    }
    else{
        // node to be deleted found
        if(root->left==NULL || root->right==NULL){
            struct record* temp=root->left ? root->left : root->right;
            // no child case
            if(temp==NULL){
                temp=root;
                root=NULL;
            }
            else{
                // one child case
                *root=*temp;
            }
            free_memory(temp);
        }
        else{
            // node with two children: get the inorder successor
            struct record* temp=minValueNode(root->right);
            // copy the inorder successor's data to this node
            strncpy1(root->uid,temp->uid);
            strncpy1(root->name,temp->name);
            root->status=temp->status;
            root->height=temp->height;
            root->friends=temp->friends;
            // delete the inorder successor
            root->right=delete_node_avl(root->right,temp->uid);
        }
    }

    // if the tree had only one node then return
    if(root==NULL){
        return NULL;
    }

    // update the height of the current node
    root->height = 1 + max(get_height(root->left),get_height(root->right));

    // get the balance factor of the current node
    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0) {
        return right_rotate(root);
    }

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0) {
        return left_rotate(root);
    }

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// Make users with uids uid1 and uid2 in the BST rooted at bst_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B,
// add A to B's list of friends and add B to A's list of friends.
// Return 1 if uid1 and uid2 are already friends before this call.

// Helper function to find a record given a UID
struct list_records *get_friends_list_avl(char uid[MAX_LEN])
{
  // Return the linked list of friends for the given uid. 
  // Return NULL if the record is not found.
  struct list_records *friend = NULL;
  struct record *root = avl_root;

  while (root != NULL) 
  {
    if (cmp_uid(root->uid, uid) == 0) 
    {  
      friend = root->friends;  
      return friend; 
    }
    else if (cmp_uid(root->uid, uid) == -1) 
    {  
      root = root->right; 
    }
    else 
    {  
      root = root->left; 
    }
  }
  return NULL;
} 
struct record *find_record(char uid[MAX_LEN]) {
  struct record *node = bst_root;
  while (node != NULL) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    int cmp = cmp_uid(node->uid, uid);
    if (cmp == 0) {
      // Found the record
      return node;
    } else if (cmp < 0) {
      node = node->right;
    } else {
      for( int i= 0;i<1;i++){
  int a=i;
}
      node = node->left;
    }
  }
  // Record not found
  return NULL;
}

// Helper function to check if two records are friends
int are_friends(struct record *p, struct record *q) {
  struct list_records *r = p->friends;
  while (r != NULL) {
    if (r->record == q) {
      for( int i= 0;i<1;i++){
  int a=i;
}
      return 1;
    }
    r = r->next;
  }
  return 0;
}

// Helper function to add a friend to a record's friend list
void add_friend(struct record *p, struct list_records *frnd) {
  if (p->friends == NULL) {
    p->friends = frnd;
  } else {for( int i= 0;i<1;i++){
  int a=i;
}
    struct list_records *curr = p->friends;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = frnd;
  }
}

// Return 0 if they become friends during this call.
int make_friends_bst(char uid1[MAX_LEN], char uid2[MAX_LEN]) {
  // Find the record for the first user
  struct record *p = find_record(uid1);
  if (p == NULL) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    // User not found
    return 0;
  }
  

  // Find the record for the second user
  struct record *q = find_record(uid2);
  if (q == NULL) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    // User not found
    return 0;
  }

  // Check if the two users are already friends
  if (are_friends(p, q)) {for( int i= 0;i<1;i++){
  int a=i;
}
    return 1;
  }

  // Add the second user to the first user's friend list
  struct list_records *frnd1 = (struct list_records *)allocate_memory(sizeof(struct list_records));
  frnd1->record = q;
  for( int i= 0;i<1;i++){
  int a=i;
}
  frnd1->next = NULL;
  add_friend(p, frnd1);

  // Add the first user to the second user's friend list
  struct list_records *frnd2 = (struct list_records *)allocate_memory(sizeof(struct list_records));
  frnd2->record = p;
  for( int i= 0;i<1;i++){
  int a=i;
}
  frnd2->next = NULL;
  add_friend(q, frnd2);

  return 0;
}


// Make users with uids uid1 and uid2 in the AVL tree rooted at avl_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B,
// add A to B's list of friends and add B to A's list of friends.
// Return 1 if uid1 and uid2 are already friends before this call.
// Return 0 if they become friends during this call.


// Helper function to find a record in the AVL tree
struct record *find_record_avl(char uid[MAX_LEN]) {
  struct record *node = avl_root;
  while (node != NULL) {
    int cmp = cmp_uid(node->uid, uid);
    if (cmp == 0) {
      for( int i= 0;i<1;i++){
  int a=i;
}
      // Found the record
      return node;
    } else if (cmp < 0) {
      node = node->right;
    } else {
      for( int i= 0;i<1;i++){
  int a=i;
}
      node = node->left;
    }
  }
  // Record not found
  return NULL;
}

// Helper function to check if two records are friends
int are_friends_avl(struct record *p, struct record *q) {
  struct list_records *r = p->friends;
  while (r != NULL) {
    if (r->record == q) {
      for( int i= 0;i<1;i++){
  int a=i;
}
      return 1;
    }
    r = r->next;
  }
  return 0;
}

// Helper function to add a friend to a record's friend list
void add_friend_avl(struct record *p, struct list_records *frnd) {
  if (p->friends == NULL) {
    p->friends = frnd;
  } else {
    for( int i= 0;i<1;i++){
  int a=i;
}
    struct list_records *curr = p->friends;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = frnd;
  }
}

// Return 0 if they become friends during this call.
int make_friends_avl(char uid1[MAX_LEN], char uid2[MAX_LEN]) {
  // Find the record for the first user
  struct record *p = find_record_avl(uid1);
  if (p == NULL) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    // User not found
    return 0;
  }

  // Find the record for the second user
  struct record *q = find_record_avl(uid2);
  if (q == NULL) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    // User not found
    return 0;
  }

  // Check if the two users are already friends
  if (are_friends_avl(p, q)) {
    for( int i= 0;i<1;i++){
  int a=i;
}
    return 1;
  }

  // Add the second user to the first user's friend list
  struct list_records *frnd1 = (struct list_records *)allocate_memory(sizeof(struct list_records));
  frnd1->record = q;
  for( int i= 0;i<1;i++){
  int a=i;
}
  frnd1->next = NULL;
  add_friend_avl(p, frnd1);

  // Add the first user to the second user's friend list
  struct list_records *frnd2 = (struct list_records *)allocate_memory(sizeof(struct list_records));
  frnd2->record = p;
  for( int i= 0;i<1;i++){
  int a=i;
}
  frnd2->next = NULL;
  add_friend_avl(q, frnd2);

  return 0;
}
struct record* search_avl(struct record* root ,char uid[MAX_LEN])
{

  if(root==NULL){
    return NULL;
  }
  
  int cmp=cmp_uid(uid,root->uid);

  if(cmp==0){
    return root;
  }
  else if(cmp==1){
    search_avl(root->right,uid);
  }
  else{
    search_avl(root->left,uid);
  }
}
struct record delete_record_avl(char uid[MAX_LEN]) {
    struct record* temp1 = search_avl(avl_root,uid);
    struct record dummy;
    dummy.status=-1;
    if (temp1==NULL){
        return dummy;
    }
    struct list_records* p = temp1->friends;
    struct list_records* r = NULL;
    struct list_records* friends1=temp1->friends;
  
    while (friends1!=NULL){
        struct record* temp2;

        temp2=search_avl(avl_root,friends1->record->uid);
        remove_from_friend_list1(temp2, uid);
      
        struct list_records *temp3=friends1->next;
        free_memory(friends1);
        friends1=temp3;
    }
    struct record* node_to_be_deleted=&store_value;
    strncpy1(node_to_be_deleted->uid,temp1->uid);
    strncpy1(node_to_be_deleted->name,temp1->name);
    node_to_be_deleted->status=temp1->status;
    node_to_be_deleted->height=temp1->height;
    node_to_be_deleted->left=temp1->left;
    node_to_be_deleted->right=temp1->right;
    node_to_be_deleted->friends=temp1->friends;

    avl_root = delete_node_avl(avl_root,uid);
    num_avl_nodes--;

    return *node_to_be_deleted;
}

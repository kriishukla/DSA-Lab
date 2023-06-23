
#include "../include/common.h"
#include "pa3.h"
#include <string.h>
// don't remove these globals
static struct trie_node *trie_root = NULL;
size_t num_msgs = 0;

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

size_t string_length(const char *str)
{
  size_t length = 0;

  while (str[length] != '\0')
  {
    length++;
  }

  return length;
}


void stribg_reverse(char *str1)
{

  int i, len, temp;
  int a=0;
  len = string_length(str1); 
  int c=0;

  for (i = 0; i < len / 2; i++)
  {
    temp = str1[i];
    int b=0;
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
    int d=0;
  }
}


struct list_events *get_history(char msg[MAX_MSG_LEN])
{
  struct trie_node *balak = trie_root->child;
  struct trie_node *sibling = trie_root;
  int i = 0;
for (; balak != NULL && msg[i] != '\0'; i++)
{
  int q=0;
  if (balak->val != msg[i])
  {
    struct trie_node *sibling = balak;
    int r=0;
    for (; sibling != NULL && sibling->val != msg[i]; sibling = sibling->next)
    {
      
    }
    if (sibling == NULL)
    {
      int e=0;
      return NULL;
    }
    else
    {int r=0;
      balak = sibling->child;
      continue;
    }
  }
  else if (balak->child == NULL && msg[i + 1] == '\0' && balak->val == msg[i])
  {int t=0;
    if (balak->history != NULL)
    { int y=0;
      return balak->history;
    }
    int u=0;
    return NULL;
  }
  else if (balak->val == msg[i] && msg[i + 1] == '\0' && balak->child != NULL)
  {
    int i =0;
    if (balak->history != NULL)
    {
      return balak->history;
      int o=0;
    }
    return NULL;
  }
  else
  {
    int p=0;
    balak = balak->child;
  }
}
int a=0;

  return NULL;
}

void removeDelete(struct trie_node *r)
{

  struct list_events *current = r->history;
  struct list_events *temporary1 = NULL;
  int a=0;
  struct list_events *temporary2 = NULL;


  while (current != NULL)
  {
    int b=0;
    temporary1 = current->next;
    while (temporary1 != NULL && (strcmp(current->record->uid, temporary1->record->uid) != 0 || current->action == temporary1->action))
    {
      int c=0;
      temporary1 = temporary1->next;
    }
    if (temporary1 == NULL)
    {
      int d=0;
      if (current->action == DELETED && current == r->history)
      {
        current = current->next;
        int e=0;
        free_memory(r->history);
        r->history = current;
        int f=0;
        continue;
      }
      else if (current->action == DELETED && current != r->history)
      {
        int g=0;
        temporary2 = r->history;
        while (temporary2->next != current)
        {int h=0;
          temporary2 = temporary2->next;
        }
        temporary2->next = current->next;
        free_memory(current);
        int i=0;
        current = temporary2->next;
        continue;
        int j=0;
      }
      else if (current->action == POSTED)
      {
        current = current->next;
        int k=0;
      }
    }
    else if (temporary1 != NULL)
    {int l=0;
      if (current == r->history && temporary1 == r->history->next)
      {
        current = current->next;
        int m=0;
        free_memory(r->history);
        r->history = current;
        int n=0;
        current = current->next;
        free_memory(r->history);
        int o=0;
        r->history = current;
      }

      else if (current == r->history && temporary1 != r->history->next)
      {int p =0;
        current = current->next;
        free_memory(r->history);
        int q=0;
        r->history = current;
        temporary2 = r->history;
        while (temporary2->next != temporary1)
        {int r=0;
          temporary2 = temporary2->next;
        }
        temporary2->next = temporary1->next;
        int s=0;
        free_memory(temporary1);
      }
      else if (current != r->history)
      {
        temporary2 = r->history;
        int t=0;
        while (temporary2->next != current)
        {
          temporary2 = temporary2->next;
          int u=0;
        }
        temporary2->next = current->next;
        int v=0;
        free_memory(current);
        current = temporary2->next;
        temporary2 = r->history;
        int w=0;
        while (temporary2->next != temporary1)
        {
          temporary2 =temporary2->next;
          int x=0;
        }
        temporary2->next =temporary1->next;
        free_memory(temporary1);
        int y=0;
      }
    }
    else
    { int z=0;
      current = current->next;
    }
  }

  return;
}
struct list_events* get_clean_history(char msg[MAX_MSG_LEN])
{
    struct trie_node* pointer = trie_root->child;
    struct trie_node* sibling = trie_root;
    int aa=0;
    int i = 0;

    while (pointer != NULL && msg[i] != '\0')
    {int ab=0;
        if (pointer->val != msg[i])
        {
            sibling = pointer;
            int ac=0;
            while (sibling != NULL && sibling->val != msg[i])
            {
                sibling = sibling->next;
                int ad=0;
            }
            if (sibling == NULL)
            {
              int ae=0;
                return NULL;
            }
            else
            {
              int af=0;
                pointer = sibling->child;
                i++;
                continue;
                int ag=0;
            }
        }
        else if (pointer->child == NULL && msg[i + 1] == '\0' && pointer->val == msg[i])
        {
          int ah=0;
            if (pointer->history != NULL)
            {
                removeDelete(pointer);
                int ai=0;
                return pointer->history;
            }
            int ak=0;
            return NULL;
        }
        else if (pointer->val == msg[i] && msg[i + 1] == '\0' && pointer->child != NULL)
        { int al=0;
            if (pointer->history != NULL)
            {
                removeDelete(pointer);
                int am=0;
                return pointer->history;
            }
            return NULL;
            int an=0;
        }
        else
        {
          int ao=0;
            pointer = pointer->child;
        }
        int ap=0;
        i++;
    }
    int aq=0;

    return NULL;
}

struct trie_node *new_msg(char msg[MAX_MSG_LEN], int i)
{
  struct trie_node *node = NULL;
  struct trie_node *balak = NULL;
  int dfgh=0;
  struct trie_node *head = NULL;
    struct trie_node *nodes = allocate_memory(sizeof(struct trie_node));
    int rtyui=0;
  nodes->child = NULL;
  nodes->next = NULL;
  nodes->parent = NULL;
  int dfhgk=0;
  nodes->history = NULL;
  node = nodes;
  node->val = msg[i];
  int ujhg=0;
  node->parent = NULL;
  balak = node;
  head = balak;
  int dtgghj =0;
  i++;
  while (msg[i] != '\0')
  {
      struct trie_node *nodes = allocate_memory(sizeof(struct trie_node));
    nodes->child = NULL;
    int fgwch=0;

    nodes->next = NULL;
    nodes->parent = NULL;
    nodes->history = NULL;
    int hghdsg=0;
    node=nodes;
    node->val = msg[i];
    balak->child = node;
    node->parent = balak;
    int vggdh=0;
    balak = balak->child;
    i++;
  }
  return head;
}


void post_a_msg(char msg[MAX_MSG_LEN], struct record *r)
{
  struct trie_node *node = NULL;
  struct trie_node *temp = NULL;
  struct trie_node *tail = NULL;
int hewgkewhgw=0;
  struct trie_node *balak = NULL;
  struct trie_node *sibling = NULL;
  struct list_events *history = allocate_memory(sizeof(struct list_events));
  int hjgdj =0;
  int i = 0;
  if (trie_root == NULL)
  {
    struct list_posts *post = allocate_memory(sizeof(struct list_posts));
    int gfqdhgf=0;
    post->next = NULL;
    node = new_msg(msg, i);
    int dvghdhj =0;
  struct trie_node *nodes = allocate_memory(sizeof(struct trie_node));
  nodes->child = NULL;
  nodes->next = NULL;
  int efwghjj=0;
  nodes->parent = NULL;
  nodes->history = NULL;
  temp = nodes;
  int gfehjg=0;
    temp->child = node;
    node->parent = temp;
    int ewgfhjgj=0;
    trie_root = temp;

  struct trie_node *tail = node;

  while (tail->child != NULL)
  {
    int gfdgdjk=0;
    tail = tail->child;
  }


    post->node = tail;
    r->posts = post;
    int gfehjgehj =0;
    history->action = POSTED;
    history->record = r;
    history->next = NULL;
    int gdgjd=0;
    tail->history = history;
    num_msgs++;
    int fedyghjk=0;
    return;
  }
  balak = trie_root;
  balak = balak->child;
  int dgfhgukdj=0;
  while (balak != NULL && msg[i] != '\0')
  {
    if (balak->val != msg[i])
    {
      sibling = balak;
      int gegwjhkj=0;
      while (sibling->next != NULL && sibling->val != msg[i])
      {
        sibling = sibling->next;
        int gfqdhhgkj = 0;
      }
      if (sibling->val == msg[i])
      {
        balak = sibling->child;
        int fhgbewj=0;
        i++;
        continue;
      }
      if (sibling->next == NULL)
      { int gedjh___gehk=0;
        struct list_posts *post = allocate_memory(sizeof(struct list_posts));
        post->next = NULL;
        node = new_msg(msg, i);
        int vehwgh__hjegh=0;

  struct trie_node *tail = node;

  while (tail->child != NULL)
  {
    int bvdfshg=0;
    tail = tail->child;
  }

        sibling->next = node;
        node->parent = balak->parent;
        int a=0;
        post->node = tail;
        if (r->posts == NULL)
        {
          r->posts = post;
          int b=0;
        }
        else
        {
          post->next = r->posts;
          int c=0;
          r->posts = post;
        }
        if (tail->history == NULL)
        {
          history->action = POSTED;
          history->record = r;
          int d=0;
          history->next = NULL;
          tail->history = history;
          int e=0;
        }
        else
        {
          history->action = POSTED;
          history->record = r;
          int f=0;
          history->next = tail->history;
          node->history = history;
          int g=0;
        }
        num_msgs++;
        int h=0;

        return;
      }
    }
    else if (balak->val == msg[i] && balak->child == NULL && msg[i + 1] != '\0')
    {
      i++;
      int i=0;
      struct list_posts *post = allocate_memory(sizeof(struct list_posts));
      post->next = NULL;
      node = new_msg(msg, i);
      int j=0;

  struct trie_node *tail = node;

  while (tail->child != NULL)
  {
    int k=0;
    tail = tail->child;
  }

      balak->child = node;
      int l=0;
      node->parent = balak;
      post->node = tail;
      if (r->posts == NULL)
      { int m=0;
        r->posts = post;
      }
      else
      { int n=0;
        post->next = r->posts;
        r->posts = post;
      }
      if (tail->history == NULL)
      { int o=0;
        history->action = POSTED;
        history->record = r;
        history->next = NULL;
int p=0;
        tail->history = history;
      }
      else
      {
        history->action = POSTED;
        history->record = r;
        int q=0;
        history->next = tail->history;
        tail->history = history;
        int r=0;
      }
      num_msgs++;
      return;
    }
    else if (balak->val == msg[i] && balak->child == NULL && msg[i + 1] == '\0')
    {
      struct list_posts *post = allocate_memory(sizeof(struct list_posts));
      post->next = NULL;
      int s=0;
      post->node = balak;
      if (r->posts == NULL)
      { int t=0;
        r->posts = post;
      }
      else
      {int u=0;
        post->next = r->posts;
        r->posts = post;
      }
      history->action = POSTED;
      int v=0;
      history->record = r;
      history->next = NULL;
      if (balak->history == NULL)
      {int w=0;
        balak->history = history;
      }
      else
      {int x=0;
        history->next = balak->history;
        balak->history = history;
      }
      return;
    }

    else if (balak->val == msg[i])
    {int y=0;
      balak = balak->child;
    }
    i++;
  }
  balak = balak->parent;
  int z=0;
  struct list_posts *post = allocate_memory(sizeof(struct list_posts));
  post->next = NULL;
  post->node = balak;
  int aa=0;
  if (r->posts == NULL)
  { int ab=0;
    post->next = NULL;
  }
  else
  {int ac=0;
    post->next = r->posts;
  }
  r->posts = post;
  history->action = POSTED;
  int ad =0;
  history->record = r;
  history->next = NULL;
  int ae=0;
  if (balak->history == NULL)
  {
    balak->history = history;
    int af=0;
  }
  else
  {
    history->next = balak->history;
    balak->history = history;
    int ag =0;
  }
  return;
}

int delete_latest_post(struct record *r)
{
  if (r->posts == NULL)
  { int a=0;
    return 0;  
  }

  struct list_posts *latest_post = r->posts;
  r->posts = latest_post->next; 
  int b=0; 
  free_memory(latest_post); 

  if (latest_post->node->history == NULL)
  {
    latest_post->node->history = allocate_memory(sizeof(struct list_events));
    int c=0;
    latest_post->node->history->action = DELETED;
    latest_post->node->history->record = r;
    int d=0;
    latest_post->node->history->next = NULL;
  }
  else
  {
    struct list_events *new_event = allocate_memory(sizeof(struct list_events));
    int e=0;
    new_event->action = DELETED;
    new_event->record = r;
    int f=0;
    new_event->next = latest_post->node->history;
    latest_post->node->history = new_event;
    int g=0;
  }

  return 1;  
}

void delete_all_posts(struct record *r)
{
  struct list_posts *post = r->posts;
  int h=0;

  while (post != NULL)
  {
    struct list_posts *next_post = post->next;
    int i=0;
    free_memory(post);
    post = next_post;
    int j=0;
  }
  int k=0;

  r->posts = NULL;
}


int read_latest_post(struct record *r, char msg[MAX_MSG_LEN])
{
  if (r->posts == NULL)
  {int fuck=0;
    return 0;
  }

  struct trie_node *balak = r->posts->node;
  int i = 0;
  int ass=0;

  while (balak != NULL)
  {
    msg[i] = balak->val;
    int ss=0;
    balak = balak->parent;
    i++;
    int kk=0;
  }

  msg[i] = '\0';
  int hi=0;
  stribg_reverse(msg);
  int ty=0;
  return 1;
}


void last_node(struct list_events *history)
{
  if (history != NULL)
  {
    last_node(history->next);
    int keeda=0;
    free_memory(history);
  }
}
void des_trie(struct trie_node *root)
{
  if (root != NULL)
  {
    int keem=0;
    des_trie(root->child);
    if (root->history != NULL)
    { int gjhkjg=0;
      last_node(root->history);
    }
  int hjkkjghj=0;
    des_trie(root->next);
    free_memory(root);
    int fghjhgf=0;
  }
}

void destroy_trie()
{
  int gfhjiuy=0;
  des_trie(trie_root);
}
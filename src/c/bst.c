#include<stdlib.h>
#include<stdio.h>

typedef struct {
  int value;
  struct btnode* left;
  struct btnode* right;
} btnode;

typedef struct btnode* ptr_btnode;

/** Non-recursive insertion of node in binary search tree */
int insert_bst_node(btnode* root,int  value) {
  btnode* cur_node = NULL;
  btnode* new_node = NULL;

  if (NULL == root) {
    root = (btnode*) malloc(sizeof(btnode));
    if (NULL == root) {
      printf("Out of memory. Unable to allocate new node\n");
      return 0;
    }
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return 1;
  } else {
    cur_node = root;
    while (1) {
      // Less Than
      if (value < cur_node->value) {
	if (NULL != cur_node->left) {
	  cur_node = (btnode*) cur_node->left;
	} else {
	  // Found empty leaf node
	  new_node = (btnode*) malloc(sizeof(btnode));
	  if (NULL == new_node) {
	    printf("Out of memory. Unable to allocate new node\n");
	    return 0;
	  }
	  new_node->value = value;
	  new_node->left = NULL;
	  new_node->right = NULL;
	  cur_node->left = (struct btbnode*) new_node;
	  return 1;
	}
	// Greater than or equal
      } else {
	if (NULL != cur_node->right) {
	  cur_node = (btnode*) cur_node->right;
	} else {
	  // Found empty leaf node
	  new_node = (btnode*) malloc(sizeof(btnode));
	  if (NULL == new_node) {
	    printf("Out of memory. Unable to allocate new node\n");
	    return 0;
	  }
	  new_node->value = value;
	  new_node->left = NULL;
	  new_node->right = NULL;
	  cur_node->right = (struct btnode*) new_node;
	  return 1;
	}
      }
    }        
  }
}

/** Finds and returns the btnode with the given value or NULL if no such node exists */
btnode* find_bst_node(btnode* root, int value) {
  btnode* cur_node = root;
  if (NULL == root) return NULL;
  while (NULL != cur_node) {
    if (cur_node->value == value) return cur_node;
    else if (value < cur_node->value) cur_node = (btnode*) cur_node->left;
    else cur_node = (btnode*) cur_node->right;
  }
  return NULL;
}

/** Finds and returns the bnode with the integer value that is the closest to the given value */
btnode* find_closest_bst_node(btnode* root, int value) {
  btnode* cur_node = root;
  btnode* next_node = root;
  if (NULL == root) return NULL;

  while (NULL != cur_node) {
    if (cur_node->value == value) {
      return cur_node;
    }

    if (value < cur_node->value) {
      next_node = (btnode*) cur_node->left;
    }
    else {
      next_node = (btnode*) cur_node->right;
    }
    if (NULL == next_node) {
      return cur_node;
    }

    cur_node = next_node;
  }
  return NULL;
}

/** Checks a binary tree to see if it's a proper binary search tree (recursive) */
int is_bst(btnode* node, int max_value, int min_value) {
  if (node == NULL) return 1;
  if (node->value >= max_value || node->value <= min_value) return 0;
  return is_bst(node->left, node->value, min_value) && is_bst(node->right, max_value, node->value);
}

int main(void) {
  btnode* root = NULL;
  int ret;
  ret = insert_bst_node(root, 10);
  printf("Ret: %d\n", ret);

  return 0;
}

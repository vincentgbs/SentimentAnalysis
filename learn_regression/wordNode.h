/* node for a linked list of words*/
#ifndef WORDNODE_H
#define WORDNODE_H

#define WORDLEN 50

struct wordNode *HEAD = NULL;

struct wordNode {
  char id[WORDLEN];
  float point;
  int frequency;
  struct wordNode *previous;
  struct wordNode *next;
};

struct wordNode createNode (char *id, int point) {
  struct wordNode n;
  strcpy(n.id, id);
  n.point = point;
  n.frequency = 1;
  n.previous = NULL;
  n.next = NULL;
  return n;
}

void addNode (struct wordNode *n) {
  if (HEAD == NULL) {
    HEAD = n;
  }
  else if (strcmp(n->id,HEAD->id) < 0) {
    n->next = HEAD;
    HEAD = n;
  }
  else {
    struct wordNode *current = NULL;
    struct wordNode *trail = NULL;
    current = HEAD;
    while((current != NULL) && strcmp((n->id), current->id) > 0 ) {
      trail = current;
      current = current->next;
    }

    if ((current != NULL) && (strcmp((*n).id,(*current).id) == 0)) {
      (*current).point = ((*current).point * (*current).frequency + (*n).point) / ++(*current).frequency;
    }
    else {
      trail->next = n;
      n->next = current;      
    }
  }
}


void printNode(struct wordNode *n) {
  if (n == NULL) {
    printf("(NULL)");
  }
  else{
    printf("id: %s, point: %.2f, f: %d\n", n->id, n->point, n->frequency);
  }
}

void printList(struct wordNode *n) {
  struct wordNode *current = n;
  while (current != NULL) {
    printNode(current);
    current = current->next;
  }
}

/* find a node base on its id
  input is char* and return node address */
struct wordNode* findNode (struct wordNode *startNode, char *word) {
  struct wordNode *current = startNode;
  if (current == NULL) return NULL;
  /*move current to next until current <= word*/
  while (strcmp(word,current->id) > 0) {
    current = current->next;
  }

  /*when word == current*/
  if (strcmp(word,current->id) == 0) {
    return current;
  }
  /*when word is not in the list*/
  else {
    return NULL;
  }
}
#endif // WORDNODE_H

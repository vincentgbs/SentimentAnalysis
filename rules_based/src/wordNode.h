/* node for a linked list of words*/
#ifndef WORDNODE_H
#define WORDNODE_H

#define WORDLEN 50

struct wordNode *HEAD = NULL;

struct wordNode {
  char id[WORDLEN];
  double point;
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
  printf("id: %s, point: %.2f, f: %d\n", n->id, n->point, n->frequency);
}

void printList(struct wordNode *n) {
  struct wordNode *current = n;
  while (current != NULL) {
    printNode(current);
    current = current->next;
  }
}

#endif // WORDNODE_H

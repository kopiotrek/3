#pragma ONCE

class Node
{
    char symbol;
    int *head;
    Node *children = new Node[2]();

public:
    Node();
};

class Tree
{
    int position;
    Node *nodes;

public:
    Tree();
    Tree(char *symbols[]);
};
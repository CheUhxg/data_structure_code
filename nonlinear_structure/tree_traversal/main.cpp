#include<bits/stdc++.h>
#define N 30
#define Stack_Size 50
typedef struct Node
{
	char v;
	struct Node* lchild, * rchild;
}Tree, * TreePointer;
typedef struct {
	TreePointer elem[Stack_Size];
	int top;
}Stack;
typedef struct
{
	TreePointer elem[Stack_Size];
	int top, tail;
}Queue;
TreePointer tree, ft;
int n, i;
const char Tree_s[N] = { 'A','B','D','G','#','#','#','E','#','H','I','#','#','#','C','#','F','#','#' };
int build_tree(TreePointer x) {
	TreePointer p = x;
	char t;
	n++;
	t = Tree_s[i++];
	if (t == '#') {
		p->v = '#';
		p = NULL;
	}
	else {
		p->v = t;
		p->lchild = (TreePointer)malloc(sizeof(Tree));
		p->rchild = (TreePointer)malloc(sizeof(Tree));
		build_tree(p->lchild);
		build_tree(p->rchild);
	}
	return 0;
}
void proorder_traversal(TreePointer x) {
	if (x->v != '#') {
		printf("%c", x->v);
		proorder_traversal(x->lchild);
		proorder_traversal(x->rchild);
	}
	return;
}
void inorder_traversal(TreePointer x) {
	if (x->v != '#') {
		inorder_traversal(x->lchild);
		printf("%c", x->v);
		inorder_traversal(x->rchild);
	}
	return;
}
void posorder_traversal(TreePointer x) {
	if (x->v != '#') {
		posorder_traversal(x->lchild);
		posorder_traversal(x->rchild);
		printf("%c", x->v);
	}
	return;
}
void rninorder_traversal(TreePointer x) {
	TreePointer p = x;
	Stack tp;
	tp.top = -1;
	while (p->v != '#' || tp.top != -1) {
		while (p->v != '#') {
			tp.elem[++tp.top] = p;
			p = p->lchild;
		}
		if (tp.top != -1) {
			p = tp.elem[tp.top--];
			printf("%c", p->v);
			p = p->rchild;
		}
	}
	return;
}
void rnposorder_traversal(Tree x) {
	TreePointer p = &x, q = NULL;
	Stack tp;
	tp.top = -1;
	while (p->v != '#' || tp.top != -1) {
		while (p->v != '#') {
			tp.elem[++tp.top] = p;
			p = p->lchild;
		}
		if (tp.top != -1) {
			p = tp.elem[tp.top];
			if (p->rchild->v == '#' || p->rchild == q) {
				printf("%c", p->v);
				q = p;
				tp.top--;
				p->v = '#';
			}
			else p = p->rchild;
		}
	}
	return;
}
void level_traversal(TreePointer x) {
	TreePointer p = x;
	Queue tq;
	tq.top = -1;
	tq.tail = 0;
	tq.elem[tq.tail] = p;
	while (tq.tail != tq.top) {
		p = tq.elem[++tq.top];
		printf("%c", p->v);
		if (p->lchild->v != '#')tq.elem[++tq.tail] = p->lchild;
		if (p->rchild->v != '#')tq.elem[++tq.tail] = p->rchild;
	}
}
int path(TreePointer root, TreePointer node, Stack* s)
{
	TreePointer p = root, q = NULL;
	Stack* t = (Stack*)malloc(sizeof(Stack));
	t->top = -1;
	while (p->v != '#' || t->top != -1) {
		while (p->v != '#' && p != node) {
			t->elem[++t->top] = p;
			s->elem[++s->top] = p;
			p = p->lchild;
		}
		if (p == node) {
			s->elem[++s->top] = p;
			return 1;
		}
		if (t->top != -1) {
			p = t->elem[t->top];
			if (p->rchild->v == '#' || p->rchild == q) {
				q = p;
				t->top--;
				s->top--;
				p->v = '#';
			}
			else p = p->rchild;
		}
	}
	return 0;
}
int main() {
	tree = (TreePointer)malloc(sizeof(Tree));
	build_tree(tree);
	rninorder_traversal(tree);
	printf("\n");
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
	TreePointer node = tree->lchild->rchild->rchild->lchild;
	path(tree, node, s);
	while (s->top != -1) {
		printf("%c", s->elem[s->top--]->v);
	}
	return 0;
}

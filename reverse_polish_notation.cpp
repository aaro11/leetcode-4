#include <stdio.h>
#include <stdlib.h>

//用栈

typedef struct stack{
	char c[100];
	int top;
	int size;
}stack;
typedef  struct level{
	char ch;
	int l;
}level;
void initStack(stack *s)
{
	s->top = -1;
	s->size = 100;

}
void pushStack(stack *s, char ch)
{
	s->top++;
	if (s->top >= s->size)
		printf("已满");
	else
		s->c[s->top] = ch;
}
char popStack(stack *s)
{
	char ch;
	if (s->top == -1)
		printf("已空");
	else
		ch = s->c[s->top--];
	return ch;

}
int main(int argc, char *argv[])
{
	struct level lev[4];
	struct stack s;
	lev[0].ch = '+';
	lev[0].l = 1;
	lev[1].ch = '-';
	lev[1].l = 1;
	lev[2].ch = '*';
	lev[2].l = 2;
	lev[3].ch = '/';
	lev[3].l = 2;
	initStack(&s);
	int i = 0, j = 0;
	char a[100], newa[100];
	scanf("%s", a);
	while (a[i] != '#')
	{
		if (a[i] >= '0'&&a[i] <= '9')
		{
			newa[j] = a[i];
			j++;
		}
		else if (a[i] == '(')
			pushStack(&s, a[i]);
		else if (a[i] == ')')
		{
			char ch = popStack(&s);
			while (ch != '(')
			{
				newa[j] = ch;
				j++;
				ch = popStack(&s);
			}

		}
		else
		{
			int x;
			int stackVar, arrayVar;
			do{
				stackVar = 0;
				arrayVar = 0;
				for (x = 0; x<4; x++)
				{
					if (lev[x].ch == a[i])
						arrayVar = lev[x].l;
					if (lev[x].ch == s.c[s.top])
						stackVar = lev[x].l;
				}
				if (arrayVar <= stackVar)
				{
					newa[j] = popStack(&s); j++;
				}
				else
					pushStack(&s, a[i]);
			} while (arrayVar <= stackVar);
		}
		i++;
	}
	while (s.top != -1)
	{
		newa[j] = popStack(&s); j++;
	}
	int y;
	for (y = 0; y<j; y++)
		printf("%c", newa[y]);
	system("PAUSE");
	return 0;
}
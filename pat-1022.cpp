#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

#define N 10000

typedef struct
{
	int id;
	int year;
	char title[82];
	char author[82];
	char publisher[82];
	char* keywords[5];
	char keys[60];
}book;

book books[N];
vector<book *>bs;

void inline printid(int id)
{
	                       if (id<10) printf("000000%d\n",id);else
                       if (id<100) printf("00000%d\n",id);else
                       if (id<1000) printf("0000%d\n",id);else
                       if (id<10000) printf("000%d\n",id);else
                       if (id<100000) printf("00%d\n",id);else
                       if (id<1000000) printf("0%d\n",id);else
                       printf("%d\n",id);
}
bool s(book *b1, book* b2)
{
	if (b1->id >= b2->id)
		return false;
	return true;
}

void inline nn(char *s)
{
	int aa = strlen(s); 
	while (s[aa] == '\n' || s[aa] == ' ' || s[aa] == '\0')
		s[aa--] = '\0';
}

int main()
{
	int n; cin >> n;
	char keys[200], *tok;

	for (int i = 0; i < n; i++)
	{
		scanf("%d\n", &books[i].id);
		fgets(books[i].title, 82, stdin);
		nn(books[i].title);
		fgets(books[i].author, 82, stdin);
		nn(books[i].author);
		fgets(books[i].keys, 60, stdin);
		nn(books[i].keys);

		tok = strtok(books[i].keys, " ");
		int j = 0;
		while (tok != NULL && j < 5)
		{
			books[i].keywords[j++] = tok;
			tok = strtok(NULL, " ");
		}
		fgets(books[i].publisher, 82, stdin);
		nn(books[i].publisher);
		scanf("%d\n", &books[i].year);
		bs.push_back(&books[i]);
	}

	sort(bs.begin(), bs.end(), s);

	int m; scanf("%d\n", &m);

	for (int i = 0; i < m; i++)
	{
		 bool f = false;
		fgets(keys, 90, stdin);
		nn(keys);
		puts(keys);
		switch(keys[0])
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				if (strcmp(keys + 3, bs[i]->title) == 0)
				{
					printid(bs[i]->id);
					f = true;
				}
			}
			if ( f == false) puts("Not Found");
			break;
		case '2':
			for (int i = 0; i < n; i++)
			{
				if (strcmp(keys + 3, bs[i]->author) == 0)
				{
					printid(bs[i]->id);
					f = true;
				}
			}
			if ( f == false) puts("Not Found");
			break;
		case '3':
			for (int i = 0; i < n; i++)
			{
				int j = 0;
				while (bs[i]->keywords[j] != NULL && j < 5)
					if (strcmp(keys + 3, bs[i]->keywords[j]) == 0)
					{
						printid(bs[i]->id);
						f = true;
						break;
					}
					else
						j++;
			}
			if ( f == false) puts("Not Found");
			break;
		case '4':
			for (int i = 0; i < n; i++)
			{
				if (strcmp(keys + 3, bs[i]->publisher) == 0)
				{
					printid(bs[i]->id);
					f = true;
				}
			}
			if ( f == false) puts("Not Found");
			break;
		case '5':
			int y;
			sscanf(keys + 3, "%d", &y);
			for (int i = 0; i < n; i++)
			{
				if (y == bs[i]->year)
				{
					printid(bs[i]->id);
					f = true;
				}
			}
			if ( f == false) puts("Not Found");
			break;
		}
	}
	return 0;
}


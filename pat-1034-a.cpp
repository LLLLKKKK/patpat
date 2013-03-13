
#define N 2000
int w[N] = {0};
int wm[N] = {0};
int sumw[N] = {0};
int sumn[N];

int p[N] = {0};
int rrank[N] = {0};
int gang[N] = {0};

int ctop[N] = {0};
int nn[N];

int findset(int x)
{
	if (p[x] != x)
		p[x] = findset(p[x]);
	return p[x];
}
void link(int x, int y, int c)
{
	if (x != y)
	{
		int sw = sumw[x] + sumw[y] + c;
		if (rrank[x] > rrank[y])
		{	p[y] = x; sumn[x] += sumn[y]; sumw[x] = sw;}
		else
		{
			p[x] = y; sumn[y] += sumn[x]; sumw[y] = sw;
			if (rrank[x] == rrank[y])
				rrank[y]++;
		}
	}
	else
	{
		sumw[x] += c;
	}
}
#define oo(a) (a[0] - 'A') * 26 * 26 + (a[1] - 'A') * 26 + a[2] - 'A';

bool ss(int a, int b)
{
	if (ctop[a] < ctop[b])
		return true;
	return false;
}
int main()
{
	int ptoc[26 * 26 * 26] = {0};
	int n, k; scanf("%d%d", &n, &k);
	int num = 1;
	for (int i = 0; i < N; i++)
	{	p[i] = i; gang[i] = i; nn[i] = i; sumn[i] = 1;}
	char a[4], b[4]; int c;
	for (int i = 0; i < n; i++)
	{
		
		scanf("%s %s %d", a, b, &c);
		int ac = oo(a); int ap, bp;
		int bc = oo(b);
		if (ptoc[ac] == 0)
		{
			ap = num - 1;
			ptoc[ac] = num; 
			ctop[ap] = ac;
			num++;
		}else ap = ptoc[ac] - 1;
		if (ptoc[bc] == 0)
		{
			bp = num - 1;
			ptoc[bc] = num;
			ctop[bp] = bc;
			num++;
		}else bp = ptoc[bc] - 1;
		w[ap] += c; w[bp] += c;
		if (wm[ap] == 0) wm[ap] = w[ap];
		if (wm[bp] == 0) wm[bp] = w[bp];
		link(findset(bp), findset(ap), c);

		int r = findset(bp);
		if (w[ap] > wm[r]) { wm[r] = w[ap]; gang[r] = ap; }
		if (w[bp] > wm[r]) { wm[r] = w[bp]; gang[r] = bp; }
	}

	int count = 0;
	num--;
	for (int i = 0; i < num; i++)
		if (p[i] == i && sumw[i] > k && sumn[i] > 2)
				count++;
	sort(nn, nn + num - 1, ss);
	if (count != 0)
	{
		printf("%d\n", count);
		for (int i = 0; i < num; i++)
		{
			int j = nn[i];
			if (p[j] == j && sumw[j] > k && sumn[j] > 2)
				{
					int c = ctop[gang[j]];
					printf("%c%c%c %d\n", c / 26 / 26 + 'A', c / 26 % 26 + 'A', c % 26 + 'A', sumn[j]);
				}
		}
	}
	else 
		puts("0\n");
	return 0;
}

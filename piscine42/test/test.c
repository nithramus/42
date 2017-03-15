#include <string.h>
#include <stdio.h>

int main()
{
	char a[] = "testdu\0 prog";
	char *b = strdup(a);
	printf("%s", b);
}

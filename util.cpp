#include "util.h"

	int util::strlen(char *str)
	{
		int len = 0;
		while (str[len])
			len++;
		return len;
	}

	void util::strcpy(char *destination, char *source)
	{
		int len = strlen(source);
		for (int i = 0; i <= len; i++)
			destination[i] = source[i];
	}

	char * util::strcom(char * a, char * b)
	{
		char *com = new char(util::strlen(a) + util::strlen(b) + 1);
		util::strcpy(com, a);
		util::strcpy(com+strlen(a), b);
		return com;
	}

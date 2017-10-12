
size_t strcspn( const char * string, const char * chars )
{
	char	c;
	const char*	p;
	const char* s;

	for (s = string, c = *s; c != 0; s++, c = *s) {
		for (p = chars; *p != 0; p++) {
			if (c == *p) {
				return s - string;
			}
		}
	}
	return s - string;
}

char * strpbrk( const char* s1, const char* s2 )
{
	const char *scanp;
	int c, sc;

	while ((c = *s1++) != 0) {
		for (scanp = s2; (sc = *scanp++) != 0;)
			if (sc == c)
				return ((char *)(s1 - 1));
	}

	return NULL;
}

void exit(int status)
{
  // Dummy function.
}


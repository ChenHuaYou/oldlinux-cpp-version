#include "kernel.h"

void * String::memcpy(char *dst, char *src, int n)
{
    char *p = dst;
    while (n--)
        *dst++ = *src++;
    return p;
}

/*
 * Met un ensemble memoire (dst>>n) à la valeur src
 */
void * String::memset(char *dst,char src, int n)
{
    char *p = dst;
    while (n--)
        *dst++ = src;
    return p;
}

int String::strlen(char *s)
{
    int i = 0;
    while (*s++)
        i++;
    return i;
}

char * String::strncpy(char *destString, const char *sourceString,int maxLength)
{
    unsigned count;

    if ((destString == (char *) NULL) || (sourceString == (char *) NULL))
    {
        return (destString = NULL);
    }

    if (maxLength > 255)
        maxLength = 255;

    for (count = 0; (int)count < (int)maxLength; count ++)
    {
        destString[count] = sourceString[count];

        if (sourceString[count] == '\0')
            break;
    }

    if (count >= 255)
    {
        return (destString = NULL);
    }

    return (destString);
}

int String::strcmp(const char *dst, char *src)
{
    int i = 0;

    while ((dst[i] == src[i])) {
        if (src[i++] == 0)
            return 0;
    }

    return 1;
}


int String::strcpy(char *dst,const char *src)
{
    int i = 0;
    while ((dst[i] = src[i++]));

    return i;
}


void String::strcat(void *dest,const void *src)
{
    memcpy((char*)((long)dest+(int)strlen((char*)dest)),(char*)src,strlen((char*)src));
}


int String::strncmp( const char* s1, const char* s2, int c ) {
    int result = 0;

    while ( c ) {
        result = *s1 - *s2++;

        if ( ( result != 0 ) || ( *s1++ == 0 ) ) {
            break;
        }

        c--;
    }

    return result;
}

	void String::itoa(char *buf, unsigned long int n, int base)
	{
		unsigned long int tmp;
		int i, j;

		tmp = n;
		i = 0;

		do {
			tmp = n % base;
			buf[i++] = (tmp < 10) ? (tmp + '0') : (tmp + 'a' - 10);
		} while (n /= base);
		buf[i--] = 0;

		for (j = 0; j < i; j++, i--) {
			tmp = buf[j];
			buf[j] = buf[i];
			buf[i] = tmp;
		}
	}


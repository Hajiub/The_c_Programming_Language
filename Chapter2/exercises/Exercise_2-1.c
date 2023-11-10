/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
              variables, both signed and unsigned, by printing appropriate values from standard headers
              and by direct computation. Harder if you compute them: determine the ranges of the various
              floating-point types.
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_range(const char* type, const char* signed_str, const char* unsigned_str, long long min, unsigned long long max) {
    printf("Range of %s:\n", type);
    printf("  Signed %s: %lld to %lld\n", signed_str, min, max);
    printf("  Unsigned %s: 0 to %llu\n", unsigned_str, max * 2ULL + 1);
    printf("\n");
}

int main() {
    print_range("Char", "char", "char", CHAR_MIN, UCHAR_MAX);

    print_range("Short", "short", "short", SHRT_MIN, USHRT_MAX);

    print_range("Int", "int", "unsigned int", INT_MIN, UINT_MAX);

    print_range("Long", "long", "unsigned long", LONG_MIN, ULONG_MAX);

    printf("Range of Float:\n");
    printf("  from %E to %E\n", FLT_MIN, FLT_MAX);
    printf("\n");

    printf("Range of Double:\n");
    printf("  from %E to %E\n", DBL_MIN, DBL_MAX);

    return 0;
}


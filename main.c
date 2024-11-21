#include "ft_printf.h"

int main(void)
{
//     int ret_ft;
//     int ret_original;

//     printf("\n--- Testing ft_printf ---\n");

//     // Test 1: Simple string
//     ret_ft = ft_printf("Hello, World!\n");
//     ret_original = printf("Hello, World!\n");
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 2: Integer
//     ret_ft = ft_printf("Integer: %d\n", 42);
//     ret_original = printf("Integer: %d\n", 42);
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 3: String
//     ret_ft = ft_printf("String: %s\n", "Test");
//     ret_original = printf("String: %s\n", "Test");
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 4: Pointer
//     int x = 42;
//     ret_ft = ft_printf("Pointer: %p\n", &x);
//     ret_original = printf("Pointer: %p\n", &x);
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 5: Hexadecimal (lowercase and uppercase)
//     ret_ft = ft_printf("Hex: %x, %X\n", 255, 255);
//     ret_original = printf("Hex: %x, %X\n", 255, 255);
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 6: Unsigned integer
//     ret_ft = ft_printf("Unsigned: %u\n", 4294967295U);
//     ret_original = printf("Unsigned: %u\n", 4294967295U);
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     // Test 7: Percent sign
//     ret_ft = ft_printf("Percent: %%\n");
//     ret_original = printf("Percent: %%\n");
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     char *s = NULL;
//     // Test 8: Edge case with NULL string
//     ret_ft = ft_printf("NULL string: %s\n", s);
//     ret_original = printf("NULL string: %s\n", s);
//     printf("Return values: ft_printf = %d, printf = %d\n", ret_ft, ret_original);

//     //Test 9: test passing null to each function 
//    ret_ft = ft_printf(NULL);
//    ret_original = printf(NULL);
//    printf("Return values: ft_printf = %s, printf = %s\n", ret_ft, ret_original);

// 	int a;
// 	char c;
// 	char *ss;
// 	unsigned int u;

// 	u = -5500;
// 	ss = "NAME !";
// 	c = 'z';
// 	a = 13516;
// 	int hexa = 270;
// 	char *s ;
// 	s = NULL;
// 	int counter = ft_printf("hello test %i %c %s %%%% %u %x %X %p\n", a, c, ss, u, hexa, hexa, &a);
// 	ft_printf("%p", s);
// 	ft_printf("Caractères imprimés : %d\n", counter);
// 	ft_printf("%s\n", s);
// 	printf("--------------------------------------------\n");
// 	int count = printf("hello test %i %c %s %%%% %u %x %X %p\n", a, c, ss, u, hexa, hexa, &a);
// 	printf("Caractères imprimés : %d\n", count);
// 	printf("%s, %p\n", s, s);
//     printf("[%d]\n", ft_printf("%revv"));
// 	printf("[%d]\n", printf("%revv"));

    printf("-----------------------------------------------\n");
    // ft_printf("IMax %x IMin %x LMax %x Lmin %x ULmax%x 0 %x  -42 %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    // ft_printf("number : %x \n", 9223372036854775807LL);
    // ft_printf("unsigned long : %x \n", ULONG_MAX);
    // ft_printf("long max : %x \n", LONG_MAX);
    // ft_printf("long min : %x \n", LONG_MIN);
    // ft_printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    // printf("%d", ft_printf("%"));
    printf("%d",ft_printf("%wwww"));
}
#include <stdio.h>
int main() 
{ 
    char *str = "#include <stdio.h>%cint main() %c{ %c    char *str = %s; %c    printf( str, 10, 10, 10, str, 10, 10, 10 ); %c    return 0; %c}"; 
    printf( str, 10, 10, 10, str, 10, 10, 10 ); // ASCII中，10为换行键，34为引号
    return 0; 
}
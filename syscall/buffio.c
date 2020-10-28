#include<stdio.h>
#include <sys/types.h>
 #include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main( int argc, char const *argv[])
{
    printf("Hello %d\n",3); //buffer
    printf("world\n");
    return 0;
}
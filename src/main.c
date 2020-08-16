
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("testing...\n");

    #if HAVE_PTHREAD_H
    printf("pthread library enabled\n");
    #endif

    return EXIT_SUCCESS;
}

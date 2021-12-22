#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "DevicesHash.h"



uint8_t buff[] = "Hello honrun.";


int main(void)
{
    printf("Hash test.\r\n\n");

    printf("HASH_SDBM:\t%d\r\n", uiHashGet(buff, strlen((char *)buff), HASH_SDBM));
    printf("HASH_RS:\t%d\r\n",   uiHashGet(buff, strlen((char *)buff), HASH_RS));
    printf("HASH_JS:\t%d\r\n",   uiHashGet(buff, strlen((char *)buff), HASH_JS));
    printf("HASH_PJW:\t%d\r\n",  uiHashGet(buff, strlen((char *)buff), HASH_PJW));
    printf("HASH_ELF:\t%d\r\n",  uiHashGet(buff, strlen((char *)buff), HASH_ELF));
    printf("HASH_BKDR:\t%d\r\n", uiHashGet(buff, strlen((char *)buff), HASH_BKDR));
    printf("HASH_DJB:\t%d\r\n",  uiHashGet(buff, strlen((char *)buff), HASH_DJB));
    printf("HASH_AP:\t%d\r\n",   uiHashGet(buff, strlen((char *)buff), HASH_AP));

    return 0;
}

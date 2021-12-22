#include "stdint.h"
#include "DevicesHash.h"



uint32_t uiSDBMHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 0;

    while((iLength--) > 0)
    {
        uiHashValue = (*pucBuff++) + (uiHashValue << 6) + (uiHashValue << 16) - uiHashValue;
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiRSHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t a = 63689, b = 378551, uiHashValue = 0;

    while((iLength--) > 0)
    {
        uiHashValue = uiHashValue * a + (*pucBuff++);
        a *= b;
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiJSHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 1315423911;

    while((iLength--) > 0)
    {
        uiHashValue ^= ((uiHashValue << 5) + (*pucBuff++) + (uiHashValue >> 2));
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiPJWHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t BitsInUnignedInt = (uint32_t)(sizeof(uint32_t) * 8);
    uint32_t ThreeQuarters = (uint32_t)((BitsInUnignedInt * 3) / 4);
    uint32_t OneEighth = (uint32_t)(BitsInUnignedInt / 8);
    uint32_t HighBits = (uint32_t)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
    uint32_t uiHashValue = 0;
    uint32_t test = 0;

    while((iLength--) > 0)
    {
        uiHashValue = (uiHashValue << OneEighth) + (*pucBuff++);
        if ((test = uiHashValue & HighBits) != 0)
        {
            uiHashValue = ((uiHashValue ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiELFHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 0, x = 0;

    while((iLength--) > 0)
    {
        uiHashValue = (uiHashValue << 4) + (*pucBuff++);
        if ((x = uiHashValue & 0xF0000000L) != 0)
        {
            uiHashValue ^= (x >> 24);
            uiHashValue &= ~x;
        }
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiBKDRHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 0, seed = 131; // 31 131 1313 13131 131313 etc..

    while((iLength--) > 0)
    {
        uiHashValue = uiHashValue * seed + (*pucBuff++);
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiDJBHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 5381;

    while((iLength--) > 0)
    {
        uiHashValue += (uiHashValue << 5) + (*pucBuff++);
    }

    return (uiHashValue & 0x7FFFFFFF);
}

uint32_t uiAPHash(uint8_t *pucBuff, int32_t iLength)
{
    uint32_t uiHashValue = 0, i = 0;

    for (i = 0; i < iLength; ++i)
    {
        if ((i & 1) == 0)
        {
            uiHashValue ^= ((uiHashValue << 7) ^ (*pucBuff++) ^ (uiHashValue >> 3));
        }
        else
        {
            uiHashValue ^= (~((uiHashValue << 11) ^ (*pucBuff++) ^ (uiHashValue >> 5)));
        }
    }

    return (uiHashValue & 0x7FFFFFFF);
}

/*
* return void;
* input:
* function: ¹þÏ£Öµ»ñÈ¡
*/
uint32_t uiHashGet(uint8_t * pucBuff, int32_t iLength, HashPolynomialEnum enumHashCategory)
{
    uint32_t uiHashValue = 0;

    switch (enumHashCategory)
    {
        case HASH_SDBM: uiHashValue = uiSDBMHash(pucBuff, iLength); break;
        case HASH_RS:   uiHashValue = uiRSHash(pucBuff, iLength);   break;
        case HASH_JS:   uiHashValue = uiJSHash(pucBuff, iLength);   break;
        case HASH_PJW:  uiHashValue = uiPJWHash(pucBuff, iLength);  break;
        case HASH_ELF:  uiHashValue = uiELFHash(pucBuff, iLength);  break;
        case HASH_BKDR: uiHashValue = uiBKDRHash(pucBuff, iLength); break;
        case HASH_DJB:  uiHashValue = uiDJBHash(pucBuff, iLength);  break;
        case HASH_AP:   uiHashValue = uiAPHash(pucBuff, iLength);   break;

        default: return 0;
    }

    return (uiHashValue & 0x7FFFFFFF);
}

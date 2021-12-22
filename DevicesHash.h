#ifndef _DevicesHash_H_
#define _DevicesHash_H_

typedef enum {
	HASH_SDBM = 0,
	HASH_RS,
	HASH_JS,
	HASH_PJW,
	HASH_ELF,
	HASH_BKDR,
	HASH_DJB,
	HASH_AP,
}HashPolynomialEnum;



uint32_t uiSDBMHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiRSHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiJSHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiPJWHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiELFHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiBKDRHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiDJBHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiAPHash(uint8_t *pucBuff, int32_t iLength);
uint32_t uiHashGet(uint8_t * pucBuff, int32_t iLength, HashPolynomialEnum enumHashCategory);

#endif

/* Functions used to encrypt passwords */

#include <stdint.h>
#include <stdio.h>

#define SIZE_SHA256 65 /* 64 + 1 (\0) */

// 3.2
uint32_t rotr(uint32_t x, size_t n);

uint32_t shr(uint32_t x, size_t n);

// 4.1.2
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);

uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);

uint32_t ep0(uint32_t x);

uint32_t ep1(uint32_t x);

uint32_t sig0(uint32_t x);

uint32_t sig1(uint32_t x);

/* Swap byte endian */
uint32_t swapE32(uint32_t val);

uint64_t swapE64(uint64_t val);

/* Store hex numbers to make the final hash */
void hex(void *buffer, size_t len, char **finalHash);

/* Main function charged to coordinate the encryption */
char *mainEncrypt(char *plainText);
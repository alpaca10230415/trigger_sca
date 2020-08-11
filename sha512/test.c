#include <stdio.h>
#include "sha512.h"
#include "hal.h"

#define INLEN 112

const unsigned char msg[INLEN] = {
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x62, 0x63, 0x64, 0x65,
    0x66, 0x67, 0x68, 0x69, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
    0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x65, 0x66, 0x67, 0x68,
    0x69, 0x6a, 0x6b, 0x6c, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d,
    0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x68, 0x69, 0x6a, 0x6b,
    0x6c, 0x6d, 0x6e, 0x6f, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,
    0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x6b, 0x6c, 0x6d, 0x6e,
    0x6f, 0x70, 0x71, 0x72, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73,
    0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x6e, 0x6f, 0x70, 0x71,
    0x72, 0x73, 0x74, 0x75};


const unsigned char cmp[CRYPTO_BYTES] = {
    0x8e, 0x95, 0x9b, 0x75, 0xda, 0xe3, 0x13, 0xda, 0x8c, 0xf4, 0xf7, 0x28,
    0x14, 0xfc, 0x14, 0x3f, 0x8f, 0x77, 0x79, 0xc6, 0xeb, 0x9f, 0x7f, 0xa1,
    0x72, 0x99, 0xae, 0xad, 0xb6, 0x88, 0x90, 0x18, 0x50, 0x1d, 0x28, 0x9e,
    0x49, 0x00, 0xf7, 0xe4, 0x33, 0x1b, 0x99, 0xde, 0xc4, 0xb5, 0x43, 0x3a,
    0xc7, 0xd3, 0x29, 0xee, 0xb6, 0xdd, 0x26, 0x54, 0x5e, 0x96, 0xe5, 0x5b,
    0x87, 0x4b, 0xe9, 0x09
};

int main(void)
{
  unsigned char digest[CRYPTO_BYTES];
  hal_setup(CLOCK_FAST);


  hal_send_str("\n============ IGNORE OUTPUT BEFORE THIS LINE ============\n");
  sha512(digest, msg, INLEN);

  int i;
  for(i=0;i<CRYPTO_BYTES;i++)
  {
    if(cmp[i] != digest[i])
    {
      hal_send_str("Test failed!\n");
      while(1);
      return -1;
    }
  }

  hal_send_str("Test successful!\n");

  while(1);
  return 0;
}
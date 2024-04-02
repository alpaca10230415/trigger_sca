#include <stdio.h>
#include "aes128encrypt.h"
#include "hal.h"
#include "plaintext.h"

const unsigned char key[CRYPTO_KEYBYTES] = {
  0x66, 0xd9, 0xb7, 0x60, 0x0e, 0xda, 0xaa, 0x81, 0x42, 0xa2, 0xd6, 0x3d, 0x8f,
  0x51, 0x6c, 0x6f };

void my_sleep(unsigned int secs);

void my_sleep(unsigned int secs) {
  #define STEPS_PER_SEC 650000
  unsigned int i,s;
  for (s=0; s < secs; s++) {
    for (i=0; i < STEPS_PER_SEC; i++) {
       asm("nop");
    }
  }
}

int main(void)
{
  char outstr[128];
  unsigned char out[CRYPTO_OUTPUTBYTES];
  hal_setup(CLOCK_BENCHMARK);

  int i;
  my_sleep(70);
  for(i=0;i<CRYPTO_TRACE;i++) {
    my_sleep(40);
    if((i%10) == 0) my_sleep(10);
    aes128encrypt(out, in[i], key);
    sprintf(outstr, "number for %d trace\n", i);
    hal_send_str(outstr); 
  }

  while(1);

  return 0;
}

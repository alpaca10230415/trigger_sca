#!/usr/bin/env python3
import numpy as np

con = 0
crypto_trace = 1000

if __name__ == "__main__":
    f = open("plaintext.h", 'w')
    f.write("#define CRYPTO_TRACE " + str(crypto_trace) + "\n\n")
    f.write("const unsigned char in[CRYPTO_TRACE][CRYPTO_INPUTBYTES] = {  \n")
    for j in range(crypto_trace):
        f.write("{ """)
        #f.write("0x{:02x}".format((j%256)))
        #f.write(", ")
        plaintext = np.random.randint(low=0, high=256, size=16-con)
        for i in range(16-con):
            f.write("0x{:02x}".format(plaintext[i]))
            if i!=(15-con):
                f.write(", ")

        if j==crypto_trace-1:
            f.write(" }\n")
        else:
            f.write(" },\n")
    f.write("};\n")
    f.close()

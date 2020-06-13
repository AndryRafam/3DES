# TDES (Triple Data Encryption Standard)

TDES is a symmetric key-block cipher which applies DES (Data Encryption Standard) three times with three different keys (k1, k2, k3).
Like DES, the TDES structure is based on Feistel scheme.


# How TDES works ?
- Encryption

Lets:
- S be a block of 64 bits size clear message
- E(k,S) be an encrypting function with the key k
- D(k,S) a decrypting function with the key k
- k1, k2 and k3; three different keys (56 bits size each + 8 parity bits)

TDES(S)= E(k3,D(k2,E(k1,S))). (Encrypt with k1; Decrypt with k2 and Encrypt again with k3. The total key size is 112 bits).

- Decryption

Decryption is the reverse operation:

Lets C the ciphertext obtained through the TDES operation.

S = D(k1,E(k2,D(k3,C))). (Decrypt with k3; Encrypt with k2 and Decrypt with k1).

- More information on encrypting / decrypting can be found on wikipedia: https://en.wikipedia.org/wiki/Triple_DES#Security


# How to run the program on linux (Debian based distro)

- 1) Download the program.
- 2) Open a terminal, go to the program folder. 
- 3) Type "make" to run the makefile program (compilation program).
- 4) Type "./exe" to run the program.


# Program sample

[ Clear Text ] -> Hello Github. How are you today ?

[ Encrypted Text ] -> 34AF9AC9A6D3A431 53D873168FCEAB91 A8112E4682CF932D 50F2C84247D4C2F5 8626E8CEC2271296


# WARNING !!!

THE SOFTWARE IS UNDER MIT LICENSE AND IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND !!! TDES IS OFFICIALLY BEING RETIRED !!! 
THIS PROGRAM IS INTENDED FOR EDUCATIONAL PURPOSE, NOT FOR INDUSTRIAL USE !!!

MORE INFORMATION HERE: https://www.cryptomathic.com/news-events/blog/3des-is-officially-being-retired


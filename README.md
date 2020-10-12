Objective
--------------------------------------
Writing a program to do a Kamasutracipher encryption/decryption.

The description of the Kama Sutra cipher is as follows:
In the 4th century BC, the Indian text "Kama Sutra" proposed a method of encrypting text.
Each letter of the alphabet was paired with one other letter. A ciphertext was formed by replacing 
each letter in the plaintext with its paired letter. When this scheme is used in the English language,
the number of possible keys is surprisingly high: around 7:9  1012. An exhaustive attack on such
a scheme would be unwieldly using a modern computer, and it was certainly infeasible at the time
this scheme was suggested.

For example, suppose the key is just a regular alphabet as follows.
abcdefghijklmnopqrstuvwxyz

Then, suppose the plaintext contains of the following
abab bcbc cdcd

The resulting ciphertext would be
baba adad dcdc

Instructions
--------------------------------------
kamasutra -k <keyfile.txt>
kamasutra -e <keyfile.txt> <plaintext.txt> <ciphertext.txt>
kamasutra -d <keyfile.txt> <ciphertext.txt> <plaintext.txt>

Sources
--------------------------------------
kamasutra.cpp


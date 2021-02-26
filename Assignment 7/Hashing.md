Hashing will be done using the following loop:

for(int i = 0; i < key[0]*3+4; i++){
    hash = hash + key[i%4]*key[(i+1)%4];
}

Let's break this down.

The loop will repeat at minimum, with the ASCII value of the first letter in the
key deciding how many extra times the loop will repeat multiplied by 3.

Inside, the hash value is calculated by multipling the ascii value of two letters
in the key and then adding it to the previous hash value.
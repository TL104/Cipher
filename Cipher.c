
#include <stdio.h>
#include <stdlib.h>

void encrypt(char*, int);
void decrypt(char*, int);
void validation(void);

int main(){
   
   printf("\nWelcome to cryptography");
   validation();
   printf("\n\n");
   printf("Tyler and Lawhorn Security Systems\n3-4-2020\n\n");
   return 0;
}
/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
void encrypt(char* message, int key){
   char cipher[2][94];
   int  i, c, size = 150;
       
   c = 65; for(i = 0; i < 26; ++i){cipher[0][i] = c; ++c;}
   c = 97; for(i = 26; i < 52; ++i){cipher[0][i] = c; ++c;}
   c = 48; for(i = 52; i < 62; ++i){cipher[0][i] = c; ++c;}
   c = 33; for(i = 62; i < 77; ++i){cipher[0][i] = c; ++c;}
   c = 58; for(i = 77; i < 84; ++i){cipher[0][i] = c; ++c;}
   c = 91; for(i = 84; i < 90; ++i){cipher[0][i] = c; ++c;}
   c = 123; for(i = 90; i < 94; ++i){cipher[0][i] = c; ++c;}
      
   for(i = 0; i < 94; ++i){
      if(i + key < 94) {cipher[1][i] = cipher[0][i+key];}
      else {cipher[1][i] = cipher[0][(i+key)-94];}
   }
   char changeCase[size];
   int capitalCount = 0, lowerCount = -1, digitCount = 0, symbolCount = 0,
       charCount = 0;
  
   for(i = 0; i < size; ++i){changeCase[i] = '\0';}
   
   for(i = 0; i < size; ++i){
      if(message[i] >= 'A' && message[i] <= 'Z')
         {capitalCount++; changeCase[i] = (message[i] + 32);}
      if(message[i] >= 'a' && message[i] <= 'z')
         {lowerCount++; changeCase[i] = (message[i] - 32);}
      if(message[i] >= '0' && message[i] <= '9'){digitCount++;}
      if(message[i] >= '!' && message[i] <= '/'){symbolCount++;}
      if(message[i] >= ':' && message[i] <= '@'){symbolCount++;}
      if(message[i] >= '[' && message[i] <= '`'){symbolCount++;}
      if(message[i] >= '{' && message[i] <= '~'){symbolCount++;}
   }
   charCount = (capitalCount + lowerCount + digitCount + symbolCount);
   printf("\nNumber of Captital Letters: %d\n",capitalCount);
   printf("Number of Small Letters: %d\n",lowerCount);
   printf("Number of Digits: %d\n",digitCount);
   printf("Number of Symbols: %d\n", symbolCount);
   printf("Number of Characters in the message: %d\n",charCount);
   printf("Converting Letters: %s\n",changeCase);
   int j = 0;
   char newMsg[size];
   for(i = 0; i < size; ++i){newMsg[i] = '\0';}
   for(i = 0; i < 94; ++i){
      if(cipher[0][i] == message[j] && j < size){
         newMsg[j] = cipher[1][i];
         j++;
         i = -1;
      }
   }
   printf("\nYour encrypted text is:\n%s",newMsg);
   printf("\n\nConcatenation of orignial and encrypted text: %s%s",message,newMsg);

   
   
}
/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
void decrypt(char* message, int key){
   char cipher[2][94];
   int  i, c, size = 150;
   
   c = 65; for(i = 0; i < 26; ++i){cipher[0][i] = c; ++c;}
   c = 97; for(i = 26; i < 52; ++i){cipher[0][i] = c; ++c;}
   c = 48; for(i = 52; i < 62; ++i){cipher[0][i] = c; ++c;}
   c = 33; for(i = 62; i < 77; ++i){cipher[0][i] = c; ++c;}
   c = 58; for(i = 77; i < 84; ++i){cipher[0][i] = c; ++c;}
   c = 91; for(i = 84; i < 90; ++i){cipher[0][i] = c; ++c;}
   c = 123; for(i = 90; i < 94; ++i){cipher[0][i] = c; ++c;}
   
   for(i = 0; i < 94; ++i){
      if(i + key < 94) {cipher[1][i] = cipher[0][i+key];}
      else {cipher[1][i] = cipher[0][(i+key)-94];}
   }
   char changeCase[size];
   int capitalCount = 0, lowerCount = -1, digitCount = 0, symbolCount = 0,
       charCount = 0;
     
   for(i = 0; i < size; ++i){changeCase[i] = '\0';}
      
   for(i = 0; i < size; ++i){
      if(message[i] >= 'A' && message[i] <= 'Z'){
         capitalCount++; changeCase[i] = (message[i] + 32);}
      if(message[i] >= 'a' && message[i] <= 'z'){
         lowerCount++; changeCase[i] = (message[i] - 32);}
      if(message[i] >= '0' && message[i] <= '9'){digitCount++;}
      if(message[i] >= 33 && message[i] <= 47){symbolCount++;}
      if(message[i] >= 58 && message[i] <= 64){symbolCount++;}
      if(message[i] >= 91 && message[i] <= 96){symbolCount++;}
      if(message[i] >= 123 && message[i] <= 126){symbolCount++;}
   }
   charCount = (capitalCount + lowerCount + digitCount + symbolCount);
   printf("\nNumber of Captital Letters: %d\n",capitalCount);
   printf("Number of Small Letters: %d\n",lowerCount);
   printf("Number of Digits: %d\n",digitCount);
   printf("Number of Symbols: %d\n", symbolCount);
   printf("Number of Characters in the message: %d\n",charCount);
   printf("Converting Letters: %s\n",changeCase);
   int j = 0;
   char newMsg[size];
   for(i = 0; i < size; ++i){newMsg[i] = '\0';}
   for(i = 0; i < 94; ++i){
      if(cipher[1][i] == message[j] && j < size){
         newMsg[j] = cipher[0][i];
         j++;
         i = -1;
      }
   }
   printf("\nYour decrypted text is:\n%s",newMsg);
   printf("\n\nConcatenation of orignial and decrypted text: %s%s",message,newMsg);

}
/* <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> */
void validation(void){
   int  i, size = 150, key;
   char input[size];
   
   char c = 'o',
        q = 'o';
   
   while(c == 'o'){
      for(i = 0; i < size; ++i){input[i] = '\0';}
      printf("\n\nWhat would you like to do to a message? (encrypt, decrypt, exit)\n");
      printf("Enter your choice: ");
      scanf("%s",input);
      q = 'o';
      i = 0;
      if(input[i] == 'e' || input[i] == 'E'){
         i++;
         if(input[i] == 'n' || input[i] == 'N'){
            i++;
            if(input[i] == 'c' || input[i] == 'C'){
               i++;
               if(input[i] == 'r' || input[i] == 'R'){
                  i++;
                  if(input[i] == 'y' || input[i] == 'Y'){
                     i++;
                     if(input[i] == 'p' || input[i] == 'P'){
                        i++;
                        if(input[i] == 't' || input[i] == 'T'){
                           i++;
                           if(input[i] == '\0'){
                              q = 'E';
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      if(q != 'E'){
         i = 0;
         if(input[i] == 'd' || input[i] == 'D'){
            i++;
            if(input[i] == 'e' || input[i] == 'E'){
               i++;
               if(input[i] == 'c' || input[i] == 'C'){
                  i++;
                  if(input[i] == 'r' || input[i] == 'R'){
                     i++;
                     if(input[i] == 'y' || input[i] == 'Y'){
                        i++;
                        if(input[i] == 'p' || input[i] == 'P'){
                           i++;
                           if(input[i] == 't' || input[i] == 'T'){
                              i++;
                              if(input[i] == '\0'){
                                 q = 'D';
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      if(q != 'E' && q != 'D'){
         i = 0;
         if(input[i] == 'e' || input[i] == 'E'){
            i++;
            if(input[i] == 'x' || input[i] == 'X'){
               i++;
               if(input[i] == 'i' || input[i] == 'I'){
                  i++;
                  if(input[i] == 't' || input[i] == 'T'){
                     i++;
                     if(input[i] == '\0'){
                        q = 'X';
                     }
                  }
               }
            }
         }
      }
      if(q == 'E' || q == 'D'){
         printf("\nEnter your message:\n");
         scanf("%s",input);
         printf("Enter the key number (1-93)\n");
         scanf("%d",&key);
         if(key > 0 && key < 94){
            if(q == 'E'){encrypt(input,key); q = 'x';}
            if(q == 'D'){decrypt(input,key); q = 'x';}
         }
         else {printf("Invalid Key Number\n\n");}
      }
      if(q == 'o'){printf("\nInvalid input\n\n");}
      if(q == 'X'){c = 'x';}
   }
}


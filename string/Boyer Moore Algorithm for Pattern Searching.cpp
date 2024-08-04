void computeFullShift(int shiftArr[], int longSuffArr[], string patrn) {
   // length of pattern
   int n = patrn.size(); 
   int i = n;
   int j = n+1;
   longSuffArr[i] = j;
   while(i > 0) {
      // Searching right if (i-1)th and (j-1)th item are not the same
      while(j <= n && patrn[i-1] != patrn[j-1] ) {
          // to shift pattern from i to j
         if(shiftArr[j] == 0) {
            shiftArr[j] = j-i; 
         }
         // Updating long suffix value
         j = longSuffArr[j]; 
      }
      i--;
      j--;
      longSuffArr[i] = j;
   }  
}
// Function for good suffix match
void computeGoodSuffix(int shiftArr[], int longSuffArr[], string patrn) {
   // length of the pattern
   int n = patrn.size(); 
   int j;
   j = longSuffArr[0];
   // Looping through the pattern
   for(int i = 0; i<n; i++) {
      // setting shift to long suffix value
      if(shiftArr[i] == 0) {
         shiftArr[i] = j; 
         if(i == j) {
            // Updating long suffix value
            j = longSuffArr[j]; 
         }
      }
   }
}
// Function for searching the pattern
void searchPattern(string orgnStr, string patrn, int array[], int *index) {
   // length of the pattern
   int patLen = patrn.size(); 
   // length of main string
   int strLen = orgnStr.size();
   int longerSuffArray[patLen+1];
   int shiftArr[patLen + 1];
   // Initializing shift array elements to 0
   for(int i = 0; i<=patLen; i++) {
      shiftArr[i] = 0;
   }
   // Calling computeFullShift function
   computeFullShift(shiftArr, longerSuffArray, patrn); 
   // Calling computeGoodSuffix function
   computeGoodSuffix(shiftArr, longerSuffArray, patrn); 
   int shift = 0;
   while(shift <= (strLen - patLen)) {
      int j = patLen - 1;
      // decrement j when pattern and main string character is matching
      while(j >= 0 && patrn[j] == orgnStr[shift+j]) {
         j--; 
      }
      if(j < 0) {
         (*index)++;
         // to store the position where pattern is found
         array[(*index)] = shift; 
         shift += shiftArr[0];
      }else {
          shift += shiftArr[j+1];
      }
   }
}
int main() {
   // original string    
   string orgnStr = "AABAAABCEDBABCDDEBC"; 
   // Pattern to be searched
   string patrn = "ABC"; 
   // Array to store the positions where pattern is found
   int locArray[orgnStr.size()]; 
   int index = -1;
   // Calling the searchPattern function
   searchPattern(orgnStr, patrn, locArray, &index); 
   // Printing the positions where pattern is found
   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i]<<endl;
   }
}

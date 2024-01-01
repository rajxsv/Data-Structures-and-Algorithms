#include <iostream>
#include <conio.h>
#include <string.h>
int main()
{
   char str[100], word[20];
   int i, j, lengths, lengthw, r, ans = 0, chk;

   printf("Enter the String: ");
   gets(str);

   printf("Enter a Word: ");
   gets(word);
   
   lengths = strlen(str);
   lengthw = strlen(word);

   for (i = 0; i < lengths; i++)
   {
      r = i;
      for (j = 0; j < lengthw; j++)
      {
         if (str[i] == word[j])
            i++;
      }
      chk = i - r;
      if (chk == lengthw)
         ans++;
      i = r;
   }

   printf("\nOccurrence = %d", ans);
   getch();
   return 0;
}
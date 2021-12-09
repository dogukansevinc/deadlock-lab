#include <stdio.h>
int
main ()
{
  int n = 5;
  int m = 3;
  int i;
  int j;
  int k;
  int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
  int max[5][3] = { {8, 5, 3}, {3, 2, 2}, {9, 0, 2}, {6, 2, 2}, {4, 5, 3} };
  int avail[3] = { 3, 3, 2 };
  int finish[n], ans[n], index = 0;
  for (k = 0; k < n; k++)
    finish[k] = 0;
  int need[n][m];
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	need[i][j] = max[i][j] - alloc[i][j];
    }
  int y = 0;
  int found = 0;
  for (k = 0; k < 5; k++)
    {
      for (i = 0; i < n; i++)
	{
	  if (finish[i] == 0)
	    {
	      int f = 0;
	      for (j = 0; j < m; j++)
		{
		  if (need[i][j] > avail[j])
		    {
		      f = 1;
		      break;
		    }
		}
	      if (f == 0)
		{
		  ans[index++] = i;
		  for (y = 0; y < m; y++)
		    avail[y] += alloc[i][y];
		  finish[i] = 1;
		  found = 1;
		}
	    }
	}
    }
  if (found == 0)
    {
      printf ("System is not in safe state.\n");
      return 0;
    }
  printf ("System is Safe.\nSAFE Sequence:\t");
  for (i = 0; i < n - 1; i++)
    printf ("P%d ->", ans[i]);
  printf ("P%d", ans[n - 1]);
  return 0;

}

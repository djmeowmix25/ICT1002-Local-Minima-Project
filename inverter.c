#include <stdio.h>
#include <math.h>

float determinant(float[][25], float);

void cofactor(float[][25], float f, double *inversedArray);

void transpose(float[][25], float[][25], float f, double *inversedArray);

void inverter_function(int dim,  double *inversedArray);

void inverter_function(int dim,  double *inversedArray)

{

  float a[25][25], d;

  int i, j;

  int k = dim;
  for (i = 0; i < k; i++)
  {
    for (j = 0; j < k; j++)
    {
          a[i][j] = inversedArray[(i * k) + j];
    }
  }

  d = determinant(a, k);

  if (d == 0)

    printf("\nInverse of Entered Matrix is not possible\n");

  else
    cofactor(a, k, inversedArray);
}

/*For calculating Determinant of the Matrix */

float determinant(float a[25][25], float k)

{

  float s = 1, det = 0, b[25][25];

  int i, j, m, n, c;

  if (k == 1)

  {

    return (a[0][0]);
  }

  else

  {

    det = 0;

    for (c = 0; c < k; c++)

    {

      m = 0;

      n = 0;

      for (i = 0; i < k; i++)

      {

        for (j = 0; j < k; j++)

        {

          b[i][j] = 0;

          if (i != 0 && j != c)

          {

            b[m][n] = a[i][j];

            if (n < (k - 2))

              n++;

            else

            {

              n = 0;

              m++;
            }
          }
        }
      }

      det = det + s * (a[0][c] * determinant(b, k - 1));

      s = -1 * s;
    }
  }

  return (det);
}

void cofactor(float num[25][25], float f, double *inversedArray)

{

  float b[25][25], fac[25][25];

  int p, q, m, n, i, j;

  for (q = 0; q < f; q++)

  {

    for (p = 0; p < f; p++)

    {

      m = 0;

      n = 0;

      for (i = 0; i < f; i++)

      {

        for (j = 0; j < f; j++)

        {

          if (i != q && j != p)

          {

            b[m][n] = num[i][j];

            if (n < (f - 2))

              n++;

            else

            {

              n = 0;

              m++;
            }
          }
        }
      }

      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }

  transpose(num, fac, f, inversedArray);
}

/*Finding transpose of matrix*/

void transpose(float num[25][25], float fac[25][25], float r, double *inversedArray)

{

  int i, j;

  float b[25][25], inverse[25][25], d;

  for (i = 0; i < r; i++)

  {

    for (j = 0; j < r; j++)

    {

      b[i][j] = fac[j][i];
    }
  }

  d = determinant(num, r);
int k =0;
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      inverse[i][j] = b[i][j] / d;
      inversedArray[k] = inverse[i][j];
      k = k+1;
    }
  }

}
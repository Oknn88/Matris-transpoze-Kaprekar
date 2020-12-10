/*Bu proje sınırlarını kullanıcının belirlediği bir matris oluştur. Matrisin içini 5 ile 40 bin rastgele arası
sayılarla doldurur ve bu matrsi önce bubblesort yapar,sonra transpoze eder. Matrisin bubblesort ve transpoze
halini bir dosyaya yazar ve bu matriste kaprekar sayı olup olmadığına bakar. Kaprekar sayı varsa sayıyı veya
sayıları bir dosyaya yazar.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*matrisolustur fonksiyonu:
  Matrisin boyutalırını kullanıcıdan alıyor.
  Bu matrise 5 ile 40000 arsı sayılar atıyor.
  Matrisi return ediyor.
*/
int matrisolustur(int *r_ptr, int *c_ptr)
{

	printf("Matrisin boyutlarini giriniz\n");
	printf("1. boyut: ");
	scanf("%d",r_ptr);
	printf("2. boyutu giriniz: ");
	scanf("%d",c_ptr);
	int *arr = (int *)malloc(*r_ptr * *c_ptr * sizeof(int));
	int i, j, rastgele;
	for (i = 0; i < *r_ptr; i++)
    {
        for (j = 0; j < *c_ptr; j++)
        {
           rastgele = rand() %40000 + 5;
           *(arr + i**c_ptr + j) = rastgele;
        }
    }

    return arr;
}
/*bubblesort fonksiyonu:
  r,c matris boyutlarını alıyor.
  arr_ptr matrisi tutuyor.
  Matrisi bubblesort yapıyor.
*/
void bubblesort(int r, int c, int *arr_ptr)
{
    int temp;
    bool a = true;
    while(a)
    {
        a = false;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if ((i*c + j)==(r*c-1))
            {

            }
            else if(*(arr_ptr + i*c + j) < *(arr_ptr+ i*c + j+1))
            {
                a = true;
                temp = *(arr_ptr + i*c + j);
                *(arr_ptr + i*c + j) = *(arr_ptr + i*c + j+1);
                *(arr_ptr + i*c + j+1) = temp;
            }
        }
    }
    }
}

/*transpoze fonksiyonu:
  r,c matris boyutlarını alıyor.
  transpoze_ptr bubblesort edilmiş matrisi tutuyor.
  transpoze_olan bubblesort edilmiş matrisi tutup transpoze ediyor
*/
void transpoze(int r, int c, int *transpoze_ptr,int *transpoze_olan)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transpoze_olan[i*c + j] = *(transpoze_ptr + i*c + j);
        }

    }

}
/*transpozedosya fonksiyonu:
  r,c matris boyutunu tutuyor.
  transpoz_dosya matrisin transpoze edilmiş halini tutuyor.
  f_matrisarr matrisin bubblesort halini tutuyor.
  transpoze.txt adında bir dosya oluşturup matrisin bubblesort edilmiş halini ve transpoze edilmiş halini bu dosyaya yazıyor.
  transpoze.txt adlı dosya oluşturulmuşmu diye kontrol edip oluşturulmuşsa "yazdırma işlemi tamam" yazıyor.
*/
void transpozedosya(int r,int c,int *transpoz_dosya,int *f_matrisarr)
{
    bool x;

    FILE *t_dosya = fopen("transpoze.txt", "w");

        fprintf(t_dosya, "===Matrisin ilk hali===\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            fprintf(t_dosya, "%d ",*(f_matrisarr + i*c + j));
            if (j == r - 1)
                fprintf(t_dosya, "\n");
        }
    }

    fprintf(t_dosya, "===Matrisin transpoze hali===\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            fprintf(t_dosya, "%d ",transpoz_dosya[j*c + i]);
            if (j == r - 1)
                fprintf(t_dosya, "\n");
        }
    }

    if(t_dosya = fopen("transpoze.txt" , "r"))
    {
        x = true;
    }
    else
    {
        x = false;
    }

    if(x == true)
    {
        printf("\nyazdirma islemi tamam!\n");
    }
    fclose(t_dosya);
}

/*kaprekar fonksiyonu:
  a ya transpoz edilmiş matrisdeki sayılar yollanıyor.
  bu sayıların kaprekar sayı olup olmadığını kontrol ediyor.
*/
bool kaprekar(int a)
{
    if (a == 1)
       return true;

    int degisken = a * a;
    int basamak = 0;
    while (degisken)
    {
        basamak++;
        degisken /= 10;
    }

    degisken = a * a;

    for (int i = 1; i<basamak; i++)
    {
         int result = pow(10, i);
         if (result == a)
            continue;
         int toplam = degisken/result + degisken % result;
         if (toplam == a)
           return true;
    }
    return false;
}

/*kaprekardosya fonksiyonu:
  r,c matris boyutunu tutuyor.
  k_tronspoz transpoz edilmiş matrisi tutuyor.
  kaprekar fonksiyonuna matris sayılarını tekekr teker yollayıp kaprekar sayı olup olmadıklarını alıyor.
  kaprekar.txt dosyasını oluştup içine matrisde kaprekar sayısı varsa bunları yazıyor.
  hiç kaprekar sayısı yoksa "Kaprekar yok" uyarısını veriyor.
*/
void kaprekardosya(int r, int c,int *k_transpoz)
{
    int a;
    FILE *k_dosya = fopen("kaprekar.txt", "w");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
           if (kaprekar(k_transpoz[i*c + j])==true)
		  {
		   fprintf(k_dosya, "%d Kaprekar sayıdır \n",k_transpoz[i*c + j]);
		    a = 1;
		  }
        }

    }

    if(a==1)
    {

    }
    else
    {
        printf("Kaprekar yok\n");
    }
    fclose(k_dosya);
}



int main()
{
    int r,c,*matris_arr;
    matris_arr = matrisolustur(&r,&c);
	bubblesort(r,c,matris_arr);;
	int transpozearray[r*c];
    transpoze(r,c,matris_arr,transpozearray);
    transpozedosya(r,c,transpozearray,matris_arr);
    kaprekardosya(r,c,transpozearray);
return 0;
}

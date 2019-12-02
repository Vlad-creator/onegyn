#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qSort1(char* v[], int left, int right);
void swap1(char* v[], int left, int right);

int main()
{
    FILE* fp;
    FILE* fpe;
    fp = fopen("C:\\Users\\vlad-\\OneDrive\\Рабочий стол\\gnu.txt", "r");
    fpe = fopen("C:\\Users\\vlad-\\OneDrive\\Рабочий стол\\gnu1.txt", "w");


    int strings = 1;

    fseek (fp, 0, SEEK_END);
    long long int SIZE = ftell(fp);
    rewind(fp);
    char* buffer  = (char*)calloc(SIZE, sizeof(char));
    int result = fread(buffer, 1, SIZE, fp);
    SIZE = result;

    for (int i = 0 ; i < SIZE ; i++)
    {
        if (buffer[i] == '\n')
        {
            strings++;
            buffer[i] = '\0';
        }
    }

    char** strukaz  = (char**)calloc(strings, sizeof(char*));

    int j = 0, k = 0;
    for (int i = 0 ; i < SIZE ; i++)
    {
        if (i == 0)
        {
            strukaz[j] = &buffer[i];
            j++;
        }
        if (buffer[i] == '\0')
        {
            strukaz[j] = &buffer[i + 1];
            j++;
        }
    }

    qSort1(strukaz , 0 , strings - 1);

    for (int i = 0 ; i < strings ; i++)
    {
            fputs (strukaz[i] , fpe);
            fputc ((int)'\n' , fpe);
    }

    free(buffer);
    free(strukaz);
    fclose(fp);
    fclose(fpe);
    return 0;
}





void qSort1(char* v[], int left, int right)
{
    int last = 0;
    int counter = 0;

    if (left >= right)
        return ;

    swap1(v, left, (left + right) / 2);

    last = left;

    for (counter = left + 1; counter <= right; counter++)
    {
        if (strcmp(v[counter], v[left]) < 0)
        {
            swap1(v, counter, ++last);
        }
    }

    swap1(v, left, last);

    qSort1(v, left, last - 1);
    qSort1(v, last + 1, right);
}



void swap1(char* v[], int left, int right)
{
    char* k = v[left];
    v[left] = v[right];
    v[right] = k;
}







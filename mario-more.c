#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height? ");
    }
    while (height < 1 || height > 8);

    //print new line
    for (int row = 0; row < height; row++)
    {
        //print space
        for (int space = 0; space < (height - (row + 1)); space++)
        {
            printf(" ");
        }
        //print hash
        for (int lh = 0; lh < (row + 1); lh++)
        {
            printf("#");
        }
        //print gap
        for (int gap = 0; gap < 2; gap++)
        {
            printf(" ");
        }
        for (int rh = 0; rh < (row + 1); rh++)
        {
            printf("#");
        }
        printf("\n");
    }


}
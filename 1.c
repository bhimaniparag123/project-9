#include <stdio.h>

main() 
{
    FILE *evenFile, *oddFile;
    int i;

    evenFile = fopen("even_file.txt", "w");
    if (evenFile == NULL) {
        perror("Error opening even_file.txt");
        return 1;
    }

    oddFile = fopen("odd_file.txt", "w");
    if (oddFile == NULL) 
	{
        perror("Error opening odd_file.txt");
        fclose(evenFile);
        
        return 1;
    }
    for (i = 50; i <= 70; i++) 
	{
        if (i % 2 == 0) 
		{
            fprintf(evenFile, "%d", i);
            if (i != 70) {
                fprintf(evenFile, ", ");
                         }
        } 
		else
	  	{
            fprintf(oddFile, "%d", i);
            if (i != 69) {
                fprintf(oddFile, ", ");
                         }
        }
    }
    fclose(evenFile);
    fclose(oddFile);

    printf("Even numbers written to even_file.txt\n");
    printf("Odd numbers written to odd_file.txt\n");
}
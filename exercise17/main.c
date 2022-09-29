#include <stdio.h>

void splitFile(char *filename, int fileSize)
{
    int result = 0;
    FILE *fFirst;
    FILE *fOutput;
    char buffer[1000];
    int size, line, written;

    if ((filename != NULL)){
        fFirst = fopen(filename, "rb");
        if (fFirst != NULL){
            fOutput = NULL;
            result = 1;   
            while (!feof(fFirst)){
                if (fOutput == NULL){
                    sprintf(buffer, "%s.part%03d", filename, result);
                    fOutput = fopen(buffer, "wb");
                    if (fOutput == NULL){
                        result *= -1;
                        break;
                    }
                    size = 0;
                }

                line = sizeof(buffer);
                if ((size + line) > fileSize){
                    line = fileSize - size;
                }
                
                line = fread(buffer, 1, line, fFirst);
                if (line == 0){
                    result *= -1;
                    break;
                }

                written = fwrite(buffer, 1, line, fOutput);
                if (written != line){
                    result *= -1;
                    break;
                }

                size += written;
                if (size >= fileSize){
                    fclose(fOutput);
                    fOutput = NULL;
                    result++;
                }
            }

            if (fOutput != NULL){
                fclose(fOutput);
            }
            fclose(fFirst);
        }
    }
}

int main(){
    char filename[50];
    int fileSize;
    printf("Give file name: ");
    scanf("%s", filename);
    printf("Give file size: ");
    scanf("%d", &fileSize);
    splitFile(filename, fileSize);
    return 0;
}

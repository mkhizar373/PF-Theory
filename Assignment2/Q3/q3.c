#include <stdio.h>
#include <string.h>

void compressWord(char *word, int *removedCount) {
    int length = strlen(word);
    int i, j = 0;
    char temp[length + 1];

    for(i = 0; i < length; i++) {
        if(i == 0 || word[i] != word[i-1]) {
            temp[j++] = word[i];
        } else {
            (*removedCount)++;
        }
    }
    temp[j] = '\0';
    strcpy(word, temp);
}

void compressWords(char words[][100], int numWords, int *totalRemovedCount) {
    for(int i = 0; i < numWords; i++) {
        int removedCount = 0;
        compressWord(words[i], &removedCount);
        *totalRemovedCount += removedCount;
    }
}

int main() {
    int numWords;
    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    char words[numWords][100];
    printf("Enter the words:\n");
    for(int i = 0; i < numWords; i++) {
        scanf("%s", words[i]);
    }

    int totalRemovedCount = 0;
    
    compressWords(words, numWords, &totalRemovedCount);

    printf("Compressed words: \n");
    for(int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\nCharacters removed: %d\n", totalRemovedCount);

    return 0;
}

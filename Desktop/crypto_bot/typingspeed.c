#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){
    char target_sentence[] = "This is and the best part and it was fabulous in greatest and fastest happy that is awesome";
    char user_input[200];
    time_t start,end;
    double time_taken;

    printf("TYPING SPEED TEST\n");
    printf("Type the following sentence exactly:\n\n");
    printf("%s\n\n", target_sentence);
    printf("Press ENTER to start typing...\n");
    getchar();

    start = time(NULL);
    printf("\nGO! Type here: ");
    fgets(user_input,200,stdin);
    end = time(NULL);
    time_taken = difftime(end,start);

    printf("\n------------------------------------------------\n");
    printf("You took %.2f seconds.\n", time_taken);

    size_t len = strlen(user_input);
    if(len>0 && user_input[len -1]=='\n'){
        user_input[len - 1] = '\0';
    }
    if(strcmp(user_input,target_sentence)==0){
        printf("\nResult: Perfect Accuracy\n");

        double wpm = (strlen(target_sentence)/time_taken)*60;
        printf("Speed: %.0f WPM\n",wpm/5);

    }else{
        printf("\nResult: You made a typo!\n");
        printf("Expected: %s\n",target_sentence);
        printf("You Typed: %s\n",user_input);
    }
    return 0;
}
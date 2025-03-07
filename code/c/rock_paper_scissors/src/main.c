#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

// C rock_paper_scissors

enum choice {ROCK = 0, PAPER = 1, SCISSORS = 2, NONE = -1};

/* Convert input string to choice.
    if input is invalid, NONE will be returned. */
enum choice strchoice(char *input);

/* Convert enum choice to string.
    ROCK = "rock"
    PAPER = "paper"
    SCISSORS = "scissors"
    default = "" */
char *choicestr(enum choice choice);

/* One of ROCK, PAPER or SCISSORS. */
enum choice randchoice();

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "No choice specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *user_input = argv[1];
    enum choice user_choice = strchoice(user_input);
    if (user_choice == NONE) {
        fprintf(stderr, "Invalid choice \"%s\", valid choices are \"rock\", "
                "\"paper\" and \"scissors\". (All case-insensitive), exiting.\n"
                , user_input);
        return EXIT_FAILURE;
    }

    enum choice computer_choice = randchoice();

    printf("User: %s\n", user_input);
    printf("Computer: %s\n", choicestr(computer_choice));

    if (computer_choice == user_choice)
        printf("Tie!\n");
    else if ((computer_choice == ROCK && user_choice == PAPER) ||
            (computer_choice == PAPER && user_choice == SCISSORS) ||
            (computer_choice == SCISSORS && user_choice == ROCK))
        printf("Winner: User!\n");
    else
        printf("Winner: Computer!\n");

    return EXIT_SUCCESS;
}

enum choice strchoice(char *input)
{
    if (!strcasecmp(input, "rock"))
        return ROCK;
    else if (!strcasecmp(input, "paper"))
        return PAPER;
    else if (!strcasecmp(input, "scissors"))
        return SCISSORS;
    else
        return NONE;
}

char *choicestr(enum choice choice)
{
    switch (choice) {
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        default:
            return "";
    }
}

enum choice randchoice()
{
    time_t now;
    time(&now);
    srand(now);
    return ((float)rand() / (float)RAND_MAX) * 3;
}

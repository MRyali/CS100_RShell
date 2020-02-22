#include "Tokenizer.hpp"

//Uses the memchr functino to check if the tokens cstring contains a comment (represented by '#')
bool Tokenizer::containsComment(char* tokens) {
    if ((char*)memchr(tokens, '#', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr functino to check if the tokens cstring contains a semicolon (represented by ';')
bool Tokenizer::containsSemiColon(char* tokens) {
    if ((char*)memchr(tokens, ';', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses strncmp to compare if the token passed in is either the AND or OR operator
bool Tokenizer::containsOrAnd(char* tokens) {
    return ((strncmp("&&", tokens, 2) == 0) || (strncmp("||", tokens, 2) == 0));
}

deque<char*> Tokenizer::getConnectors() {
    deque<char*> newConnectorList;

    for (char* item: connectors) {
        newConnectorList.push_back(item);
    }

    return newConnectorList;
}

void Tokenizer::tokenize() {
    if (inputStr.length() != 0) {
        char* primitiveInput = new char[inputStr.size() + 1];
        strcpy(primitiveInput, inputStr.c_str());
        char* currToken = strtok(primitiveInput, " ");

        bool firstTokenIsSemiColon = false;

        if (containsSemiColon(currToken)) {
            currToken[strlen(currToken) - 1] = 0;
            string semicolon = ";";
            char* semicolonArray = new char[2];
            strcpy(semicolonArray, semicolon.c_str());
            connectors.push_back(semicolonArray);
            firstTokenIsSemiColon = true;
        }

        if (!containsComment(currToken)) {
            while (currToken != 0 && !containsComment(currToken)) {
                CommandToken* currCommand = new CommandToken(currToken);
                char* nextToken = currToken;
                if (!containsComment(nextToken) && !firstTokenIsSemiColon) {
                    nextToken = strtok(NULL, " ");
                    while (nextToken != NULL && !containsComment(nextToken)) {
                        if (!containsComment(nextToken)) {
                            if (!containsOrAnd(nextToken)) {
                                if (containsSemiColon(nextToken)) {
                                    nextToken[strlen(nextToken) - 1] = 0;
                                    currCommand->addArgument(nextToken);
                                    string semicolon2 = ";";
                                    char* semicolonArray2 = new char[2];
                                    strcpy(semicolonArray2, semicolon2.c_str());
                                    connectors.push_back(semicolonArray2);

                                    break;
                                }
                                if (containsComment(nextToken)) {
                                   break;
                                }
                                else {
                                    currCommand->addArgument(nextToken);
                                }
                            }
                            else {
                                if (containsComment(nextToken)) {
                                    break;
                                }
                                connectors.push_back(nextToken);
                                break;
                            }
                        }
                        nextToken = strtok(NULL, " ");
                    }

                    currToken = nextToken;
                    currToken = strtok(NULL, " ");

                    if (currCommand->getName() == "exit") {
                        ExitToken* exitToken = new ExitToken();
                        commandTokens.push_back(exitToken);

                    }
                    else {
                        commandTokens.push_back(currCommand);
                    }
                }
                else {
                    commandTokens.push_back(currCommand);
                    currToken = nextToken;
                    currToken = strtok(NULL, " ");
                    firstTokenIsSemiColon = false;
                }
            }
        }
    }
}

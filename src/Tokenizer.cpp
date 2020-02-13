#include "Tokenizer.hpp"

bool containsComment(char* tokens) {
    if ((char*)memchr(tokens, '#', strlen(tokens)) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool containsSemiColon(char* tokens) {
    if ((char*)memchr(tokens, ';', strlen(tokens)) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool containsOrAnd(char* tokens) {
    return ((strncmp("&&", tokens, 2) == 0) || (strncmp("||", tokens, 2) == 0));
}

void Tokenizer::tokenize() {
    
    
    if (inputStr.length() != 0) {
        char* primitiveInput = new char[inputStr.length() + 1];
        strcpy(primitiveInput, inputStr.c_str());
        char* currToken = strtok(primitiveInput, " ");
        
        bool firstTokenIsSemiColon = false;
        
        if (containsSemiColon(currToken)) {
            currToken[strlen(currToken) - 1] = 0;
            char semicolonArray[] = ";";
            char* semicolon = semicolonArray;
            connectors.push_back(semicolon);
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
                                    nextToken[strlen(currToken) - 1] = 0;
                                    char semicolonArray2[] = ";";
                                    char* semicolon2 = semicolonArray2;
                                    connectors.push_back(semicolon2);
                                    
                                    currCommand->addArgument(nextToken);
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
                                
                                if (containsOrAnd(nextToken)) {
                                    connectors.push_back(nextToken);
                                }
    
                                break;
                            }
                        }
                        nextToken = strtok(NULL, " ");
                    }
                    
                    currToken = nextToken;
                    currToken = strtok(NULL, currToken);
                    
                    if (currCommand->getName() == "exit") {
                        commandTokens.push_back(currCommand);
                        ExitToken* exitToken = new ExitToken();
                        
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

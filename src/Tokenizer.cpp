#include "Tokenizer.hpp"

//Uses the memchr function to check if the tokens cstring contains a comment (represented by '#')
bool Tokenizer::containsComment(char* tokens) {
    if ((char*)memchr(tokens, '#', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr function to check if the tokens cstring contains a semicolon (represented by ';')
bool Tokenizer::containsSemiColon(char* tokens) {
    if ((char*)memchr(tokens, ';', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool Tokenizer::containsDash(char* tokens) {
    if ((char*)memchr(tokens, '-', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr function to check if the tokens cstring contains a left parenthese (represented by '(')
bool Tokenizer::containsLeftPrecedence(char* tokens) {
    if ((char*)memchr(tokens, '(', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr function to check if the tokens cstring contains a right parenthese (represented by ')')
bool Tokenizer::containsRightPrecedence(char* tokens) {
    if ((char*)memchr(tokens, ')', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr function to check if the tokens cstring contains a left bracket (represented by '[')
bool Tokenizer::containsLeftBracket(char* tokens) {
    if ((char*)memchr(tokens, '[', strlen(tokens)) != NULL) {
        return true;
    }
    else {
        return false;
    }
}

//Uses the memchr function to check if the tokens cstring contains a right bracket (represented by ']')
bool Tokenizer::containsRightBracket(char* tokens) {
    if ((char*)memchr(tokens, ']', strlen(tokens)) != NULL) {
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

void Tokenizer::tokenize() {
    if (inputStr.length() != 0) {
        char* primitiveInput = new char[inputStr.size() + 1];
        strcpy(primitiveInput, inputStr.c_str());
        char* currToken = strtok(primitiveInput, " ");
        
        bool containsPrecedence = false, containsBracket = false;
        for (char c: inputStr) {
            if (c == '(') {
                containsPrecedence = true;
            }
            else if (c == '[') {
                containsBracket = true;
            }
        }
        
        string expression = "";
        
        if (containsBracket && containsPrecedence) {
            precedenceFiltered = true;
            while (currToken != 0) {
                int rightPrecedenceNum = 0;
                
                if (containsLeftPrecedence(currToken) && containsRightPrecedence(currToken) && containsLeftBracket(currToken) && containsRightBracket(currToken)) {
                    cout << "This is a weird case what do i do help me plz" << endl;
                }
                else if (containsLeftPrecedence(currToken) && containsLeftBracket(currToken)) {
                    while (containsLeftPrecedence(currToken)) {
                        expression += "( ";
                        memmove(currToken, currToken + 1, strlen(currToken));
                    }
                    
                    expression += "[ " + string(currToken) + " ";
                }
                else if (containsLeftBracket(currToken) && containsRightBracket(currToken)) {
                    expression += "[ ";
                    memmove(currToken, currToken + 1, strlen(currToken));
                    
                    if (containsComment(currToken) || containsSemiColon(currToken)) {
                        int index = strlen(currToken) - 2;
                        memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                    }
                    else {
                        currToken[strlen(currToken) - 1] = 0;
                    }
                    
                    expression += string(currToken) + " ] ";
                }
                else if (containsLeftBracket(currToken)) {
                    expression += "[ ";
                    memmove(currToken, currToken + 1, strlen(currToken));
                    
                    expression += string(currToken) + " ";
                }
                else if (containsRightBracket(currToken)) {
                    if (containsComment(currToken) || containsSemiColon(currToken)) {
                        int index = strlen(currToken) - 2;
                        memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                    }
                    else {
                        currToken[strlen(currToken) - 1] = 0;
                    }
                    
                    expression += string(currToken) + " ] ";
                }
                else if (containsLeftPrecedence(currToken)) {
                    while (containsLeftPrecedence(currToken)) {
                        expression += "( ";
                        memmove(currToken, currToken + 1, strlen(currToken));
                    }
                    
                    expression += string(currToken) + " ";
                }
                else if (containsRightPrecedence(currToken)) {
                    while (containsRightPrecedence(currToken)) {
                        rightPrecedenceNum += 1;
                        
                        if (containsComment(currToken) || containsSemiColon(currToken)) {
                            int index = strlen(currToken) - 2;
                            memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                        }
                        else {
                            currToken[strlen(currToken) - 1] = 0;
                        }
                    }
                    
                    if (containsSemiColon(currToken)) {
                        currToken[strlen(currToken) - 1] = 0;
                        expression += string(currToken) + " ";
                        
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                        
                        expression += "; ";
                    }
                    else if (containsComment(currToken)) {
                        currToken[strlen(currToken) - 1] = 0;
                        expression += string(currToken) + " ";
                        
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                        
                        expression += "# ";
                    }
                    else {
                        expression += string(currToken) + " ";
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                    }
                }
                else {
                    expression += string(currToken) + " ";
                }
                
                currToken = strtok(NULL, " ");
            }
            
            primitiveInput = new char[expression.size() - 1];
            strcpy(primitiveInput, expression.c_str());
            currToken = strtok(primitiveInput, " ");
            
            deque<char*> cstrings;
            deque<string> separatedCommands;
            
            bool init = false, insideParentheses = false;
            
            while (currToken != 0) {
                if (containsLeftPrecedence(currToken)) {
                    insideParentheses = true;
                    
                    if (!init) {
                        deque<char*> command;
                        
                        while (!cstrings.empty()) {
                            if (containsLeftPrecedence(cstrings.front())) {
                                cstrings.pop_front();
                                break;
                            }
                            
                            command.push_front(cstrings.front());
                            cstrings.pop_front();
                        }
                        
                        string commandString = "";
                        
                        while (!command.empty()) {
                            commandString += command.front();
                            commandString += " ";
                            command.pop_front();
                        }
                        
                        if (commandString.size() != 0) {
                            separatedCommands.push_back(commandString);
                        }
                    }
                    
                    init = true;
                }
                else if (containsRightPrecedence(currToken)) {
                    insideParentheses = false;
                    init = false;
                    deque<char*> command;
                    
                    while (!cstrings.empty()) {
                        if (containsLeftPrecedence(cstrings.front())) {
                            cstrings.pop_front();
                            break;
                        }
                        
                        command.push_front(cstrings.front());
                        cstrings.pop_front();
                    }
                    
                    string commandString = "";
                    
                    while (!command.empty()) {
                        commandString += command.front();
                        commandString += " ";
                        command.pop_front();
                    }
                    
                    if (commandString.size() != 0) {
                        separatedCommands.push_back(commandString);
                    }
                }
                else if ((containsOrAnd(currToken) || containsComment(currToken) || containsSemiColon(currToken)) && !insideParentheses) {
                    outerConnectors.push_back(currToken);
                }
                else {
                    cstrings.push_front(currToken);
                }
                
                currToken = strtok(NULL, " ");
            }
            
            reverse(cstrings.begin(), cstrings.end());
            
            string completedCommand = "";
            while (!cstrings.empty()) {
                completedCommand += cstrings.front();
                completedCommand += " ";
                cstrings.pop_front();
            }
            
            if (completedCommand.size() != 0) {
                separatedCommands.push_back(completedCommand);
            }
            
            for (auto s: separatedCommands) {
                cout << s << endl;
            }
            
            while (separatedCommands.size() != 0) {
                char* topCommand = new char[separatedCommands.front().size() + 1];
                strcpy(topCommand, separatedCommands.front().c_str());
                separatedCommands.pop_front();
                
                currToken = strtok(topCommand, " ");
                
                bool firstTokenIsSemiColon = false;

                if (containsSemiColon(currToken)) {
                    currToken[strlen(currToken) - 1] = 0;
                    string semicolon = ";";
                    char* semicolonArray = new char[2];
                    strcpy(semicolonArray, semicolon.c_str());
                    connectors.push_back(semicolonArray);
                    firstTokenIsSemiColon = true;
                }
                
                if (containsLeftBracket(currToken)) {
                    string testString = "test";
                    char* testToken = new char[testString.size() + 1];
                    strcpy(testToken, testString.c_str());
                    
                    CommandToken* currCommand = new CommandToken(testToken);
                    
                    char* nextToken = currToken;
                    nextToken = strtok(NULL, " ");
                    
                    if (containsDash(nextToken)) {
                        currCommand->addArgument(nextToken);
                        
                        nextToken = strtok(NULL, " ");
                        currCommand->addArgument(nextToken);
                        
                        nextToken = strtok(NULL, " ");
                    }
                    else {
                        currCommand->addArgument(nextToken);
                        nextToken = strtok(NULL, " ");
                    }
                    
                    commandTokens.push_back(currCommand);
                    nextToken = strtok(NULL, " ");
                    
                    if (nextToken != 0) {
                        if (containsSemiColon(nextToken) || containsOrAnd(nextToken)) {
                            connectors.push_back(nextToken);
                            nextToken = strtok(NULL, " ");
                        }
                    }
                    
                    currToken = nextToken;
                }

                if (!containsComment(currToken)) {
                    while (currToken != 0 && !containsComment(currToken)) {
                        if (containsLeftBracket(currToken)) {
                            string testString = "test";
                            char* testToken = new char[testString.size() + 1];
                            strcpy(testToken, testString.c_str());
                            
                            CommandToken* currCommand = new CommandToken(testToken);
                            
                            char* nextToken = currToken;
                            nextToken = strtok(NULL, " ");
                            
                            if (containsDash(nextToken)) {
                                currCommand->addArgument(nextToken);
                                
                                nextToken = strtok(NULL, " ");
                                currCommand->addArgument(nextToken);
                                
                                nextToken = strtok(NULL, " ");
                            }
                            else {
                                currCommand->addArgument(nextToken);
                                nextToken = strtok(NULL, " ");
                            }
                            
                            commandTokens.push_back(currCommand);
                            nextToken = strtok(NULL, " ");
                            
                            if (nextToken != 0) {
                                if (containsSemiColon(nextToken) || containsOrAnd(nextToken)) {
                                    connectors.push_back(nextToken);
                                    nextToken = strtok(NULL, " ");
                                }
                            }
                            
                            currToken = nextToken;
                        }
                        
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
                
                if (connectors.size() > 0) {
                    CommandToken* left = commandTokens.front();
                    commandTokens.pop_front();
                    
                    CommandToken* right = commandTokens.front();
                    commandTokens.pop_front();
                    
                    char* currSeparator = connectors.front();
                    connectors.pop_front();
                    
                    if (currSeparator == andLiteral) {
                        AndToken* andToken = new AndToken(left, right);
                        finalCommandTokens.push_back(andToken);
                    }
                    else if (currSeparator == orLiteral) {
                        OrToken* orToken = new OrToken(left, right);
                        finalCommandTokens.push_back(orToken);
                    }
                    else if (currSeparator == semiLiteral) {
                        SemiColonToken* semiColonToken = new SemiColonToken(left, right);
                        finalCommandTokens.push_back(semiColonToken);
                    }
                    
                    while (connectors.size() != 0) {
                        CommandToken* leftSide = commandTokens.front();
                        commandTokens.pop_front();
                        
                        CommandToken* rightSide = commandTokens.front();
                        commandTokens.pop_front();
                        
                        char* currSep = connectors.front();
                        connectors.pop_front();
                        
                        if (currSep == andLiteral) {
                            AndToken* andToken = new AndToken(leftSide, rightSide);
                            finalCommandTokens.push_back(andToken);
                        }
                        else if (currSep == orLiteral) {
                            OrToken* orToken = new OrToken(leftSide, rightSide);
                            finalCommandTokens.push_back(orToken);
                        }
                        else if (currSep == semiLiteral) {
                            SemiColonToken* semiColonToken = new SemiColonToken(leftSide, rightSide);
                            finalCommandTokens.push_back(semiColonToken);
                        }
                    }
                }
                else {
                    if (commandTokens.size() == 1) {
                        Token* currentCommand = commandTokens.front();
                        commandTokens.pop_front();
                        finalCommandTokens.push_back(currentCommand);
                    }
                }
            }
        }
        else if (containsPrecedence) {
            precedenceFiltered = true;
            while (currToken != 0) {
                int rightPrecedenceNum = 0;
                
                if (containsLeftPrecedence(currToken)) {
                    while (containsLeftPrecedence(currToken)) {
                        expression += "( ";
                        memmove(currToken, currToken + 1, strlen(currToken));
                    }
                    
                    expression += string(currToken) + " ";
                }
                else if (containsRightPrecedence(currToken)) {
                    while (containsRightPrecedence(currToken)) {
                        rightPrecedenceNum += 1;
                        
                        if (containsComment(currToken) || containsSemiColon(currToken)) {
                            int index = strlen(currToken) - 2;
                            memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                        }
                        else {
                            currToken[strlen(currToken) - 1] = 0;
                        }
                    }
                    
                    if (containsSemiColon(currToken)) {
                        currToken[strlen(currToken) - 1] = 0;
                        expression += string(currToken) + " ";
                        
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                        
                        expression += "; ";
                    }
                    else if (containsComment(currToken)) {
                        currToken[strlen(currToken) - 1] = 0;
                        expression += string(currToken) + " ";
                        
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                        
                        expression += "# ";
                    }
                    else {
                        expression += string(currToken) + " ";
                        for (int i = 0; i < rightPrecedenceNum; i++) {
                            expression += ") ";
                        }
                    }
                }
                else {
                    expression += string(currToken) + " ";
                }
                
                currToken = strtok(NULL, " ");
            }
            
            primitiveInput = new char[expression.size() - 1];
            strcpy(primitiveInput, expression.c_str());
            currToken = strtok(primitiveInput, " ");
            
            deque<char*> cstrings;
            deque<string> separatedCommands;
            
            bool init = false, insideParentheses = false;
            
            while (currToken != 0) {
                if (containsLeftPrecedence(currToken)) {
                    insideParentheses = true;
                    
                    if (!init) {
                        deque<char*> command;
                        
                        while (!cstrings.empty()) {
                            if (containsLeftPrecedence(cstrings.front())) {
                                cstrings.pop_front();
                                break;
                            }
                            
                            command.push_front(cstrings.front());
                            cstrings.pop_front();
                        }
                        
                        string commandString = "";
                        
                        while (!command.empty()) {
                            commandString += command.front();
                            commandString += " ";
                            command.pop_front();
                        }
                        
                        if (commandString.size() != 0) {
                            separatedCommands.push_back(commandString);
                        }
                    }
                    
                    init = true;
                }
                else if (containsRightPrecedence(currToken)) {
                    insideParentheses = false;
                    init = false;
                    deque<char*> command;
                    
                    while (!cstrings.empty()) {
                        if (containsLeftPrecedence(cstrings.front())) {
                            cstrings.pop_front();
                            break;
                        }
                        
                        command.push_front(cstrings.front());
                        cstrings.pop_front();
                    }
                    
                    string commandString = "";
                    
                    while (!command.empty()) {
                        commandString += command.front();
                        commandString += " ";
                        command.pop_front();
                    }
                    
                    if (commandString.size() != 0) {
                        separatedCommands.push_back(commandString);
                    }
                }
                else if ((containsOrAnd(currToken) || containsComment(currToken) || containsSemiColon(currToken)) && !insideParentheses) {
                    outerConnectors.push_back(currToken);
                }
                else {
                    cstrings.push_front(currToken);
                }
                
                currToken = strtok(NULL, " ");
            }
            
            reverse(cstrings.begin(), cstrings.end());
            
            string completedCommand = "";
            while (!cstrings.empty()) {
                completedCommand += cstrings.front();
                completedCommand += " ";
                cstrings.pop_front();
            }
            
            if (completedCommand.size() != 0) {
                separatedCommands.push_back(completedCommand);
            }
            
            for (auto s: separatedCommands) {
                cout << s << endl;
            }
            
            while (separatedCommands.size() != 0) {
                char* topCommand = new char[separatedCommands.front().size() + 1];
                strcpy(topCommand, separatedCommands.front().c_str());
                separatedCommands.pop_front();
                
                currToken = strtok(topCommand, " ");
                
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
                
                if (connectors.size() > 0) {
                    CommandToken* left = commandTokens.front();
                    commandTokens.pop_front();
                    
                    CommandToken* right = commandTokens.front();
                    commandTokens.pop_front();
                    
                    char* currSeparator = connectors.front();
                    connectors.pop_front();
                    
                    if (currSeparator == andLiteral) {
                        AndToken* andToken = new AndToken(left, right);
                        finalCommandTokens.push_back(andToken);
                    }
                    else if (currSeparator == orLiteral) {
                        OrToken* orToken = new OrToken(left, right);
                        finalCommandTokens.push_back(orToken);
                    }
                    else if (currSeparator == semiLiteral) {
                        SemiColonToken* semiColonToken = new SemiColonToken(left, right);
                        finalCommandTokens.push_back(semiColonToken);
                    }
                    
                    while (connectors.size() != 0) {
                        CommandToken* leftSide = commandTokens.front();
                        commandTokens.pop_front();
                        
                        CommandToken* rightSide = commandTokens.front();
                        commandTokens.pop_front();
                        
                        char* currSep = connectors.front();
                        connectors.pop_front();
                        
                        if (currSep == andLiteral) {
                            AndToken* andToken = new AndToken(leftSide, rightSide);
                            finalCommandTokens.push_back(andToken);
                        }
                        else if (currSep == orLiteral) {
                            OrToken* orToken = new OrToken(leftSide, rightSide);
                            finalCommandTokens.push_back(orToken);
                        }
                        else if (currSep == semiLiteral) {
                            SemiColonToken* semiColonToken = new SemiColonToken(leftSide, rightSide);
                            finalCommandTokens.push_back(semiColonToken);
                        }
                    }
                }
                else {
                    if (commandTokens.size() == 1) {
                        Token* currentCommand = commandTokens.front();
                        commandTokens.pop_front();
                        finalCommandTokens.push_back(currentCommand);
                    }
                }
            }
        }
        else if (containsBracket) {
            precedenceFiltered = true;
            while (currToken != 0) {
                if (containsLeftBracket(currToken) && containsRightBracket(currToken)) {
                    memmove(currToken, currToken + 1, strlen(currToken));
                    
                    if (containsComment(currToken) || containsSemiColon(currToken)) {
                        int index = strlen(currToken) - 2;
                        memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                    }
                    else {
                        currToken[strlen(currToken) - 1] = 0;
                    }
                    
                    expression += "[ " + string(currToken) + " ] ";
                }
                else if (containsLeftBracket(currToken)) {
                    memmove(currToken, currToken + 1, strlen(currToken));
                    expression += "[ " + string(currToken) + " ";
                }
                else if (containsRightBracket(currToken)) {
                    if (containsComment(currToken) || containsSemiColon(currToken)) {
                        int index = strlen(currToken) - 2;
                        memmove(&currToken[index], &currToken[index + 1], strlen(currToken) - index);
                    }
                    else {
                        currToken[strlen(currToken) - 1] = 0;
                    }
                    
                    expression += string(currToken) + " ] ";
                }
                else {
                    expression += string(currToken) + " ";
                }
                
                currToken = strtok(NULL, " ");
            }
            
            primitiveInput = new char[expression.size() - 1];
            strcpy(primitiveInput, expression.c_str());
            currToken = strtok(primitiveInput, " ");
            
            bool firstTokenIsSemiColon = false;

            if (containsSemiColon(currToken)) {
                currToken[strlen(currToken) - 1] = 0;
                string semicolon = ";";
                char* semicolonArray = new char[2];
                strcpy(semicolonArray, semicolon.c_str());
                connectors.push_back(semicolonArray);
                firstTokenIsSemiColon = true;
            }
            
            if (containsLeftBracket(currToken)) {
                string testString = "test";
                char* testToken = new char[testString.size() + 1];
                strcpy(testToken, testString.c_str());
                
                CommandToken* currCommand = new CommandToken(testToken);
                
                char* nextToken = currToken;
                nextToken = strtok(NULL, " ");
                
                if (containsDash(nextToken)) {
                    currCommand->addArgument(nextToken);
                    
                    nextToken = strtok(NULL, " ");
                    currCommand->addArgument(nextToken);
                    
                    nextToken = strtok(NULL, " ");
                }
                else {
                    currCommand->addArgument(nextToken);
                    nextToken = strtok(NULL, " ");
                }
                
                commandTokens.push_back(currCommand);
                nextToken = strtok(NULL, " ");
                
                if (nextToken != 0) {
                    if (containsSemiColon(nextToken) || containsOrAnd(nextToken)) {
                        connectors.push_back(nextToken);
                        nextToken = strtok(NULL, " ");
                    }
                }
                
                currToken = nextToken;
            }

            if (currToken != 0 && !containsComment(currToken)) {
                while (currToken != 0 && !containsComment(currToken)) {
                    if (containsLeftBracket(currToken)) {
                        string testString = "test";
                        char* testToken = new char[testString.size() + 1];
                        strcpy(testToken, testString.c_str());
                        
                        CommandToken* currCommand = new CommandToken(testToken);
                        
                        char* nextToken = currToken;
                        nextToken = strtok(NULL, " ");
                        
                        if (containsDash(nextToken)) {
                            currCommand->addArgument(nextToken);
                            
                            nextToken = strtok(NULL, " ");
                            currCommand->addArgument(nextToken);
                            
                            nextToken = strtok(NULL, " ");
                        }
                        else {
                            currCommand->addArgument(nextToken);
                            nextToken = strtok(NULL, " ");
                        }
                        
                        commandTokens.push_back(currCommand);
                        nextToken = strtok(NULL, " ");
                        
                        if (nextToken != 0) {
                            if (containsSemiColon(nextToken) || containsOrAnd(nextToken)) {
                                connectors.push_back(nextToken);
                                nextToken = strtok(NULL, " ");
                            }
                        }
                        
                        currToken = nextToken;
                    }
                    
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
            
            if (connectors.size() > 0) {
                CommandToken* left = commandTokens.front();
                commandTokens.pop_front();
                
                CommandToken* right = commandTokens.front();
                commandTokens.pop_front();
                
                char* currSeparator = connectors.front();
                connectors.pop_front();
                
                if (currSeparator == andLiteral) {
                    AndToken* andToken = new AndToken(left, right);
                    finalCommandTokens.push_back(andToken);
                }
                else if (currSeparator == orLiteral) {
                    OrToken* orToken = new OrToken(left, right);
                    finalCommandTokens.push_back(orToken);
                }
                else if (currSeparator == semiLiteral) {
                    SemiColonToken* semiColonToken = new SemiColonToken(left, right);
                    finalCommandTokens.push_back(semiColonToken);
                }
                
                while (connectors.size() != 0) {
                    CommandToken* leftSide = commandTokens.front();
                    commandTokens.pop_front();
                    
                    CommandToken* rightSide = commandTokens.front();
                    commandTokens.pop_front();
                    
                    char* currSep = connectors.front();
                    connectors.pop_front();
                    
                    if (currSep == andLiteral) {
                        AndToken* andToken = new AndToken(leftSide, rightSide);
                        finalCommandTokens.push_back(andToken);
                    }
                    else if (currSep == orLiteral) {
                        OrToken* orToken = new OrToken(leftSide, rightSide);
                        finalCommandTokens.push_back(orToken);
                    }
                    else if (currSep == semiLiteral) {
                        SemiColonToken* semiColonToken = new SemiColonToken(leftSide, rightSide);
                        finalCommandTokens.push_back(semiColonToken);
                    }
                }
            }
            else {
                if (commandTokens.size() == 1) {
                    Token* currentCommand = commandTokens.front();
                    commandTokens.pop_front();
                    finalCommandTokens.push_back(currentCommand);
                }
            }
        }
        else {
            precedenceFiltered = false;
            bool firstTokenIsSemiColon = false;

            if (containsSemiColon(currToken)) {
                currToken[strlen(currToken) - 1] = 0;
                string semicolon = ";";
                char* semicolonArray = new char[2];
                strcpy(semicolonArray, semicolon.c_str());
                outerConnectors.push_back(semicolonArray);
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
                                        outerConnectors.push_back(semicolonArray2);
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
                                    outerConnectors.push_back(nextToken);
                                    break;
                                }
                            }
                            nextToken = strtok(NULL, " ");
                        }
                        currToken = nextToken;
                        currToken = strtok(NULL, " ");

                        if (currCommand->getName() == "exit") {
                            ExitToken* exitToken = new ExitToken();
                            finalCommandTokens.push_back(exitToken);
                        }
                        else {
                            finalCommandTokens.push_back(currCommand);
                        }
                    }
                    else {
                        finalCommandTokens.push_back(currCommand);
                        currToken = nextToken;
                        currToken = strtok(NULL, " ");
                        firstTokenIsSemiColon = false;
                    }
                }
            }
        }
    }
}

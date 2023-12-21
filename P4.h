#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <set>

struct Variable {
    std::string name;
    std::string value;
};

struct Token {
    std::string type;
    std::string value;
};

struct TreeNode {
    std::string value;
    std::string variableValue;
    int variableCount;
    int lineNumber;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(std::string val, std::string varVal = "", int count = 0, int line = 0)
            : value(std::move(val)), variableValue(std::move(varVal)), variableCount(count), lineNumber(line), left(nullptr), right(nullptr) {}

    TreeNode *extra;

    //void generateCode(std::ostream& os, const std::vector<Token>& tokens);
};

std::vector<Token> lexer(const std::string& input);
void generateCodePreorder(TreeNode* root, std::ofstream& outputFile);
void generateBlockCode(TreeNode* root);
void generateVarListCode(TreeNode* root);
void printGlobalVariables(std::ofstream& outputFile);

TreeNode* program(const std::vector<Token>& tokens);
TreeNode* vars(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* varList(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* exp(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* M(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* N(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* R(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* stats(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* mStat(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* stat(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* block(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* in(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* out(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* ifStatement(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* loop(const std::vector<Token>& tokens, int& variableCount, int& lineNumber, std::set<std::string>& declaredVariables);
TreeNode* assign(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);
TreeNode* RO(const std::vector<Token>& tokens, int& variableCount, int& lineNumber);


#endif // PARSER_H

#ifndef Evaluate_H
#define Evaluate_H
#include "Token.h"
#include "Stack.h"

typedef struct {
	char* operator;
	int (*callback)(int, int);
} EvaluateEntry;

int evaluate(char *expression);
void tryEvaluateOperatorsOnStackThenPush(Stack *dataStack, Stack *operatorStack, OperatorToken *operator);
void evaluateAllOperatorsOnStack(Stack *dataStack, Stack *operatorStack);
void evaluateOperator(Stack *dataStack, OperatorToken *operator);

int multiply(int value1, int value2);
int divide(int value1, int value2);
int modulo(int value1, int value2);
int plus(int value1, int value2);
int minus(int value1, int value2);
int xor(int value1, int value2);
int and(int value1, int value2);
int or(int value1, int value2);

#endif // Evaluate_H

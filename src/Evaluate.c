#include "Evaluate.h"
#include "Token.h"
#include "Stack.h"
#include "Error.h"
#include <stdio.h>
#include <string.h>

EvaluateEntry evaluateTable[] = {	{.operator = "*", .callback = multiply},
									{.operator = "/", .callback = divide},
									{.operator = "%", .callback = modulo},
									{.operator = "+", .callback = plus},
									{.operator = "-", .callback = minus},
									{.operator = "^", .callback = xor},
									{.operator = "&", .callback = and},
									{.operator = "|", .callback = or}};

int evaluate(char *expression) {
	
}

void tryEvaluateOperatorsOnStackThenPush(Stack *dataStack, Stack *operatorStack, OperatorToken *operator) {
	
}

void evaluateAllOperatorsOnStack(Stack *dataStack, Stack *operatorStack) {
	OperatorToken *operator;
	
	while((operator = pop(operatorStack)) != NULL) {
		evaluateOperator(dataStack, operator);
	}
}

void evaluateOperator(Stack *dataStack, OperatorToken *operator) {
	NumberToken *numberToken1;
	NumberToken *numberToken2;
	NumberToken *resultToken;
	int result, i;
	
	numberToken2 = pop(dataStack);
	numberToken1 = pop(dataStack);
	
	for(i = 0; i < 8; i++) {
		if(strcmp(evaluateTable[i].operator, operator->name) == 0) {
			result = evaluateTable[i].callback(numberToken1->value, numberToken2->value);
		}
	}
		
	resultToken = createNumberToken(result);
	
	push(dataStack, resultToken);
	
}

int multiply(int value1, int value2) {return value1 * value2;}
int divide(int value1, int value2) {return value1 / value2;}
int modulo(int value1, int value2) {return value1 % value2;}
int plus(int value1, int value2) {return value1 + value2;}
int minus(int value1, int value2) {return value1 - value2;}
int xor(int value1, int value2) {return value1 ^ value2;}
int and(int value1, int value2) {return value1 & value2;}
int or(int value1, int value2) {return value1 | value2;}
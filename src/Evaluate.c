#include "Evaluate.h"
#include "Token.h"
#include "Stack.h"
#include "Error.h"
#include "CException.h"
#include <stdio.h>
#include <string.h>

ErrorCode e;

EvaluateEntry evaluateTable[] = {	{.operator = "*", .callback = multiply},
									{.operator = "/", .callback = divide},
									{.operator = "%", .callback = modulo},
									{.operator = "+", .callback = plus},
									{.operator = "-", .callback = minus},
									{.operator = "^", .callback = xor},
									{.operator = "&", .callback = and},
									{.operator = "|", .callback = or}};

int evaluate(char *expression) {
	Stack *dataStack, *operatorStack;
	dataStack = stackNew();
	operatorStack = stackNew();
	Tokenizer *tokenizer = tokenizerNew(expression);
	Token *token;
	
	NumberToken *result;
	int i;
	
	for(i = 0; i < 3 || token == NULL; i++) {
		token = nextToken(tokenizer);
		if(i % 2 == 0) {
			if(token->type == NUMBER_TOKEN) {
				push(dataStack, (NumberToken *)token);
			} else {
				Throw(ERR_NOT_DATA);
			}
		} else {
			if(token->type == OPERATOR_TOKEN) {
				push(operatorStack, (OperatorToken *)token);
			} else {
				Throw(ERR_NOT_OPERATOR);
			}
		}
	}
	
	token = nextToken(tokenizer);
	if(token == NULL) {
		evaluateAllOperatorsOnStack(dataStack, operatorStack);
	} else {
		if(token->type != OPERATOR_TOKEN)
			Throw(ERR_NOT_OPERATOR);
	
		tryEvaluateOperatorsOnStackThenPush(dataStack, operatorStack, (OperatorToken *)token);
		
		token = nextToken(tokenizer);
		if(token != NULL) {
			if(token->type == NUMBER_TOKEN) {
				push(dataStack, (NumberToken *)token);
			} else {
				Throw(ERR_NOT_DATA);
			}
		} else {
			Throw(ERR_INVALID_EXPRESSION);
		}
	}
	
	result = pop(dataStack);
	
	return result->value;
}

void tryEvaluateOperatorsOnStackThenPush(Stack *dataStack, Stack *operatorStack, OperatorToken *operator) {
	OperatorToken *operatorAtTos;
	int firstTime = 1;
	
	while((operatorAtTos = pop(operatorStack)) != NULL) {
		if(operator->precedence > operatorAtTos->precedence) {
			if(firstTime)
				push(operatorStack, operatorAtTos);
			break;
		} else {
			evaluateOperator(dataStack, operatorAtTos);
			firstTime = 0;
		}
	}

	push(operatorStack, operator);	
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
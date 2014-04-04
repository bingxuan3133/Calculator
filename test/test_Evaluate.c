#include "unity.h"
#include "Evaluate.h"
#include "mock_Token.h"
#include "mock_Stack.h"
#include "Error.h"
#include <stdio.h>

void setUp(void) {}

void tearDown(void) {}

void test_multiply_should_multiply_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(35, multiply(5,7));
}

void test_divide_should_return_quotient_of_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(5, divide(40, 8));
}

void test_modulo_should_modulo_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(1, modulo(3, 2));
}

void test_plus_should_plus_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(5, plus(2, 3));
}

void test_minus_should_return_different_of_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(5, minus(8, 3));
}

void test_xor_should_return_different_of_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(1, xor(1, 0));
}

void test_and_should_return_different_of_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(1, and(1, 1));
}

void test_or_should_return_different_of_two_values_correctly(void) {
	TEST_ASSERT_EQUAL(1, or(1, 0));
}

void test_evaluateOperator_given_3_multiply_7_should_return_21(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 21};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(21, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_7_divide_3_should_return_2(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "/", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 2};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(2, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_7_modulo_3_should_return_1(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "%", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 1};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(1, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_3_plus_7_should_return_10(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 10};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(10, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_3_minus_7_should_return_negative_4(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "-", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = -4};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(-4, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_3_xor_with_7_should_return_4(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 4};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(4, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_3_and_with_7_should_return_3(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 3};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(3, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateOperator_given_3_or_with_7_should_return_7(void) {
	Stack dataStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 7};
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	
	createNumberToken_ExpectAndReturn(7, &number3);
	
	push_Expect(&dataStack, &number3);
	
	evaluateOperator(&dataStack, &operator);
}

void test_evaluateAllOperatorsOnStack_3_7_in_data_stack_then_plus_in_operator_stack(void) { // 3 + 7
	Stack dataStack, operatorStack;
	OperatorToken operator = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 10};
	
	pop_ExpectAndReturn(&operatorStack, &operator);
	
	pop_ExpectAndReturn(&dataStack, &number2);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(10, &number3);
	push_Expect(&dataStack, &number3);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluateAllOperatorsOnStack(&dataStack, &operatorStack);
}

void test_evaluateAllOperatorsOnStack_3_7_2_in_data_stack_then_plus_multiply_in_operator_stack(void) { // 3 + 7 * 2
	Stack dataStack, operatorStack;
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};
	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 7};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken subResult = {.type = NUMBER_TOKEN, .value = 14};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 17};
	
	pop_ExpectAndReturn(&operatorStack, &operator2);
	
	pop_ExpectAndReturn(&dataStack, &number3);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(14, &subResult);
	push_Expect(&dataStack, &subResult);
	
	pop_ExpectAndReturn(&operatorStack, &operator1);
	
	pop_ExpectAndReturn(&dataStack, &subResult);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(17, &result);
	push_Expect(&dataStack, &result);
	
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluateAllOperatorsOnStack(&dataStack, &operatorStack);
}

void test_evaluateAllOperatorsOnStack_1_2_3_4_5_6_in_data_stack_then_or_and_xor_plus_multiply_in_operator_stack(void) { // 1 | 2 & 3 ^ 4 + 5 * 6
	Stack dataStack, operatorStack;
	OperatorToken operator1 = {.type = OPERATOR_TOKEN, .name = "|", .precedence = 10};
	OperatorToken operator2 = {.type = OPERATOR_TOKEN, .name = "&", .precedence = 20};
	OperatorToken operator3 = {.type = OPERATOR_TOKEN, .name = "^", .precedence = 50};
	OperatorToken operator4 = {.type = OPERATOR_TOKEN, .name = "+", .precedence = 70};
	OperatorToken operator5 = {.type = OPERATOR_TOKEN, .name = "*", .precedence = 100};

	NumberToken number1 = {.type = NUMBER_TOKEN, .value = 1};
	NumberToken number2 = {.type = NUMBER_TOKEN, .value = 2};
	NumberToken number3 = {.type = NUMBER_TOKEN, .value = 3};
	NumberToken number4 = {.type = NUMBER_TOKEN, .value = 4};
	NumberToken number5 = {.type = NUMBER_TOKEN, .value = 5};
	NumberToken number6 = {.type = NUMBER_TOKEN, .value = 6};
	NumberToken subResult1 = {.type = NUMBER_TOKEN, .value = 30};
	NumberToken subResult2 = {.type = NUMBER_TOKEN, .value = 34};
	NumberToken subResult3 = {.type = NUMBER_TOKEN, .value = 33};
	NumberToken subResult4 = {.type = NUMBER_TOKEN, .value = 0};
	NumberToken result = {.type = NUMBER_TOKEN, .value = 1};
	
	// 5 * 6
	pop_ExpectAndReturn(&operatorStack, &operator5);
	
	pop_ExpectAndReturn(&dataStack, &number6);
	pop_ExpectAndReturn(&dataStack, &number5);
	createNumberToken_ExpectAndReturn(30, &subResult1);
	push_Expect(&dataStack, &subResult1);
	
	// 4 + 30
	pop_ExpectAndReturn(&operatorStack, &operator4);
	
	pop_ExpectAndReturn(&dataStack, &subResult1);
	pop_ExpectAndReturn(&dataStack, &number4);
	createNumberToken_ExpectAndReturn(34, &subResult2);
	push_Expect(&dataStack, &subResult2);
	
	// 3 ^ 34
	pop_ExpectAndReturn(&operatorStack, &operator3);
	
	pop_ExpectAndReturn(&dataStack, &subResult2);
	pop_ExpectAndReturn(&dataStack, &number3);
	createNumberToken_ExpectAndReturn(33, &subResult3);
	push_Expect(&dataStack, &subResult3);
	
	// 2 & 33
	pop_ExpectAndReturn(&operatorStack, &operator2);
	
	pop_ExpectAndReturn(&dataStack, &subResult3);
	pop_ExpectAndReturn(&dataStack, &number2);
	createNumberToken_ExpectAndReturn(0, &subResult4);
	push_Expect(&dataStack, &subResult4);
	
	// 1 | 0
	pop_ExpectAndReturn(&operatorStack, &operator1);
	
	pop_ExpectAndReturn(&dataStack, &subResult4);
	pop_ExpectAndReturn(&dataStack, &number1);
	createNumberToken_ExpectAndReturn(1, &result);
	push_Expect(&dataStack, &result);
	
	// end
	pop_ExpectAndReturn(&operatorStack, NULL);
	
	evaluateAllOperatorsOnStack(&dataStack, &operatorStack);
}














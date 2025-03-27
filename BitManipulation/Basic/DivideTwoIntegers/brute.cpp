int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.
	int sum = 0 , count = 0;
	while(sum + divisor <= dividend){
		count++;
		sum += divisor;
	}
	return count;
} 


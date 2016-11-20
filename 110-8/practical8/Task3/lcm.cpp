int gcd(int, int);

int lcm(int *numbers, int length)
{
	switch(length) {
		// Return 0 if empty list;
		case 0:
		{
			return 0;
			break;
		}
		// Return the number is list has one member
		case 1:
		{
			return numbers[0];
			break;
		}
		// Find LCM of two
		case 2:
		{
			int t = numbers[0] * numbers[1];
			
			if( t < 0 )
				t *= -1;
			
			return t / gcd( numbers[0], numbers[1]);
			break;
		}
		// lcm(a, b, c) == lcm(a, lcm(b, c) )
		default:
		{
			int reducedNums[2] = {numbers[0], lcm(numbers+1, length-1) };
			
			return lcm(reducedNums, 2);
			break;
		}
	}
}

int gcd(int a, int b)
{
	if( b == 0 ) {
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}
// Source : https://oj.leetcode.com/problems/maximum-product-subarray/
// Author : zheng yi xiong 
// Date   : 2014-11-5

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) which has the largest product.

* For example, given the array [2,3,-2,4],
* the contiguous subarray [2,3] has the largest product = 6.
*               
**********************************************************************************/

class Solution {
public:
	int maxProduct(int A[], int n) {
		int positiveProductFirst = 0, positiveProductLast = 0, midProduct = 1;	
		//positiveProductFirst: positive product before first negative number
		//positiveProductLast: positive product after last negative number
		//midProduct: the product except positiveProductFirst positiveProductLast and negativeFirst negativeLast
		int negativeFirst = 0, negativeLast = 0;	//first negative number and last one
		int max_product = 0x80000000;				//min int
		int i = 0;
		while( (i < n) && (0 == A[i])) ++i;
		if (i >= n)
		{
			return 0;
		}

		for (; i < n; ++i)
		{
			if (0 == A[i])
			{
				if (0 == negativeLast)
				{
					if (0 != negativeFirst)
					{
						if (positiveProductLast > positiveProductFirst)
						{
							positiveProductFirst = positiveProductLast;
						}
						else if (0 == positiveProductFirst)
						{
							positiveProductFirst = negativeFirst;
						}
					}
				}
				else
				{
					positiveProductFirst = (0 == positiveProductFirst) ? 1 : positiveProductFirst;
					positiveProductLast = (0 == positiveProductLast) ? 1 : positiveProductLast;
					if (0 < midProduct)
					{
						positiveProductFirst *= midProduct * negativeFirst * negativeLast * positiveProductLast;
					}
					else
					{
						if ( (positiveProductFirst * negativeFirst) < (negativeLast * positiveProductLast) )
						{
							positiveProductFirst *= negativeFirst * midProduct;
						}
						else
						{
							positiveProductFirst = positiveProductLast * negativeLast * midProduct;
						}
					}
				}

				if (max_product < positiveProductFirst)
				{
					max_product = positiveProductFirst;
				}
				positiveProductFirst = 0;
				positiveProductLast = 0;
				negativeFirst = 0;
				negativeLast = 0;
				midProduct = 1;
				if (0 > max_product)
				{
					max_product = 0;
				}
				while( (i + 1 < n) && (0 == A[i + 1])) ++i;
			}
			else if (0 > A[i])
			{
				if (0 == negativeFirst)
				{
					negativeFirst = A[i];
				}
				else
				{
					if (0 != positiveProductLast)
					{
						midProduct *= positiveProductLast;
					}

					if (0 != negativeLast)
					{
						midProduct *= negativeLast;
					}

					positiveProductLast = 0;
					negativeLast = A[i];
				}
			}
			else
			{
				if (0 == negativeFirst)
				{
					if (0 == positiveProductFirst)
					{
						positiveProductFirst = A[i];
					}
					else
					{
						positiveProductFirst *= A[i];
					}
				}
				else
				{
					if (0 == positiveProductLast)
					{
						positiveProductLast = A[i];
					}
					else
					{
						positiveProductLast *= A[i];
					}
				}
			}
		}

		if (0 != A[n-1])
		{
			if (0 == negativeLast)
			{
				if (0 != negativeFirst)
				{
					if (positiveProductLast > positiveProductFirst)
					{
						positiveProductFirst = positiveProductLast;
					}
					else if (0 == positiveProductFirst)
					{
						positiveProductFirst = negativeFirst;
					}
				}
			}
			else
			{
				positiveProductFirst = (0 == positiveProductFirst) ? 1 : positiveProductFirst;
				positiveProductLast = (0 == positiveProductLast) ? 1 : positiveProductLast;
				if (0 < midProduct)
				{
					positiveProductFirst *= midProduct * negativeFirst * negativeLast * positiveProductLast;
				}
				else
				{
					if ( (positiveProductFirst * negativeFirst) < (negativeLast * positiveProductLast) )
					{
						positiveProductFirst *= negativeFirst * midProduct;
					}
					else
					{
						positiveProductFirst = positiveProductLast * negativeLast * midProduct;
					}
				}
			}

			if (max_product < positiveProductFirst)
			{
				max_product = positiveProductFirst;
			}
		}

		return max_product;
	}
};
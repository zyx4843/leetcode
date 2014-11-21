// Source : https://oj.leetcode.com/problems/min-stack/
// Author : zheng yi xiong 
// Date   : 2014-11-18

/********************************************************************************** 
* 
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
*               
**********************************************************************************/

class MinStack {
    #define MAX_DATA 32
public:
    MinStack(void)
    {
    	m_pVecNode		= NULL;
		m_nodeIndex		= MAX_DATA - 1;
		m_pVecOrder		= NULL;
		m_orderIndex	= MAX_DATA - 1;
    }

    ~MinStack(void)
    {
    	STACK_NODE		*tempNode = 0;
		while (NULL != m_pVecNode)
		{
			tempNode = m_pVecNode;
			m_pVecNode = m_pVecNode->pNext;
			delete tempNode;
		}

		MIN_NODE		*tempOrder = 0;
		while (NULL != m_pVecOrder)
		{
			tempOrder = m_pVecOrder;
			m_pVecOrder = m_pVecOrder->pNext;
			delete tempOrder;
		}
    }
    
    void push(int x) {
        if (MAX_DATA - 1 <= m_nodeIndex)
		{
			STACK_NODE	*tempNode = new STACK_NODE;
			tempNode->pNext = m_pVecNode;
			m_pVecNode = tempNode;
			m_nodeIndex = -1;
		}

		m_pVecNode->data[++m_nodeIndex] = x;

		if (NULL != m_pVecOrder)
		{
			if (x == m_pVecOrder->data[m_orderIndex])
			{
				++m_pVecOrder->count[m_orderIndex];
			}
			else if (x < m_pVecOrder->data[m_orderIndex])
			{
				if (MAX_DATA - 1 <= m_nodeIndex)
				{
					m_orderIndex = 0;
					MIN_NODE	*tempMin = new MIN_NODE;
					tempMin->pNext = m_pVecOrder;
					m_pVecOrder = tempMin;
					m_pVecOrder->data[0] = x;
					m_pVecOrder->count[0] = 1;
				}
				else
				{
					m_pVecOrder->data[++m_orderIndex] = x;
					m_pVecOrder->count[m_orderIndex] = 1;
				}
			}
		}
		else
		{
			m_orderIndex = 0;
			m_pVecOrder = new MIN_NODE;
			m_pVecOrder->pNext = NULL;
			m_pVecOrder->data[0] = x;
			m_pVecOrder->count[0] = 1;
		}
    }

    void pop() {
        if (NULL != m_pVecNode)
		{
			int x = m_pVecNode->data[m_nodeIndex];
			if (0 >= m_nodeIndex)
			{
				STACK_NODE	*tempNode = m_pVecNode;
				m_pVecNode = m_pVecNode->pNext;
				delete tempNode;
				m_nodeIndex = MAX_DATA - 1;
			}
			else
			{
				--m_nodeIndex;
			}

			if (x == m_pVecOrder->data[m_orderIndex])
			{
				if (1 >= m_pVecOrder->count[m_orderIndex])
				{
					if (0 >= m_orderIndex)
					{
						MIN_NODE	*tempMin = m_pVecOrder;
						m_pVecOrder = m_pVecOrder->pNext;
						delete tempMin;
						m_orderIndex = MAX_DATA - 1;
					}
					else
					{
						--m_orderIndex;
					}
				}
				else
				{
					--m_pVecOrder->count[m_orderIndex];
				}
			}
		}
    }

    int top() {
    	if (NULL != m_pVecNode)
		{
			return m_pVecNode->data[m_nodeIndex];
		}
		else
		{
			return 0;
		}
    }

    int getMin() {
        if (NULL != m_pVecOrder)
		{
			return m_pVecOrder->data[m_orderIndex];
		}
		else
		{
			return 0;
		}
    }
private:
	typedef struct _stack_node_
	{
		int			data[MAX_DATA];
		struct _stack_node_ *pNext;
	}STACK_NODE;

	typedef struct _min_node_
	{
		int			data[MAX_DATA];
		int			count[MAX_DATA];
		struct _min_node_ *pNext;
	}MIN_NODE;

	STACK_NODE		*m_pVecNode;	//stack data list
	int				m_nodeIndex;	//index in MAX_DATA

	MIN_NODE		*m_pVecOrder;	//ordr list
	int				m_orderIndex;
};
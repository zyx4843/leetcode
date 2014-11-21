// Source : https://oj.leetcode.com/problems/lru-cache/
// Author : zheng yi xiong 
// Date   : 2014-11-21

/********************************************************************************** 
* 
* Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

* get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
* set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*               
**********************************************************************************/

class LRUCache{
private:
	typedef struct _cache_node_
	{
		int value;
		int useCnt;		//used count 
	}CACHE_NODE;

	std::map<int, CACHE_NODE>	m_cacheMap;
	std::queue<int>				m_queueUse;	//use key queue

	int							m_capacity;
	int							m_mapSize;
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
		m_mapSize = 0;
	}

	int get(int key) {
		if (m_cacheMap.find(key) != m_cacheMap.end())
		{
			++m_cacheMap[key].useCnt;
			m_queueUse.push(key);
			return m_cacheMap[key].value;
		}
		else
		{
			return -1;
		}
	}

	void set(int key, int value) {
		if (m_cacheMap.find(key) != m_cacheMap.end())
		{
			m_cacheMap[key].value = value;
			++m_cacheMap[key].useCnt;
		}
		else
		{
			if (m_mapSize < m_capacity)
			{
				m_cacheMap[key].value = value;
				m_cacheMap[key].useCnt = 1;
				++m_mapSize;
			}
			else
			{
				int earseKey = m_queueUse.front();
				m_queueUse.pop();
				--m_cacheMap[earseKey].useCnt;
				while (0 != m_cacheMap[earseKey].useCnt)
				{
					earseKey = m_queueUse.front();
					m_queueUse.pop();
					--m_cacheMap[earseKey].useCnt;
				}

				m_cacheMap.erase(m_cacheMap.find(earseKey));
				m_cacheMap[key].value = value;
				m_cacheMap[key].useCnt = 1;
			}
		}

		m_queueUse.push(key);
	}
};
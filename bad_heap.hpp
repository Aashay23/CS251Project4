#ifndef CS251_HEAP_HPP
#define CS251_HEAP_HPP

#include <bits/stl_pair.h>
#include <stdexcept>
#include <functional>
#include <exception>

template<typename Key, typename Value, typename Comp=std::less<Key> >
class Heap {
public:
	typedef Key                               key_type;
	typedef Value                             value_type;
	typedef std::pair<key_type, value_type>   node_type;
	typedef Comp                              comp_type;
		
	Heap() {
		counter = 0;
		length = 1;
		index = 1;
		size = 0;
		pq = new node_type[length];
		// ADD CODE HERE; Create an array implementation of a binary heap to store the sparsevectors.
	}
	
    ~Heap() {
    		delete [] pq;
    		pq = NULL;
		// ADD CODE HERE; "Delete" the created array, freeing memory.
	}
	
	void push(const key_type& k, const value_type& v) {
		size = sizeof(pq)/sizeof(pq[1]);
		if(size == length){
			resize(2*size);
		}
		pq[index++] = node_type(k,v);
		swim(index-1);
		// ADD CODE HERE; Add onto heap.
	}
	
	node_type pop() {
		size = sizeof(pq)/sizeof(pq[1]);
			if(size == 0){
			std::cout << "check" << std::endl;
				throw "heap fucked up";
			}else{
				exch(1, index);
				return pq[index];
				
			}
	}
	
	const node_type* find(const key_type& k) const {
		// ADD CODE HERE; Binary Search.
	}
	
    size_t getNumberOfOperations() const {
		// ADD CODE HERE; Increment counter for number of comparisions performed.
	}
	
    size_t getHeight() const {
		// ADD CODE HERE
	}
	
    size_t getSize() const {
		// ADD CODE HERE
	}

private:
    node_type* pq;
    int counter;
    int length;
    int index;
    int size;
    comp_type _less;

    void resize(int l){
					node_type* newarr = new node_type[l];
					memcpy(newarr, pq, sizeof(int));					
					delete [] pq;
					pq = NULL;
					pq = newarr;
					//length = l;
					//delete [] newarr;
    }
    void exch(int one, int two){
    	node_type temp = pq[one];
    	pq[one] = pq[two];
    	pq[two] = temp;
    }
    void swim(int k){
    	while(k>1 && _less(pq[k/2].first, pq[k].first)){
    		counter++;
    		exch(k/2, k);
    		k = k/2;
    	}
    }
};

#endif // CS251_HEAP_HPP

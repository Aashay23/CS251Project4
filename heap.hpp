#ifndef CS251_HEAP_HPP
#define CS251_HEAP_HPP
#ifndef NULL
#define NULL 0
#endif
#include <bits/stl_pair.h>
#include <stdexcept>
#include <functional>
#include <exception>
#include <cstddef>

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
		height = 0;
		pq = new node_type[length];
		// ADD CODE HERE; Create an array implementation of a binary heap to store the sparsevectors.
	}
	
    ~Heap() {
    		delete [] pq;
		// ADD CODE HERE; "Delete" the created array, freeing memory.
	}
	
	void push(const key_type& k, const value_type& v) {
		if(index == length){
			resize(2*length);
		}
	 height = index;
		pq[index++] = node_type(k,v);
		size++;
		swim(height);
		// ADD CODE HERE; Add onto heap.
	}
	
	node_type pop() {
			if(height == 0){
				throw "heap fucked up";
			}else{
				exch(1, height);
				node_type temp = pq[height];
				index--;
				height--;
				size--;
				sink(1, height);
				return temp;
			}
	}
	
	const node_type* find(const key_type& k) const {
		node_type* found;
		for(int q=0;q<length;q++){
			if(pq[q].first == k){
				found = &pq[q];
				return found;
			}
		}
		
		// ADD CODE HERE
	}
	
    size_t getNumberOfOperations() const {
    	return counter;
		// ADD CODE HERE; Increment counter for number of comparisions performed.
	}
	
    size_t getHeight() const {
    	if(height == 0){
    		return 0;
    	}else{
    		return log2(height);
    	}
		// ADD CODE HERE
	}
	
    size_t getSize() const {
    	return size;
		// ADD CODE HERE
	}

private:
    node_type* pq;
    int counter;
    int length;
    int index;
    int size;
    int height;
    comp_type _lessthan;

    void resize(int l){
					node_type* newarr = new node_type[l];
					for(int i=1;i<length;i++){
						newarr[i] = pq[i];
					}				
					delete [] pq;
					pq = NULL;
					pq = newarr;
					length = l;
    }
    void exch(int one, int two){
    	node_type temp = pq[one];
    	pq[one] = pq[two];
    	pq[two] = temp;
    }
    void swim(int k){
    	while(k>1 && _lessthan(pq[k/2].first, pq[k].first)){
    		counter++;
    		exch(k/2, k);
    		k = k/2;
    	}
    }
    void sink(int k, int N){
    	int j;
    	while(2*k <= N){
    		j = 2*k;
    		if(j < N && _lessthan(pq[j].first, pq[j+1].first)){
    			counter++;
    			j++;
    		}
    		if(!(_lessthan(pq[k].first, pq[j].first))){
    			counter++;
    			break;
    		}
    		exch(k, j);
    		k = j;
    	}
    }
};

#endif // CS251_HEAP_HPP

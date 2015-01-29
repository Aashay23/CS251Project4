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
		//std::cout << "incoming: " << k << ", " << v << std::endl;
		//size = sizeof(pq)/sizeof(pq[1]);
		if(index == length){
			resize(2*length);
		}
	 height = index;
		//std::cout << "index:" << index << "l:" << length << std::endl;
		pq[index++] = node_type(k,v);
		//std::cout << "t:" << t << "index:" << index << std::endl;
		size++;
		swim(height);
		// ADD CODE HERE; Add onto heap.
	}
	
	node_type pop() {
		//std::cout << "here here" << std::endl;
		//size = sizeof(pq)/sizeof(pq[1]);
			if(height == 0){
			//std::cout << "ha ha" << std::endl;
				throw "heap fucked up";
			}else{
				//std::cout << "1" << pq[1] << "index: " << t << pq[t] << std::endl;
				exch(1, height);
				node_type temp = pq[height];
				//delete &pq[index].first;
				//delete &pq[index].second;
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
			}//else{
				//throw "NullpointerException.";
			//}
		}
		
		// ADD CODE HERE; Binary Search.
	}
	
    size_t getNumberOfOperations() const {
    	//std::cout << "counter: " << counter << std::endl;
    	return counter;
		// ADD CODE HERE; Increment counter for number of comparisions performed.
	}
	
    size_t getHeight() const {
    	//size_t ret = log2(index);
    	//size_t fret = ret-1;
    //	std::cout << "index " << index << "t  " << t << std::endl;
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
    comp_type _less;

    void resize(int l){
    	//std::cout << "ok?" << std::endl;
					node_type* newarr = new node_type[l];
				//	std::cout << "hmmm" << std::endl;
					for(int i=1;i<length;i++){
						newarr[i] = pq[i];
					}	
					//std::cout << "ha ha" << std::endl;				
					delete [] pq;
				//	std::cout << "yolo" << std::endl;
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
    	while(k>1 && _less(pq[k/2].first, pq[k].first)){
    		counter++;
    		exch(k/2, k);
    		k = k/2;
    	}
    }
    void sink(int k, int N){
    	int j;
    	while(2*k <= N){
    		j = 2*k;
    		if(j < N && _less(pq[j].first, pq[j+1].first)){
    			counter++;
    			j++;
    		}
    		if(!(_less(pq[k].first, pq[j].first))){
    			counter++;
    			break;
    		}
    		exch(k, j);
    		k = j;
    	}
    }
};

#endif // CS251_HEAP_HPP

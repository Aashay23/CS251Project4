#ifndef CS251_MERGE_HPP
#define CS251_MERGE_HPP

#include "heap.hpp"
#include <vector>
#include <list>
#include <set>

typedef std::vector<int>                    SparseVector;
typedef std::list<int>                      IList;
typedef std::vector<std::pair<int, IList> > SparseMerge;
typedef std::pair<int, IList>               pair_type;

Heap<int, int, std::greater<int> > myMerge_heap;

void populateInput(const std::vector<SparseVector>& input){
		for(int i=0;i<input.size();i++){
			for(int j=0;j<input[i].size();j++){
				myMerge_heap.push(input[i][j], i);
			}
		}
}

void populateOutput(IList int_list, pair_type output_pair, size_t minNode, SparseMerge& output){
		int_list.sort();
		output_pair.first=minNode;
		output_pair.second = int_list;
		output.push_back(output_pair);
}

void merge(const std::vector<SparseVector>& input, SparseMerge& output){
		std::pair<int, int> node;
		pair_type output_pair;
		IList int_list;
		size_t minNode;
		
		populateInput(input);
		
		node = myMerge_heap.pop();
		minNode = node.first;
		int_list.push_back(node.second);
		
		while(myMerge_heap.getSize() != 0){
			node = myMerge_heap.pop();
			if(minNode == node.first){
				int_list.push_back(node.second);
			}else{
				populateOutput(int_list, output_pair, minNode, output);
				int_list.clear();
				int_list.push_back(node.second);
				minNode = node.first;
			}
		}

		if(myMerge_heap.getSize() == 0){
			populateOutput(int_list, output_pair, minNode, output);
		}
	// ADD CODE HERE
}

#endif // CS251_MERGE_HPP

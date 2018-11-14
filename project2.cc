///////////////////////////////////////////////////////////////////////////////
// project2.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "project2.hh"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;


//-----------------------------------------------------------------------------
// Randomize the order of all items in the list
//-----------------------------------------------------------------------------
void randomize_list(string_vector & strings) {
	// Initialize pseudo random generator with seed.
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	srand(seed);

	// Swap stuff.
	for (int i = 0; i < strings.size(); i++) {
		int num = rand();
		num = num % strings.size();
		swap(strings[i], strings[num]);
	}
	return;
}

//-----------------------------------------------------------------------------
void merge(string_vector & strings, size_t start, size_t mid, size_t end) {
	size_t right = mid + 1;
	// Base case, check to skip the merge.
	if (strings[mid] <= strings[right]) {
		return;
	}
	while (start <= mid && right <= end) {  
		// Check if in-place, move vector segment.
		if (strings[start] <= strings[right]) {
			start++;
		}
		// Check if not in-place, rotate, move vector segment.
		if (strings[start] > strings[right]) {
			// Moves the lesser value, strings[right] to the front of the vector segment.
			rotate(strings.begin()+start, strings.begin()+right, strings.begin()+right+1);
			start++;
			mid++;
			right++;
		}
	}
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings, size_t start, size_t end) {
	if (start < end) {
		size_t mid = (start+end) / 2;
		mergesort(strings, start, mid);
		mergesort(strings, mid + 1, end);
		merge(strings, start, mid, end);
	}
	return;
}

//-----------------------------------------------------------------------------
// Implementation of the Hoare Partition.
// This partition uses the first element of the list as a partition
// and divides the list into less than and greater than the pivot value
// It returns the index of the final position of the pivot value.
//-----------------------------------------------------------------------------
int hoare_partition(string_vector & strings, int start, int end) {
  // TODO: implement this function, then delete this comment
  return 0;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings, int start, int end) {
  // TODO: implement this function, then delete this comment
  return;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// ALREADY IMPLEMENTED 
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
//-----------------------------------------------------------------------------
bool load_words(string_vector& words, const std::string& path) 
{
  //std::cout << "Loading words from [" << path << "]" << std::endl;
  words.clear();
  std::ifstream ifs(path.c_str());
  if (!ifs.is_open() || !ifs.good()) {
    //cout << "Failed to open [" << path << "]" << std::endl;
    return false;
  }
  int countWordsLoaded = 0;
  while (!ifs.eof()) {
    std::string lineBuffer;
    std::getline(ifs, lineBuffer);
    if (ifs.eof()) {
      break;
    }
    words.push_back(lineBuffer);
    countWordsLoaded++;
  }
  //std::cout << "Loaded " << countWordsLoaded << " words from [" << path << "]" << std::endl;;
  return true;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  mergesort(strings, 0, strings.size() - 1);
  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  quicksort(strings, 0, strings.size() - 1);
  return;
}


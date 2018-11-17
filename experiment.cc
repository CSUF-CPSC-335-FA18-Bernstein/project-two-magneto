///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run an algorithm once and measure its elapsed
// time precisely. You should modify this program to gather all of your
// experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "project2.hh"
#include "timer.hh"

using namespace std;

int main() {

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }

  int n = 1000;
  string_vector n_words(all_words.begin(), all_words.begin() + n);

  randomize_list(n_words);

  Timer timer;
  mergesort(n_words);
  double elapsed = timer.elapsed();
  cout << "mergesort, "
       << "n=" << n << ", "
       << "elapsed time = " << elapsed << " seconds" << endl;

  
  
  
    /*ofstream mergesort_file, quicksort_file;
    mergesort_file.open("mergesort.txt");
    cout << "Mergesort\n";	
    for(int i = 0; i < 50000; i++){
   	  string_vector all_words;
 	  if ( ! load_words(all_words, "words.txt") ) {
 	  	cerr << "error: cannot open \"words.txt\"" << endl;
	  	return 1;
	  }
	
	  int n = 1000;	
	  string_vector n_words(all_words.begin(), all_words.begin() + n);

	  randomize_list(n_words);

	  Timer timer;
	  mergesort(n_words);
	  double elapsed = timer.elapsed();
	   cout << "Quicksort #" << i << "\t" << elapsed << endl;
	  mergesort_file << elapsed << endl;
}
    mergesort_file.close();

    cout << "Quicksort\n";	
    quicksort_file.open("quicksort.txt");	
    for(int i = 0; i < 50000; i++){
   	  string_vector all_words;
 	  if ( ! load_words(all_words, "words.txt") ) {
 	  	cerr << "error: cannot open \"words.txt\"" << endl;
	  	return 1;
	  }
	
	  int n = 1000;	
	  string_vector n_words(all_words.begin(), all_words.begin() + n);

	  randomize_list(n_words);

	  Timer timer;
	  quicksort(n_words);
	  double elapsed = timer.elapsed();
	  cout << "Quicksort #" << i << "\t" << elapsed << endl;
	  quicksort_file << elapsed << endl;
}
    quicksort_file.close();*/
  
  
  
  
  return 0;
}




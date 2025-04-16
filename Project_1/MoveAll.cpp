#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

	//using loop to iterate through vector of books
	for (auto it = source.begin(); it != source.end();) {
		bool found = false;
		//secondary loop to look for matching keywords
        for (const std::string& key : it->getKeywords()) {
            if (key == keyword) {
				//moves found book with matching keyword into destination data structure
                dest.push_back(std::move(*it));
				//removes book from original source
                it = source.erase(it);
				//counter for books moved
                books_moved++;
				found = true;
				// //breaks out of loop since book has been found, onto the next
                // break;
            }
        }
		if (!found) {
            ++it;
        }
    }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}
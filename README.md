# Compounded_word_solution
This is the solution of the compounded word problem in which we have to print the longest compounded word, second longest compounded word and the time taken to process the input file

We have to write name of the input file inside the ifstream function at line number 91.
By default I have written it "Input_01.txt".
After that you have to only compile and run the cpp file in any compiler.

In my program I have used Trie data structure.
For that I have made insert function which insert() each strings into the Trie DS. I have made a getNode() function which create a node of Trie DS.
For the search purpose I have made a search1() function which is a recursive function which call the another function search() when it reaches the end of a word.And passes the current node and the root of trie into it.

The search function matches the child array of both the node and call the search() again for the node for which the child array value is not null for both(the curr and root).If the curr node in the search reaches end we put the value of string for that node into our result unordered_set.

At last we take out the two largest string from the unordered_set and output it on the screen.
We also output the time taken in processing the input file in sec with the help of clock_t.

Thanks for reading this!!

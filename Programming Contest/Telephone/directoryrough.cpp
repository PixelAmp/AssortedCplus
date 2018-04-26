#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <iomanip>
#include <ctype.h>
using namespace std;

struct Node {
	string name;
	string converted; //Name converted  to  hashing and sorting friendly format
	string phone_num;
	Node *next;
};

//Function prototypes
string convert_name(string);
string convert_whitespace(string);
string remove_whitespace(string);
string convert_acronyms(string);
string convert_numbers(string);
string word_conversion(string);
string triplet_convert(int, int, int);
Node* merge_sort(Node *);

int main(int argc, char *argv[]) {
	//Data
	Node *directory[26] =  {NULL};
	Node *end[26] = {NULL}; //Points  to final node for O(1) insertion into linked list
	string iline; //Input buffer

	while (getline(cin, iline)){
			Node *newNode = new Node(); //Creates Node to  hold subscriber data
			newNode->phone_num = iline.substr(0, 7).insert(3, 1, ' '); //Phone number with space
			newNode->name = iline.substr(7); //Name - printing format
			newNode->converted = convert_name(iline.substr(7)); //Name - sorting format
			newNode->next = NULL;
			int hash = newNode->converted[0] - 'A'; //Hash: First letter is nth letter of alphabet
			if (directory[hash] == NULL) //If first entry, set as first entry
				directory[hash] = newNode;
			else //If not first entry, just add to end
				end[hash]->next = newNode;
			end[hash] = newNode; //Set the final node as the most recent node added
	}

	//Sorts each individual linked list with recursive merge sort
	for (int i = 0; i < 26; i++)
		directory[i] = merge_sort(directory[i]);
	
	//Prints each node
	for (Node * node : directory)
		while (node){ 
			cout <<setw(52) << left << node->name<< "    " << node->phone_num <<endl;
			node = node->next;
		}

	return 0;
}

//Converts the string using each of the required changes for sorting
string convert_name(string name){
	
	name = convert_whitespace(name);
	name = remove_whitespace(name);
	name = convert_acronyms(name);
	name = convert_numbers(name);
	for (int i = 0; i < name.length(); i++)
		name[i] = toupper(name[i]);
	return name;

}

//Converts all special (non-aplhanumeric) characters to whitespace
string convert_whitespace(string name){
	for (int i = 0; i < name.length(); i++)
		if (!isalnum(name[i]))
			name[i] = ' ';
	return name;
}

//Removes all excess whitespace
string remove_whitespace(string name ) { 
	int i = 0;
	bool wflag = false;

	string buffer;
	for (char c : name){
		if (isspace(c)){
			if (!wflag) //Prints space as long as previous char wasn't space
				buffer.push_back(c);
			wflag = true;
		}
		else{
			buffer.push_back(c);
			wflag = false;
		}
	}

	return buffer; 
}
string convert_acronyms(string name) {
	string buffer;
	string holder;
	bool capsflag = true;
	name.push_back(' '); //So that the algorithm catches final word
	
	for (char c : name){
		//If a character isn't a space - push it to the word holder
		if (!isspace(c)){
			holder.push_back(c);
			if (capsflag && !isupper(c))
				capsflag = false;
		}
		else {
			//If all characters were uppercase - it is an acronym
			if (capsflag){
				//Therefore, add all of the characters to the name with spaces between
				for (char holdc : holder){
					buffer.push_back(holdc);
					buffer.push_back(' ');
				}
			}
			//Otherwise, add word normally
			else{
				for (char holdc : holder)
					buffer.push_back(holdc);
				buffer.push_back(' ');
			}
			holder.clear(); //Clear word holder for next word
			capsflag = true;
		}
	}
	buffer.pop_back(); //Remove extra whitespace added due to algorithm
	return buffer;
}

//Finds numbers and converts them
string convert_numbers(string name) { 
	string buffer;
	string holder;
	bool numflag = false;
	name.push_back(' '); //Appens extra whitespace  for algorithm

	for (char c : name){
		//If number is a digit, add it to the number holder
		if (isdigit(c)){
			holder.push_back(c);
			numflag = true;
		}
		else{
			//If previous characters were digits, unload the holder into buffer with conversion
			if (numflag){
				buffer.append(word_conversion(holder));
				buffer.push_back(' ');
				holder.clear();
				numflag = false;
			}
			//Otherwise, add character to buffer normally
			else
				buffer.push_back(c);
		}
	}

	buffer.pop_back(); //Removes extra whitespace used by algorithm
	return buffer; 
}

//Converts number to word representation of number
string word_conversion(string num){
	int len = num.length();
	int nums[9] = {0,0,0,0,0,0,0,0,0}; //Array of numbers defaulted to zero
	
	//Adds numbers into array
	int len_count = len;
	for (char n : num){
		nums[9 - len_count] = int(n) - '0';
		len_count--;
	}
	
	string numbuffer;

	//millions
	if (len > 6){
		numbuffer.append(triplet_convert(nums[0], nums[1], nums[2]));
		numbuffer.append("million ");
	}

	//thousands
	if (len > 3){
		numbuffer.append(triplet_convert(nums[3], nums[4], nums[5]));
		numbuffer.append("thousand ");
	}

	//hundreds
	if (len > 0){
		if (len == 1 && num[8] == 0)
			numbuffer.append("zero ");
		else 
			numbuffer.append(triplet_convert(nums[6], nums[7], nums[8]));
	}

	numbuffer.pop_back(); //Removes extra whitespace added by algorithm
	return numbuffer;
}

//Converts each triplet (ie. in 123,456,789 then 123 is a triplet, 456 is a triplet, etc.)
string triplet_convert(int a, int b, int c){
	//singles
	string singles[10] {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	//tens
	string tens[10] {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string teens[10] {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	string numbuffer;

	if (a > 0){
		numbuffer.append(singles[a]);
		numbuffer.append(" hundred ");
	}
	if (b > 1){
		numbuffer.append(tens[b]);
		numbuffer.append(" ");
		if (c > 0) {
			numbuffer.append(singles[c]);
			numbuffer.append(" ");
		}
	}
	else if (b == 1) {
		numbuffer.append(teens[c]);
		numbuffer.append(" ");
	}

	return numbuffer;
}

//Recursive merge sort
Node* merge_sort(Node * start){
	//If empty, return nothing
	if(!start)
		return NULL;

	//Finds length of current list
	Node *node = start;
	int count = 0;
	while (node){
		count++;
		node  = node->next;
	}

	//If only two elements, put in order and return
	if(count == 2){
		if (start->converted.compare(start->next->converted) <= 0){
			return start;
		}
		else {
			Node * temp = NULL;
			Node * i = start->next;
			i->next = start;
			start->next = temp;
			return i;
		}
	}

	//If only one element, return it
	else if (count == 1)
		return start;

	//Otherwise, call merge sort on each half and sort the sorted lists
	else{
		//Point to halfway point in list
		int half = count / 2;
		Node *second_start = start;
		while (half != 0){
			second_start = second_start->next;
			half--;
		}

		//Seperates list into two lists
		Node *temp = second_start->next;
		second_start->next = NULL;
		second_start = temp;

		//Sort individual lists
		Node *first_list = merge_sort(start);
		Node *second_list = merge_sort(second_start);

		//Sort both lists into new list
		Node *sorted_list = new Node();
		Node *current_node = sorted_list;

		while (first_list && second_list){
			//If both lists have remaining nodes, compare and add to master list
			if (first_list->converted.compare(second_list->converted) <= 0){
				Node * temp = first_list;
				first_list = first_list->next;
				current_node->next = temp;
				current_node = current_node->next;
			}	
			else {
				Node * temp = second_list;
				second_list = second_list->next;
				current_node->next = temp;
				current_node = current_node->next;
			}
		}

		//If only first list has nodes remaining, add the rest to the master list
		if (first_list)
			while (first_list){
				Node * temp = first_list;
				first_list = first_list->next;
				current_node->next = temp;
				current_node = current_node->next;
			}

		//If second first list has nodes remaining, add the rest to the master list
		else if (second_list)
			while (second_list){
				Node * temp = second_list;
				second_list = second_list->next;
				current_node->next = temp;
				current_node = current_node->next;
			}
		
		return sorted_list->next;
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ifstream input("name_train.csv");
	ofstream output("converted_train.csv");
	string value;

	while ( input.good() ){
	    getline ( input, value );
	    value.erase(
	    	remove( value.begin(), value.end(), '\"' ),
	    	value.end()
	    );
	    transform(value.begin(), value.end(), value.begin(), ::tolower);

	    output << "[ ";
	    for (int i = 0; i < value.length(); ++i)
	    {
	    	if ((int)value[i] != 32) {
	    		output << (int)value[i] << " ";
	    	}
	    }
	    output << "]\n";
	}
	output.close();
}